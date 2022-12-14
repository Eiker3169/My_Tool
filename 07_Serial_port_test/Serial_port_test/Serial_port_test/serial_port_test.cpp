#include "serial_port_test.h"
#include "ui_serial_port_test.h"

#include "MyHighlighter.h"
#include <QTextBlock>
#include <QPalette>

Serial_port_test::Serial_port_test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Serial_port_test)
{
    ui->setupUi(this);

    QStringList m_portNameList = getPortNameList();
    ui->serialPortCbx->addItems(m_portNameList);

    ui->serialPortCbx->installEventFilter(this);

    timer.setTimerType(Qt::PreciseTimer);
    test_timer.setTimerType(Qt::PreciseTimer);

//    QObject::connect(&timer,&QTimer::timeout,this,&Serial_port_test::message_filtering);

//    timer.start(100);

    //背景和选区颜色
    QPalette pt = palette();
    pt.setBrush(QPalette::Text, Qt::white);
    pt.setBrush(QPalette::Base, Qt::black);
    pt.setBrush(QPalette::Highlight, Qt::gray);
    pt.setBrush(QPalette::HighlightedText, Qt::NoBrush);
    ui->logtextEdit->setPalette(pt);

    //语法高亮
    MyHighlighter *keys_lighter = new MyHighlighter(ui->logtextEdit->document());
    Q_UNUSED(keys_lighter)

    //当前行颜色设置
    connect(ui->logtextEdit, &QTextEdit::cursorPositionChanged, this, &Serial_port_test::updateHighlight);
    updateHighlight();

    connect(ui->msg_filtering,&QLineEdit::textChanged,this,[=]{
        keys_lighter->highlightingRules.removeLast();
        msg_filtering_changed = ui->msg_filtering->text();
        MyHighlighter::HighlightingRule filtering;
        filtering.pattern.setPattern(msg_filtering_changed);
        filtering.format.setForeground(QColor(238, 0, 0));
        keys_lighter->highlightingRules.append(filtering);

    });

    connect(ui->set_hz,&QLineEdit::textChanged,this,[=]{
        bool ok;
        QString tmp_str = ui->set_hz->text();
        int tmp_int = tmp_str.toInt(&ok,10);
        if((tmp_int>=1)&&(tmp_int<=10)){
            test_hz = tmp_int;
        }
    });

}

Serial_port_test::~Serial_port_test()
{
    delete ui;
}

QStringList Serial_port_test::getPortNameList()
{
    QStringList m_serialPortName;
        foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
        {
            m_serialPortName << info.portName();
            qDebug()<<"serialPortName:"<<info.portName();
        }
        return m_serialPortName;
}

void Serial_port_test::StringToHex(QString str, QByteArray &senddata)
{
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
        //char lstr,
        hstr = str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
}

char Serial_port_test::ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return (-1);

}

void Serial_port_test::recvData()
{
    if(rec_timer == false){
        rec_timer = true;
    QObject::connect(&timer,&QTimer::timeout,this,&Serial_port_test::message_filtering);
    timer.start(100);
    }

    QMutexLocker locker(&status_mutex);

    QByteArray recvbuf;
    recvbuf = serial->readAll();

    serial_buf += QString(recvbuf);
}

bool Serial_port_test::message_filtering()
{

    if(serial_buf != ""){
        QMutexLocker locker(&status_mutex);

        QString tmp_str = ui->msg_filtering->text();
        bool tmp_bool = serial_buf.contains(tmp_str,Qt::CaseInsensitive);
        if(is_open_filtering == true){
            if(!tmp_bool){
                serial_buf = "";
                return false;
            }
        }

        if(received_count_flag == true){
            if(tmp_bool){
                received_count++;
            }
        }

        QDateTime dateTime = QDateTime::currentDateTime();// 字符串格式化
        QString timestr = dateTime.toString("[yyyy-MM-dd hh:mm:ss.zzz]");
        timestr = QString("<font color=\"#00FA9A\">%1</font> ").arg(timestr);
        ui->logtextEdit->append(timestr);

        ui->logtextEdit->append(serial_buf);
        rec_timer = false;
        QObject::disconnect(&timer,nullptr,nullptr,nullptr);
        serial_buf = "";
        return true;
    }
    return false;


}

bool Serial_port_test::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress){
        if(watched == ui->serialPortCbx){

            QComboBox * combobox = qobject_cast<QComboBox *>(watched);
            combobox->clear();
            QStringList m_portNameList = getPortNameList();
            combobox->addItems(m_portNameList);
        }
        return true;
    }
    return false;
}

int Serial_port_test::indexOfNthStr(QString sourceStr, QString str, uint N)
{
    int index = -1;
       while(N--)
       {
           index = sourceStr.indexOf(str,index+1);
           if(index == -1)
           {
               break;
           }
       }
       return index;
}



void Serial_port_test::updateHighlight()
{
    QList<QTextEdit::ExtraSelection> extra_selections;

    //当前行背景样式
    QTextEdit::ExtraSelection line;
    line.format.setBackground(QColor(0, 0, 255));
    line.format.setProperty(QTextFormat::FullWidthSelection, true);
    line.cursor = ui->logtextEdit->textCursor();
    line.cursor.clearSelection();
    extra_selections.append(line);

    ui->logtextEdit->setExtraSelections(extra_selections);
}

void Serial_port_test::on_openSerialBtn_clicked()
{
    if(!isconnected){
        // 打开串口
        QString serialPortName = "";
        serialPortName = ui->serialPortCbx->currentText();
        if(serialPortName == ""){
            QMessageBox::warning(this, "参数错误", "未选择串口号或者无可用串口！");
            return;
        }

        // 设置串口名
        serial = new QSerialPort;
        //comm.reset(serial);
        serial->setPortName((ui->serialPortCbx->currentText()));

        // 打开串口
        bool re = serial->open(QIODevice::ReadWrite);

        if(re){
            if(ui->baudrateCbx->currentText()=="9600")
                serial->setBaudRate(QSerialPort::Baud9600);
            else if (ui->baudrateCbx->currentText()=="1000000")
                serial->setBaudRate(BaudRate::Baud1000000);
            else if (ui->baudrateCbx->currentText()=="115200")
                serial->setBaudRate(QSerialPort::Baud115200);//设置波特率为115200

            serial->setDataBits(QSerialPort::Data8);//设置数据位8
            serial->setParity(QSerialPort::NoParity); //校验位设置为0
            serial->setStopBits(QSerialPort::OneStop);//停止位设置为1
            serial->setFlowControl(QSerialPort::NoFlowControl);//设置为无流控制

            connect(serial, SIGNAL(readyRead()), this, SLOT(recvData()));// 连接信号槽，处理接收数据
            ui->openSerialBtn->setText(tr("关闭串口"));

            isconnected = true;// 连接成功，更新连接状态

            ui->serialPortCbx->setEnabled(false);// 打开后，不能选择串口号
            ui->baudrateCbx->setEnabled(false);
        }
        else {
            QMessageBox::warning(this, "操作错误", "打开串口失败");
        }
    }
    else{
        isconnected = false;

        disconnect(serial, SIGNAL(readyRead()), this, SLOT(recvData()));
        serial->clear();
        serial->close();
        serial->deleteLater();

        ui->openSerialBtn->setText(tr("打开串口"));
        ui->serialPortCbx->setEnabled(true);// 关闭后，可以重新选择串口号
        ui->baudrateCbx->setEnabled(true);
   }


}


void Serial_port_test::on_clear_data_clicked()
{
    ui->logtextEdit->setText("");
}


void Serial_port_test::on_start_test_clicked()
{
    if(is_open == false)
    {
        ui->received_rate->setText("接受率：");
        ui->should_accept->setText("");
        ui->received->setText("");
        ui->start_test->setEnabled(false);
        ui->close_test->setEnabled(true);
        ui->set_hz->setEnabled(false);
        is_open = true;
        received_count_flag = true;
        received_count = 0;
        test_count = 0;
        QObject::connect(&test_timer,&QTimer::timeout,this,[&](){
            test_count += test_hz;
            QString str = "应接受：";
            str += QString::number(test_count);
            ui->should_accept->setText(str);
            str = "已接受：";
            str += QString::number(received_count);
            ui->received->setText(str);

            if(is_close_test_connect == true){
                QObject::disconnect(&test_timer,nullptr,nullptr,nullptr);

                double tmp_double = (double)received_count / (double)test_count;
                tmp_double *= (double)100;

                QString str = "接受率：";
                str += QString::number(tmp_double,'f',2);
                str += "%";

                ui->received_rate->setText(str);

                is_close_test_connect = false;
                received_count_flag = false;
            }

        });

        test_timer.start(1000);
    }
}


void Serial_port_test::on_close_test_clicked()
{
    if(is_open == true){
        ui->start_test->setEnabled(true);
        ui->close_test->setEnabled(false);
        ui->set_hz->setEnabled(true);
        is_open = false;

        is_close_test_connect = true;

    }
}


void Serial_port_test::on_start_filtering_clicked()
{
    is_open_filtering = true;
    ui->start_filtering->setEnabled(false);
    ui->stop_filtering->setEnabled(true);
    ui->msg_filtering->setEnabled(false);
}


void Serial_port_test::on_stop_filtering_clicked()
{
    is_open_filtering = false;
    ui->start_filtering->setEnabled(true);
    ui->stop_filtering->setEnabled(false);
    ui->msg_filtering->setEnabled(true);
}


void Serial_port_test::on_send_clicked()
{
    if(isconnected == true){
        if(ui->send->text().isEmpty()){
            return;
        }

        QString send_str = ui->send_data->text().toUpper();
        qDebug()<<send_str;

        QByteArray send_data;
        StringToHex(send_str,send_data);
        serial->write(send_data);

    }

}


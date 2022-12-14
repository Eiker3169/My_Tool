#include "serial_port_test.h"
#include "ui_serial_port_test.h"

Serial_port_test::Serial_port_test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Serial_port_test)
{
    ui->setupUi(this);

    QStringList m_portNameList = getPortNameList();
    ui->serialPortCbx->addItems(m_portNameList);

    ui->serialPortCbx->installEventFilter(this);

    timer.setTimerType(Qt::PreciseTimer);

//    QObject::connect(&timer,&QTimer::timeout,this,&Serial_port_test::message_filtering);

//    timer.start(100);



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

void Serial_port_test::thread_run()
{
//    if(serial_buf != ""){
//        if(message_filtering_flag == true){
//            QString str = "received 35";
//            if(serial_buf.contains(str,Qt::CaseInsensitive)){
//               QDateTime dateTime = QDateTime::currentDateTime();// 字符串格式化
//               QString timestr = dateTime.toString("[yyyy-MM-dd hh:mm:ss.zzz] ");
//               timestr = QString("<font color=\"#00FA9A\">%1</font> ").arg(timestr);
//               timestr+="received 35";
//                ui->logtextEdit->append(timestr);

//                if(is_open == true){
//                    received_count++;
//                    QString str = "实接受：";
//                    str += QString::number(received_count);
//                    ui->received->setText(str);

//                }
//            }
//            serial_buf = "";
//            ui->logtextEdit->moveCursor(QTextCursor::End);
//        }
//        else{
//            QDateTime dateTime = QDateTime::currentDateTime();// 字符串格式化
//            QString timestr = dateTime.toString("[yyyy-MM-dd hh:mm:ss.zzz] ");
//            timestr = QString("<font color=\"#00FA9A\">%1</font> ").arg(timestr);
//            ui->logtextEdit->append(timestr);

//            QString str = "";
//            foreach(auto msg,serial_buf){
//                if(msg != '\n'){
//                    str.append(msg);
//                }
//                else{
//                    QString tmp_msg = ui->msg_filtering->text();
//                    str = change_str_color(str,tmp_msg,"red");
//                    ui->logtextEdit->append(str);
//                    str = "";
//                }
//            }

//            serial_buf = "";
//            ui->logtextEdit->moveCursor(QTextCursor::End);
//        }


//    }



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

//    QDateTime dateTime = QDateTime::currentDateTime();// 字符串格式化
//    QString timestr = dateTime.toString("[yyyy-MM-dd hh:mm:ss.zzz] ");
//    timestr += tmp_str;

    //qDebug()<<timestr;


}

void Serial_port_test::message_filtering()
{
    if(serial_buf != ""){
        QMutexLocker locker(&status_mutex);

        QDateTime dateTime = QDateTime::currentDateTime();// 字符串格式化
        QString timestr = dateTime.toString("[yyyy-MM-dd hh:mm:ss.zzz] ");
        timestr = QString("<font color=\"#00FA9A\">%1</font> ").arg(timestr);
        ui->logtextEdit->append(timestr);

        QString tmp_str = ui->msg_filtering->text();
        QRegExp tmp_RegExp(QString("(%1)").arg(tmp_str));
        tmp_RegExp.setCaseSensitivity(Qt::CaseInsensitive);
        if(tmp_str != ""){
            serial_buf = serial_buf.replace(tmp_RegExp,QString("<font color=\"#FF0000\">%1</font>").arg(tmp_str));
        }

//    //    serial_buf = serial_buf.replace(QRegExp(tmp_str,Qt::CaseInsensitive),QString("<span style=\"color:red\">%1</span>").arg(tmp_str));
//        if(tmp_str != ""){
//            serial_buf = serial_buf.replace(QRegExp(tmp_str,Qt::CaseInsensitive),QString("<font color=\"#FF0000\">%1</font>").arg(tmp_str));
//        }

        ui->logtextEdit->append(serial_buf);
        rec_timer = false;
        QObject::disconnect(&timer,nullptr,nullptr,nullptr);
        serial_buf = "";
    }

//    QMutexLocker locker(&status_mutex);
//    QtConcurrent::run(this,&Serial_port_test::thread_run);

/*    if(serial_buf != ""){
        if(message_filtering_flag == true){
            QString str = "received 35";
            if(serial_buf.contains(str,Qt::CaseInsensitive)){
               QDateTime dateTime = QDateTime::currentDateTime();// 字符串格式化
               QString timestr = dateTime.toString("[yyyy-MM-dd hh:mm:ss.zzz] ");
               timestr = QString("<font color=\"#00FA9A\">%1</font> ").arg(timestr);
               timestr+="received 35";
                ui->logtextEdit->append(timestr);

                if(is_open == true){
                    received_count++;
                    QString str = "实接受：";
                    str += QString::number(received_count);
                    ui->received->setText(str);

                }
            }
            serial_buf = "";
            ui->logtextEdit->moveCursor(QTextCursor::End);
        }
        else{
            QDateTime dateTime = QDateTime::currentDateTime();// 字符串格式化
            QString timestr = dateTime.toString("[yyyy-MM-dd hh:mm:ss.zzz] ");
            timestr = QString("<font color=\"#00FA9A\">%1</font> ").arg(timestr);
            ui->logtextEdit->append(timestr);

            QString str = "";
            foreach(auto msg,serial_buf){
                if(msg != '\n'){
                    str.append(msg);
                }
                else{
                    QString tmp_msg = ui->msg_filtering->text();
                    str = change_str_color(str,tmp_msg,"red");
                    ui->logtextEdit->append(str);
                    str = "";
                }
            }

            serial_buf = "";
            ui->logtextEdit->moveCursor(QTextCursor::End);
        }


    } */
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

QString Serial_port_test::change_str_color(QString sourceStr, QString str, QString color)
{   QString tmp_str = "";
    QString tmp_str_change = "";
    int tmp_str_size = str.size();
    int tmp_sourceStr_size = sourceStr.size();
    int tmp_count = sourceStr.count(str);
    bool pos_flag = false;
    for(int i = 0; i < tmp_sourceStr_size; i++){
        for(int j = 0; j < tmp_count+1; j++){
            int tmp_pos = indexOfNthStr(sourceStr, str, j);
            if((i >= tmp_pos)&&(i < (tmp_pos + tmp_str_size))){
                pos_flag = true;
                if(i == tmp_pos){
                    if(color == "red"){
                        tmp_str_change = QString("<font color=\"#FF0000\">%1</font>").arg(str);
                    }
                    else if(color == "green"){
                        tmp_str_change = QString("<font color=\"#00FA9A\">%1</font>").arg(str);
                    }
                    else if(color == "bule"){
                        tmp_str_change = QString("<<font color=\"#0000FF\">%1</font>").arg(str);
                    }
                    else{
                        tmp_str_change = QString("<font color=\"#FFFFFF\">%1</font>").arg(str);
                    }

//                    int tmp_int = tmp_str_change.size();
//                    for(int c = 0; c < tmp_int-1; c++){
//                        tmp_str.append(tmp_str_change.at(c));
//                    }
                    tmp_str.append(tmp_str_change);
                }
            }

        }
        if(pos_flag != true){
            tmp_str += sourceStr.at(i);
        }
        pos_flag = false;
    }
    return tmp_str;
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
        is_open = true;
        received_count = 0;
        test_count = 0;
        QObject::connect(&test_timer,&QTimer::timeout,this,[&](){
            test_count++;
            QString str = "应接受：";
            str += QString::number(test_count);
            ui->should_accept->setText(str);
        });

        test_timer.start(1000);
    }
}


void Serial_port_test::on_close_test_clicked()
{
    if(is_open == true){
        ui->start_test->setEnabled(true);
        ui->close_test->setEnabled(false);
        is_open = false;
        QObject::disconnect(&test_timer,nullptr,nullptr,nullptr);

        double tmp_double = (double)received_count / (double)test_count;
        tmp_double *= (double)100;

        QString str = "接受率：";
        str += QString::number(tmp_double,'f',2);
        str += "%";

        ui->received_rate->setText(str);
    }
}


void Serial_port_test::on_start_filtering_clicked()
{

}


void Serial_port_test::on_stop_filtering_clicked()
{

}


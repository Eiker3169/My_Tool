#include "client.h"
#include "ui_client.h"

client::client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);

    tcpsocket=NULL;

    tcpsocket=new QTcpSocket(this);

    connect(tcpsocket,&QTcpSocket::connected,[=](){
            ui->sended_text->setText("服务器连接成功！");
        });

    connect(tcpsocket,&QTcpSocket::readyRead,[=](){
           //获取通信套接字的内容
            QString str=tcpsocket->readAll();

            show_received_text(str);

//        QByteArray bytes=tcpsocket->readAll();
//        QString str = bytes.toHex();
//        QString str=tcpsocket->readAll();
//        qDebug()<<str;
//            bool ok;
//            int length = str.length();
//            for(int i = 0; i < length-6; i++){
//                if((str.mid(i,2)=="59")&&(str.mid(i+4,2)=="30")){
//                    QString tmp = str.mid(i+2,2);
//                    int value = tmp.toInt(&ok,16)*2;
//                    tmp = str.mid(i+6,value);
//                    show_received_text(tmp);
//                }
//            }



        });

}

client::~client()
{
    if(m_send_data != NULL){
        delete m_send_data;
    }

    if(m_receive_data != NULL){
        delete m_receive_data;
    }
    delete ui;
}

void client::on_connect_clicked()
{
    if(ui->server_ip == nullptr || ui->port == nullptr)
            return ;

    //获取IP地址和端口号
    QString IP=ui->server_ip->text();
    quint16 Port=ui->port->text().toInt();

    //与服务器连接
    tcpsocket->connectToHost(IP,Port);

}


void client::on_send_clicked()
{
    if(tcpsocket == NULL)
        return;

    ui->recevied_text->setText("");

    //获取发送的信息
    QString str=ui->sended_text->toPlainText();

    //将信息写入到通信套接字
    tcpsocket->write(str.toUtf8().data());

}

unsigned char client::random_number(int range_head, int range_tail)
{
    return QRandomGenerator::global()->bounded(range_head, range_tail);
}

void client::connect_interval(int time_)
{
    if(is_connect == false){
        timer = new QTimer(this);
        if(start_flag == 1){
            is_connect = QObject::connect(timer, SIGNAL(timeout()), this, SLOT(test()));
        }
        else if(start_flag ==2){
            is_connect = QObject::connect(timer, SIGNAL(timeout()), this, SLOT(send_sended_text_content()));
        }
        timer->start(time_);
    }
}

void client::show_sended_text(QString str)
{
    ui->sended_text->insertPlainText(str);
}

void client::show_received_text(QString str)
{
    ui->recevied_text->insertPlainText(str);
}

void client::send_data(QString str)
{
    tcpsocket->write(str.toUtf8().data());


//    QString tmp_str;
//    int length = str.length();
//    unsigned _length = length/2;
//    QString str_length = QString::number(_length,16);
//    if(str_length.length()==1)
//    {
//        str_length = "0"+str_length;
//    }

////    unsigned char crc_hi = CRC & 0xff;
////    unsigned char crc_lo = CRC >> 8;
////    QString crc_h = QString::number((char)crc_hi,16);
////    QString crc_l = QString::number((char)crc_lo,16);
////    QString crc_ = crc_h+crc_l;
//    tmp_str = "59" + str_length + "30" + str + "0000" + "47";

//    tcpsocket->write(tmp_str.toUtf8().data());
}

void client::show_send_data(QString str)
{
    show_sended_text(str);
}

void client::receive_data(QString str)
{
    receive_str+=str;
}

void client::show_recive_data(QString str)
{
    show_received_text(str);
}

void client::m_error_rate()
{
    int error_ = 0;
    send_str = ui->sended_text->toPlainText();
    receive_str = ui->recevied_text->toPlainText();
    int send_len = send_str.toLocal8Bit().length();
    int receive_len = receive_str.toLocal8Bit().length();

    show_sended_received_byte(send_len, receive_len);

    for(int i = 0; i < send_len && i < receive_len; i++){
        if(send_str.mid(i,1) != receive_str.mid(i,1)){
            error_++;
        }
    }

    double tem;

    if(send_len > receive_len){
        error_ += (send_len - receive_len);
        tem = (double)error_/(double)send_len;
    }
    else if(receive_len > send_len){
        error_ += (receive_len - send_len);
        tem = (double)error_/(double)receive_len;
    }
    else{
        tem = (double)error_/(double)send_len;
    }
    tem *= 100;
    qDebug()<<tem;

    show_error_byte(error_);

    QString str = QString::number(tem, 'f', 5);
    ui->error_rate_->setText(str + "%");
}

void client::show_sended_received_byte(int sended, int received)
{
    QString str1, str2;
    str1 = QString::number(sended);
    str2 = QString::number(received);
    ui->sended_byte->setText(str1);
    ui->received_byte->setText(str2);
}

void client::show_error_byte(int error_byte)
{
    QString str = QString::number(error_byte);
    ui->error_byte->setText(str);
}

void client::send_sended_text_content()
{
    m_str = "";
    if(count < m_total_once){
        m_str = sended_text_content.mid(count*once, once);
        send_data(m_str);
    }
    else{
        m_str = sended_text_content.mid(count*once, m_total_0);
        send_data(m_str);

        if(is_connect == true){
            count = 0;
            QObject::disconnect(timer, SIGNAL(timeout()), this, SLOT(send_sended_text_content()));
            is_connect = false;
          }

        QTimer m_timer;
        QEventLoop m_loop;
         QObject::connect(&m_timer,&QTimer::timeout,&m_loop,[&](){
             m_timer.stop();
             m_loop.quit();
             m_error_rate();
             ui->start->setEnabled(true);
             ui->start_2->setEnabled(true);
         });

         m_timer.start(1000);
         m_loop.exec();
    }

    count++;
}

void client::test()
{
    m_str = "";
    unsigned int tem;
    if(count < m_total_once){
        for(int i = 0; i < once; i++){
            tem = random_number(0,15);
            m_send_data[m_send_data_count++] = tem;
            QString str = QString::number(tem,16);
            m_str += str;
        }
        send_data(m_str);
        show_send_data(m_str);
    }
    else{
        for(int i = 0; i < m_total_0; i++){
            tem = random_number(0,15);
            m_send_data[m_send_data_count++] = tem;
            QString str = QString::number(tem,16);
            m_str += str;
        }
        send_data(m_str);
        show_send_data(m_str);
        if(is_connect == true){
            count = 0;
            QObject::disconnect(timer, SIGNAL(timeout()), this, SLOT(test()));
            is_connect = false;
          }

        QTimer m_timer;
        QEventLoop m_loop;
         QObject::connect(&m_timer,&QTimer::timeout,&m_loop,[&](){
             m_timer.stop();
             m_loop.quit();
             m_error_rate();
             ui->start->setEnabled(true);
             ui->start_2->setEnabled(true);
         });

         m_timer.start(1000);
         m_loop.exec();

      }



    send_str += m_str;
    count++;

}

void client::on_start_clicked()
{
    ui->start->setEnabled(false);
    ui->start_2->setEnabled(false);
    start_flag = 1;
    if(is_connect == true){
        QObject::disconnect(timer, SIGNAL(timeout()), this, SLOT(test()));
        is_connect = false;
    }

    count = 0;
    m_send_data_count = 0;
    m_receive_data_count = 0;
    send_str = "";
    receive_str = "";

    QString tem;
    tem = ui->total_send_byte->text();
    m_total = tem.toInt();

    if(m_send_data == NULL){
        m_send_data = new unsigned int [m_total];
    }
    else{
        delete m_send_data;
        m_send_data = new unsigned int [m_total];
    }

    if(m_receive_data == NULL){
        m_receive_data = new unsigned int [m_total];
    }
    else{
        delete m_receive_data;
        m_receive_data = new unsigned int [m_total];
    }


    m_total_0 = m_total % once;
    m_total_once = m_total / once;
    qDebug()<<m_total_0;
    qDebug()<<m_total_once;

    ui->sended_text->setText("");
    ui->recevied_text->setText("");


    connect_interval(50);
}




void client::on_reset_clicked()
{
    ui->sended_text->setText("");
    ui->recevied_text->setText("");
    ui->sended_byte->setText("");
    ui->received_byte->setText("");
    ui->error_byte->setText("");
    ui->error_rate_->setText("");
}





void client::on_start_2_clicked()
{
    ui->start->setEnabled(false);
    ui->start_2->setEnabled(false);
    start_flag = 2;
    if(is_connect == true){
        QObject::disconnect(timer, SIGNAL(timeout()), this, SLOT(send_sended_text_content()));
        is_connect = false;
    }
    count = 0;
    sended_text_content = "";
    send_str = ui->sended_text->toPlainText();
    m_total = send_str.toLocal8Bit().length();
    sended_text_content = ui->sended_text->document()->toPlainText();

    m_total_0 = m_total % once;
    m_total_once = m_total / once;

    ui->recevied_text->setText("");

    connect_interval(50);

}


void client::on_reset_2_clicked()
{
    ui->sended_text->setText("");
    ui->recevied_text->setText("");
    ui->sended_byte->setText("");
    ui->received_byte->setText("");
    ui->error_byte->setText("");
    ui->error_rate_->setText("");
}


void client::on_checkout_clicked()
{
    m_error_rate();
}


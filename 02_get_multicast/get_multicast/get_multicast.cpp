#include "get_multicast.h"
#include "ui_get_multicast.h"

#include <QWidget>


get_multicast::get_multicast(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::get_multicast)
{
    ui->setupUi(this);
    init_multicast();


}

get_multicast::~get_multicast()
{
    delete ui;
}



//待移植
void get_multicast::on_scan_ip_clicked()
{
    is_close = true;
    if(is_join == false)
    {
        is_join = true;
        joinMulticast();
        show_ = new scan_ip;
        show_->setAttribute(Qt::WA_DeleteOnClose);
        show_->show();
        connect(show_,&QWidget::destroyed,this,[=](){
            qDebug()<<"test";
            is_close = false;
            leaveMulticast();
        });
    }
//    else
//    {
//        is_join = false;
//        leaveMulticast();
//    }



}

void get_multicast::init_multicast()
{
    useRow = 0;
    is_join = false;
    is_close = false;
    m_qudpSocket = new QUdpSocket;

}

void get_multicast::joinMulticast()
{
    if(!m_qudpSocket->bind(QHostAddress::AnyIPv4,45454,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint)){//绑定组播端口号
        qDebug()<<"绑定组播端口失败";
        is_join = false;
    }
    else{
        qDebug()<<"加入组播";
        m_qudpSocket->joinMulticastGroup(QHostAddress("224.0.0.115")); //加入组播ip
        connect(m_qudpSocket,SIGNAL(readyRead()),this,SLOT(dealReadyRead()));
    }
}

void get_multicast::leaveMulticast()
{
    m_qudpSocket->leaveMulticastGroup(QHostAddress("224.0.0.115"));
    m_qudpSocket->abort();
    disconnect(m_qudpSocket,SIGNAL(readyRead()),this,SLOT(dealReadyRead()));
    is_join=false;
    qDebug()<<"退出组播";
}

void get_multicast::dealReadyRead()
{
    qDebug()<<"cc";
    if(is_close == true){
    bool ok,is_exist=false;
    QString data_hexstr,STX,IP;
    QByteArray array;
    QUdpSocket *udpSocket = dynamic_cast<QUdpSocket *>(sender());

    while (udpSocket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = udpSocket->receiveDatagram();
        array = datagram.data();
        data_hexstr = array.toHex();
        IP = datagram.senderAddress().toString();
        STX = data_hexstr.mid(0,2);

        if(data_hexstr.mid(0,4)=="ffff"&&data_hexstr.mid(30,2)=="a6"){ //选择打印需要的IP
            qDebug()<<data_hexstr<<","<<datagram.senderAddress()<<datagram.senderPort();
            for(int i=0;i<256;i++)
            {
                if(IP == buf[i])
                {
                    is_exist = true;
                }

            }
            if(is_exist == false)
            {
                 buf[useRow] = IP;
                 show_->show_ip(IP,useRow);
                 useRow++;
            }
            else
            {
                is_exist = false;
            }
            }


    }
    }
}









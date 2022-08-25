#include "get_multicast.h"
#include "ui_get_multicast.h"



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

void get_multicast::init_multicast()
{
    m_qudpSocket = new QUdpSocket(this);
    m_qudpSocket->bind(QHostAddress::AnyIPv4,45454,QUdpSocket::ShareAddress);//绑定所有ip来接收组播组信息，45454为组播端口号
    m_qudpSocket->joinMulticastGroup(QHostAddress("224.0.0.115")); //加入组播ip
    connect(m_qudpSocket,SIGNAL(readyRead()),this,SLOT(dealReadyRead()));
}

void get_multicast::dealReadyRead()
{
    bool ok;
    QString data_hexstr,STX;
    QByteArray array;
    QUdpSocket *udpSocket = dynamic_cast<QUdpSocket *>(sender());

    while (udpSocket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = udpSocket->receiveDatagram();
        array = datagram.data();
        data_hexstr = array.toHex();
        STX = data_hexstr.mid(0,2);
        if(data_hexstr.mid(0,4)=="ffff"&&data_hexstr.mid(30,2)=="a6"){ //选择打印需要的IP
        qDebug()<<data_hexstr<<","<<datagram.senderAddress()<<datagram.senderPort();
            }
        }
}


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
            is_close = false;
            leaveMulticast();
            useRow = 0;
            for(int i=0;i<256;i++){
                buf[i]="";
            }
        });
    }




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
    bool isOK;
    QString port = "",IP = "";
    quint16 port_u16;
    qint16 port_16;
    port = ui->port->text();
    port_16 = port.toShort(&isOK);
    port_u16 = port_16;
    if(port_u16==0)
    {
        port_u16 = 45454;
    }
    IP = ui->IP->text();
    if(IP == "")
    {
        IP = "224.0.0.115";
    }
    if(!m_qudpSocket->bind(QHostAddress::AnyIPv4,port_u16,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint)){//绑定组播端口号
        qDebug()<<"绑定组播端口失败";
        is_join = false;
    }
    else{
        qDebug()<<"加入组播";
        m_qudpSocket->joinMulticastGroup(QHostAddress(IP)); //加入组播ip
        connect(m_qudpSocket,SIGNAL(readyRead()),this,SLOT(dealReadyRead()));
    }
}

void get_multicast::leaveMulticast()
{
    QString IP = "";
    IP = ui->IP->text();
    if(IP == "")
    {
        IP = "224.0.0.115";
    }
    m_qudpSocket->leaveMulticastGroup(QHostAddress(IP));
    m_qudpSocket->abort();
    disconnect(m_qudpSocket,SIGNAL(readyRead()),this,SLOT(dealReadyRead()));
    is_join=false;
    qDebug()<<"退出组播";
}

void get_multicast::dealReadyRead()
{
    bool isOK;
    if(is_close == true){
    bool ok,is_exist=false;
    QString data_hexstr,STX,IP,n_1="",x_1="",n_2="",x_2="",data_1="",data_2="";
    QByteArray array;
    QUdpSocket *udpSocket = dynamic_cast<QUdpSocket *>(sender());
    int int_n_1,int_x_1,int_n_2,int_x_2,int_data_1,int_data_2;
    n_1 = ui->n_1->text();
    n_2 = ui->n_2->text();
    x_1 = ui->x_1->text();
    x_2 = ui->x_2->text();
    data_1 = ui->data_1->text();
    data_2 = ui->data_2->text();
    int_n_1 = n_1.toShort(&isOK);
    int_n_2 = n_2.toShort(&isOK);
    int_x_1 = x_1.toShort(&isOK);
    int_x_2 = x_2.toShort(&isOK);

    if(n_1 == "n")
        int_n_1 = 0;
    if(x_1 == "x")
        int_x_1 = 4;
    if(data_1 == "data")
        data_1 = "ffff";

    if(n_2 == "n")
        int_n_2 = 30;
    if(x_2 == "x")
        int_x_2 = 2;
    if(data_2 == "data")
        data_2 = "a6";


    while (udpSocket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = udpSocket->receiveDatagram();
        array = datagram.data();
        data_hexstr = array.toHex();
        IP = datagram.senderAddress().toString();
        STX = data_hexstr.mid(0,2);

        if(data_hexstr.mid(int_n_1,int_x_1)==data_1&&data_hexstr.mid(int_n_2,int_x_2)==data_2){ //选择打印需要的IP
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









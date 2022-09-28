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
            ui->read_text->setText("服务器连接成功！");
        });

    connect(tcpsocket,&QTcpSocket::readyRead,[=](){
           //获取通信套接字的内容
            QString str=tcpsocket->readAll();

            ui->read_text->setText("服务器端："+str);
        });

}

client::~client()
{
    delete ui;
}

void client::on_pushButton_clicked()
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

    //获取发送的信息
    QString str=ui->write_text->toPlainText();

    //将信息写入到通信套接字
    tcpsocket->write(str.toUtf8().data());

}


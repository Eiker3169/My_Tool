#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);

    tcp_server=NULL;
    tcp_socket=NULL;

    //创建监听套接字
    tcp_server=new QTcpServer(this);

    //bind+listen
    tcp_server->listen(QHostAddress::Any,8888);//绑定当前局域网内所有的ip绑定端口 设置服务器地址和端口号

    //服务器建立连接
    connect(tcp_server,&QTcpServer::newConnection,[=](){

            //取出连接好的套接字
            tcp_socket=tcp_server->nextPendingConnection();

            //获得通信套接字的控制信息
            QString ip=tcp_socket->peerAddress().toString();//获取连接的ip地址
            quint16 port=tcp_socket->peerPort();//获取连接的端口号
            QString temp=QString("[%1:%2] 客服端连接成功").arg(ip).arg(port);


            ui->read_text->setText(temp);//显示连接成功

            //接收信息  必须放到连接中的槽函数 不然tcpsocket就是一个野指针
            connect(tcp_socket,&QTcpSocket::readyRead,[=](){
                //从通信套接字中取出内容
                QString str=tcp_socket->readAll();
                 //在编辑区域显示
                ui->read_text->insertPlainText(str);

                tcp_socket->write(str.toUtf8().data());
            });
        });

}

server::~server()
{
    delete ui;

}

void server::on_send_clicked()
{
    if(tcp_socket==NULL){
            return ;
        }
        //获取编辑区域的内容
        QString str=ui->write_text->toPlainText();

        //写入通信套接字 协议栈自动发送
        tcp_socket->write(str.toUtf8().data());

}


#ifndef SERVER_H
#define SERVER_H

#include <QWidget>

#include<QTcpServer>//监听套接字
#include<QTcpSocket>//通信套接字

namespace Ui {
class server;
}

class server : public QWidget
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = nullptr);
    ~server();

private slots:
    void on_send_clicked();

private:
    Ui::server *ui;

    QTcpServer *tcp_server;
    QTcpSocket *tcp_socket;
};

#endif // SERVER_H

#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>

#include<QTcpSocket>

namespace Ui {
class client;
}

class client : public QWidget
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();

private slots:
    void on_pushButton_clicked();

    void on_send_clicked();

private:
    Ui::client *ui;

    QTcpSocket *tcpsocket;//声明套接字 客户端只有一个通信套接字
};

#endif // CLIENT_H

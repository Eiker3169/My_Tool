#ifndef GET_MULTICAST_H
#define GET_MULTICAST_H

#include <QMainWindow>

#include <QUdpSocket>
#include <QNetworkDatagram>

#include "scan_ip.h"

QT_BEGIN_NAMESPACE
namespace Ui { class get_multicast; }
QT_END_NAMESPACE

class get_multicast : public QMainWindow
{
    Q_OBJECT

public:
    get_multicast(QWidget *parent = nullptr);
    ~get_multicast();


private:
    Ui::get_multicast *ui;



private slots:
    void on_scan_ip_clicked();

private:
    bool is_join,is_close;
    int useRow;
    QString buf[256];
    void init_multicast();
    QUdpSocket * m_qudpSocket;

    void joinMulticast();
    void leaveMulticast();

private slots:
    void dealReadyRead();

public:
    scan_ip * show_;

};
#endif // GET_MULTICAST_H

#ifndef GET_MULTICAST_H
#define GET_MULTICAST_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QNetworkDatagram>

QT_BEGIN_NAMESPACE
namespace Ui { class get_multicast; }
QT_END_NAMESPACE

class get_multicast : public QMainWindow
{
    Q_OBJECT

public:
    get_multicast(QWidget *parent = nullptr);
    ~get_multicast();
    void init_multicast();
    QUdpSocket * m_qudpSocket;

private:
    Ui::get_multicast *ui;

private slots:
    void dealReadyRead();
};
#endif // GET_MULTICAST_H

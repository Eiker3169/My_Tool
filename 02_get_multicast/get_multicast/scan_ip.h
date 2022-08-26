#ifndef SCAN_IP_H
#define SCAN_IP_H

#include <QWidget>

namespace Ui {
class scan_ip;
}

class scan_ip : public QWidget
{
    Q_OBJECT

public:
    explicit scan_ip(QWidget *parent = nullptr);
    ~scan_ip();

public:
    Ui::scan_ip *ui;

public:
    void show_ip(QString ip,int useRow);
};

#endif // SCAN_IP_H

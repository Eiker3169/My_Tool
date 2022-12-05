#include "mainwindow.h"

#include <QApplication>

#include "serial_port_test.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Serial_port_test w;
    w.show();
    return a.exec();
}

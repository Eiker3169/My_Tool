#include "get_multicast.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    get_multicast w;
    w.show();
    return a.exec();
}

#include "dynamic_QtableView.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dynamic_QTableView w;
    w.show();
    return a.exec();
}

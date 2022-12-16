#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include "mydeal.h"
#include <QTableWidget>
#include "mytablewgt.h"

static const char* DefQSReceiverInfoTableSize[20][3] =
{
    {"ID" , "130", "0"},
    {"Line" , "110", "0"},
    {"Point" , "110", "0"},
    {"Index" , "60", "0"},
    {"Type" , "60", "0"},
    {"X" , "120", "0"},
    {"Y" , "120", "0"},
    {"Z" , "120", "0"},
    {"Lat.-084" , "180", "0"},
    {"Long.-084" , "180", "0"},
    {"Elav.-84" , "180", "0"},
    {"Status" , "100", "0"},
    {"Point Depth" , "120", "0"},
    {"Water Depth" , "120", "0"},
    {"Seis Datum" , "150", "0"},
    {" " , "150", "0"},
    {" " , "150", "0"},
    {" " , "150", "0"},
    {" " , "150", "0"}
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


public slots:

private:
    MyTableWgt *m_pTableWgt=nullptr;
};
#endif // WIDGET_H

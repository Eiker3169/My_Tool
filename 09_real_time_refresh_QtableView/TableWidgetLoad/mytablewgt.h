#ifndef MYTABLEWGT_H
#define MYTABLEWGT_H

#include <QWidget>
#include <QTableWidget>
#include <QThread>
#include "mydeal.h"

class MyTableWgt : public QTableWidget
{
    Q_OBJECT
public:
    explicit MyTableWgt(QWidget *parent = nullptr);
    ~MyTableWgt();

    void ClearAllRow();

    void Run();

protected:
    void wheelEvent(QWheelEvent *event);

signals:
    void sSendVerValue(int);

    void startRunning(QString);

public slots:
    void OnVertivalValueChanged(int i_value);

    void ReceiverData();
    void ReceiverChanged();

private:
    QThread m_thread;
    MyDeal *m_pDeal=nullptr;

    int m_Value=0;
};

#endif // MYTABLEWGT_H

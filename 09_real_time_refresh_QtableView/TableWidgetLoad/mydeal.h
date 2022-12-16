#ifndef MYDEAL_H
#define MYDEAL_H

#include <QObject>

struct myData
{
  QString str0;
  QString str1;
  QString str2;
  QString str3;
  QString str4;
  QString str5;
  QString str6;
  QString str7;
  QString str8;
  QString str9;
  QString str10;

};

class MyDeal : public QObject
{
    Q_OBJECT
public:
    explicit MyDeal(QObject *parent = nullptr);
    ~MyDeal();

    int GetCurrentRow();

    QList <myData> GetDataList();

    void LoadData(int row);

    QList <myData> GetSendData();

    QList <myData> GetFirstData();

    int GetDataSize();

signals:

    void sSendFinished();

    void sSendValueChanaged();

public slots:
    void CreateData(QString i_path);

private:
    int m_CurrentRow=0;

    QList <myData> m_DataList;

    QList<myData>m_SendData;

    QList<myData>m_FirstData;

    int m_DataSize=0;
};

#endif // MYDEAL_H

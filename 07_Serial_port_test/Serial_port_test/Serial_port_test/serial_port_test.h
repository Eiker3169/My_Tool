#ifndef SERIAL_PORT_TEST_H
#define SERIAL_PORT_TEST_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QMutex>
#include <QDateTime>
#include <QEventLoop>
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtConcurrent/QtConcurrent>

using namespace QtConcurrent;

enum BaudRate {
    Baud1000000 = 1000000,
};



namespace Ui {
class Serial_port_test;
}

class Serial_port_test : public QWidget
{
    Q_OBJECT

public:
    explicit Serial_port_test(QWidget *parent = nullptr);
    ~Serial_port_test();

private:
    Ui::Serial_port_test *ui;

public:
    QSharedPointer<QIODevice> comm;
    QSerialPort* serial;
    QMutex status_mutex;

    QTimer timer;
    QString serial_buf = "";
    QTimer test_timer;
    bool isconnected = false;// 串口是否已连接

    bool is_open = false;
    int received_count = 0;
    int test_count = 0;

    bool message_filtering_flag = false;


public:
    /**
     * @brief getPortNameList  获取在线串口列表
     * @return
     */
    QStringList getPortNameList(void);

    void thread_run(void);

public slots:
    /**
     * @brief recvData 读到串口数据槽函数
     */
    void recvData();

    /**
     * @brief message_filtering 过滤串口接收到的数据
     */
    void message_filtering(void);

    /**
     * @brief eventFilter 重写点击串口端口刷新串口
     * @param watched
     * @param event
     * @return
     */
    bool eventFilter(QObject *watched, QEvent *event);

    /**
     * @brief indexOfNthStr 获取字符串中第n个str的位置
     * @param sourceStr
     * @param str
     * @param N
     * @return
     */
    int indexOfNthStr(QString sourceStr, QString str, uint N);

    /**
     * @brief change_str_color 改变str在sourceStr中的颜色
     * @param sourceStr
     * @param str
     * @param color
     * @return
     */
    QString change_str_color(QString sourceStr, QString str, QString color);

private slots:
    void on_openSerialBtn_clicked();
    void on_clear_data_clicked();
    void on_start_test_clicked();
    void on_close_test_clicked();
};

#endif // SERIAL_PORT_TEST_H

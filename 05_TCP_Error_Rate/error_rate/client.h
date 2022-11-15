#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>

#include<QTcpSocket>
#include <QDebug>
#include <QTimer>
#include <QRandomGenerator>

#define once 100

namespace Ui {
class client;
}

class client : public QWidget
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();

private slots:
    void on_connect_clicked();

    void on_send_clicked();

private:
    Ui::client *ui;

public:
    QTcpSocket *tcpsocket;

    QTimer * timer;
    QString start_time;
    QString end_time;
    QString cumulative_time;
    QString screenshots_interval;
    QString screenshot_path;
    QString error_rate_;
    QString error_byte;
    QString total_send_byte;
    QString sended_byte;
    QString received_byte;
    QString m_str;
    QString send_str;
    QString receive_str;
    QString sended_text_content;

    bool is_connect = false;
    int start_flag = 0;
    int count = 0;
    int m_total = 0;
    int m_total_0 = 0;
    int m_total_once = 0;
    unsigned int * m_send_data = NULL;
    unsigned int * m_receive_data = NULL;
    unsigned int m_send_data_count = 0;
    unsigned int m_receive_data_count = 0;

public:
    /**
     * @brief random_number 产生随机数
     * @param range_head    随机数头
     * @param range_tail    随机数尾
     * @return              随机数
     */
    unsigned char random_number(int range_head, int range_tail);

    /**
     * @brief connect_interval 间隔
     * @param time_ 间隔时间
     */
    void connect_interval(int time_);

    /**
     * @brief show_sended_text 显示发送的文本
     * @param str
     */
    void show_sended_text(QString str);

    /**
     * @brief show_received_text 显示接收的文本
     * @param str
     */
    void show_received_text(QString str);

    /**
     * @brief send_data 发送数据
     * @param str       数据
     */
    void send_data(QString str);

    /**
     * @brief show_send_data 显示要发送的数据
     * @param str
     */
    void show_send_data(QString str);

    /**
     * @brief receive_data 接收数据
     * @param str          数据
     */
    void receive_data(QString str);

    /**
     * @brief show_recive_data 显示接收到的数据
     * @param str
     */
    void show_recive_data(QString str);

    /**
     * @brief error_rate 误码率计算
     */
    void m_error_rate(void);

    /**
     * @brief show_sended_received_byte 显示已发送字节、已接收字节
     * @param sended 已发送字节
     * @param received 已接收字节
     */
    void show_sended_received_byte(int sended, int received);

    /**
     * @brief show_error_byte 显示错误字节
     * @param error_byte 错误字节数量
     */
    void show_error_byte(int error_byte);



public slots:

    void test(void);

    /**
     * @brief send_sended_text_content 手动发送sended_text_content
     */
    void send_sended_text_content(void);


private slots:
    void on_start_clicked();
    void on_reset_clicked();
    void on_start_2_clicked();
    void on_reset_2_clicked();
    void on_checkout_clicked();
};

#endif // CLIENT_H

#include "mainwindow.h"
#include "sqlite.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    sqlite my_sql;
    bool tmp_bool = false;
    my_sql.create_db("db_connection","capture_db");
    my_sql.open_db();
    my_sql.create_table("create table my_table(serial_number int primary key, data vachar(1000))");

    for(int i = 0; i < 100; i++){
        if(tmp_bool == false){
            tmp_bool = true;
            my_sql.insert_data_to_db("insert into my_table values("+QString::number(i)+",'AAA')");
        }
        else{
            tmp_bool = false;
            my_sql.insert_data_to_db("insert into my_table values("+QString::number(i)+",'BBB')");
        }

    }
    QString tmp_str = "";
    tmp_str = my_sql.inquire_str_data_from_db(QString("select data from my_table where serial_number=%1").arg(4));
    qDebug()<<tmp_str;

    my_sql.delete_table("my_table");
    my_sql.close_db();

    return a.exec();
}

#include "sqlite.h"

sqlite::sqlite()
{

}


/**
 * @brief create_db     创建数据库
 * @param connection    连接名
 * @param my_db         数据库名
 */
void sqlite::create_db(QString connection, QString my_db)
{
    if (QSqlDatabase::contains(connection))
    {
        database = QSqlDatabase::database(connection);
    }
    else
    {
        // 建立和SQlite数据库的连接
        database = QSqlDatabase::addDatabase("QSQLITE", connection);
        // 设置数据库文件的名字
        database.setDatabaseName(my_db);
    }
}

bool sqlite::open_db()
{
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();

        return false;
    }
    else
    {
        return true;
    }
}

void sqlite::close_db()
{
    if(database.isOpen()){
        database.close();
    }
}

bool sqlite::create_table(QString creat_table_statement)
{
    if(database.isOpen()){
        // 用于执行sql语句的对象
        QSqlQuery sqlQuery(database);
        // 构建创建数据库的sql语句字符串
        QString createSql = QString(creat_table_statement);
        sqlQuery.prepare(createSql);
        // 执行sql语句
        if(!sqlQuery.exec())
        {
            qDebug() << "Error: Fail to create table. " << sqlQuery.lastError();
            return false;
        }
        else
        {     qDebug() << "Table created!";
            return true;
        }
    }
    return false;
}

void sqlite::delete_table(QString table_name)
{
    if(database.isOpen()){
        QSqlQuery sqlQuery(database);
        sqlQuery.prepare(QString("drop table %1").arg(table_name));
        if(sqlQuery.exec()){
            qDebug()<<"Delete table successfully";

        }
        else{
            qDebug()<<"Failed to delete table";

        }
    }
}

bool sqlite::insert_data_to_db(QString insert_data_statement)
{
    if(database.isOpen()){
        QSqlQuery sqlQuery(database);

        sqlQuery.prepare(insert_data_statement);

        if(sqlQuery.exec()){
            qDebug()<<"Insert data to db successfully";
            return true;
        }
        else{
            qDebug()<<"Failed to insert data";
            return false;
        }
    }
    return false;
}

QString sqlite::inquire_str_data_from_db(QString inquire_data_statement)
{
    QString tmp_str;
    if(database.isOpen()){
        QSqlQuery query(database);
        query.prepare(inquire_data_statement);
        if(query.exec()){
            while(query.next()){
                tmp_str = query.value("data").toString();
            }
            return tmp_str;
        }
        else{
            qDebug()<<"Failed to inquire data";
            return "";
        }
    }
}






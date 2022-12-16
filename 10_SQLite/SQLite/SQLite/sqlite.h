#ifndef SQLITE_H
#define SQLITE_H

#include <QObject>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class sqlite : public QObject
{
    Q_OBJECT
public:
    sqlite();

public:
    QSqlDatabase database;

public:

    void create_db(QString connection, QString my_db);

    bool open_db();

    void close_db();

    bool create_table(QString creat_table_statement);

    bool insert_data_to_db(QString insert_data_statement);

    QString inquire_str_data_from_db(QString inquire_data_statement);
};

#endif // SQLITE_H

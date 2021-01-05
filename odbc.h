#ifndef ODBC_H
#define ODBC_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Odbc : public QObject
{
    Q_OBJECT
public:
    explicit Odbc(QObject *parent = nullptr);
    Q_INVOKABLE void mysqlConn();
    Q_INVOKABLE void mssqlConn();
    Q_INVOKABLE void postgresConn();

    Q_INVOKABLE void excelConn();

    Q_INVOKABLE void mongoConn();

signals:

};

#endif // ODBC_H

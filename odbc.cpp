#include "odbc.h"

Odbc::Odbc(QObject *parent) : QObject(parent)
{

}

void Odbc::mysqlConn()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "mysql_conn");
    // Fetching from MYSQL database
    db.setDatabaseName("DRIVER={MySQL ODBC 8.0 Unicode Driver};Database=mysql"); // "WorkDatabase" is the name of the database we want
    db.setUserName("root");
    db.setPassword("");

    bool ok = db.open();
    if(ok){
        qDebug() << "Connected MySQL";

        QSqlQuery q1;

        // Fetch data from TABLE
        q1.prepare("SELECT * FROM db");

        if(q1.exec()){
            while(q1.next()){
                qDebug() << q1.value(0).toString() ;
            }
        }else{
            qDebug() << q1.lastError().text();
        }

    } else{
        qDebug() << db.lastError().text() << "ERROR";
    }
}

void Odbc::mssqlConn()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "mssql_conn");
    // Fetching from MSSQL database
    // Windows Authentication for localservver
    // For remote server, server ip, username and password required
    db.setDatabaseName("DRIVER={SQL Server};Server=DESKTOP-NSN20CD\\SERVERNAME;Database=mssql-test;Trusted_Connection=True;"); // "WorkDatabase" is the name of the database we want
    db.setUserName("DESKTOP-NSN20\\test");

    bool ok = db.open();
    if(ok){
        qDebug() << "Connected MS SQL";

        QSqlQuery q1;

        // Fetch data from TABLE
        q1.prepare("SELECT * FROM test_table");

        if(q1.exec()){
            while(q1.next()){
                qDebug() << q1.value(0).toString()  ;
            }
        }else{
            qDebug() << q1.lastError().text();
        }

    } else{
        qDebug() << db.lastError().text() << "ERROR";
    }
}

void Odbc::postgresConn()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "psgl_conn");
    // Fetching from Postgres database
    db.setDatabaseName("DRIVER={PostgreSQL Unicode};Server=localhost;Database=pg_test;Trusted_Connection=True;"); // "WorkDatabase" is the name of the database we want
    db.setUserName("postgres");
    db.setPassword("password");

    bool ok = db.open();
    if(ok){
        qDebug() << "Connected Postgres SQL";

        QSqlQuery q1;

        // Fetch data from TABLE
        q1.prepare("SELECT * FROM test_table");

        if(q1.exec()){
            while(q1.next()){
                qDebug() << q1.value(0).toString() ;
            }
        }else{
            qDebug() << q1.lastError().text();
        }

    } else{
        qDebug() << db.lastError().text() << "ERROR";
    }
}

void Odbc::excelConn()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "xlsx_conn");
    db.setDatabaseName("DRIVER={Microsoft Excel Driver (*.xls, *.xlsx, *.xlsm, *.xlsb)};DBQ=C:\\Users\\vishal\\Desktop\\Book1.xlsx");

    if(db.open())
    {
          QSqlQuery query("select * from [" + QString("Sheet2") + "$]",db);
        // Select range, place A1:B5 after $r
        while (query.next())
        {
            QString column1= query.value(0).toString();
            qDebug() << column1;
        }
    }
    else {
        qDebug() << db.lastError().text();
    }
}

void Odbc::mongoConn()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "mongo_conn");
    // Fetching from Mongo database
    db.setDatabaseName("DRIVER={MongoDB ODBC 1.4.2 ANSI Driver};Server=127.0.0.1;Port=3307;Database=mongo_test");



    if( db.open()){
        qDebug() << "Connected MongoDb SQL";

        QSqlQuery query("select * from test_collection",db);
        while (query.next())
        {
            QString column1= query.value(0).toString();
            qDebug() << column1;
        }

    } else{
        qDebug() << db.lastError().text() << "ERROR";
    }
}

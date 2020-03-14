#include "mainwindow.h"
#include <QApplication>


#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("cancer");
    db.setUserName("root");
    db.setPassword("");
    if (db.open())   {
       qDebug() << "Connected!";
    }
    else   {
      qDebug() << "Failed to connect.";
      return 0;
    }

    return a.exec();
}

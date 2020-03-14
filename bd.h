#ifndef BD_H
#define BD_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

#include <vector>

#include "patient.h"
#include "personne.h"

class bd
{
public:
    bd();
    void insererPatient(Patient pa);
    vector<QString> listePatients();
private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    vector<QString> listePatient;
};

#endif // BD_H

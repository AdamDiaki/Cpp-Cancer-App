#include "bd.h"

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <string>
#include <QVariant>

bd::bd()
{
    db.setHostName("127.0.0.1");
    db.setPort(8888);
    db.setDatabaseName("Cancer");
    db.setUserName("root");
    db.setPassword("");
    if (db.open())   {
       qDebug() << "Connected!";
    }
    else   {
      qDebug() << "Failed to connect.";
    }
}

void bd::insererPatient(Patient pa)
{
//    QString command = "INSERT INTO `patient`(`nomP`, `prenomP`, `adresseP`, `dateNaissanceP`, `mail`,"
//                      " `alimentation`, `job`, `moyHeureSommeilP`, `contactChimique`, `heureTravailHebdo`, `sport`) "
//                      "VALUES ("+pa.getNom()+","+pa.getPrenom()+","+pa.getaddress()+","+pa.getdateNaissance()+","+pa.getemail()+
//                      ","+pa.getmodeAlim()+","+pa.getJob()+","+std::to_string(pa.getMoySommeil())+
//                      ","+std::to_string(pa.getContactChimique())+","+std::to_string(pa.getTravail())+","+std::to_string(pa.getSport())+") ";

    QSqlQuery query(db);
    query.prepare("INSERT INTO `patient`(`nomP`, `prenomP`, `adresseP`, `dateNaissanceP`, `mail`,"
                  " `alimentation`, `job`, `moyHeureSommeilP`, `contactChimique`, `heureTravailHebdo`, `sport`) "
                  "VALUES (:nomP, :prenomP, :adresseP, :dateNaissanceP, :mail, :alimentation, :job, :moyHeureSommeilP,"
                  ":contactChimique, :heureTravailHebdo, :sport) ");
    query.bindValue(":nomP", QString::fromStdString(pa.getNom()));
    query.bindValue(":prenomP", QString::fromStdString(pa.getPrenom()));
    query.bindValue(":adresseP", QString::fromStdString(pa.getaddress()));
    query.bindValue(":dateNaissanceP", QString::fromStdString(pa.getdateNaissance()));
    query.bindValue(":mail", QString::fromStdString(pa.getemail()));
    query.bindValue(":alimentation", QString::fromStdString(pa.getmodeAlim()));
    query.bindValue(":job", QString::fromStdString(pa.getJob()));
    query.bindValue(":moyHeureSommeilP", QString::fromStdString(std::to_string(pa.getMoySommeil())));
    query.bindValue(":contactChimique", QString::fromStdString(std::to_string(pa.getContactChimique())));
    query.bindValue(":heureTravailHebdo", QString::fromStdString(std::to_string(pa.getTravail())));
    query.bindValue(":sport", QString::fromStdString(std::to_string(pa.getSport())));
    query.exec();
}

vector<QString> bd::listePatients()
{
    QString command = "SELECT CONCAT(nomP,'',prenomP) FROM patient";

    QSqlQuery query(db);
//    query.prepare("SELECT CONCAT(nomP,'',prenomP) FROM :patient");
//    query.bindValue(":patient", "patient");
    if(query.exec(command))
    while(query.next()) {
        QString pat = query.value("CONCAT(nomP,'',prenomP)").toString();
        listePatient.push_back(pat);
    }
    return listePatient;
}

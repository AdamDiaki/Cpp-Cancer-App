#include "formulaire.h"
#include "ui_formulaire.h"
#include "patient.h"

//######################################
#include "bd.h"

Formulaire::Formulaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Formulaire)
{
    ui->setupUi(this);
}

Formulaire::~Formulaire()
{
    delete ui;
}


void Formulaire::on_buttonBox_accepted()
{
    ui->comboBoxPatient->addItem("");
    vector<QString> liste = li->listePatients();
    for(int i(0); i<liste.size(); i++) {
        ui->comboBoxPatient->addItem(liste[i]);
    }

    if(ui->comboBoxPatient->currentText() == ""){
        ui->buttonBox->setEnabled(false);
        ui->label_17->setText("existe déjà");
    }
    QString mailPatient = ui->textEdit->toPlainText();
    QString prenomPatient = ui->textEdit_2->toPlainText();
    QString nomPatient = ui->textEdit_3->toPlainText();
    QString alimentationPatient = ui->textEdit_4->toPlainText();
    QString JobPatient = ui->textEdit_5->toPlainText();
    int SommeilPatient = ui->comboBox->currentText().toInt();
    QString nomPublisher = ui->textEdit_7->toPlainText();
    QString prenomPublisher = ui->textEdit_8->toPlainText();
    QString mailPublisher = ui->textEdit_9->toPlainText();
    QString dateNaissance = ui->dateEdit->date().toString("dd/MM/yyyy");
    int contactChimique = 0;
    if(ui->checkBox->isChecked()){
        contactChimique = 1;
    }
    int heureTravail = ui->comboBox_2->currentText().toInt();
    QString adress = ui->textEdit_10->toPlainText();
    int sport = 0;
    if(ui->checkBox_2->isChecked()){
        sport = 1;
    }
    Patient pat(nomPatient.toStdString(), prenomPatient.toStdString(), mailPatient.toStdString(),adress.toStdString(),dateNaissance.toStdString(),alimentationPatient.toStdString(),JobPatient.toStdString(),SommeilPatient,contactChimique, heureTravail,sport);
    //######################################
    li->insererPatient(pat);

}

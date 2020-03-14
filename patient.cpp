#include "Patient.h"

Patient::Patient(string nom, string prenom, string address, string email, string dateNaissance, string modeAlim, string Job, int MoySommeil,int ContactChimique, int Travail, int sport) : Personne(nom, prenom, address, email, dateNaissance){
    this->ModeAlim = modeAlim;
    this->Job = Job;
    this->MoyNbHSommeil = MoySommeil;
    this->ContactChimique = ContactChimique;
    this->PeriodeTravail = Travail;
    this->Sport = sport;
}

string Patient::getmodeAlim()
{
    return ModeAlim;
}

string Patient::getJob()
{
    return Job;
}

int Patient::getMoySommeil()
{
    return MoyNbHSommeil;
}

int Patient::getContactChimique()
{
    return ContactChimique;
}

int Patient::getTravail()
{
    return PeriodeTravail;
}

int Patient::getSport()
{
    return Sport;
}

Patient::~Patient()
{
}

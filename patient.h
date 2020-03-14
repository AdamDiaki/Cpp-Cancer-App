#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Personne.h"

using namespace std;

class Patient :public Personne {
private:
    string ModeAlim;
    string Job;
    int MoyNbHSommeil;
    int ContactChimique;
    int PeriodeTravail;
    int Sport;
public:
    Patient(string nom, string prenom, string address, string email, string dateNaissance, string modeAlim, string Job, int MoySommeil,int ContactChimique, int Travail, int sport);
    //######################
    string getmodeAlim();
    string getJob();
    int getMoySommeil();
    int getContactChimique();
    int getTravail();
    int getSport();
    ~Patient();
};


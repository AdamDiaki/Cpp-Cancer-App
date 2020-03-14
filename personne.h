#pragma once

#include <iostream>
#include <string>

using namespace std;

class Personne{
private:
    int Id;
    string Nom;
    string Prenom;
    string Address;
    string Email;
    string dateNaissance;
public:
    Personne(string nom, string prenom, string address, string email, string dateNaissance);
    //##################
    string getNom();
    string getPrenom();
    string getaddress();
    string getemail();
    string getdateNaissance();
    ~Personne();
};


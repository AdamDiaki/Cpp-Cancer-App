#include "Personne.h"


Personne::Personne(string nom, string prenom, string address, string email, string dateNaissance)
{
    this->Nom = nom;
    this->Prenom = prenom;
    this->Address = address;
    this->Email = email;
    this->dateNaissance = dateNaissance;
}

string Personne::getNom()
{
    return Nom;
}

string Personne::getPrenom()
{
    return Prenom;
}

string Personne::getaddress()
{
    return Address;
}

string Personne::getemail()
{
    return Email;
}

string Personne::getdateNaissance()
{
    return dateNaissance;
}

Personne::~Personne()
{
}

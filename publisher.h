#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Personne.h"
#include "entree.h"

using namespace std;

class Entree;

class Publisher:public Personne{
private:
    vector<Entree*> vec;
public:
    Publisher(string nom, string prenom, string address, string email, string dateNaissance);
   virtual ~Publisher();
};


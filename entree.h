#pragma once

#include <iostream>
#include <string>
#include "Clicher.h"
#include "publisher.h"
#include "patient.h"

using namespace std;

class Publisher;
class Patient;

class Entree{
private:
    int Id;
    Clicher *c;
    Publisher *publi;
    Patient *pat;
    //vector<image> ;
public:
    Entree();
    ~Entree();
    void Afficher();
    void Ajouter();
    void Modifier();
    void Supprimer();
};


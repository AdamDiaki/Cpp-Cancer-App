#pragma once

#include <iostream>
#include <string>

using namespace std;

class Cancer{
private:
    int Id;
    string Nom;
    string type;
    bool guerrissable;
    int rarete;

public:
    Cancer();
    ~Cancer();
};


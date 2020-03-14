#ifndef FORMULAIRE_H
#define FORMULAIRE_H

#include <QDialog>
#include "bd.h"

namespace Ui {
class Formulaire;
}

class Formulaire : public QDialog
{
    Q_OBJECT

public:
    explicit Formulaire(QWidget *parent = nullptr);
    ~Formulaire();

private slots:

    void on_buttonBox_accepted();

private:
    Ui::Formulaire *ui;
    bd *li = new bd();
};

#endif // FORMULAIRE_H

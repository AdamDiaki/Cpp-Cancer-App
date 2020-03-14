#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QLabel"

//######################################
#include "bd.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const QString folderPath = QFileDialog::getExistingDirectory(this, tr("C:/Users/Delal Seletli/Desktop/image"));
    if(!folderPath.isEmpty())
    {
        QDir dir(folderPath);
        QStringList filter;
        filter << QLatin1String("*.png");
        filter << QLatin1String("*.jpeg");
        filter << QLatin1String("*.jpg");
        dir.setNameFilters(filter);
        QFileInfoList filelistinfo = dir.entryInfoList();
        QStringList fileList;
        foreach (const QFileInfo &fileinfo, filelistinfo) {
            QString imageFile = fileinfo.absoluteFilePath();
            QPixmap pix(imageFile);
            QLabel *lab = new QLabel(this);
            lab->setPixmap(pix.scaled(1000,1000));
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    formulaire = new Formulaire(this);
    formulaire->show();

}

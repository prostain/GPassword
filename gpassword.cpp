#include "gpassword.h"
#include <QLineEdit>
#include <QString>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

GPassword::GPassword(QWidget *parent) :
    QWidget(parent)
{
    //création des layouts
    QVBoxLayout* bigLayout = new QVBoxLayout(this);
    QHBoxLayout* layoutLogin = new QHBoxLayout(this);
    QGridLayout* gridLogin = new QGridLayout(this);
    QHBoxLayout* layoutMdp = new QHBoxLayout(this);
    QHBoxLayout* layoutButton = new QHBoxLayout(this);

    QLabel* labelLogin = new QLabel(this);
    labelLogin->setText("Login :");
    QLineEdit* lineEditLogin = new QLineEdit(this);
    bigLayout->addLayout(layoutLogin);

    layoutLogin->addWidget(labelLogin,0,0);
    layoutLogin->addWidget(lineEditLogin,0,0);

    QLabel* labelPasswd = new QLabel(this);
    labelPasswd->setText("Mot de Passe :");
    lineEditPasswd = new QLineEdit(this);
    lineEditPasswd->setEnabled(this);
    bigLayout->addLayout(layoutLogin);

    layoutMdp->addWidget(labelPasswd,0,0);
    layoutMdp->addWidget(lineEditPasswd,0,0);
    bigLayout->addLayout(layoutMdp);
    lineEditPasswd->setProperty("valeur","");



    // nombre de colonne
    for(int y=0;y<3;y++)
    {
        // nombre de ligne
        for(int x=0;x<4;x++)
        {
            int nb =3*x+y;
            QString valeurBouton = QString::number(nb);

            QPushButton* leBouton = new QPushButton(valeurBouton,this);
            connect (leBouton,SIGNAL(clicked()),this,SLOT(boutonPresse()));

            bigLayout->addLayout(gridLogin);
            gridLogin->addWidget(leBouton,x,y);
            if(y==1 && x==3)
            {
                leBouton->setText("C");
            }
            if(y==2 && x==3)
            {
                leBouton->setText("AC");
            }
        }
    }


}

QString GPassword::text()
{
 return lineEditPasswd->property("valeur").toString();
}

void GPassword::boutonPresse()
{
 // réception du signal émis
 QPushButton* leBoutonPresse=(QPushButton *)sender();

 QString sonText = leBoutonPresse->text();

 if (sonText=="C")
 {
    lineEditPasswd->backspace();
}
 else if (sonText=="AC")
 {
     lineEditPasswd->clear();
 }
 else
 {
     lineEditPasswd->setText(lineEditPasswd->text()+"*");
    lineEditPasswd->setProperty("valeur",lineEditPasswd->property("valeur").toString()+sonText);

 }


}


GPassword::~GPassword()
{

}


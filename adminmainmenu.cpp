#include "adminmainmenu.h"
#include "ui_adminmainmenu.h"
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include "loginpage.h"
#include "adminprofile.h"
#include "adminsendassertion.h"
#include "adminaddpeople.h"

AdminMainMenu::AdminMainMenu(QWidget *parent) :
//    QWidget(parent),
    ui(new Ui::AdminMainMenu)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->label_14->setStyleSheet("background-color: #f0f0f0; border-radius: 20px");
    this->ui->pushButton_5->setStyleSheet("background-color: transparent");
    this->ui->label_2->setText("Hi dear " + this->get_first_name());
}

AdminMainMenu::~AdminMainMenu()
{
    delete ui;
}

void AdminMainMenu::on_pushButton_5_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Close Window","Do you want to close this window?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        LoginPage* lg = new LoginPage;
        lg->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}





void AdminMainMenu::on_pushButton_clicked()
{    
    AdminProfile* ap = new AdminProfile(this->get_username() , this->get_password() , this->get_first_name() , this->get_last_name() , this->get_national_code() , this->get_phone_number() , this->get_role());
    ap->show();
    close();
}


void AdminMainMenu::on_pushButton_4_clicked()
{
    AdminSendAssertion* asa = new AdminSendAssertion(this);
    asa->show();
    close();
}


void AdminMainMenu::on_pushButton_3_clicked()
{
    AdminAddPeople* aap = new AdminAddPeople;
    aap->show();
    close();
}


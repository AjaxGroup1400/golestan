#include "adminmainmenu.h"
#include "ui_adminmainmenu.h"
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include "loginpage.h"
#include "adminprofile.h"
#include "adminsendassertion.h"
#include "adminaddpeople.h"
#include "adminaddclass.h"
#include "adminclassinfo.h"
#include "adminmessages.h"

AdminMainMenu::AdminMainMenu( QString firstName , AdminMainMenu * member , QWidget *parent) :
//    QWidget(parent),
    ui(new Ui::AdminMainMenu)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_7->setStyleSheet("background-color: transparent");
    this->ui->label_14->setStyleSheet("background-color: #f0f0f0; border-radius: 20px");
    this->ui->pushButton_5->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color: transparent");

    this->mainmenu = member;
    if(member!=nullptr)
    {
        this->set_username(mainmenu->get_username());
        this->set_password(mainmenu->get_password());
        this->set_last_name(mainmenu->get_last_name());
        this->set_role(mainmenu->get_role());
        this->set_national_code(mainmenu->get_national_code());
        this->set_phone_number(mainmenu->get_phone_number());
    }
    this->set_first_name(firstName);
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
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

    }

}





void AdminMainMenu::on_pushButton_clicked()
{    
    AdminProfile* ap = new AdminProfile(this);
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
    AdminAddPeople* aap = new AdminAddPeople(this);
    aap->show();
    close();
}


void AdminMainMenu::on_pushButton_2_clicked()
{
    adminMessages* am = new adminMessages(this);

    am->show();

    close();
}


void AdminMainMenu::on_pushButton_7_clicked()
{
    adminAddClass* adc = new adminAddClass(this);
    adc->show();
    close();
}


void AdminMainMenu::on_pushButton_6_clicked()
{
    AdminClassInfo* aci = new AdminClassInfo(this);
    aci->show();
    close();
}


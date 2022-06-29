#include "adminprofile.h"
#include "ui_adminprofile.h"
#include <QValidator>
#include <QMessageBox>
#include "adminmainmenu.h"
AdminProfile::AdminProfile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminProfile)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color: transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->applyChangeNumber->setStyleSheet("background-color: transparent");
    this->ui->applyChangePass->setStyleSheet("background-color: transparent");
    this->ui->changePassBtn->setStyleSheet("background-color: transparent");
    this->ui->changeNumber->setStyleSheet("background-color: transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");


    this->ui->applyChangePass->setVisible(false);
    this->ui->label_24->setVisible(false);
    this->ui->changePass->setVisible(false);

    this->ui->applyChangeNumber->setVisible(false);
    this->ui->label_20->setVisible(false);



    this->ui->nameLine->setText("Shantia");
    this->ui->nameLine->setDisabled(true);
    this->ui->lastNameLine->setText("Soltani");
    this->ui->lastNameLine->setDisabled(true);
    this->ui->NcodeLine->setText("123456789");
    this->ui->NcodeLine->setDisabled(true);
    this->ui->RoleLine->setText("Admin");
    this->ui->RoleLine->setDisabled(true);
    this->ui->numberLine->setText("0910 209 8097");
    this->ui->numberLine->setDisabled(true);
    this->ui->numberLine->setValidator(new QIntValidator(0, 100, this));
}

AdminProfile::~AdminProfile()
{
    delete ui;
}

void AdminProfile::on_changeNumber_clicked()
{
    this->ui->numberLine->setDisabled(false);
    this->ui->applyChangeNumber->setVisible(true);
    this->ui->label_20->setVisible(true);
}


void AdminProfile::on_applyChangeNumber_clicked()
{
    this->ui->numberLine->setDisabled(true);
    this->ui->applyChangeNumber->setVisible(false);
    this->ui->label_20->setVisible(false);
}




void AdminProfile::on_applyChangePass_clicked()
{
    this->ui->changePass->setVisible(false);
    this->ui->applyChangePass->setVisible(false);
    this->ui->label_24->setVisible(false);
}


void AdminProfile::on_changePassBtn_clicked()
{
    this->ui->changePass->setVisible(true);
    this->ui->applyChangePass->setVisible(true);
    this->ui->label_24->setVisible(true);
}


void AdminProfile::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminMainMenu* smm = new AdminMainMenu;
        smm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


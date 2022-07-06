#include "studentprofile.h"
#include "ui_studentprofile.h"
#include <QValidator>
#include <QMessageBox>
#include "studentmainmenu.h"

StudentProfile::StudentProfile(StudentMainMenu * member , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentProfile)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color: transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->applychng->setStyleSheet("background-color: transparent");
    this->ui->applychng_2->setStyleSheet("background-color: transparent");
    this->ui->chngPass->setStyleSheet("background-color: transparent");
    this->ui->chngNumber->setStyleSheet("background-color: transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");

    this->ui->applychng_2->setVisible(false);
    this->ui->label_24->setVisible(false);
    this->ui->changePass->setVisible(false);

    this->ui->applychng->setVisible(false);
    this->ui->label_20->setVisible(false);

    this->mainmenu = member;
    this->ui->label_2->setText("Hi dear "  + mainmenu->get_first_name());

    this->ui->nameLine->setText(mainmenu->get_first_name());
    this->ui->nameLine->setDisabled(true);
    this->ui->lastNameLine->setText(mainmenu->get_last_name());
    this->ui->lastNameLine->setDisabled(true);
    this->ui->NcodeLine->setText(mainmenu->get_national_code());
    this->ui->NcodeLine->setDisabled(true);
    this->ui->RoleLine->setText(mainmenu->get_role());
    this->ui->RoleLine->setDisabled(true);
    this->ui->numberLine->setText(mainmenu->get_phone_number());
    this->ui->numberLine->setDisabled(true);
    this->ui->numberLine->setValidator(new QIntValidator(this));
}

StudentProfile::~StudentProfile()
{
    delete ui;
}

void StudentProfile::on_chngNumber_clicked()
{
    this->ui->applychng->setVisible(true);
    this->ui->label_20->setVisible(true);
    this->ui->numberLine->setDisabled(false);
}


void StudentProfile::on_chngPass_clicked()
{
    this->ui->applychng_2->setVisible(true);
    this->ui->label_24->setVisible(true);
    this->ui->changePass->setVisible(true);
}


void StudentProfile::on_applychng_clicked()
{
    this->ui->applychng->setVisible(false);
    this->ui->label_20->setVisible(false);
    this->ui->numberLine->setDisabled(true);
}


void StudentProfile::on_applychng_2_clicked()
{
    this->ui->applychng_2->setVisible(false);
    this->ui->label_24->setVisible(false);
    this->ui->changePass->setVisible(false);
}


void StudentProfile::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentMainMenu* smm = new StudentMainMenu(mainmenu->get_first_name() , mainmenu);
        smm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


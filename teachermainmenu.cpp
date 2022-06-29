#include "teachermainmenu.h"
#include "ui_teachermainmenu.h"
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include "loginpage.h"
#include "teacherprofile.h"
TeacherMainMenu::TeacherMainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherMainMenu)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color:transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color:transparent");
    this->ui->pushButton_4->setStyleSheet("background-color:transparent");
    this->ui->pushButton_5->setStyleSheet("background-color:transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->pushButton_7->setStyleSheet("background-color:transparent");
    this->ui->label_13->setStyleSheet("background-color: #f0f0f0; border-radius: 20px;");
}

TeacherMainMenu::~TeacherMainMenu()
{
    delete ui;
}

void TeacherMainMenu::on_pushButton_7_clicked()
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





void TeacherMainMenu::on_pushButton_clicked()
{
    teacherProfile* tp = new teacherProfile;
    tp->show();
    close();
}


#include "adminmainmenu.h"
#include "ui_adminmainmenu.h"

AdminMainMenu::AdminMainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminMainMenu)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color:transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color:transparent");
    this->ui->pushButton_4->setStyleSheet("background-color:transparent");
    this->ui->pushButton_5->setStyleSheet("background-color:transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");

}

AdminMainMenu::~AdminMainMenu()
{
    delete ui;
}

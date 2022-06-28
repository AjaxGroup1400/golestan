#include<QMessageBox>



#include"Filemanager.h"
#include "enterenewpass.h"
#include "ui_enterenewpass.h"
#include "loginpage.h"



EntereNewPass::EntereNewPass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EntereNewPass)
{
    ui->setupUi(this);
    this->ui->Confirmbtn->setStyleSheet("background-color:transparent");    
}

EntereNewPass::~EntereNewPass()
{
    delete ui;
}

void EntereNewPass::setIndex(int _index)
{
    this->index = _index;
}

void EntereNewPass::on_Confirmbtn_clicked()
{
    if (ui->newPass != ui->confirmNewPass)
    {
        QMessageBox * erbox = new QMessageBox(QMessageBox::Icon::Critical , "Error" , "field \"new password\" doesn't equal field \"confirm new password\"" , QMessageBox::Button::Ok);
        erbox->show();
        connect(erbox , &QMessageBox::buttonClicked , erbox , &QMessageBox::deleteLater);
        return ;
    }




    LoginPage* lg = new LoginPage;
    lg->show();
    close();
}


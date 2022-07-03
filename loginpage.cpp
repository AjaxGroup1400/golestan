#include <QMessageBox>
#include <iostream>

#include "Auth.h"
#include "Filemanager.h"

#include "loginpage.h"
#include "studentmainmenu.h"
#include "adminmainmenu.h"
#include "teachermainmenu.h"

#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    this->ui->forgotPass->setStyleSheet("background-color:transparent");
    this->ui->Loginbtn->setStyleSheet("background-color:transparent");

    ui->passLine->setEchoMode(QLineEdit::Password);
    connect(ui->showPass, SIGNAL(clicked(bool)), this, SLOT(on_showPass_clicked(bool)));
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_showPass_clicked(bool checked)
{
    if (checked==true){
        ui->passLine->setEchoMode(QLineEdit::Normal);
    }

    else{
        ui->passLine->setEchoMode(QLineEdit::Password);
    }
}


void LoginPage::on_forgotPass_clicked(bool checked)
{
    ForgotPassPage* fpg = new ForgotPassPage;
    fpg->show();
    close();
}

bool LoginPage::isUserValid()
{
    QString username = ui->userLine->text();
    QString password = ui->passLine->text();

    return Auth::canLogin(username, password);
}

void LoginPage::on_Loginbtn_clicked()
{
    int userIndex=  isUserValid();


    if(userIndex == -1)
    {
        QMessageBox* loginStatus = new QMessageBox(
            QMessageBox::Critical,
            "Can't Login",
            "Username or password is wrong, please enter valid information.",
            QMessageBox::Ok
            );


        loginStatus->show();

        return;
    }

    FileManager userFile;

    userFile.create();

    userFile.loadData();

    QString wantedUser = userFile.getRecord(userIndex);

    auto parsedUser = userFile.parse(wantedUser);

    QString userType = parsedUser[parsedUser.size() - 1];

    if(userType == "ADMIN")
    {
        AdminMainMenu* amm = new AdminMainMenu;
        amm->show();
        close();
    }
    else if(userType == "TEACHER")
    {
        TeacherMainMenu* tmm = new TeacherMainMenu;
        tmm->show();
        close();
    }
    else
    {
        StudentMainMenu* smm = new StudentMainMenu;
        smm->show();
        close();
    }
}

#include <QMessageBox>
#include <QValidator>
#include <QRegularExpression>



#include "adminaddpeople.h"
#include "ui_adminaddpeople.h"
#include "adminmainmenu.h"
#include "adminprofile.h"
#include "adminsendassertion.h"
#include "adminaddclass.h"
#include "adminclassinfo.h"
#include "Filemanager.h"
#include "Auth.h"
#include"teachermainmenu.h"

AdminAddPeople::AdminAddPeople(AdminMainMenu * member , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminAddPeople)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_7->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color: transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");
    this->ui->AddBtn->setStyleSheet("background-color: transparent");

    this->mainmenu = member;
    this->ui->label_2->setText("Hi dear " + mainmenu->get_first_name());

    this->ui->numberLine->setValidator(new QRegularExpressionValidator(QRegularExpression(R"((0|\+98)?([ ]|-|[()]){0,2}9[1|2|3|4]([ ]|-|[()]){0,2}(?:[0-9]([ ]|-|[()]){0,2}){8})"), this));
}

AdminAddPeople::~AdminAddPeople()
{
    delete ui;
}

void AdminAddPeople::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminMainMenu* amm = new AdminMainMenu(mainmenu->get_first_name() ,mainmenu);
        amm->show();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        exit->close();

        close();
    }
    else{
        exit->close();
    }
}


void AdminAddPeople::on_pushButton_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to admin profile","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        QString role ;
        if(ui->adminRadio->isChecked())
            role = "Admin";
        else if (ui->teacherRadio->isChecked())
            role = "teacher";
        else if(ui->studentRadio->isChecked())
            role = "Student";

        AdminProfile* ap= new AdminProfile(mainmenu);
        ap->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        exit->close();
    }

}


void AdminAddPeople::on_pushButton_4_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to send assertion","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminSendAssertion* asa= new AdminSendAssertion;
        asa->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

    }
}


void AdminAddPeople::on_AddBtn_clicked()
{
    QString firstname = ui->nameLine->text();

    QString lastname = ui->lastNameLine->text();

    // national code is used as username
    QString nationalCode = ui->nationalCodeLine->text();

    QString phoneNumber = ui->numberLine->text();

    QString password = lastname + phoneNumber;

    QString role;

//    if(Auth::isValidIranianNationalCode(nationalCode.toStdString().c_str()))
//    {
//        QMessageBox* invalidNationalCode = new QMessageBox(QMessageBox::Icon::Critical, "Invalid National Code", "please enter a valid national code.", QMessageBox::Button::Ok);

//        invalidNationalCode->show();

//        connect(invalidNationalCode , &QMessageBox::buttonClicked , invalidNationalCode , &QMessageBox::deleteLater);

//        return;
//    }

    if(firstname.isEmpty() || lastname.isEmpty() || nationalCode.isEmpty() || phoneNumber.isEmpty())
    {
        QMessageBox* emptyField = new QMessageBox(QMessageBox::Icon::Critical, "Empty Field", "one of the fields is empty.", QMessageBox::Button::Ok);

        emptyField->show();

        connect(emptyField , &QMessageBox::buttonClicked , emptyField , &QMessageBox::deleteLater);

        return;
    }

    if(ui->adminRadio->isChecked())
        role = "Admin";
    else if(ui->teacherRadio->isChecked())
        role = "Teacher";
    else if(ui->studentRadio->isChecked())
        role = "Student";
    else
    {
        QMessageBox* noRoleSelected = new QMessageBox(QMessageBox::Icon::Critical, "No Role Selected", "you should select a role.", QMessageBox::Button::Ok);

        noRoleSelected->show();

        connect(noRoleSelected , &QMessageBox::buttonClicked , noRoleSelected , &QMessageBox::deleteLater);

        return;
    }

    try {
        // it throws if it doesn't find national code
        Auth::findUser(nationalCode);

        QMessageBox* noRoleSelected = new QMessageBox(QMessageBox::Icon::Critical, "Duplicate National Code(Username)", "please enter another national code(username)", QMessageBox::Button::Ok);

        noRoleSelected->show();

        connect(noRoleSelected , &QMessageBox::buttonClicked , noRoleSelected , &QMessageBox::deleteLater);

    } catch (...) {

        FileManager userFile;

        userFile.create();

        userFile.loadData();

        QString newUserData = Auth::formUserData(
            nationalCode, password,
            firstname, lastname,
            nationalCode, phoneNumber,
            role, true
            );
        if(role == "Teacher")
        {
            if(TeacherMainMenu::teacherIsValidFile(ui->nationalCodeLine->text()) == -1);
                TeacherMainMenu::addNewTeacherToFile(ui->nationalCodeLine->text());
        }


        userFile.append(newUserData);

        userFile.write();

        QMessageBox* userCreated = new QMessageBox(QMessageBox::Icon::Information, "User Created", "user with entered info created.", QMessageBox::Button::Ok);

        userCreated->show();

        connect(userCreated , &QMessageBox::buttonClicked , userCreated , &QMessageBox::deleteLater);

        ui->nameLine->clear();

        ui->lastNameLine->clear();

        ui->nationalCodeLine->clear();

        ui->numberLine->clear();
    }

}


void AdminAddPeople::on_pushButton_7_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to add class","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        adminAddClass* adc= new adminAddClass(mainmenu);
        adc->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);

    }
}


void AdminAddPeople::on_pushButton_6_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to class info","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminClassInfo* aci= new AdminClassInfo(mainmenu);
        aci->show();
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
        close();
    }
    else{
        exit->close();
        connect(exit ,&QMessageBox::buttonClicked ,exit ,&QMessageBox::deleteLater);
    }
}


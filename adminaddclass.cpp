#include "adminaddclass.h"
#include "ui_adminaddclass.h"
#include "adminmainmenu.h"
#include <QMessageBox>
#include "loginpage.h"
#include "adminprofile.h"
#include "adminsendassertion.h"
#include "adminaddpeople.h"
#include "adminmessages.h"
#include "Class.h"

adminAddClass::adminAddClass(AdminMainMenu * member , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminAddClass)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_5->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color: transparent");
    this->ui->pushButton_7->setStyleSheet("background-color: transparent");
    this->ui->pushButton_8->setStyleSheet("background-color: transparent");
    this->ui->pushButton_9->setStyleSheet("background-color: transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");

    this->mainmenu = member;
}

adminAddClass::~adminAddClass()
{
    delete ui;
}

void adminAddClass::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminMainMenu* amm = new AdminMainMenu(mainmenu->get_first_name() ,mainmenu);
        amm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


void adminAddClass::on_pushButton_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to admin profile","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminProfile* ap= new AdminProfile(this->mainmenu);
        ap->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void adminAddClass::on_pushButton_2_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to messages","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        adminMessages* as = new adminMessages(this->mainmenu);
        as->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void adminAddClass::on_pushButton_3_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to add people","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminAddPeople* aap= new AdminAddPeople(this->mainmenu);
        aap->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void adminAddClass::on_pushButton_4_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to send assertion","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        AdminSendAssertion* asa= new AdminSendAssertion(this->mainmenu);
        asa->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


void adminAddClass::on_pushButton_5_clicked()
{

    Class newClass (string_to_lesson(lesson_enum_str[this->lesson]), this->teacherusername);
    newClass.setLocation(this->location);
    newClass.setTime(this->time);
    newClass.setDay(string_to_day(day_enum_str[this->day]));
    QMessageBox* classAdded = new QMessageBox(QMessageBox::Icon::Information, "class Added", "Class with entered info created.", QMessageBox::Button::Ok);
    classAdded->show();

}


void adminAddClass::on_comboBox_4_currentIndexChanged(int index)
{
    this->lesson = index;
}


void adminAddClass::on_comboBox_3_currentIndexChanged(int index)
{
    this->day = index;

}


void adminAddClass::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    this->location = arg1;
}


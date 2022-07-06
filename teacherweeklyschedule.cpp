#include "teacherweeklyschedule.h"
#include "ui_teacherweeklyschedule.h"
#include "teacherprofile.h"
#include "teachersendassertion.h"
#include "teachermessages.h"
#include "teachermainmenu.h"
#include <QMessageBox>


teacherWeeklySchedule::teacherWeeklySchedule(TeacherMainMenu * member , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teacherWeeklySchedule)
{
    ui->setupUi(this);
    this->ui->pushButton_7->setStyleSheet("background-color: transparent");
    this->ui->pushButton_8->setStyleSheet("background-color: transparent");
    this->ui->pushButton_9->setStyleSheet("background-color: transparent");
    this->ui->pushButton_10->setStyleSheet("background-color: transparent");
    this->ui->pushButton_11->setStyleSheet("background-color: transparent");
    this->ui->pushButton_12->setStyleSheet("background-color: transparent");

    this->ui->backToMenu->setStyleSheet("background-color: transparent");
    this->mainmenu = member;
}

teacherWeeklySchedule::~teacherWeeklySchedule()
{
    delete ui;
}

void teacherWeeklySchedule::on_pushButton_7_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to teacher profile","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherProfile* tp= new teacherProfile(mainmenu);
        tp->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void teacherWeeklySchedule::on_pushButton_8_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to message","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherMessages* tm= new teacherMessages(mainmenu);
        tm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


void teacherWeeklySchedule::on_pushButton_10_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to send assertion","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherSendAssertion* tsa= new TeacherSendAssertion;
        tsa->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void teacherWeeklySchedule::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherMainMenu* smm = new TeacherMainMenu(mainmenu->get_first_name() , mainmenu->get_username() , mainmenu);
        smm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


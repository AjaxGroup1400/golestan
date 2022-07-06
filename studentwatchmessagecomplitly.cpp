#include "studentwatchmessagecomplitly.h"
#include "ui_studentwatchmessagecomplitly.h"
#include "studentmessages.h"
#include "studentprofile.h"
#include <QMessageBox>
#include "studentweeklyschedule.h"

StudentWatchMessageComplitly::StudentWatchMessageComplitly(StudentMainMenu * member , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentWatchMessageComplitly)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color: transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");

    this->ui->backToMenu->setStyleSheet("background-color: transparent");

    this->ui->TitleLine->setEnabled(false);
    this->ui->SenderLine->setEnabled(false);
    this->ui->messageLine->setEnabled(false);

    this->mainmenu = member ;
}

StudentWatchMessageComplitly::~StudentWatchMessageComplitly()
{
    delete ui;
}

void StudentWatchMessageComplitly::on_pushButton_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to student profile","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentProfile* sp= new StudentProfile(mainmenu);
        sp->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void StudentWatchMessageComplitly::on_pushButton_2_clicked()
{
    studentMessages* sm= new studentMessages(mainmenu);
    sm->show();
    close();
}


void StudentWatchMessageComplitly::on_backToMenu_clicked()
{
    studentMessages* sm= new studentMessages(mainmenu);
    sm->show();
    close();

}


void StudentWatchMessageComplitly::on_pushButton_3_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to weekly shedule","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        studentWeeklySchedule* swc = new studentWeeklySchedule(mainmenu);
        swc->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


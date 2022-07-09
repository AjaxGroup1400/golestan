#include "studentwatchsurvey.h"
#include "ui_studentwatchsurvey.h"
#include <QMessageBox>
#include "studentmessages.h"
#include "studentprofile.h"
#include "studentweeklyschedule.h"
#include "studentteachersurvey.h"
#include "studentterms.h"
#include "studenttermscores.h"
#include "studentenrolment.h"

StudentWatchSurvey::StudentWatchSurvey(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentWatchSurvey)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->pushButton_7->setStyleSheet("background-color:transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");
}

StudentWatchSurvey::~StudentWatchSurvey()
{
    delete ui;
}

void StudentWatchSurvey::on_pushButton_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to student profile","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentProfile* sp= new StudentProfile;
        sp->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void StudentWatchSurvey::on_pushButton_2_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to message","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        studentMessages* sm= new studentMessages;
        sm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void StudentWatchSurvey::on_pushButton_3_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to weekly shedule","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        studentWeeklySchedule* swc = new studentWeeklySchedule;
        swc->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void StudentWatchSurvey::on_pushButton_7_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to teacher survey","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentWatchSurvey* sws = new StudentWatchSurvey;
        sws->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void StudentWatchSurvey::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to teacher survey","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentTeacherSurvey* sts = new StudentTeacherSurvey;
        sts->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


void StudentWatchSurvey::on_pushButton_6_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to view scores","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentTerms* st = new StudentTerms;
        st->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void StudentWatchSurvey::on_pushButton_4_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to enrolment","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentEnrolment* se = new StudentEnrolment;
        se->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


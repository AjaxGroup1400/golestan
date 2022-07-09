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

StudentWatchSurvey::StudentWatchSurvey(StudentMainMenu * member , QWidget *parent) :
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

    this->mainmenu = member ;
    this->ui->label_2->setText("Hi dear " + mainmenu->get_first_name());
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
        StudentProfile* sp= new StudentProfile(mainmenu);
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
        studentMessages* sm= new studentMessages(mainmenu);
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
        studentWeeklySchedule* swc = new studentWeeklySchedule(mainmenu);
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
        StudentWatchSurvey* sws = new StudentWatchSurvey(mainmenu);
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
        StudentTeacherSurvey* sts = new StudentTeacherSurvey(mainmenu);
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
        StudentTerms* st = new StudentTerms(mainmenu);
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
        StudentEnrolment* se = new StudentEnrolment(mainmenu);
        se->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


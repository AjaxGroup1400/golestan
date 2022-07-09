#include "studentteachersurvey.h"
#include "ui_studentteachersurvey.h"

#include "studentmainmenu.h"
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include "loginpage.h"
#include "studentprofile.h"
#include "studentmessages.h"
#include "studentweeklyschedule.h"
#include <QGridLayout>
#include <QLabel>
#include "studentwatchsurvey.h"
#include "studentterms.h"
#include "studenttermscores.h"
#include "studentenrolment.h"

StudentTeacherSurvey::StudentTeacherSurvey(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentTeacherSurvey)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->pushButton_7->setStyleSheet("background-color:transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");

    for (int i = 0 ; i<10;i++){
        ui->verticalLayout_2->addWidget(showTeachers());

    }
}

StudentTeacherSurvey::~StudentTeacherSurvey()
{
    delete ui;
}

void StudentTeacherSurvey::on_surveyBtn_clicked(QString nameOfClass)
{
    StudentWatchSurvey* sws = new StudentWatchSurvey;
    sws->show();
    close();
}

QGroupBox *StudentTeacherSurvey::showTeachers()
{
    QWidget* widget = new QWidget;
    QGridLayout* grid = new QGridLayout(widget);

    QGroupBox* gBox = new QGroupBox;
    gBox->setMaximumWidth(741);
    gBox->setMaximumHeight(61);
    gBox->setTitle("");

    QLabel * Name = new QLabel;
    Name->setMaximumWidth(81);
    Name->setMaximumHeight(20);
    Name->setText("First Name");
    Name->setStyleSheet("font:Montesrat 9px; color:rgb(41, 39, 40);");

    QLabel * lastName = new QLabel;
    lastName->setMaximumWidth(81);
    lastName->setMaximumHeight(20);
    lastName->setText("Last Name");
    lastName->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");

    QLabel * ClassName = new QLabel;
    QString nameOfClass;
    ClassName->setMaximumWidth(81);
    ClassName->setMaximumHeight(20);
    ClassName->setText("ClassName");
    ClassName->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");


    QPushButton * survey = new QPushButton;
    survey->setMaximumWidth(81);
    survey->setMaximumHeight(20);
    survey->setText("Watch Survey");
    survey->setStyleSheet("font:Montesrat 9px; color: rgb(178, 8, 55);background-color: transparent");
    connect(survey,&QPushButton::clicked,[this, nameOfClass] { on_surveyBtn_clicked(nameOfClass);});


    grid->addWidget(Name,0,0);
    grid->addWidget(lastName,0,1);
    grid->addWidget(ClassName,0,2);
    grid->addWidget(survey,0,3);

    gBox->setLayout(grid);
    return gBox;

}

void StudentTeacherSurvey::on_pushButton_clicked()
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


void StudentTeacherSurvey::on_pushButton_2_clicked()
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


void StudentTeacherSurvey::on_pushButton_3_clicked()
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




void StudentTeacherSurvey::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentMainMenu* smm = new StudentMainMenu(mainmenu);
        smm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


void StudentTeacherSurvey::on_pushButton_6_clicked()
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


void StudentTeacherSurvey::on_pushButton_4_clicked()
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


#include "studentenrolment.h"
#include "ui_studentenrolment.h"
#include "studentmainmenu.h"
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include "loginpage.h"
#include "studentprofile.h"
#include "studentmessages.h"
#include "studentweeklyschedule.h"
#include "studentteachersurvey.h"
#include "studentterms.h"
#include "studenttermscores.h"
#include "QCheckBox"

StudentEnrolment::StudentEnrolment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentEnrolment)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_5->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->pushButton_7->setStyleSheet("background-color:transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");


    for (int terms = 0 ; terms<10;terms++){
        ui->verticalLayout_2->addWidget(showLessons());

    }
}

StudentEnrolment::~StudentEnrolment()
{
    delete ui;
}

void StudentEnrolment::on_pushButton_clicked()
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


void StudentEnrolment::on_pushButton_2_clicked()
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


void StudentEnrolment::on_pushButton_3_clicked()
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


void StudentEnrolment::on_pushButton_6_clicked()
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


void StudentEnrolment::on_pushButton_7_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to teacher survey","If you do not save the changes, they will not be saved\nDo you want to leave?");
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


void StudentEnrolment::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentMainMenu* smm = new StudentMainMenu;
        smm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}

QGroupBox *StudentEnrolment::showLessons()
{
    QWidget* widget = new QWidget;
    QGridLayout* grid = new QGridLayout(widget);

    QGroupBox* gBox = new QGroupBox;
    gBox->setMaximumWidth(741);
    gBox->setMaximumHeight(61);
    gBox->setTitle("");

    QLabel * CLassName = new QLabel;
    CLassName->setMaximumWidth(81);
    CLassName->setMaximumHeight(20);
    CLassName->setText("Class Name");
    CLassName->setStyleSheet("font:Montesrat 9px; color:rgb(41, 39, 40);");

    QLabel * teacherName = new QLabel;
    teacherName->setMaximumWidth(81);
    teacherName->setMaximumHeight(20);
    teacherName->setText("Teacher Name");
    teacherName->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");

    QLabel * Time = new QLabel;
    Time->setMaximumWidth(81);
    Time->setMaximumHeight(20);
    Time->setText("8-10 AM");
    Time->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");


    QCheckBox * selection = new QCheckBox;
    QString nameOfTerm;
    selection->setMaximumWidth(40);
    selection->setMaximumHeight(20);
    //connect(showScore,&QPushButton::clicked,[this, nameOfTerm] { goToScores(nameOfTerm);});


    grid->addWidget(CLassName,0,0);
    grid->addWidget(teacherName,0,1);
    grid->addWidget(Time,0,2);
    grid->addWidget(selection,0,3);

    gBox->setLayout(grid);
    return gBox;
}


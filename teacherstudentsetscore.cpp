#include "teacherstudentsetscore.h"
#include "ui_teacherstudentsetscore.h"
#include "teacherclasssetscore.h"
#include "teachermainmenu.h"
#include "teacherclassinfo.h"
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include "loginpage.h"
#include "teacherprofile.h"
#include "teachersendassertion.h"
#include "teachermessages.h"
#include "teacherweeklyschedule.h"
#include "QLineEdit"
#include <QDoubleValidator>

TeacherStudentSetScore::TeacherStudentSetScore(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherStudentSetScore)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color:transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color:transparent");
    this->ui->pushButton_4->setStyleSheet("background-color:transparent");
    this->ui->pushButton_5->setStyleSheet("background-color:transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->backToMenu->setStyleSheet("background-color:transparent");
    this->ui->SetScore->setStyleSheet("background-color:transparent");

    for (int i = 0 ; i<10;i++){
        ui->verticalLayout_2->addWidget(showStudent());

    }
}

TeacherStudentSetScore::~TeacherStudentSetScore()
{
    delete ui;
}

QGroupBox *TeacherStudentSetScore::showStudent()
{
    QWidget* widget = new QWidget;
    QGridLayout* grid = new QGridLayout(widget);

    QGroupBox* gBox = new QGroupBox;
    gBox->setMaximumWidth(741);
    gBox->setMaximumHeight(61);
    gBox->setTitle("");

    QLabel * Name = new QLabel;
    Name->setMaximumWidth(80);
    Name->setMaximumHeight(20);
    Name->setText("Firs Name");
    Name->setStyleSheet("font:Montesrat 9px; color:rgb(41, 39, 40);");

    QLabel * lastName = new QLabel;
    lastName->setMaximumWidth(80);
    lastName->setMaximumHeight(20);
    lastName->setText("Last Name");
    lastName->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");

    QLabel * studentNumber = new QLabel;
    studentNumber->setMaximumWidth(80);
    studentNumber->setMaximumHeight(20);
    studentNumber->setText("Student Number");
    studentNumber->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");


    QLabel * field = new QLabel;
    field->setMaximumWidth(80);
    field->setMaximumHeight(20);
    field->setText("Field");
    field->setStyleSheet("font:Montesrat 9px; color: rgb(41, 39, 40);");

    QLineEdit* score = new QLineEdit;
    score->setMaximumWidth(50);
    score->setMaximumHeight(20);
    score->setMaxLength(5);
    auto dv = new QDoubleValidator(0.00, 20.00, 3);
    score->setValidator(dv);


    grid->addWidget(Name,0,0);
    grid->addWidget(lastName,0,1);
    grid->addWidget(studentNumber,0,2);
    grid->addWidget(field,0,3);
    grid->addWidget(score,0,4);

    gBox->setLayout(grid);
    return gBox;

}

void TeacherStudentSetScore::on_pushButton_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to teacher profile","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherProfile* tp= new teacherProfile;
        tp->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void TeacherStudentSetScore::on_pushButton_2_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to message","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherMessages* tm= new teacherMessages;
        tm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void TeacherStudentSetScore::on_pushButton_3_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to class info","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherClassInfo* tci = new TeacherClassInfo;
        tci->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void TeacherStudentSetScore::on_pushButton_4_clicked()
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


void TeacherStudentSetScore::on_pushButton_5_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to weekly shedule","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherWeeklySchedule* tws = new teacherWeeklySchedule;
        tws->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void TeacherStudentSetScore::on_pushButton_6_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to set score","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherClassSetScore* tcss = new TeacherClassSetScore;
        tcss->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }

}


void TeacherStudentSetScore::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to set score","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherClassSetScore* tcss = new TeacherClassSetScore;
        tcss->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}




void TeacherStudentSetScore::on_SetScore_clicked()
{

}


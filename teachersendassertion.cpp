#include "teachersendassertion.h"
#include "ui_teachersendassertion.h"
#include <QMessageBox>


#include"StudentNotification.h"
#include "teachermainmenu.h"
#include "teacherprofile.h"
#include"Enum.h"
#include"Class.h"

TeacherSendAssertion::TeacherSendAssertion(TeacherMainMenu * tm ,  QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherSendAssertion),
    mainmenu(tm)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color:transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color:transparent");
    this->ui->pushButton_4->setStyleSheet("background-color:transparent");
    this->ui->pushButton_5->setStyleSheet("background-color:transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->sendbtn->setStyleSheet("background-color:transparent");
    this->ui->backToMenu->setStyleSheet("background-color:transparent");

    connect(ui->StudentBox,&QCheckBox::stateChanged,this,&TeacherSendAssertion::studentReciveState);
    connect(ui->TeacherBox,&QCheckBox::stateChanged,this,&TeacherSendAssertion::teacherReciveState);


}

TeacherSendAssertion::~TeacherSendAssertion()
{
    delete ui;
}

void TeacherSendAssertion::studentReciveState(int state)
{
    studentsState = state;
    qDebug()<<state;
}

void TeacherSendAssertion::teacherReciveState(int state)
{
    teachersState = state;
    qDebug()<<state;
}

void TeacherSendAssertion::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherMainMenu* tmm = new TeacherMainMenu;
        tmm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


void TeacherSendAssertion::on_pushButton_clicked()
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


void TeacherSendAssertion::on_sendbtn_clicked()
{
    QString title = ui->TitleLine->text();
    QString message = ui->messageLine->toPlainText();
    QString lesson ;
//    Class lessonClass = string_to_lesson(lesson);

//    mainmenu->sendingNotification(title , message , lessonClass );



}


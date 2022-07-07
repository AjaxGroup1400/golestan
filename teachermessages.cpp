#include <QMessageBox>
#include<fstream>
#include<QString>

#include<iostream>
using namespace std;


#include "teachermessages.h"
#include "ui_teachermessages.h"
#include "teachersendassertion.h"
#include "teachermainmenu.h"
#include "teacherprofile.h"
#include "teacherwatchmessagecomplitly.h"
#include "teacherweeklyschedule.h"



teacherMessages::teacherMessages(TeacherMainMenu * member , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teacherMessages)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->pushButton_5->setStyleSheet("background-color: transparent");
    this->ui->pushButton_6->setStyleSheet("background-color: transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");
    this->ui->msgbtn1->setStyleSheet("background-color: transparent");
    this->ui->msgbtn2->setStyleSheet("background-color: transparent");
    this->ui->msgbtn3->setStyleSheet("background-color: transparent");
    this->ui->msgbtn4->setStyleSheet("background-color: transparent");
    this->ui->msgbtn5->setStyleSheet("background-color: transparent");
    this->ui->msgbtn6->setStyleSheet("background-color: transparent");
    this->ui->msgbtn7->setStyleSheet("background-color: transparent");

    this->mainmenu = member;

    ifstream ifs(this->filePath.toStdString());
    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        for (auto i : this->dataHolder)
        {
            if(QString::fromStdString(i["allowed_student"][0]["username"].asString()) == "#")
            {
                if(i["allowed_student"][0]["is_read"] == false)
                {
                    this->unReadsender.push_back(QString::fromStdString(i["sender"].asString()));
                    this->unreadMessages.push_back(QString::fromStdString(i["description"].asString()));
                    this->unReadsender.push_back(QString::fromStdString(i["title"].asString()));
                }
                else if (i["allowed_student"][0]["is_read"] == true)
                {
                    this->Readsender.push_back(QString::fromStdString(i["sender"].asString()));
                    this->readMessages.push_back(QString::fromStdString(i["description"].asString()));
                    this->Readsender.push_back(QString::fromStdString(i["title"].asString()));

                }
                else
                {
                    exception e("\"is_read\" in file\"../data_resources/studentnotification\" doesen't contain acceptable parameters");
                    emit mainmenu->exceptioOccured(e);
                }
            }
        }
        ifs.close();
    }
    else
    {
        exception e("coulden't open file \"../data_resources/studentnotification\"");
        emit mainmenu->exceptioOccured(e);
    }



}

teacherMessages::~teacherMessages()
{
    delete ui;
}

void teacherMessages::on_pushButton_clicked()
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


void teacherMessages::on_pushButton_4_clicked()
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


void teacherMessages::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","Do you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        TeacherMainMenu* smm = new TeacherMainMenu(mainmenu->get_first_name(), mainmenu->get_username() , mainmenu );
        smm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


void teacherMessages::on_msgbtn1_clicked()
{        
    bool isread;
    QString sender = nullptr;
    for(int i = 0 ; i < unreadTitle.size() ; i++)
    {
        if(unreadTitle[i] == this->ui->msgtitle1->text() && this->ui->msg1->text() == unreadMessages[i])
        {
            sender = unReadsender[i];
            isread = false;
            break;
        }
    }
    if(sender == nullptr)
    {
        for(int i = 0 ; i < readTitle.size() ; i++)
        {
            if(readTitle[i] == this->ui->msgtitle1->text() && this->ui->msg1->text() == readMessages[i])
            {
                sender = Readsender[i];
                isread = true;
                break;
            }

        }
    }

    if(sender!=nullptr)
    {
        teacherWatchMessageComplitly* twmc = new teacherWatchMessageComplitly(this->ui->msgtitle1->text() , this->ui->msg1->text() , sender ,  isread , mainmenu);
        twmc->show();
        close();
    }
    else
    {
        exception e("coulden't find the message");
        emit mainmenu->exceptioOccured(e);
    }


}


void teacherMessages::on_pushButton_5_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Go to weekly shedule","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        teacherWeeklySchedule* tws = new teacherWeeklySchedule(mainmenu);
        tws->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}


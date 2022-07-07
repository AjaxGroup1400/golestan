#include <QMessageBox>
#include<fstream>
#include<iostream>
using namespace std;

#include"dist/json/json.h"
#include "studentmessages.h"
#include "ui_studentmessages.h"
#include "studentmainmenu.h"
#include "studentprofile.h"

#include "studentwatchmessagecomplitly.h"
#include "studentweeklyschedule.h"

studentMessages::studentMessages(StudentMainMenu * member , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::studentMessages)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color: transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color: transparent");
    this->ui->pushButton_4->setStyleSheet("background-color: transparent");
    this->ui->backToMenu->setStyleSheet("background-color: transparent");
    this->ui->msgbtn1->setStyleSheet("background-color: transparent");
    this->ui->msgbtn2->setStyleSheet("background-color: transparent");
    this->ui->msgbtn3->setStyleSheet("background-color: transparent");
    this->ui->msgbtn4->setStyleSheet("background-color: transparent");
    this->ui->msgbtn5->setStyleSheet("background-color: transparent");
    this->ui->msgbtn6->setStyleSheet("background-color: transparent");
    this->ui->msgbtn7->setStyleSheet("background-color: transparent");

    this->mainmenu = member;
    this->ui->label_2->setText(("Hi dear " + mainmenu->get_first_name()));

    ifstream ifs(this->filePath.toStdString());
    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        for (auto i : this->dataHolder)
        {
            if(QString::fromStdString(i["allowed_student"][0]["username"].asString()) == "*")
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
            else
            {
                for (auto j : i["allowed_student"])
                {
                    if(QString::fromStdString(j["username"].asString()) == mainmenu->get_username())
                    {
                        if(j["is_read"].asString() == "false" )
                        {
                            this->unReadsender.push_back( QString::fromStdString(i["sender"].asString()));
                            this->unreadMessages.push_back(QString::fromStdString(i["description"].asString()));
                            this->unreadTitle.push_back(QString::fromStdString(i["title"].asString()));
                        }
                        else if (j["is_read"].asString() == "true")
                        {
                            this->Readsender.push_back( QString::fromStdString(i["sender"].asString()));
                            this->readMessages.push_back(QString::fromStdString(i["description"].asString()));
                            this->readTitle.push_back(QString::fromStdString(i["title"].asString()));

                        }
                        else
                        {
                            exception e("\"is_read\" in file\"../data_resources/studentnotification\" doesen't contain acceptable parameters");
                            emit mainmenu->exceptioOccured(e);
                        }
                        break;
                    }
                }
            }
        }
        ifs.close();
    }



}

studentMessages::~studentMessages()
{
    delete ui;
}

void studentMessages::on_pushButton_clicked()
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


void studentMessages::on_backToMenu_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Back to menu","If you do not save the changes, they will not be saved\nDo you want to leave?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        StudentMainMenu* smm = new StudentMainMenu(mainmenu->get_first_name() , mainmenu);
        smm->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}





void studentMessages::on_msgbtn1_clicked()
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
        StudentWatchMessageComplitly* swmc = new StudentWatchMessageComplitly(this->ui->msgtitle1->text() , this->ui->msg1->text() , sender , isread , mainmenu );
        swmc->show();
        close();
    }
    else
    {
        exception e("coulden't find the message");
        emit mainmenu->exceptioOccured(e);
    }

}


void studentMessages::on_pushButton_3_clicked()
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


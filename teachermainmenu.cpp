#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include <QVector>
#include <QMultiMap>
#include <iterator>
#include<fstream>
#include<iostream>
using namespace std;



#include "teachermainmenu.h"
#include "teachersendassertion.h"
#include "ui_teachermainmenu.h"
#include "loginpage.h"
#include "teacherprofile.h"
#include "ui_Teacher.h"
#include "Auth.h"
#include "Filemanager.h"
#include "User.h"
#include"StudentNotification.h"
#include"dist/json/json.h"




TeacherMainMenu::TeacherMainMenu(QWidget *parent) :
//    QWidget(parent),
    ui(new Ui::TeacherMainMenu)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color:transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color:transparent");
    this->ui->pushButton_4->setStyleSheet("background-color:transparent");
    this->ui->pushButton_5->setStyleSheet("background-color:transparent");
    this->ui->pushButton_6->setStyleSheet("background-color:transparent");
    this->ui->pushButton_7->setStyleSheet("background-color:transparent");
    this->ui->label_13->setStyleSheet("background-color: #f0f0f0; border-radius: 20px;");

//    FileManager userFile;

//    userFile.create("teachers.txt");

//    userFile.loadData();

//    for(const QString& item: userFile.getData()){
//        auto parse = userFile.parse(item);

//        if (parse[0] == this->get_username()){
///*            QMap <QString, float> studentscore;
//            studentscore.insert(parse[2],parse[3].toFloat()) ;
//            this->students.insert( parse[1] , studentscore ) ;
//*/
//        }
//    }

//working with file fot teacher class
    initFile();
}

TeacherMainMenu::~TeacherMainMenu()
{
    delete ui;
}

void TeacherMainMenu::on_pushButton_7_clicked()
{
    QMessageBox* exit = new QMessageBox(QMessageBox::Warning,"Close Window","Do you want to close this window?");
    exit->setStandardButtons(QMessageBox::Yes);
    exit->addButton(QMessageBox::No);
    exit->setDefaultButton(QMessageBox::No);
    exit->show();
    if(exit->exec() == QMessageBox::Yes){
        LoginPage* lg = new LoginPage;
        lg->show();
        exit->close();
        close();
    }
    else{
        exit->close();
    }
}





void TeacherMainMenu::on_pushButton_clicked()
{
    teacherProfile* tp = new teacherProfile;
    tp->show();
    close();
}

//QMap<QString, float> TeacherMainMenu::studentsList(QString classname)
//{
//    QMap <QString, float> classlist;

//for (auto i=this->students.begin(); i!=this->students.end(); i++){
//    auto j = i.value().begin();

//    if (j.key() == classname){

//        classlist.insert( i.key(), j.value() );
//    }
//}
//    return classlist;

//}

void TeacherMainMenu::  deleteStudent(QString studentname , Class Class)

{
//    can be checked in Class.cpp:
//    int index = Auth::validStudent(studentname , Class.getLesson());
    Class.deleteStudent(studentname);

//    if (newPass != confirmNewPass)
//    {
//        QMessageBox * confirmPassDoesntMatch = new QMessageBox(QMessageBox::Icon::Critical , "Error" , "field \"new password\" doesn't equal field \"confirm new password\"" , QMessageBox::Button::Ok);
//        confirmPassDoesntMatch->show();
//        connect(confirmPassDoesntMatch , &QMessageBox::buttonClicked , confirmPassDoesntMatch, &QMessageBox::deleteLater);
//        return;
//    }

//    FileManager userFile;

//    userFile.create("teachers.txt");

//    userFile.loadData();


//    userFile.deleteRecord(index);


//    userFile.write();


    QMessageBox * studentdeleted = new QMessageBox(QMessageBox::Icon::Information, "Student deleted", "the student was deleted succesfuly", QMessageBox::Button::Ok);
//    studentdeleted->setParent(this);

    studentdeleted->show();

    QObject::connect(studentdeleted , &QMessageBox::buttonClicked , studentdeleted , &QMessageBox::deleteLater);

//    LoginPage* lg = new LoginPage;

//    connect(studentdeleted, &QMessageBox::buttonClicked, lg, &LoginPage::show);

    //    connect(studentdeleted, &QMessageBox::buttonClicked, this, &EntereNewPass::close);
}


void TeacherMainMenu::sendingNotification(QString title , QString message , Class Class)
{
    QList list = Class.getList().keys();

    StudentNotification member;
    QList<QMap<QString , QString>> studentUsernameList ;

    for (int i = 0 ;  i < list.size() ; i++)
    {
        QMap<QString , QString> member ;
        member["username"] = list[i];
        member["is_read"] = "false";
        studentUsernameList.push_back(member)  ;
    }
    member.addAlert(title , message , this->get_username() , studentUsernameList ) ;
}

void TeacherMainMenu::addNewTeacherToFile(QList<QString> lessons)
{
    ifstream ifs(this->filePath.toStdString());
    this->dataReader.parse(ifs , this->dataHolder);
    Json::Value teacherInformation ;
    teacherInformation["teacher"] = this->get_username().toStdString();
    for(auto &i : lessons)
    {
        teacherInformation["lessons"].append(i.toStdString());
    }
    this->dataHolder.append(teacherInformation);


    ofstream ofs(this->filePath.toStdString());
    Json::StyledWriter writer;
    string finalPart = writer.write(this->dataHolder);
    ofs.close();
}

void TeacherMainMenu::addNewLessonFile(QString lesson)
{
    this->lessons.push_back(lesson);

    ifstream ifs(this->filePath.toStdString());
    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        for(auto &members : this->dataHolder)
        {
            if(QString::fromStdString(members["teacher"].asString()) == this->get_username())
            {
                members["lessons"].append(lesson.toStdString());
                break;
            }
        }
        ofstream ofs(this->filePath.toStdString());
        Json::StyledWriter writer ;
        string finalPart = writer.write(this->dataHolder);
        ofs << finalPart;
        ofs.close();
    }
}

void TeacherMainMenu::removeLessonFile(QString lesson)
{
    this->lessons.removeOne(lesson);

    ifstream ifs(this->filePath.toStdString());
    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        Json::Value undeletedLessons;
        for(auto &members : this->dataHolder)
        {
            if(QString::fromStdString(members["teacher"].asString()) == this->get_username() )
            {
                for(auto &ls : members["lessons"])
                {
                    if(QString::fromStdString(ls.asString()) != lesson)
                        undeletedLessons.append(ls);
                }
                members["lessons"] = undeletedLessons;
                break;
            }
            ofstream ofs(this->filePath.toStdString());
            Json::StyledWriter writer ;
            string finalPart = writer.write(this->dataHolder);
            ofs << finalPart;
            ofs.close();
        }



    }
}







void TeacherMainMenu::on_pushButton_3_clicked()
{
    /*
    QMap<QString , float> chemistry = this->studentsList("chemistry");
    QMap<QString , float> physics = this->studentsList("physics");
    QMap<QString , float> bp = this->studentsList("bp");
    QMap<QString , float> calculus = this->studentsList("calculus");
    QMap<QString , float> discrete = this->studentsList("discrete");
    */
    for(auto i = this->classes.begin(); i!=classes.end(); i++){

    }

//  new page(chemistry , chemistry.size , ...)
//  class name , number of students , students' names , class location

}


void TeacherMainMenu::on_pushButton_6_clicked()
{
    /*
    QMap<QString , float> chemistry = this->studentsList("chemistry");
    QMap<QString , float> physics = this->studentsList("physics");
    QMap<QString , float> bp = this->studentsList("bp");
    QMap<QString , float> calculus = this->studentsList("calculus");
    QMap<QString , float> discrete = this->studentsList("discrete");
    */
    for(auto i = this->classes.begin(); i!=classes.end(); i++){

    }


}


void TeacherMainMenu::on_pushButton_4_clicked()
{
    TeacherSendAssertion* tsa = new TeacherSendAssertion;
    tsa->show();
    close();
}

void TeacherMainMenu::initFile()
{
    ifstream ifs(this->filePath.toStdString());
    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        for(auto teacher : this->dataHolder)
        {
            if(QString::fromStdString(teacher["teacher"].asString()) == this->get_username())
            {
                for(auto &lesson : teacher["lessons"])
                {
                    this->lessons.push_back(QString::fromStdString(lesson.asString()));
                }
                return;
            }
        }
        return;
    }

    ofstream ofs(filePath.toStdString());
    Json::StyledWriter writer;
//    this->dataHolder[0]["teacher"] = this->get_username().toStdString();
//    this->dataHolder[0]["lessons"] = Json::arrayValue;
    Json::Value baseData = Json::arrayValue;
    string finalPart = writer.write(baseData);
    ofs << finalPart;
    ofs.close();
    return;
}


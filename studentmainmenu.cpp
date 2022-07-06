#include "studentmainmenu.h"
#include "ui_studentmainmenu.h"
#include "loginpage.h"
#include "studentprofile.h"
#include "Enum.h"

#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include <iterator>
#include <string>
#include <fstream>

using std::ifstream, std::string;
using std::ofstream;

StudentMainMenu::StudentMainMenu(QWidget *parent) :
//    QWidget(parent),
    ui(new Ui::StudentMainMenu)
{
    ui->setupUi(this);
    this->ui->pushButton->setStyleSheet("background-color:transparent");
    this->ui->pushButton_2->setStyleSheet("background-color:transparent");
    this->ui->pushButton_3->setStyleSheet("background-color:transparent");
    this->ui->pushButton_4->setStyleSheet("background-color:transparent");
    this->ui->pushButton_5->setStyleSheet("background-color:transparent");
    this->ui->label_8->setStyleSheet("background-color: #f0f0f0; border-radius: 20px;");
}

StudentMainMenu::~StudentMainMenu()
{
    delete ui;
}

QList<float> StudentMainMenu::getAverages()
{
    return avereges;
}

void StudentMainMenu::scores()
{
//    for(auto i = this->classes.begin(); i!= this->classes.end(); i++ ){

//        for(auto j = i->getList().begin(); j!=i->getList().end(); i++){

//            if(j.key()==this->get_username()){
//                float score = j.value();

//                if(score!=-1){
//                    //show...
//                }
//            }
//        }
//    }
}


void StudentMainMenu::surveyOfTeachers(Class Class, int result)
{
//    Class.addSurveyResult(this->get_username(), result);
}

void StudentMainMenu::registry(Class Class)
{
    Class.addStudent(this->get_username());

    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        for(int i = 0; i < dataHolder.size(); i++)
        {
            if(get_username().toStdString() == dataHolder[i]["username"].asString())
            {
                Json::Value studentLessonsCopy = dataHolder[i]["terms"][Term]["lessons"];

                Json::Value newLesson;

                newLesson["teacher"] = Class.getTeacher().toStdString();
                newLesson["lesson"] = lesson_enum_str[Class.getLesson()].toStdString();
                newLesson["score"] = -1;

                studentLessonsCopy.append(newLesson);

                dataHolder[i]["terms"][Term]["lessons"] = studentLessonsCopy;

                ofstream ofs(filePath.toStdString());

                Json::StyledWriter writer;

                string serializedData = writer.write(dataHolder);

                ofs << serializedData;

                ofs.close();
            }
        }
    }
}

void StudentMainMenu::addTerm()
{
    Term++;

    avereges.push_back(-1);

    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        for(int i = 0; i < dataHolder.size(); i++)
        {
            if(get_username().toStdString() == dataHolder[i]["username"].asString())
            {
                dataHolder[i]["count_of_terms"] = dataHolder[i]["count_of_terms"].asInt() + 1;

                Json::Value newTerm;

                newTerm["average"] = -1;
                newTerm["lessons"] = Json::arrayValue;

                dataHolder[i]["terms"].append(newTerm);

                ofstream ofs(filePath.toStdString());

                Json::StyledWriter writer;

                string serializedData = writer.write(dataHolder);

                ofs << serializedData;

                ofs.close();
            }
        }
    }
}

void StudentMainMenu::unregistery(Class Class)
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        for(int i = 0; i < dataHolder.size(); i++)
        {
            if(get_username().toStdString() == dataHolder[i]["username"].asString())
            {
                Json::Value classesCopy = dataHolder[i]["terms"][Term]["lessons"];

                Json::Value wantedClasses;

                for(int j = 0; j < classesCopy.size(); j++)
                {
                    if(classesCopy[i]["teacher"].asString() != Class.getTeacher().toStdString())
                        wantedClasses.append(classesCopy[i]);
                }

                dataHolder[i]["terms"][Term]["lessons"] = wantedClasses;

                ofstream ofs(filePath.toStdString());

                Json::StyledWriter writer;

                string serializedData = writer.write(dataHolder);

                ofs << serializedData;

                ofs.close();

                return;
            }
        }
    }
}

void StudentMainMenu::on_pushButton_5_clicked()
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

void StudentMainMenu::on_pushButton_clicked()
{
    StudentProfile* sp = new StudentProfile;
    sp->show();
    close();
}

void StudentMainMenu::load()
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        for(auto& student : dataHolder)
        {
            if(get_username().toStdString() == student["username"].asString())
            {
                for(auto& term : student["terms"])
                {
                    this->avereges.push_back(term["average"].asFloat());
                }

                return;
            }
        }
        return;
    }

    ofstream ofs(filePath.toStdString());

    Json::StyledWriter writer;

    Json::Value baseData;

    Json::Value baseStudent;

    baseStudent["username"] = get_username().toStdString();
    baseStudent["terms"] = Json::arrayValue;
    baseStudent["count_of_terms"] = 0;

    baseData.append(baseStudent);

    string serializedData = writer.write(baseData);

    ofs << serializedData;

    ofs.close();
}

// json sturcture of each student
//
//{
//    "username": 65564,
//        "terms": [
//            {
//                "average": 5564,
//                "lesson": [
//                    {
//                        "teacher": "dsf",
//                        "score": 545.6565,
//                        "lesson": "gosasteh"
//                    }
//    ]
//            },
//            {
//                "average": -1,
//                "lessons": [
//                    {
//                        "teacher": "string",
//                        "score": -1,
//                        "name": "gosasteh"
//                    },
//                    {
//                        "teacher": "string",
//                        "score": -1,
//                        "name": "gosasteh"
//                    },
//                    {
//                        "teacher": "string",
//                        "score": -1,
//                        "name": "gosasteh"
//                    },
//                    {
//                        "teacher": "string",
//                        "score": -1,
//                        "name": "gosasteh"
//                    }
//                ]
//            }
//        ]
//}



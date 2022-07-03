#include "Class.h"
#include <iterator>
#include <fstream>
#include <string>
#include<iostream>
using namespace std;

Class::Class(enum lesson lesson, QString teacher)
{
    this->number_of_students = 0;
    this->lesson = lesson;
    this->teacher = teacher;

    ifstream ifs(filePath.toStdString());
    if(this->dataReader.parse(ifs,this->dataHolder))
    {
        this->lesson = lesson;
        this->teacher = teacher;
        this->number_of_students = this->dataHolder["number_of_students"].asInt();
        this->location = QString::fromStdString( this->dataHolder["location"].asString());
        this->time = QString::fromStdString( this->dataHolder["time"].asString());
        this->day = string_to_day(QString::fromStdString( this->dataHolder["day"].asString()));

        for(int i=0; i < dataHolder["student_list"].size(); i++){
            this->studentslist.insert(QString::fromStdString(this->dataHolder["student_list"][i]["username"].asString()),this->dataHolder["student_list"][i]["score"].asFloat());
        }
    ifs.close();
    return;
    }

    this->filePath = "../data_resources/" + lesson_enum_str[lesson] + '-' + teacher;
    ofstream ofs(filePath.toStdString());
    Json::StyledWriter writer;

    Json::Value baseData;
    baseData["teacher"] = teacher.toStdString();
    baseData["lesson"] = lesson_enum_str[lesson].toStdString();

    string serializedData = writer.write(baseData);
    ofs << serializedData;
    ofs.close();
}

Class::Class(const Class &other)
{
    this->lesson = other.lesson;
    this->teacher = other.teacher;
    this->number_of_students = other.number_of_students;
    this->location = other.location;
    this->time = other.time;
    this->day = other.day;
    for(auto i = other.studentslist.begin();i!= other.studentslist.end(); i++){
        this->studentslist.insert(i.key(), i.value());
    }
}

void Class::setLocation(QString loc)
{
    this->location = loc;

    ifstream ifs (this->filePath.toStdString());
    if(this->dataReader.parse(ifs,this->dataHolder))
    {
        this->dataHolder["location"] = loc.toStdString();

        ofstream ofs (this->filePath.toStdString());
        Json::StyledWriter writer;
        string finalPart = writer.write(this->dataHolder);
        ofs << finalPart;
        ofs.close();
        return;
    }

}

void Class::setTime(QString time)
{
    this->time = time;

    ifstream ifs (this->filePath.toStdString());
    if(this->dataReader.parse(ifs,this->dataHolder))
    {
        this->dataHolder["time"] = time.toStdString();

        ofstream ofs (this->filePath.toStdString());
        Json::StyledWriter writer;
        string finalPart = writer.write(this->dataHolder);
        ofs << finalPart;
        ofs.close();
        return;
    }
}

void Class::setDay(enum day day)
{
    this->day = day;

    ifstream ifs (this->filePath.toStdString());
    if(this->dataReader.parse(ifs,this->dataHolder))
    {
        this->dataHolder["day"] = day_enum_str[day].toStdString();

        ofstream ofs (this->filePath.toStdString());
        Json::StyledWriter writer;
        string finalPart = writer.write(this->dataHolder);
        ofs << finalPart;
        ofs.close();
        return;
    }
}

void Class::addStudent(QString student_username)
{
    this->studentslist.insert(student_username, -1);
    this->number_of_students ++;

    ifstream ifs(this->filePath.toStdString());
    if (this->dataReader.parse(ifs , this->dataHolder))
    {
        this->dataHolder["number_of_students"] = this->dataHolder["number_of_students"].asInt() + 1 ;
        Json::Value newStudent ;
        newStudent["username"] = student_username.toStdString();
        newStudent["score"] =  -1;
        this->dataHolder["student_list"].append(newStudent);

        ofstream ofs(this->filePath.toStdString());
        Json::StyledWriter writer ;
        string finalPart = writer.write(this->dataHolder);
        ofs << finalPart ;
        ofs.close();
    }
}

void Class::deleteStudent(QString student_username)
{
    this->studentslist.remove(student_username);
    this->number_of_students --;

    ifstream ifs(this->filePath.toStdString());
    if (this->dataReader.parse(ifs , this->dataHolder))
    {
        this->dataHolder["number_of_students"] = this->dataHolder["number_of_students"].asInt() - 1 ;
        Json::Value undeletedStudents;
        for(auto &i : this->dataHolder["student_list"])
        {
            if (student_username != QString::fromStdString(i["username"].asString()) )
            {
                undeletedStudents.append(i);
            }
        }
        this->dataHolder["student_list"] = undeletedStudents;


        ofstream ofs(this->filePath.toStdString());
        Json::StyledWriter writer;
        string finalPart = writer.write(this->dataHolder);
        ofs << finalPart;
        ofs.close();
    }




}

void Class::setScore(QString student_username, float score)
{
    for(auto i = this->studentslist.begin() ; i != this->studentslist.end(); i++){
        if(i.key()==student_username){
            i.value()=score;
        }
    }

    ifstream ifs (this->filePath.toStdString());
    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        for(int i = 0 ; i < this->dataHolder["student_list"].size() ; i++)
        {
            if(QString::fromStdString(this->dataHolder["student_list"][i]["username"].asString()) == student_username)
                this->dataHolder["student_list"][i]["score"] = score;
        }

        ofstream ofs(this->filePath.toStdString());
        Json::StyledWriter wrieter;
        string finalPart = wrieter.write(this->dataHolder);
        ofs << finalPart;
        ofs.close();
    }

}

bool Class::studentIsValid(QString studentUsername, QString lesson)
{
    ifstream ifs(this->filePath.toStdString());
    if(this->dataReader.parse(ifs , this->dataHolder))
    {
        for(auto i : this->dataHolder["student_list"] )
        {
            if(QString::fromStdString(i["username"].asString()) == studentUsername)
                return true;
        }
        return false;
    }

}

//void Class::addSurveyResult(QString student_username, int result)
//{
//    this->surveyresult.insert(student_username, result);
//}

lesson Class::getLesson()
{
    return this->lesson;
}

QString Class::getTeacher()
{
    return this->teacher;
}

QString Class::getLocation()
{
    return this->location;
}

QString Class::getTime()
{
    return this->time;
}

day Class::getDay()
{
    return this-> day;
}

QMap<QString, float> Class::getList()
{
    return this->studentslist;
}

//QMap<QString, int> Class::getSurveyResult()
//{
//return this->surveyresult;
//}

lesson string_to_lesson(QString lesson_str)
{


            if(lesson_str=="BP") return lesson::BP;
            else if(lesson_str=="CHEMISTRY") return lesson::CHEMISTRY;
            else if(lesson_str=="DISCRETE") return lesson::DISCRETE;
            else if(lesson_str=="CALCULUS") return lesson::CALCULUS;
            else return lesson::PHYSICS;

}

day string_to_day(QString day_str)
{
    if(day_str=="SATURDAY") return day::SATURDAY;
    else if(day_str=="SUNDAY") return day::SUNDAY;
    else if(day_str=="MONDAY") return day::MONDAY;
    else if(day_str=="TUESDAY") return day::TUESDAY;
    else if(day_str=="WEDNESDAY") return day::WEDNESDAY;
    else if(day_str=="THURSDAY") return day::THURSDAY;
    else return day::FRIDAY;
}

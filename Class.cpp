#include "Class.h"
#include <iterator>
#include <fstream>
#include <string>

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
}

void Class::setTime(QString time)
{
    this->time = time;
}

void Class::setDay(enum day day)
{
    this->day = day;
}

void Class::addStudent(QString student_username)
{
    this->studentslist.insert(student_username, -1);
    this->number_of_students ++;
}

void Class::deleteStudent(QString student_username)
{
    this->studentslist.remove(student_username);
    this->number_of_students --;
}

void Class::setScore(QString student_username, float score)
{
    for(auto i = this->studentslist.begin() ; i != this->studentslist.end(); i++){
        if(i.key()==student_username){
            i.value()=score;
        }
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

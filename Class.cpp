#include "Class.h"
#include <iterator>

Class::Class()
{

}

Class::Class(enum lesson lesson, QString teacher)
{
    this->number_of_students = 0;
    this->lesson = lesson;
    this->teacher = teacher;
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

void Class::addSurveyResult(QString student_username, int result)
{
    this->surveyresult.insert(student_username, result);
}

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

QMap<QString, int> Class::getSurveyResult()
{
return this->surveyresult;
}

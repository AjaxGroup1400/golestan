#ifndef CLASS_H
#define CLASS_H

#include <QString>
#include <QMultiMap>
#include "dist/json/json.h"

enum lesson {
    CHEMISTRY,
    BP,
    DISCRETE,
    CALCULUS,
    PHYSICS
};

lesson string_to_lesson(QString lesson_str);

static QString lesson_enum_str[] =
        { "CHEMISTRY", "BP", "DISCRETE", "CALCULUS" , "PHYSICS"};

enum day{
    SATURDAY,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

day string_to_day(QString day_str);


static QString day_enum_str[] =
        { "SATURDAY", "SUNDAY", "MONDAY", "TUESDAY" , "WEDNESDAY", "THURSDAY", "FRIDAY"};


//QString LessonToString ( int enum_val )
//{
//    QString tmp(lesson_enum_str[enum_val]);
//    return tmp;
//}

//QString DayToString ( int enum_val )
//{
//    QString tmp(day_enum_str[enum_val]);
//    return tmp;
//}


class Class
{
public:

    Class(lesson lesson, QString teacher);
    Class(const Class &other);
    lesson getLesson();
    QString getTeacher();
    QString getLocation();
    QString getTime();
    day getDay();
    QMap < QString , float > getList();
//    QMap < QString , int > getSurveyResult();

    void setLocation(QString loc); //update file
    void setTime(QString time); //update file
    void setDay(day day); //update file
    void addStudent(QString student_username); //add record to file
    void deleteStudent(QString student_username); //check if student exists and delete record from file
    void setScore(QString student_username, float score); //update file
//    void addSurveyResult(QString student_username , int result); //update file

private:
    QString filePath;
    Json::Value dataHolder;
    Json::Reader dataReader;

    lesson lesson;
    QString teacher; //teacher username
    int number_of_students;

    QString location;
    QString time;
    day day;

    QMap < QString , float > studentslist;
//    QMap < QString , int > surveyresult;

};

#endif // CLASS_H

#ifndef TEACHERWEEKLYCALENDER_H
#define TEACHERWEEKLYCALENDER_H

#include "Weeklycalender.h"
#include <QString>

class TeacherWeeklycalender : public WeeklyCalender
{
public:
    TeacherWeeklycalender();

    virtual void show(QString username);
};

#endif // TEACHERWEEKLYCALENDER_H

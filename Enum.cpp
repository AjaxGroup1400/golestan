#include "Enum.h"

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

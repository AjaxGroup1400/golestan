#include "TeacherWeeklycalender.h"

#include <fstream>


using namespace std;

TeacherWeeklycalender::TeacherWeeklycalender()
{

}

void TeacherWeeklycalender::show(QString username)
{
    ifstream ifs(filePath.toStdString());

    if(dataReader.parse(ifs, dataHolder))
    {
        Json::Value teacherClasses = dataHolder["teachers"];

        for(int i = 0; i < teacherClasses.size(); i++)
        {
            if(teacherClasses[i]["username"] == username.toStdString())
            {
                Json::Value wantedTeacherClasses = teacherClasses[i]["classes"];

                for(int j = 0; j < wantedTeacherClasses.size(); j++)
                {
                    QVector<QString> classData;
                    classData.push_back(QString::fromStdString(wantedTeacherClasses[j]["name"].asString()));
                    classData.push_back(QString::fromStdString(wantedTeacherClasses[j]["day"].asString()));
                    classData.push_back(QString::fromStdString(wantedTeacherClasses[j]["time"].asString()));

                    calender.push_back(classData);
                }
            }
        }
    }
}

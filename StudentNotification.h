#ifndef STUDENTNOTIFICATION_H
#define STUDENTNOTIFICATION_H



#include"dist/json/json.h"
#include<QString>
#include<QList>
#include<QMap>


class StudentNotification
{
public:
    StudentNotification();

    void addAlert(QString title , QString description , QString sender , QList<QMap<QString , QString>> allowedStudent);
    QList<QMap<QString , QString>> getNotifications(QString studentUsername);




private:
    Json::Reader dataReader;
    Json::Value dataHolder ;
    QString filePath = "../data_resources/studentnotification.json";

};

#endif // STUDENTNOTIFICATION_H

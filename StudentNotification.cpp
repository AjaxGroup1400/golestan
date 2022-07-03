#include "StudentNotification.h"
#include<fstream>
#include<iostream>
using namespace std ;
#include<QMessageBox>
#include<QObject>
#include<QAbstractButton>

StudentNotification::StudentNotification()
{




}

void StudentNotification::addAlert(QString title, QString description, QString sender, QList<QMap<QString, QString> > allowedStudent)
{
    ifstream ifs(filePath.toStdString());
    if(dataReader.parse(ifs , dataHolder))
    {
        Json::Value newAlert ;
        newAlert["title"] = title.toStdString();
        newAlert["description"] = description.toStdString() ;
        newAlert["sender"] = sender.toStdString() ;


        Json::Value jsonAllowedStudents ;
        for(auto &student : allowedStudent)
        {
            Json::Value jsonStudent ;
            jsonStudent["username"] = student["username"].toStdString();
            jsonStudent["is_read"] = student["isRead"].toStdString();
            jsonAllowedStudents.append(jsonStudent);
        }
        newAlert["allowed_student"] = jsonAllowedStudents;
        dataHolder.append(newAlert);

        Json::StyledWriter writer ;
        ofstream ofwriter(filePath.toStdString());
        string finalPart = writer.write(dataHolder);
        ofwriter << finalPart;
        ofwriter.close();


        QMessageBox * done = new QMessageBox(QMessageBox::Icon::Information , "Sending assertion" , "The assertion was sent succesfuly" , QMessageBox::Button::Ok);
        done->show();
        QObject::connect(done , &QMessageBox::buttonClicked , done , &QMessageBox::deleteLater );
    }
    return ;
}

QList<QMap<QString, QString>> StudentNotification::getNotifications(QString studentUsername)
{
    ifstream ifs(filePath.toStdString());
    QList<QMap<QString , QString>> relatedAlerts ;

    if(dataReader.parse(ifs , dataHolder))
    {
        Json::Value wholeFile ;
        for(int i = 0 ; i < dataHolder.size() ; i++)
        {
            for(int j = 0 ; j < dataHolder[i]["allowed_student"].size() ; j++ )
            {
                if (dataHolder[i]["allowed_students"][j] == studentUsername.toStdString())
                {
                    QMap<QString , QString> relatedMessage;
                    relatedMessage[QString::fromStdString(dataHolder[i]["title"].asString())] = QString::fromStdString(dataHolder[i]["description"].asString()) ;
                    relatedAlerts.push_back(relatedMessage);
                }
            }
        }
        ifs.close();
        return relatedAlerts;
    }
    throw exception ("coulden't open the file \"../data_resources/studentnotification.json\"");

}

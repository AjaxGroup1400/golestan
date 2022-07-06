#include <QString>

#include "Filemanager.h"
#include "Auth.h"

// for hash class
#include <functional>

using std::hash;

Auth::Auth()
{
    return;
}

Auth::~Auth()
{
    return;
}

QString Auth::formUserData(QString username, QString password, QString firstname, QString lastname, QString nationalCode, QString phoneNumber, QString role)
{
    hash<QString> passHasher;

    QString mergedData = username + '\t' +
                         QString::number(passHasher(password)) + '\t' +
                         firstname + '\t' +
                         lastname + '\t' +
                         nationalCode + '\t' +
                         phoneNumber + '\t'
                         + role;

    return mergedData;
}

QString Auth::formUserData(QString teacherusername, QString lesson)
{
    QString mergedData = teacherusername + '\t' +
                         lesson;

    return mergedData;
}
/*
int Auth::validStudent(QString studentusername, QString lesson)
{
    FileManager usersFile;

    usersFile.create("teachers.txt");

    usersFile.loadData();

    auto& dataCopy = usersFile.getData();

    for(int i = 0; i < dataCopy.size(); i++)
    {
        QVector<QString> parsedUser = usersFile.parse(dataCopy.at(i));

        if(parsedUser.at(1) == studentusername && parsedUser.at(2) == lesson)
            return i;
    }

    return -1;
}
*/
int Auth::canLogin(QString username, QString password)
{
    FileManager usersFile;

    usersFile.create("users.txt");

    usersFile.loadData();

    auto& dataCopy = usersFile.getData();

    hash<QString> passHasher;

    for(int i = 0; i < dataCopy.size(); i++)
    {
        QVector<QString> parsedUser = usersFile.parse(dataCopy.at(i));

        if(parsedUser.at(0) == username && parsedUser.at(1) == QString::number(passHasher(password)))
            return i;
    }

    return -1;
}

int Auth::isHintValid(QString username, QString phoneNumber)
{
    FileManager usersFile;

    usersFile.create();

    usersFile.loadData();

    auto& dataCopy = usersFile.getData();

    for(int i = 0; i < dataCopy.size(); i++)
    {
        QVector<QString> parsedUser = usersFile.parse(dataCopy.at(i));

        // last element in parsed user is hint
        if(parsedUser.at(0) == username && parsedUser.at(5) == phoneNumber)
            return i;
    }

    return -1;
}




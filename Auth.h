#ifndef AUTH_H
#define AUTH_H

#include <QString>

class Auth
{
public:
    Auth();

    ~Auth();

    static QString formUserData(QString username, QString password, QString firstname, QString lastname, QString hint);

    static int canLogin(QString username, QString password);

    static int isHintValid(QString hint);
};

//FileManager file;

//file.loadData();

//file.apeend(Auth::formUserData("sdfsdf", "354654", "AMir", "", ""));

//file.write();

#endif // AUTH_H

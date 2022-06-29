#ifndef USER_H
#define USER_H

#include <QWidget>
#include<QString>


class User : public QWidget
{
    Q_OBJECT
public:
    explicit User(QWidget *parent = nullptr);

    void set_first_name(QString name);
    void set_last_name(QString name);
    void set_national_code(QString national);
    void set_phone_number (QString phone);
    void set_role(QString _role);
    void set_hint(QString _hint);
    void set_username(QString user);
    void set_password(QString pass);

    QString get_first_name();
    QString get_last_name();
    QString get_national_code();
    QString get_phone_number ();
    QString get_role();
    QString get_hint();
    QString get_username();
    QString get_password();

signals:

private:
    QString first_name ;
    QString last_name ;
    QString national_code ;
    QString phone_number ;
    QString role ;
    QString hint ;
    QString username ;
    QString password ;
};

#endif // USER_H

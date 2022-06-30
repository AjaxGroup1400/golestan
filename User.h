#ifndef USER_H
#define USER_H

#include <QWidget>
#include<QString>

#include"dist/json/json.h"


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

/*
 * #include<nlohmann/json.hpp>
 * #include<fstream>
 * #include<cstdio>    // for rename or delete
 *#include<iomnip>     // setw
 *
 *class Database
 *{
 *  public:
 *  void Insert(Book book);
 *  void Delete(long int PK);
 *  void Update(Book book);
 *  Book Read(long int PK);
 *
 *}
 *
 *json BookJs
 *
 *
 *ofstream wb(setExtention(std::to_string(book.primaryKey) , ".json")) ;
 *if (!wb)
 *  throw "Error" ;
 *wb << setw[4]  << BookJs ;     // saves the datas with 4 spaces
 *if (wb.bad())
 *  throw "Error";
 *wb.close();
 *
 *
 *
 *
 *json BookJs
 *ifstream rb(setExtention(std::to_string(PK) , ".json"));
 *if (!rb)
 *  throw "Error"
 *rb >> BookJs;
 *Book new book;
 *newbook.Name = BookJs["Name"].get<string>();
 *
 *string helper;
 *helper.c_str    // converting from string to char []
remove(helper.c_str);


* */










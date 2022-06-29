#include<QMessageBox>
#include<QAbstractButton>


#include "Teacher.h"
#include "ui_Teacher.h"
#include "Auth.h"
#include "Filemanager.h"
#include "User.h"
#include <QAbstractButton>
#include <QVector>
#include <QMultiMap>

Teacher::Teacher(QWidget *parent) :
    //QDialog(parent),
    ui(new Ui::Teacher)
{
    FileManager userFile;

    userFile.create("teacher.txt");

    userFile.loadData();

    for(const QString& item: userFile.getData()){
        auto parse = userFile.parse(item);

        if (parse[0] == this->get_username()){
            QMap <QString, float> studentscore;
            studentscore.insert(parse[2],parse[3].toFloat()) ;
            this->students.insert( parse[1] , studentscore ) ;
        }
    }

    //ui->setupUi(this);
}

Teacher::~Teacher()
{
    delete ui;
}

QMap<QString, float> Teacher::studentsList(QString classname)
{
    QMap <QString, float> classlist;

for (auto i=this->students.begin(); i!=this->students.end(); i++){
    auto j = i.value().begin();

    if (j.key() == classname){

        classlist.insert( i.key(), j.value() );
    }

    return classlist;
}

void Teacher::deletest(QString name , QString lesson)
{
    int index = Auth::validStudent(name , lesson);
//    if (newPass != confirmNewPass)
//    {
//        QMessageBox * confirmPassDoesntMatch = new QMessageBox(QMessageBox::Icon::Critical , "Error" , "field \"new password\" doesn't equal field \"confirm new password\"" , QMessageBox::Button::Ok);
//        confirmPassDoesntMatch->show();
//        connect(confirmPassDoesntMatch , &QMessageBox::buttonClicked , confirmPassDoesntMatch, &QMessageBox::deleteLater);
//        return;
//    }

    FileManager userFile;

    userFile.create("teacher.txt");

    userFile.loadData();


    userFile.deleteRecord(index);


    userFile.write();

    QMessageBox * studentdeleted = new QMessageBox(QMessageBox::Icon::Information, "Student deleted", "the student was deleted succesfuly", QMessageBox::Button::Ok);
//    studentdeleted->setParent(this);

    studentdeleted->show();

    QObject::connect(studentdeleted , &QMessageBox::buttonClicked , studentdeleted , &QMessageBox::deleteLater);

//    LoginPage* lg = new LoginPage;

//    connect(studentdeleted, &QMessageBox::buttonClicked, lg, &LoginPage::show);

    //    connect(studentdeleted, &QMessageBox::buttonClicked, this, &EntereNewPass::close);
}

void Teacher::sendingNotification(QString message , QString lesson , QList<QString> list)
{
    QString finalmessage = "Lesson" + lesson + "from" + this->get_first_name() + this->get_last_name() +": \n" + message;

    for (auto i = list.begin() ; i != list.end() ; i++ )
    {
//        QObject::connect (this, &Teacher::notificationSent, , )

    }
    emit (Teacher:: notificationSent(finalmessage) );

}


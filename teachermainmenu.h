#ifndef TEACHERMAINMENU_H
#define TEACHERMAINMENU_H


#include <QDialog>
#include <QList>
#include <QMultiMap>
#include <QString>
#include <QObject>
#include <QWidget>

#include"User.h"

namespace Ui {
class TeacherMainMenu  ;
}

class TeacherMainMenu : public User
{
    Q_OBJECT

public:
    explicit TeacherMainMenu(QWidget *parent = nullptr);
    ~TeacherMainMenu();
    QMap<QString, float> studentsList(QString classname);

    void deletest(QString name , QString lesson);
    void sendingNotification(QString message , QString lesson , QList<QString> list);

private slots:
    void on_pushButton_7_clicked();


    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::TeacherMainMenu *ui;

        QMultiMap < QString ,QMap<QString, float> > students;

signals:
    QString notificationSent(QString);

};

#endif // TEACHERMAINMENU_H

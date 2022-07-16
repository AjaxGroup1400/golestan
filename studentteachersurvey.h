#ifndef STUDENTTEACHERSURVEY_H
#define STUDENTTEACHERSURVEY_H

#include <QWidget>
#include "studentmainmenu.h"
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include <QGroupBox>
#include "loginpage.h"
#include "studentprofile.h"
#include "studentmessages.h"
#include "studentweeklyschedule.h"

namespace Ui {
class StudentTeacherSurvey;
}

class StudentTeacherSurvey : public QWidget
{
    Q_OBJECT

public:
    explicit StudentTeacherSurvey(QWidget *parent = nullptr);
    ~StudentTeacherSurvey();
private slots:
    void on_surveyBtn_clicked(QString nameOfClass);
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


    void on_backToMenu_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

public slots:
    QGroupBox* showTeachers();
private:
    Ui::StudentTeacherSurvey *ui;
};

#endif // STUDENTTEACHERSURVEY_H

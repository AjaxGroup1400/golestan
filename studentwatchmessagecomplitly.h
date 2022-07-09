#ifndef STUDENTWATCHMESSAGECOMPLITLY_H
#define STUDENTWATCHMESSAGECOMPLITLY_H

#include <QWidget>

#include"studentmainmenu.h"

namespace Ui {
class StudentWatchMessageComplitly;
}

class StudentWatchMessageComplitly : public QWidget
{
    Q_OBJECT

public:
    explicit StudentWatchMessageComplitly(StudentMainMenu * member , QWidget *parent = nullptr);
    ~StudentWatchMessageComplitly();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::StudentWatchMessageComplitly *ui;
    StudentMainMenu * mainmenu;
};

#endif // STUDENTWATCHMESSAGECOMPLITLY_H

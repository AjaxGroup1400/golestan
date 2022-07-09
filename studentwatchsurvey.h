#ifndef STUDENTWATCHSURVEY_H
#define STUDENTWATCHSURVEY_H

#include <QWidget>

namespace Ui {
class StudentWatchSurvey;
}

class StudentWatchSurvey : public QWidget
{
    Q_OBJECT

public:
    explicit StudentWatchSurvey(QWidget *parent = nullptr);
    ~StudentWatchSurvey();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::StudentWatchSurvey *ui;
};

#endif // STUDENTWATCHSURVEY_H

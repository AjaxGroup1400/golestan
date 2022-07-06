#ifndef STUDENTPROFILE_H
#define STUDENTPROFILE_H

#include <QWidget>

namespace Ui {
class StudentProfile;
}

class StudentProfile : public QWidget
{
    Q_OBJECT

public:
    explicit StudentProfile(QString username , QString password , QString firstname , QString lastname , QString nationlcode , QString phonenumber , QString role , QWidget *parent = nullptr);
    ~StudentProfile();

private slots:
    void on_chngNumber_clicked();

    void on_chngPass_clicked();

    void on_applychng_clicked();

    void on_applychng_2_clicked();

    void on_backToMenu_clicked();

private:
    Ui::StudentProfile *ui;
};

#endif // STUDENTPROFILE_H

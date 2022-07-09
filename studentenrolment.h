#ifndef STUDENTENROLMENT_H
#define STUDENTENROLMENT_H

#include <QWidget>
#include <QGroupBox>

namespace Ui {
class StudentEnrolment;
}

class StudentEnrolment : public QWidget
{
    Q_OBJECT

public:
    explicit StudentEnrolment(QWidget *parent = nullptr);
    ~StudentEnrolment();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_backToMenu_clicked();
public slots:
    QGroupBox* showLessons();
private:
    Ui::StudentEnrolment *ui;
};

#endif // STUDENTENROLMENT_H
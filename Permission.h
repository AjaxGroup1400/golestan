#ifndef PERMISSION_H
#define PERMISSION_H

#include <QObject>

class Permission : public QObject
{
    Q_OBJECT
public:
    explicit Permission(QObject *parent = nullptr);

        QString get_permission();
        bool is_allowed(QString value);

signals:

private:
    QString allowed_tasks ;

};

#endif // PERMISSION_H

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QFile>
#include <QString>
#include <QList>
#include <QVector>

class FileManager
{
private:
    QString dirPath = "../data_resources/";
    QString filename;
    QList<QString> data;

    void init();

public:
    FileManager();

    FileManager(QString dirPath);

    ~FileManager();

    const QString &getDirPath() const;

    void create(QString filename);

    void loadData();

    void write();

    void append(QString record);

    void deleteRecord(int index);

    QVector<QString> parse(QString str, char delimiter = '\t');

    QString getRecord(int index);
};

#endif // FILEMANAGER_H

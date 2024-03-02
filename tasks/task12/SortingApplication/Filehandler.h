#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <QString>
#include <QFile>

class FileHandler
{
public:
    FileHandler(const QString& fileName);
    QVector<int>& readArrayFromFile () const;
    void saveArrayToFile(const QVector<int> &data);
    ~FileHandler();
    QFile* getFile() const;
private:
    QFile *m_fileToSort;
    QString m_fileName;

};

#endif // FILEHANDLER_H

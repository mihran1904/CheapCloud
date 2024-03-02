#include "Filehandler.h"
#include <QTextStream>
#include <QRandomGenerator>
#include <QDateTime>
#include <QVector>
#include <QDir>
#include <QStandardPaths>
FileHandler::FileHandler(const QString &fileName) : m_fileName{fileName} {
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/cheapcloud/tasks/task12/SortingApplication/" + fileName;
    m_fileToSort = new QFile(filePath);

    if (m_fileToSort->exists()) {
        qWarning() << "File already exists.";
    } else {
        if (m_fileToSort->open(QIODevice::ReadWrite | QIODevice::Text)) {
            int random_num = 0;
            QTextStream out(m_fileToSort);

            int nums_count = 1000;
            int numsPerLine = 30;  // Adjust this value based on your preference

            for (int i = 0; i < nums_count; ++i) {
                random_num = QRandomGenerator::global()->bounded(100);
                out << random_num + i << ',';

                // Add a newline character after a certain number of elements
                if ((i + 1) % numsPerLine == 0) {
                    out << '\n';
                }
            }

            m_fileToSort->close();  // Close the file after writing
        } else {
            qWarning() << "Failed to open or create the File";
        }
    }

    // Reopen the file for reading
    if (m_fileToSort->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open the File for reading";
    }

}

QFile* FileHandler::getFile() const {
    return m_fileToSort;
}
QVector<int>& FileHandler::readArrayFromFile() const {
    if (!m_fileToSort->isOpen()) {
        qWarning() << "File is not open for reading.";
    }

    // Reset the file position to the beginning
    if (!m_fileToSort->seek(0)) {
        qWarning() << "Failed to seek to the beginning of the file.";
    }
    QTextStream in(m_fileToSort);
    QVector<int> *data = new QVector<int>();
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(',');
        int num;
        for (const QString &part : parts) {
            if (!part.isEmpty()) {
                bool ok;
                num = part.toInt(&ok);
                data->push_back(num);
            }
        }

    }
    return *data;
}

void FileHandler::saveArrayToFile(const QVector<int> &data) {
    if (!m_fileToSort->open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Failed to open the File for writing";
        return;
    }
    QTextStream out(m_fileToSort);
    for (int i = 0; i < data.size(); ++i) {
        out << data[i] << ',';
    }
    qDebug() << "nums written in file";
    m_fileToSort->close();
}

FileHandler::~FileHandler() {
    if (m_fileToSort->isOpen()) {
        m_fileToSort->close();
    }
    delete m_fileToSort;
}




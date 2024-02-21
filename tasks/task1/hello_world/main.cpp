#include <QCoreApplication>
#include <QTextStream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString str = "Hello World!";
    QTextStream out(stdout);
    out << str << Qt::endl;
    return a.exec();
}

#include <QCoreApplication>
#include <QTextStream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream out(stdout);
    int i_val = 3;
    double d_val = 3.14;
    float f_val = 2.24;
    char c_val = 'c';
    char str[] = "C style string";
    bool b_val = true;
    out << "this is int value: " << i_val
        << "\n this is float value: " << f_val
        << "\n this is double value: " << d_val
        << "\n this is char value: " << c_val
        << "\n this is bool value: " << b_val
        << "\n this is char[] value: ";
    out << str << Qt::endl;

    return a.exec();
}

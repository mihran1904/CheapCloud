#include <QCoreApplication>
#include <QTextStream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream out(stdout);
    int val = 5;
    int& val_r = val;
    out << " val before: " << val << Qt::endl;
    val_r = 2;
    out << " val after: " << val << Qt::endl;
    int* val_p = &val;
    int& val_r2 = *val_p;
    val_r2 = 4;
    out << " val_p: " << val_p << '\n' << " val_r2: " << val_r2 << Qt::endl;
    out << " val after second change: " << val << Qt::endl;
    out << " How you can see its have same addresses "
        << "\n address of val: " <<  &val
        << "\n address of val_r: " << &val_r << Qt::endl;
    return a.exec();
}

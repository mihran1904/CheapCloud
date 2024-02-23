#include <QCoreApplication>
#include <QTextStream>
int get_max(const int* arr,const int size) {
    int max = 0;
    for (int i = 0; i < size; ++i) {
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}
int get_min(const int* arr,const int size) {
    int min = 0;
    for (int i = 0; i < size; ++i) {
        if (min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}
int get_average(const int* arr,const int size) {
    int res = 0;
    for (int i = 0; i < size; ++i) {
        res += arr[i];
    }
    res = res / (size - 1);
    return res;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    const int size = 5;
    int arr[size] = {1,4,0,2,-2};
    QTextStream out(stdout);
    out <<" max value for arr: " << get_max(arr,size) << Qt::endl;
    out <<" min value for arr: " << get_min(arr,size) << Qt::endl;
    out <<" average value for arr: " << get_average(arr,size) << Qt::endl;

    QString str = "";
    str += " Hello";
    str += " World";
    out << str << Qt::endl;

    return a.exec();
}

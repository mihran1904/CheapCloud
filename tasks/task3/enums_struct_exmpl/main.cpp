#include <QCoreApplication>
#include <QTextStream>
#include <QDate>

enum Day_of_Week {
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
};

struct Date {
    Date(){
        m_date = QDate::currentDate();
        month = m_date.toString("MMMM");
        day = m_date.day();
        year = m_date.year();
    }
 int day;
 int year;
 QString month;
 private:
 QDate m_date;
};
void display_current_date() {
 Date curr_date;
 int date = QDate::currentDate().dayOfWeek();
 enum Day_of_Week day_of_week = static_cast<Day_of_Week>(date);
 QTextStream out(stdout);
 out << " day: " << curr_date.day
     << "\n month: " << curr_date.month
     << "\n year: " << curr_date.year
     << "\n day of week: " ;
 switch (day_of_week) {
 case 1: out << "Monday" << Qt::endl ; break;
 case 2: out << "Tuesday" << Qt::endl; break;
 case 3: out << "Wednesday" << Qt::endl; break;
 case 4: out << "Thursday" << Qt::endl; break;
 case 5: out << "Friday" << Qt::endl; break;
 case 6: out << "Saturday" << Qt::endl; break;
 case 7: out << "Sunday" << Qt::endl; break;
 default: out << -1 << Qt::endl;
 }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    display_current_date();
    return a.exec();
}

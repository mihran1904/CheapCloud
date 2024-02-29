#include "rectangel.h"
#include "myexception.h"
Rectangel::Rectangel(double height,double lenght) : m_height{height},m_lenght{lenght} {}

double Rectangel::calculate_area() {
    if (m_height < 1 || m_lenght < 1) {
        throw MyException("invalid value from rectangel!");
    }
    return m_height * m_lenght;
}

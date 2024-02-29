#include "circle.h"
#include "myexception.h"
Circle::Circle(double radius) : m_radius{radius} {}

double Circle::calculate_area() {
    if (m_radius < 1) {
        throw MyException("invalid value from circle!");
    }
    return m_radius * m_radius * 3.14;
}

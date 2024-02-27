#include "circle.h"

Circle::Circle(double radius) : m_radius{radius} {}

double Circle::calculate_area() {
    const double pi = 3.14;
    double res = pi * m_radius * m_radius;
    return res;
}

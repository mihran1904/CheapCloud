#include "circle.h"

Circle::Circle(double radius) : m_radius{radius} {}

double Circle::calculate_area() {
    return 3.14 * m_radius * m_radius;
}

#include "rectangle.h"

Rectangle::Rectangle(double height, double length) : m_height{height},m_length{length} {}

double Rectangle::calculate_area() {
    return m_height * m_length;
}

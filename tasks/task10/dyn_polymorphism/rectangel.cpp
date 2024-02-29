#include "rectangel.h"

Rectangel::Rectangel(double height,double length) :  m_height{height},m_length{length} {}

double Rectangel::calculate_area() {
    return m_height * m_length;
}

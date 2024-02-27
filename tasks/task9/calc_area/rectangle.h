#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(double height,double length);
    double calculate_area() override;
private:
    double m_length;
    double m_height;
};

#endif // RECTANGLE_H

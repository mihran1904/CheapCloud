#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle : public Shape
{
public:
    Circle(double radius);
    double calculate_area() override;
private:
    double m_radius;
};

#endif // CIRCLE_H

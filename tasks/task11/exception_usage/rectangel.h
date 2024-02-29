#ifndef RECTANGEL_H
#define RECTANGEL_H
#include "shape.h"

class Rectangel : public Shape
{
public:
    Rectangel(double height,double length);
    double calculate_area() override;
private:
    double m_height;
    double m_lenght;
};

#endif // RECTANGEL_H

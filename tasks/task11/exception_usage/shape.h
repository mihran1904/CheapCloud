#ifndef SHAPE_H
#define SHAPE_H
class Shape {
public:
    virtual double calculate_area() = 0;
    virtual ~Shape(){};
};

#endif // SHAPE_H

#pragma once
#include"Interpolation.h"
#include"Points.h"


class LinearInterpolation :public Interpolation {
protected:
    static double* xp, * yp;
public:
    LinearInterpolation() {};
    LinearInterpolation(int);
    ~LinearInterpolation() {
        delete xp;
        delete yp;
    }
    void SetNum(int);
    int linear(Points*);
    double get_int_x_at(int);
    double get_int_y_at(int);
    void write_to_file(Points*, std::string);
};




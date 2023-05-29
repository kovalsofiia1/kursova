#pragma once
#include"Interpolation.h"
#include"Points.h"

class CubicSplineInterpolation : public Interpolation {
protected:
    double* a, * b, * c, * d, * interpolated_x, * interpolated_y;
public:
    CubicSplineInterpolation() {}
    CubicSplineInterpolation(int);
    ~CubicSplineInterpolation() {
        delete a;
        delete b;
        delete c;
        delete d;
        delete interpolated_x;
        delete interpolated_y;
    }
    void SetNum(int);
    int build_splines(Points*);
    int interpolate(Points*);
    double get_int_x_at(int);
    double get_int_y_at(int);
    double get_a_at(int);
    double get_b_at(int);
    double get_c_at(int);
    double get_d_at(int);
    void write_to_file(Points*, std::string);

};


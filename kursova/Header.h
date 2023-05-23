#pragma once
#include<vector>
#include<iostream>
#include <string>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<fstream>

using namespace std;
using namespace System::Collections::Generic;


class Point {
    double x, y;
public:
    Point() {};

    Point(double, double);
    double GetX();
    double GetY();
};


class Points :public Point {
protected:
    int size;
    vector <Point> list;
public:
    Points() {};
    Points(int);
    int GetSize();
    void AddPoint(double, double);
    void RemovePoint(int);
    bool check_if_present(double);
    void sort_points();
    double GetX(int );
    double GetY(int );
    void Print_Points();
    void Clear_Points();
    Point& operator[](int);
};


class Interpolation
{
protected:
    int num_of_interpolated_points;
public:
    Interpolation() {};
    Interpolation(int);
    int GetNumOfP() const;
    void SetNum(int);
};

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
    void linear(Points*);
    double get_int_x_at(int);
    double get_int_y_at(int);
    void write_to_file(Points*, string);
};



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
    void build_splines(Points*);
    void interpolate(Points* );
    double get_int_x_at(int);
    double get_int_y_at(int);
    double get_a_at(int);
    double get_b_at(int);
    double get_c_at(int);
    double get_d_at(int);
    void write_to_file(Points*, string);

};


void find_Y_M(double&, double&, Points*);

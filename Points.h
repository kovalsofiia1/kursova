#pragma once
#include"Point.h"
#include<vector>
#include<iostream>

class Points :public Point {
protected:
    int size;
    std::vector<Point> list;
public:
    Points() {};
    Points(int);
    int GetSize();
    void AddPoint(double, double);
    void RemovePoint(int);
    bool check_if_present(double);
    void sort_points();
    double GetX(int);
    double GetY(int);
    void Print_Points();
    void Clear_Points();
    Point& operator[](int);
};


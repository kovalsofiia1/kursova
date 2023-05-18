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

    Point(double X, double Y) {
        x = X; y = Y;
    }
    double GetX() { return x; }
    double GetY() { return y; }
};


class Points :public Point {
protected:
    int size;
    vector <Point> list;
public:
    Points() {};
    Points(int size) {
        this->size = size;
    }

    int GetSize() {
        return list.size();
    }
    void Fill_Points(List < double >^ x, List<double>^ y) {
        for (int i = 0; i < x->Count; i++) {
            list.push_back(Point(x[i], y[i]));
        }
        sort_points();
    }
    void sort_points()
    {
        int i, j;
        double key, key1;
        for (i = 1; i < list.size(); i++)
        {
            key = list[i].GetX();
            key1 = list[i].GetY();
            j = i - 1;

            while (j >= 0 && list[j].GetX() > key)
            {
                list[j + 1] = Point(list[j].GetX(), list[j].GetY());
                j = j - 1;
            }
            list[j + 1] = Point(key, key1);
        }
    }

    void Print_Points() {
        for (int i = 0; i < list.size(); i++) {
            cout << "\nPoint " << i + 1 << " :" << endl;
            cout << "x= "; cout << list[i].GetX() << "  ";
            cout << "y= "; cout << list[i].GetY();
        }
    }
    Point& operator[](int i) {
        return list[i];
    }
};


class Interpolation
{
protected:
    int num_of_interpolated_points;
public:
    Interpolation() {};
    Interpolation(int num) {
        num_of_interpolated_points = num;
    }
    int GetNumOfP() const {
        return num_of_interpolated_points;
    }
    virtual void write_to_file(string filename) {}
};

class LinearInterpolation :public Interpolation {
protected:
    static double* xp, * yp;
public:
    LinearInterpolation() {};
    LinearInterpolation(int num);
    static void linear(Points(&dots), int p) {
        double step = (dots[dots.GetSize() - 1].GetX() - dots[0].GetX()) / (p - 1);
        cout << "\n" << step << endl;
        int j = 0;
        for (int i = 0; i < p; i++) {

            xp[i] = dots[0].GetX() + i * step;
            //cout<<xp[i]<<endl;
            while (xp[i] > dots[j].GetX() && xp[i] > dots[j + 1].GetX()) {
                j++;
            }
            yp[i] = dots[j].GetY() +
                ((dots[j + 1].GetY() - dots[j].GetY()) / (dots[j + 1].GetX() - dots[j].GetX())) *
                (xp[i] - dots[j].GetX());

            cout << "Interpolated value at " << xp[i] << " is " << yp[i] << endl;
        }
    }
    double get_int_x_at(int n) {
        return xp[n];
    }
    double get_int_y_at(int n) {
        return yp[n];
    }
    void write_to_file(Points(&dots), string name) {
        ofstream file;
        if (name.find(".txt", ios::app) == 0) {
            name += ".txt";
        }
        file.open(name);
        if (!file.is_open()) {
            cout << "Can't open file!";
            return;
        }
        file << "Linear Interpolation " << endl;
        for (int i = 0; i < dots.GetSize(); i++) {
            file << "Point " << i + 1 << ": (" << dots[i].GetX() << " ; " << dots[i].GetY() << " )" << endl;
        }
        file << "Interpolated points :" << endl;
        for (int i = 0; i < num_of_interpolated_points; i++) {
            file << "( " << xp[i] << " ; " << yp[i] << " )" << endl;
        }
        file.close();

    }
};
double* LinearInterpolation::xp = nullptr;
double* LinearInterpolation::yp = nullptr;

LinearInterpolation::LinearInterpolation(const int num) {
    num_of_interpolated_points = num;
    xp = new double[num];
    yp = new double[num];
}

class CubicSplineInterpolation : public Interpolation {
protected:
    double* a, * b, * c, * d, * interpolated_x, * interpolated_y;
public:
    CubicSplineInterpolation() {}
    CubicSplineInterpolation(int num) {
        num_of_interpolated_points = num;
        interpolated_x = new double[num_of_interpolated_points];
        interpolated_y = new double[num_of_interpolated_points];
    }
    void build_splines(Points(&dots)) {
        int n = dots.GetSize();
        a = new double[n];
        b = new double[n];
        c = new double[n];
        d = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = dots[i].GetY();
        }
        c[0] = 0;

        double* alpha = new double[n - 1];
        double* beta = new double[n - 1];
        double A, B, C, F, h_i, h_i1, z;
        alpha[0] = beta[0] = 0.;

        for (int i = 1; i < n - 1; ++i)
        {
            h_i = dots[i].GetX() - dots[i - 1].GetX();
            h_i1 = dots[i + 1].GetX() - dots[i].GetX();
            A = h_i;
            C = 2. * (h_i + h_i1);
            B = h_i1;
            F = 6. * ((dots[i + 1].GetY() - dots[i].GetY()) / h_i1 - (dots[i].GetY() - dots[i - 1].GetY()) / h_i);
            z = (A * alpha[i - 1] + C);
            alpha[i] = -B / z;
            beta[i] = (F - A * beta[i - 1]) / z;
        }

        c[n - 1] = 0;
        // Розв'язування системи методом прогонки
        for (int i = n - 2; i > 0; --i)
            c[i] = alpha[i] * c[i + 1] + beta[i];

        delete[] beta;
        delete[] alpha;

        for (int i = n - 1; i > 0; --i)
        {
            double h_i = dots[i].GetX() - dots[i - 1].GetX();
            d[i] = (c[i] - c[i - 1]) / h_i;
            b[i] = h_i * (2. * c[i] + c[i - 1]) / 6. + (dots[i].GetY() - dots[i - 1].GetY()) / h_i;
        }
        cout << endl;
        for (int i = 1; i < n; i++) {
            cout << setw(10) << a[i] << setw(10) << " " << b[i] << setw(10) << " " << c[i] / 2 << setw(10) << " " << d[i] / 6 << endl;
        }
    }

    void interpolate(Points(&dots)) {
        int p = num_of_interpolated_points;
        double step = (dots[dots.GetSize() - 1].GetX() - dots[0].GetX()) / (p - 1);
        cout << "\n" << step << endl;
        int j = 1;
        for (int i = 0; i < p; i++) {
            interpolated_x[i] = dots[0].GetX() + i * step;
            while (interpolated_x[i] > dots[j].GetX() /*&& interpolated_x[i]>dots[j+1].GetX()*/) {
                j++;
            }
            //cout<<j<<endl;
            double dx = interpolated_x[i] - dots[j].GetX();
            //cout<<dx<<endl;
            interpolated_y[i] = a[j] + b[j] * dx + c[j] / 2 * dx * dx + d[j] / 6 * dx * dx * dx;
            cout << "Interpolated value at " << interpolated_x[i] << " is " << interpolated_y[i] << endl;
        }

    }

    double get_int_x_at(int n) {
        return interpolated_x[n];
    }
    double get_int_y_at(int n) {
        return interpolated_y[n];
    }
    double get_a_at(int n) {
        return a[n];
    }
    double get_b_at(int n) {
        return b[n];
    }
    double get_c_at(int n) {
        return c[n];
    }
    double get_d_at(int n) {
        return d[n];
    }
    
    void write_to_file(Points(&dots), string name) {
        ofstream file;
        if (name.find(".txt", ios::app) == 0) {
            name += ".txt";
        }
        file.open(name);
        file << "\nCubic spline Interpolation " << endl;
        for (int i = 0; i < dots.GetSize(); i++) {
            file << "Point " << i + 1 << ": (" << dots[i].GetX() << " ; " << dots[i].GetY() << " )" << endl;
        }
        file << "Interpolated points :" << endl;
        for (int i = 0; i < num_of_interpolated_points; i++) {
            file << "( " << interpolated_x[i] << " ; " << interpolated_y[i] << " )" << endl;
        }
        file.close();

    }

};

double precision(double num, int n) {
    cout << num << endl;
    ostringstream oss;
    oss << setprecision(n) << fixed << num;
    double formatted = stod(oss.str());
    cout << formatted<<endl;
    return formatted;

}
void find_Y_M(double& min, double& max, Points& p) {
    min = 0; max = 0;
    for (int i = 0; i < p.GetSize(); i++) {
        if (p[i].GetY() > max) {
            max = p[i].GetY();
        }
        else if (p[i].GetY() < min) {
            min = p[i].GetY();
        }
    }
}


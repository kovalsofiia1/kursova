
#include"Cubic.h"
#include<fstream>
using namespace System::Windows::Forms;
CubicSplineInterpolation::CubicSplineInterpolation(int num) {
    num_of_interpolated_points = num;
    interpolated_x = new double[num_of_interpolated_points];
    interpolated_y = new double[num_of_interpolated_points];
}

void CubicSplineInterpolation::SetNum(int num) {
    num_of_interpolated_points = num;
    interpolated_x = new double[num_of_interpolated_points];
    interpolated_y = new double[num_of_interpolated_points];
}
int CubicSplineInterpolation::build_splines(Points* dots) {
    dots->sort_points();
    int count = 0;
    int n = dots->GetSize();
    a = new double[n];
    b = new double[n];
    c = new double[n];
    d = new double[n];
    for (int i = 0; i < n; i++) {
        count++;
        a[i] = dots->GetY(i);
    }
    c[0] = 0;

    double* alpha = new double[n - 1];
    double* beta = new double[n - 1];
    double A, B, C, F, h_i, h_i1, z;
    alpha[0] = beta[0] = 0.;

    for (int i = 1; i < n - 1; ++i)
    {
        count++;
        h_i = dots->GetX(i) - dots->GetX(i - 1);
        h_i1 = dots->GetX(i + 1) - dots->GetX(i);
        A = h_i;
        C = 2. * (h_i + h_i1);
        B = h_i1;
        F = 6. * ((dots->GetY(i + 1) - dots->GetY(i)) / h_i1 - (dots->GetY(i) - dots->GetY(i - 1)) / h_i);
        z = (A * alpha[i - 1] + C);
        alpha[i] = -B / z;
        beta[i] = (F - A * beta[i - 1]) / z;
    }

    c[n - 1] = 0;
    // Розв'язування системи методом прогонки
    for (int i = n - 2; i > 0; --i) {
        count++;
        c[i] = alpha[i] * c[i + 1] + beta[i];
    }
    delete[] beta;
    delete[] alpha;

    for (int i = n - 1; i > 0; --i)
    {
        count++;
        double h_i = dots->GetX(i) - dots->GetX(i - 1);
        d[i] = (c[i] - c[i - 1]) / h_i;
        b[i] = h_i * (2. * c[i] + c[i - 1]) / 6. + (dots->GetY(i) - dots->GetY(i - 1)) / h_i;
    }
    
    for (int i = 1; i < n; i++) {
        //std::cout << setw(10) << a[i] << setw(10) << " " << b[i] << setw(10) << " " << c[i] / 2 << setw(10) << " " << d[i] / 6 << endl;
    }
    return count;
}

int CubicSplineInterpolation::interpolate(Points* dots) {
    int count = build_splines(dots);
    int p = num_of_interpolated_points;
    double step = (dots->GetX(dots->GetSize() - 1) - dots->GetX(0)) / (p - 1);
    //cout << "\n" << step << endl;
    int j = 1;
    for (int i = 0; i < p; i++) {
        count++;
        interpolated_x[i] = dots->GetX(0) + i * step;
        while (interpolated_x[i] > dots->GetX(j)) {
            j++;
        }

        double dx = interpolated_x[i] - dots->GetX(j);

        interpolated_y[i] = a[j] + b[j] * dx + c[j] / 2 * dx * dx + d[j] / 6 * dx * dx * dx;
        //cout << "Interpolated value at " << interpolated_x[i] << " is " << interpolated_y[i] << endl;
    }
    return count;
}
double CubicSplineInterpolation::get_int_x_at(int n) {
    return interpolated_x[n];
}
double CubicSplineInterpolation::get_int_y_at(int n) {
    return interpolated_y[n];
}
double CubicSplineInterpolation::get_a_at(int n) {
    return a[n];
}
double CubicSplineInterpolation::get_b_at(int n) {
    return b[n];
}
double CubicSplineInterpolation::get_c_at(int n) {
    return c[n];
}
double CubicSplineInterpolation::get_d_at(int n) {
    return d[n];
}

void CubicSplineInterpolation::write_to_file(Points* dots, std::string name) {
    std::ofstream file;
    if (name.find(".txt", std::ios::app) == -1) {
        name += ".txt";
    }
    file.open(name, std::ios::app);
    if (!file.is_open()) {
        MessageBox::Show("Can't open file!");
    }
    else {
        file << "\nCubic spline Interpolation " << std::endl;
        for (int i = 0; i < dots->GetSize(); i++) {
            file << "Point " << i + 1 << ": (" << dots->GetX(i) << " ; " << dots->GetY(i) << " )" << std::endl;
        }
        file << "Interpolated points :" << std::endl;
        for (int i = 0; i < num_of_interpolated_points; i++) {
            file << "( " << interpolated_x[i] << " ; " << interpolated_y[i] << " )" << std::endl;
        }
        file << "Cubic splines :" << std::endl;
        int n = 10000;
        for (int i = 1; i < dots->GetSize(); i++) {
            double dd = round((d[i] / 6) * n) / n;
            double cc = round(c[i] / 2 * n) / n;
            double bb = round(b[i] * n) / n;
            double aa = round(a[i] * n) / n;
            double x = dots->GetX(i);
            file << "S" << i << "(x) = " << dd << " *(x - " << x << ")^3 + " << cc << " *(x - " << x << ")^2 + " << bb << " *(x - " << x << ") + " << aa << std::endl;
        }
        file.close();
    }
}

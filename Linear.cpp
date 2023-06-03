#include"Linear.h"
#include<fstream>
using namespace System::Windows::Forms;
LinearInterpolation::LinearInterpolation(const int num) {
    num_of_interpolated_points = num;
    xp = new double[num];
    yp = new double[num];
}
double* LinearInterpolation::xp = nullptr;
double* LinearInterpolation::yp = nullptr;

void LinearInterpolation::SetNum(int num) {
    num_of_interpolated_points = num;
    xp = new double[num];
    yp = new double[num];
}

int LinearInterpolation::linear(Points* dots) {
    int count = 0;
    dots->sort_points();
    int p = num_of_interpolated_points;
    double step = (dots->GetX(dots->GetSize() - 1) - dots->GetX(0)) / (p - 1);
    
    int j = 0;
    for (int i = 0; i < p; i++) {
        count++;
        xp[i] = dots->GetX(0) + i * step;
        while (xp[i] > dots->GetX(j) && xp[i] > dots->GetX(j + 1)) {
            j++;
        }
        yp[i] = dots->GetY(j) +
            ((dots->GetY(j + 1) - dots->GetY(j)) / (dots->GetX(j + 1) - dots->GetX(j))) *
            (xp[i] - dots->GetX(j));

 
    }
    return count;
}

double LinearInterpolation::get_int_x_at(int n) {
    return xp[n];
}
double LinearInterpolation::get_int_y_at(int n) {
    return yp[n];
}
void LinearInterpolation::write_to_file(Points* dots, std::string name) {
    std::ofstream file;
    if (name.find(".txt", std::ios::app) == -1) {
        name += ".txt";
    }
    file.open(name);
    if (!file.is_open()) {
        MessageBox::Show("Can't open file!");
        
    }
    else {

        file << "Linear Interpolation " << std::endl;
        for (int i = 0; i < dots->GetSize(); i++) {
            file << "Point " << i + 1 << ": (" << dots->GetX(i) << " ; " << dots->GetY(i) << " )" << std::endl;
        }
        file << "Interpolated points :" << std::endl;
        for (int i = 0; i < num_of_interpolated_points; i++) {
            file << "( " << xp[i] << " ; " << yp[i] << " )" << std::endl;
        }
        file << "Linear functions: " << std::endl;
        for (int i = 0; i < dots->GetSize() - 1; i++) {
            file << "f" << i << "(x) = " << dots->GetY(i) << " + ((" << dots->GetY(i + 1) << " - " << dots->GetY(i) << ") / ( " << dots->GetX(i + 1) << " - " << dots->GetX(i) << ")) * ( x - " << dots->GetX(i) << " ) ;" << std::endl;

        }
        file.close();
    }
}


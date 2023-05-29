#include"Interpolation.h"

Interpolation::Interpolation(int num) {
    num_of_interpolated_points = num;
}
int Interpolation::GetNumOfP() const {
    return num_of_interpolated_points;
}

#pragma once

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

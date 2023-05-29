#include"Points.h"


Points::Points(int size) {
    this->size = size;
}

int Points::GetSize() {
    return list.size();
}

void Points::AddPoint(double xx, double yy) {
    list.push_back(Point(xx, yy));
    list.shrink_to_fit();
    //sort_points();
}

void Points::RemovePoint(int i) {
    list.erase(list.begin() + i);
    list.shrink_to_fit();
}

bool Points::check_if_present(double xx) {
    for (auto l : list) {
        if (xx == l.GetX()) {
            return true;
        }
    }

    return false;
}

void Points::sort_points()
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
double Points::GetX(int i) {
    return list[i].GetX();
}
double Points::GetY(int i) {
    return list[i].GetY();
}
void Points::Print_Points() {
    for (int i = 0; i < list.size(); i++) {
        std::cout << "\nPoint " << i + 1 << " :" << std::endl;
        std::cout << "x= "; std::cout << list[i].GetX() << "  ";
        std::cout << "y= "; std::cout << list[i].GetY();
    }
}
void Points::Clear_Points() {
    list.clear();
    list.shrink_to_fit();
}
Point& Points::operator[](int i) {
    return list[i];
}
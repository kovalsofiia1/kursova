#include"Header.h"

void find_Y_M(double& min, double& max, Points* p) {
    min = p->GetY(0); max = p->GetY(0);
    for (int i = 0; i < p->GetSize(); i++) {
        if (p->GetY(i) > max) {
            max = p->GetY(i);
        }
        if (p->GetY(i) < min) {
            min = p->GetY(i);
        }
    }
    
}


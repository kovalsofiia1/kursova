#include <iostream>
#include <cmath>
#include<cstring>
#include <sstream>
#include<vector>
using namespace std;
class LinearInterpolation;
class Points;
bool is_double(string& s,double &d);
class Point{
    double x,y;
public:
    Point(){};

    Point(double X,double Y){
        x=X;y=Y;
    }
    double GetX(){return x;}
    double GetY(){return y;}
};


class Points:public Point {
protected:
    int size;
    vector <Point> list;
public:
    Points(){};
    Points(int size) {
        //this->list = new Point[size];
        this->size = size;
    }
    //~Points() {
     //   delete[] list;
    //}
    int GetSize(){
        return list.size();
    }
    void Fill_Points(){
    //void Fill_Points(int size){
        int choice=1;
        int i=0;
        while(choice==1){
            string X, Y;
            double xx,yy;
            cout<<"\nPoint "<<i+1<<" :"<<endl;
            int error=0;
            while(error==0){
                cout<<"x= "; cin>>X;
                error= is_double(X,xx);
                if(error==0){
                    cout<<"Wrong input!"<<endl;
                }
            }
            error=0;
            while(error==0){
                cout<<"y= "; cin>>Y;
                error= is_double(Y,yy);
                if(error==0){
                    cout<<"Wrong input!"<<endl;
                }
            }
            list.push_back(Point(xx,yy));
            cout<<"Another point? "<<endl;
            cin>>choice;
            i++;
        }
        sort_points();
    }
    void sort_points(){
        for(int i=1; i<list.size(); i++){
            for(int j=1; j<list.size()-i+1; j++){
                if(list[i-1].GetX()>list[i].GetX()){
                    double t_x,t_y,t_x1,t_y1;
                    t_x=list[i-1].GetX();
                    t_y=list[i-1].GetY();
                    t_x1=list[i].GetX();
                    t_y1=list[i].GetY();
                    list[i-1]=Point(t_x1,t_y1);
                    list[i]=Point(t_x,t_y);

                }
            }
        }
    }
    void Print_Points(){
        for(int i=0;i<list.size(); i++){
            cout<<"\nPoint "<<i+1<<" :"<<endl;
            cout<<"x= "; cout<<list[i].GetX()<<"  ";
            cout<<"y= "; cout<<list[i].GetY();
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
    Interpolation()=default;
    void InterpolationS(int num){
        num_of_interpolated_points=num;
    }
    int GetNumOfP() const{
        return num_of_interpolated_points;
    }
};

class LinearInterpolation:public Interpolation{
protected:
    static double *xp,*yp;
public:
    LinearInterpolation();
    LinearInterpolation(int num);
    static void linear(Points (&dots),int p){
        double step=(dots[dots.GetSize()-1].GetX()-dots[0].GetX())/(p-1);
        cout<<"\n"<<step<<endl;
        int j=0;
        for (int i = 0; i < p; i++) {

            xp[i] = dots[0].GetX()+i*step;
            //cout<<xp[i]<<endl;
            while(xp[i]>dots[j].GetX() && xp[i]>dots[j+1].GetX()){
                j++;
            }
            yp[i] = dots[j].GetY() +
                        ((dots[j + 1].GetY() - dots[j].GetY()) / (dots[j + 1].GetX() - dots[j].GetX())) *
                        (xp[i] - dots[j].GetX());

            cout << "Interpolated value at " << xp[i] << " is " << yp[i] << endl;
        }
    }
};
double* LinearInterpolation::xp = nullptr;
double* LinearInterpolation::yp = nullptr;

LinearInterpolation::LinearInterpolation(int num) {
    InterpolationS(num);
    xp=new double[num];
    yp=new double[num];
}

class CubicSplineInterpolation: public Interpolation{
protected:
    double *a,*b,*c,*d,*interpolated_x,*interpolated_y;
public:
    CubicSplineInterpolation(int num){
        InterpolationS(num);
        interpolated_x=new double[num_of_interpolated_points];
        interpolated_y=new double[num_of_interpolated_points];
    }
    void build_splines(Points (&dots)){
        int n=dots.GetSize();
        a=new double[n];
        b=new double[n];
        c=new double[n];
        d=new double[n];
        for(int i=0; i<n;i++){
            a[i]=dots[i].GetY();
        }
        c[0]=0;

        double *alpha = new double[n - 1];
        double *beta = new double[n - 1];
        double A, B, C, F, h_i,h_i1, z;
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

        c[n-1] =0;
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
        cout<<endl;
        for(int i=1; i<n;i++){
            cout<<a[i]<<" "<<b[i]<<" "<<c[i]/2<<" "<<d[i]/6<<endl;
        }
    }

    void interpolate(Points (&dots),int p){
        double step=(dots[dots.GetSize()-1].GetX()-dots[0].GetX())/(p-1);
        cout<<"\n"<<step<<endl;
        int j=1;
        for(int i=0;i<p;i++){
            interpolated_x[i]=dots[0].GetX()+i*step;
            while(interpolated_x[i]>dots[j].GetX() /*&& interpolated_x[i]>dots[j+1].GetX()*/){
                j++;
            }
            //cout<<j<<endl;
            double dx=interpolated_x[i]-dots[j].GetX();
            //cout<<dx<<endl;
            interpolated_y[i]=a[j]+b[j]*dx+c[j]/2*dx*dx+d[j]/6*dx*dx*dx;
            cout << "Interpolated value at " << interpolated_x[i] << " is " << interpolated_y[i] << endl;
        }

    }

};


bool is_double(string& s,double &d)
{
    istringstream iss(s);
    //double d;
    return iss >> d >> ws && iss.eof();
}


int main() {
    
    Points dots;
    dots.Fill_Points();
    dots.Print_Points();
    LinearInterpolation inter(10);
    inter.linear(dots,inter.GetNumOfP());
    cout<<"\nCubic Spline Interpolation"<<endl;
    CubicSplineInterpolation cubic(10);
    cubic.build_splines(dots);
    cubic.interpolate(dots,cubic.GetNumOfP());


}
/*
    string s;
    double d;
    cin>>s;
    if(is_double(s,d)){
        cout<<d;
    }else{
        cout<<2;
    }
     */

/* int n = 4;
    Points dots(n);
    dots.Fill_Points(n);
    dots.Print_Points(n);
    cout<<endl;
    for (int i = 0; i < n-1; i++) {
        int num = 5;
        double xp = dots[i].GetX();
        double step = (dots[i + 1].GetX() - dots[i].GetX()) / num;
        for (int j = 0; j < num; j++) {
            xp += step;

            double yp = dots[i].GetY() +
                        ((dots[i + 1].GetY() - dots[i].GetY()) / (dots[i + 1].GetX() - dots[i].GetX())) *
                        (xp - dots[i].GetX());


            cout << "Interpolated value at " << xp << " is " << yp << endl;
        }

    }*/
/*Point p1(3,6),p2(7,9);

//лінійна інтерполяція на 5 проміжних точок
int num=5;
double xp=p1.GetX();
double step=(p2.GetX()-p1.GetX())/num;
for(int i=0; i<num; i++){
    xp+=step;

    double yp = p1.GetY() + ((p2.GetY()-p1.GetY())/(p2.GetX()-p1.GetX())) * (xp - p1.GetX());


    cout<<"Interpolated value at "<< xp<<" is "<< yp<<endl;
}*/
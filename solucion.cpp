#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void resolver();

int main(){
    
    resolver();
}

void resolver() {
    
    ofstream outfile;
    outfile.open("datos.dat");
    
    double epsilon = 1.0;
    double deltaT= 0.01;
    double deltaX = 0.01;
    double t=0.01;
    double tmax = 2;
    double xmax = 1;
    
    float u[101][2];
    
    for(int ix=0; ix<101;i++) {
        u[ix][0] = 0.05*sin(ix*dx*0.05/M_PI/2)
    }
    
    while(t<=tmax)  {
        u[0][1] = 0;
        u[0][2] = 0;
        u[100][1] = 0;
        u[100][2] = 0;
        for(int ix=1; ix < 100; ix++) {
            
            double a = (epsilon/4)*(u[ix+1][0]*u[ix+1][0]-u[ix-1][0]*u[ix-1][0]);
            double b = (epsilon*epsilon/8)*((u[ix+1][0]-u[ix][0])*(u[ix+1][0]*u[ix+1][0]-u[ix][0]*u[ix][0])-(u[ix+1][0]-u[ix-1][0])*(u[ix+1][0]*u[ix+1][0]-u[ix-1][0]*u[ix-1][0]));
            u[ix][1] = u[ix][0] - a + b;
            
        }
        t+=dt;
    }
    
    
    
    outfile.close();
    
}
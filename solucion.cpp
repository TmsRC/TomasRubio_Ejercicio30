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
    double dt= 0.01;
    double dx = 0.01;
    double t=0.01;
    double tmax = 2;
    double xmax = 1;
    
    double u[101][2];
    
    for(int ix=0; ix<101;ix++) {
        u[ix][0] = 0.05*sin(ix*dx*2*M_PI/0.5);
        outfile << u[ix][0] << " ";
    }
    outfile << endl;
    
    while(t<=tmax)  {
        u[0][1] = 0;
        u[100][1] = 0;
        
        for(int ix=1; ix < 100; ix++) {
            
            double a = (epsilon/4)*(u[ix+1][0]*u[ix+1][0]-u[ix-1][0]*u[ix-1][0]);
            double b = (epsilon*epsilon/8)*((u[ix+1][0]-u[ix][0])*(u[ix+1][0]*u[ix+1][0]-u[ix][0]*u[ix][0])-(u[ix+1][0]-u[ix-1][0])*(u[ix+1][0]*u[ix+1][0]-u[ix-1][0]*u[ix-1][0]));
            u[ix][1] = u[ix][0] - a + b;
            
        }
        
        for(int ix=0; ix < 101; ix++) {
            u[ix][0] = u[ix][1];
            outfile << u[ix][0] << " ";
        }
        outfile << endl;
        
        t+=dt;
    }
    
    
    
    outfile.close();
    
}
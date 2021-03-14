// CSC 123
// Assignment: Lab #4
// File Name: lab4.cpp
// Author: David Liljewall
// Last Modified: 3/2/2020

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;


/// FUNCTION DECLARATIONS ///
void calc_distance(double xo, double yo, double xf, double yf);
void rand_number(int number, int upper_limit);
void unit_circle(int n_point);


int main(){
// 1. Calculate distance between two points in 2D space
// 2. Display the (x,y) location of the number of points you decide to evenly place along unit circle
// 3. Generate random numbers between 1 and limit (set by user). Show: min value, max value, average value
// 4. Exit program option
    int option;

    do{
        cout << "1) Calculate Distance Between Points" << endl;
        cout << "2) Points long a unit circle" << endl;
        cout << "3) Generate Random Numbers" << endl;
        cout << "4) Exit" << endl;
        cout << "Enter your option: " << endl;
        cin >> option;

        if(option == 1){
        //calculate distance between two points entered by user, print result
            double xo, yo, xf, yf;
            cout << "Enter xo: " << endl;
            cin >> xo;
            cout << "Enter yo: " << endl;
            cin >> yo;
            cout << "Enter xf: " << endl;
            cin >> xf;
            cout << "Enter yf: " << endl;
            cin >> yf;
            
            //function call
            calc_distance(xo, yo, xf, yf);
        }

        if(option == 2){
        //display (x,y) along unit circle based on user-defined # of points
            int npoint;
            cout << "Please enter the integer # of points along the unit circle you want: " << endl;
            cin >> npoint;

            //function call
            unit_circle(npoint);
        }

        if(option == 3){
        //display list of random integers
            int n_rand, maximum;
            cout << "Enter number of random integers to generate, from 1 to 100: " << endl;
            cin >> n_rand;
            cout << "Enter the upper limit to generate, from 1 to 100: " << endl;
            cin >> maximum;
            cout << endl << endl;

            //function call
            rand_number(n_rand, maximum);
        }
    }
    while(option < 4);
}


/// FUNCTION DEFINITIONS ///
void calc_distance(double xo, double yo, double xf, double yf){
//calculates hypotenuse between two user defined points

    double distance = sqrt(pow((xf - xo), 2) + pow((yf - yo), 2));
    cout << "Distance between point " << "(" << xo << ","
    << yo << ")" << "and " << "(" << xf << "," << yf
    << ") is : " << distance << endl << endl;
}

void unit_circle(int n_point){
//construct unit cirlce in coordinates x and y
    
    const double PI = 3.141592653589793238463;  

    double angle, x, y;
    for(int i = 0; i < n_point; i++){
        angle = i * 2*PI*(1 / double(n_point)); //angles walk around unit circle.
        //NOTE: must cast n_point to a double, otherwise 1/n_point becomes an int, since
        //n_point is an integer. this will cause angle --> 0 and not change!!
        x = cos(angle);
        y = sin(angle);
        
        cout << endl << "Angle (degrees): " << angle*(180/PI) << endl;
        cout << "(" << x << "," << y << ")" << endl << endl;
    }
}

void rand_number(int number, int upper_limit){
//generates list of random integers

    int rand_int;
    srand(unsigned(time(0))); //start the seed for random number generator

    for(int i = 0; i < number; i++){
        rand_int = (rand() % upper_limit) + 1; //generates random int 0 - upper_limit
        cout << rand_int << endl << endl;
    }
}

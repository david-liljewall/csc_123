// CSC 123
// Assignment: Lab #4
// File Name: lab4.cpp
// Author: David Liljewall
// Last Modified: 2/29/2020

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// Function declarations:
double calc_distance(double d, double x1, double y1, double x2, double y2);
double unit_circle(int npoint, double angle[], double x[], double y[]);
int randnumber(int number, int maximum, int max_value, int min_value, int average);

int main(){
// 1. Calculate distance between two points in 2D space
// 2. Display the (x,y) location of the number of points you decide to evenly place along unit circle
// 3. Generate random numbers between 1 and limit (set by user). Show: min value, max value, average value
// 4. Exit program option
    
    int menu_option;

    do{
        cout << "1) Calculate Distance Between Points" << endl;
        cout << "2) Points long a unit circle" << endl;
        cout << "3) Generate Random Numbers" << endl;
        cout << "4) Exit" << endl;
        cout << "Enter your option: " << endl;
        cin >> menu_option;

        if(menu_option == 1){
            //distance
            double xo, yo, xf, yf, distance;

            cout << "Enter xo: " << endl;
            cin >> xo;
            cout << "Enter yo: " << endl;
            cin >> yo;
            cout << "Enter xf: " << endl;
            cin >> xf;
            cout << "Enter yf: " << endl;
            cin >> yf;
            
            //function invocation
            distance = calc_distance(distance, xo, yo, xf, yf);
            cout << "Distance between point" << "(" << xo << ","
            << yo << ")" << "and " << "(" << xf << "," << yf
            << ") is : " << distance << endl << endl;

        }

        else if(menu_option == 2){
            //unit circle
            int npoint;
            double theta[0], X[0], Y[0];


            cout << "(X, Y): " << endl;
            cout << "Enter the number of points along the circle: " << endl;
            cin >> npoint;
            
            //function invocation
            unit_circle(npoint, theta, X, Y);
            
            //print points along the unit circle that were put into array form in function
            for(int j = 0; j <= npoint; j++){
                cout << endl << "(" << X[j] << "," << Y[j] << ")" << endl;
            }

        }

        else if(menu_option == 3){
            //random number genrator
            int n_rand, limit;
            int min_value, max_value, average;
            int random_integer[0];
            
            cout << "Enter number of random integerse to generate, from 1 to 100: " << endl;
            cin >> n_rand;
            cout << "Enter the upper limit to generate, from 1 to 100: " << endl;
            cin >> limit;
            cout << endl << endl;
            
            //function invocation
            randnumber(n_rand, limit, max_value, min_value, average);
            cout << "Min value: " << min_value << endl;
            cout << "Max value: " << max_value << endl;
            cout << "Average: " << average << endl;
           
            
        }
    }
while(menu_option < 4);

}

// ------------ FUNCTION DEFINITIONS --------------- //
double calc_distance(double d, double x1, double y1, double x2, double y2){

    d = abs(sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2)));
    return d;
   

}

double unit_circle(int npoint, double angle[], double x[], double y[]){
    
    const double PI = 3.141592653589793238463;
    //construct unit circle coordinates in X and Y

    //calculates and prints X,Y coordinates based on npoint. Loops till npoint iterations reached
    int n = 0;
    angle[n] = 0;
    x[n] = cos(angle[n]), y[n] = sin(angle[n]);
    for(n = 1; n <= npoint; n++){
        angle[n] = angle[n] + 2*PI*(1/npoint); 
        x[n] = cos(angle[n]);
        y[n] = sin(angle[n]);
    }

    return angle[n], x[n], y[n];
}

int randnumber(int number, int maximum, int max, int min, int ave){
    int random_integer[0];
    //generates random number array 
    srand(time(0)); //start the seed for random number generator 
    for(int i = 0; i <= number; i++){
        //NOTE: if srand() was declared within the loop, the seed for the rand 
        //generator would stay the same each loop.
        random_integer[i] = (rand() % maximum) + 1; //generates rand in range 1 to maximum
        cout << random_integer[i] << endl;
    }
    
    //calculates max
    max = random_integer[0]; //initialize
    for(int k = 1; k < number; k++){
        if(random_integer[k] > max){
            max = random_integer[k];
        }
    }

    //calculates min
    min = random_integer[0]; //initalize
    for(int k = 1; k < number; k++){
        if(random_integer[k] < max){
            min = random_integer[k];
        }
    }

    ave = 0.5 * (min + max);

    return min, max, ave;

  
}

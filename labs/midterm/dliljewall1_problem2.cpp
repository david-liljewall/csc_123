// CSC 123
// Assignment: Midterm Exam, Problem 2
// File Name: dliljewall1_problem2.cpp
// Author: David Liljewall
// Last Modified: 3/25/2020

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;


/// ----- CONSTANT PARAMETERS ----- ///
const double PI  = 3.141592653589793238463;

/// ----- FUNCTION DECLARATIONS ----- ///
void initialize_screen();
//Separates current output from 
//the output of the previously run program. 

double get_sphere_volume(double radius);
//Returns a double value which is the volume of the sphere

double get_cylinder_volume(double radius, double height);
//Returns a double value which is the volume of the cylinder

double get_cone_volume(double radius, double height);
//Returns a double value which is the volume of the cone

double get_composite_volume(double radius, double height);
//Returns a double value which is the volume of the object

double get_composite_volume(double radius, double c_height, double t_height);
//Returns a double value which is the volume of the object (Spike of Doom!)



/// ----- MAIN CODE BODY ----- ///
int main(){
    
    initialize_screen();

    //Menu Prompt Implementation:
    int option;
    do{
        cout << endl << "== Menu: Volumes ==" << endl << endl
        << "Note: All units are SI (m, m^2, m^3, etc.)" << endl
        << "1. - Sphere" << endl
        << "2. - Cylinder" << endl
        << "3. - Cone" << endl
        << "4. - EC: Composite Shape 1: Capsule" << endl
        << "5. - EC: Composite Shape 2: Spike of Doom!" << endl
        << "6. - Exit" << endl;
        cout << "Enter your option: " << endl;
        cin >> option;
        cout << endl;

        switch(option){
            case 1:{
                double r;
                double sphere_volume;
                cout << "Enter a radius: " << endl;
                cin >> r;
                sphere_volume = get_sphere_volume(r);
                cout << "Sphere volume: " << sphere_volume 
                << "[m^3]" << endl << endl;
                break;
            }
            case 2:{
                double r, h;
                double cylinder_volume;
                cout << "Enter a radius: " << endl;
                cin >> r;
                cout << "Enter a height: " << endl;
                cin >> h;
                cylinder_volume = get_cylinder_volume(r, h);
                cout << "Cylinder Volume: " << cylinder_volume 
                << "[m^3]" << endl << endl;
                break;
            }
            case 3:{
                double r, h;
                double cone_volume;
                cout << "Enter a radius: " << endl;
                cin >> r;
                cout << "Enter a height: " << endl;
                cin >> h;
                cone_volume = get_cone_volume(r, h);
                cout << "Cone Volume: " << cone_volume 
                << "[m^3]" << endl << endl;
                break;
            }
            case 4:{
                double r, h;
                double composite_volume;
                cout << "Enter the capsule radius: " << endl;
                cin >> r;
                cout << "Enter the height o middle section: " << endl;
                cin >> h;
                composite_volume = get_composite_volume(r, h);
                cout << "Composite Volume: " << composite_volume
                << "[m^3]" << endl << endl;
                break;
            }
            case 5:{
                double r, c, t;
                double composite_volume;
                cout << "Enter radius of the main body of the spike: " << endl;
                cin >> r;
                cout << "Enter length of the main body of the spike: " << endl;
                cin >> c;
                cout << "Enter heigh of one of the tips at the end (both have same height): " << endl;
                cin >> t;
                composite_volume = get_composite_volume(r, c, t);
                cout << "Composite VOlume: " << composite_volume
                << "[m^3]" << endl << endl;
                break;
            }
            case 6:{
                goto EXIT_PROGRAM;
                break;
            }
        }


    } while(option < 6);
    EXIT_PROGRAM: cout << "Program Exited -- " << endl << endl;    
}

/// ----- FUNCTION DEFINITIONS ----- ///
void initialize_screen(){
    cout << endl;
}

double get_sphere_volume(double radius){
    
    double sphere_volume = (4.0/3)*PI*pow(radius, 3);
    return sphere_volume;
}

double get_cylinder_volume(double radius, double height){

    double cylinder_volume = PI*pow(radius, 2)*height;
    return cylinder_volume;
}

double get_cone_volume(double radius, double height){

    double cone_volume = (1.0/3)*PI*pow(radius, 2)*height;
    return cone_volume;
}

double get_composite_volume(double radius, double height){

    double composite_volume = (PI*pow(radius, 2)*height) + 2*((0.5)*(4.0/3)*PI*pow(radius, 3)); 
    return composite_volume;
}

double get_composite_volume(double radius, double c_height, double t_height){

    double composite_volume = (PI*pow(radius, 2)*c_height) + 2*((1.0/3)*PI*pow(radius, 2)*t_height); 
    return composite_volume;
}






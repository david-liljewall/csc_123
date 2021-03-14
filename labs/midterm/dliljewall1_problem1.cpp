// CSC 123
// Assignment: Midterm Exam, Problem 1
// File Name: dliljewall1_problem1.cpp
// Author: David Liljewall
// Last Modified: 3/25/2020

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

/// ----- FUNCTION DECLARATIONS ----- ///
void initialize_screen();
//Separates current output from 
//the output of the previously run program. 

int random_int(int& n, int& min, int& max);
//Prompts user for:
//# of random integers, min and max values.
//Displays to user if generated number is even/odd


/// ----- MAIN CODE BODY ----- ///
int main(){

    initialize_screen();
    srand(time(NULL)); //seeds random # generator at compile time

    int number = 0, minimum = 0, maximum = 0;

    cout << "Enter how many integers you want to generate: " << endl;
    cin >> number;
    cout << "Enter the min number to create: " << endl;
    cin >> minimum;
    cout << "Enter the max number to create: " << endl;
    cin >> maximum;

    random_int(number, minimum, maximum);

}



/// ----- FUNCTION DEFINITIONS ----- ///
void initialize_screen(){
    cout << endl;
}

int random_int(int& n, int& min, int& max){
    
    int rand_int = 0; 
    int i = 0;
    int even_counter = 0, odd_counter = 0;
    //genereates random numbers between max and min 
    for(i = 0; i < n; i++){
        rand_int = (rand() % (max - min)) + min; 
        if(rand_int % 2 == 0){
            cout << "Rand Number: " << rand_int 
            << "--> Even" << endl;
            even_counter++;
        }
        else{
            cout << "Rand Number: " << rand_int 
            << "--> Odd" << endl;
            odd_counter++;
        }
    }

    cout << "Total Numbers Generated: " << n
    << " - Even #s: " << even_counter
    << " - Odd #s: " << odd_counter << endl;
}
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>

using namespace std;


/* -------------------------------------------------------------------------- */
/*                            FUNCTION DECLARATIONS                           */
/* -------------------------------------------------------------------------- */
void fill_up(const int a[], int size_of_a);
    // creates a constant array parameter (unomodifiable array) of size size_of_a
    // based on user input



/* -------------------------------------------------------------------------- */
/*                             MAIN FUNCTION BODY                             */
/* -------------------------------------------------------------------------- */

int main(){
    //*Range based for loop example: //*
    // ANCHOR -- the below code takes an array, adds 1 to each element respectively, and prints out the result.
    // "x" shall be defined as the variable that iterates through the array.
    int array[] = {2,4,6,8}; //declare array
    for(int& x : array){ // create a reference parameter "x", assign x to each element in the array ( x : array ), and add 1 (x++).
        x++;
    }
    for(auto new_x : array){ // use auto to auto-detect variable type in array, and print out new result
        cout << new_x << endl;
    }

    //** Constant Array Parameter Example //*



}



/* -------------------------------------------------------------------------- */
/*                            FUNCTION DEFINITIONS                            */
/* -------------------------------------------------------------------------- */

// CSC 123
// Assignment: Lab #10
// File Name: dliljewall1_lab10.cpp
// Author: David Liljewall
// Last Modified: 

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>

typedef int *IntPtr; // defines "IntPtr" as equivalent to typing int*. E.g. IntPtr a_ptr is equivalent to int *a_ptr

using namespace std;

/* -------------------------------------------------------------------------- */
/*                            FUNCTION DECLARATIONS                           */
/* -------------------------------------------------------------------------- */






/* -------------------------------------------------------------------------- */
/*                                MAIN FUNCTION                               */
/* -------------------------------------------------------------------------- */
int main() {

/* ---------------------------- POINTER VARIABLES --------------------------- */

    int p = 10; // initialize p integer variable

    //* IntPtr p_ptr = &p; // set the dereferenced p_ptr (value of memory address ) to the referenced p
    //* or:

    int *p_ptr; // equivalent to above IntPtr syntax from typedef a top of code...
    p_ptr =  &p; // sets pointer 

    cout << "p == " << p << endl; // prints the value of p
    cout << "*p_ptr == " << *p_ptr << endl; // prints the 
    cout << "p_ptr == " << p_ptr << endl;
    cout << "&p == " << &p << endl;

    int &a = *p_ptr;
    a = 7;
    cout << "p == " << p << endl;
    cout << "&a == " << &a << endl;
    cout << "a == " << a << endl;
    cout << "*p_ptr == " << *p_ptr << endl;


/* ----------------------------- "NEW" VARIABLES ---------------------------- */

    int *p1_ptr;
    p1_ptr = new int;
    *p1_ptr = 10;
    cout << "*p1_ptr == " << *p1_ptr << endl;
    delete p1_ptr;
    cout << "After 'delete p1_ptr', *p1_ptr == " << *p1_ptr << endl;



/* ----------------------------- DYNAMIC ARRAYS ----------------------------- */
    int array_size;

    typedef double* DblPtr; // DblPtr is now equivalent to typing double*
    DblPtr array = NULL; // creates a dynamic double array
    cout << "Dblptr array has been initialized and set to NULL " << array << endl;

    do {
        cout << "Enter the array size" << endl;
        cin >> array_size;
        array = new double [array_size];

        for(int i = 0; i < array_size; i++) {
            array[i] = i;
            cout << array[i] << endl;
        }
    } while(array_size < 100);

    //* NOTE: IMPORTANT CHECK BEFORE "FREEING" DYNAMIC MEMORY:
    if(array != NULL){
        delete[] array; // syntax for freeing memory used by array[]
        cout << "dynamic memory for DblPtr array has been freed " << endl;

        array = NULL; //* NOTE: ALWAYS set pointer to null after freeing the memory it was pointing to
    }

    // since the memory has been freed & the pointer is set to NULL, this program cannot access that memory anymore
    for(int i = 0; i < array_size; i++) {
            cout << "Attempting to access freed memory (pointer has been set to NULL)" << endl;
            cout << array[i] << endl;
            //* NOTE: since the program can't access the memory (since pointer is NULL),
            //* a segmentation fault occurs, i.e., the program attempts to access restricted memory. 
            //* It became restricted by the act of setting the pointer to NULL.
        }

    

}




/* -------------------------------------------------------------------------- */
/*                            FUNCTION DEFINITIONS                            */
/* -------------------------------------------------------------------------- */
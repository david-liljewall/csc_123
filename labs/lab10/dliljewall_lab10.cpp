// CSC 123
// Assignment: Lab #10
// File Name: dliljewall1_lab10.cpp
// Author: David Liljewall
// Last Modified: 5/6/2020

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>

using namespace std;

/* -------------------------------------------------------------------------- */
/*                              CLASS DEFINITIONS                             */
/* -------------------------------------------------------------------------- */
class Dynamic_Statistics {
   
    private:
    int list_size; // size of current dynamic array
    int *numbers_list; // dynamic array pointer variable

    public:
        Dynamic_Statistics() // constructor
        {
            numbers_list = NULL; // initialize dynamic array to NULL
        }

        ~Dynamic_Statistics() // destructor
        {
            // intentionally left blank - the deleting of dynamic memory is done in the clear_array() function
        }

        bool create_array(int n_size);
            // Creates a dynamic array using n_size. If numbers_list already exists (not NULL),
            // then the function returns FALSE. If the function can create the dynamic array then n_size 
            // is stored in list_size, and returns TRUE.
        bool clear_array();
            // Function attempts to free the memory used by the dynamic array numbers_list. If numbers_list is NULL, 
            // the function returns FALSE. If it is not NULL, list_size is set to 0 and TRUE is returned.
        void initialize_array();
            // Checks that number_list has been created and then assigns the value of 0 to all its elements.
        void print_array();
            // Prints the numbers_list if it exists. A message is displayed if the array has not been created.
        void populate_array(int max_value);
            // Fills numbers_list with random numbers from 0 to max_value.
        int get_mean();
            // Returns the mean of the numbers_list after checking if numbers_list has been created.
        int get_min();
            // Returns the minimum value in numbers_list after checking if numbers_list has been created.
        int get_max();
            // Returns the maximum value in numbers_list after checking if numbers_list has been created.
        void sort_numbers();
            // Sorts the list of numbers (using Bubble sort) after checking if numbers_list has been created.
        int get_median();
            // Gets the median value for numbers_list after checking if numbers_list hsa been created. 
        void display_mode_value();
            // Displays the mode values (or modes if there are more than one) for numbers_list after checking if
            // numbers_list has been created.
};


/* -------------------------------------------------------------------------- */
/*                                MAIN FUNCTION                               */
/* -------------------------------------------------------------------------- */
int main() {
    
    Dynamic_Statistics numbers; // create class object "numbers"
    
    int array_size, max_value;
    bool flag;

    // perform the following as long as the user inputs array_size >= 2:
    do {
        cout << " << Program Start >> " << endl << endl;
        cout << " Enter the desired array size (to exit program, enter a number <= 1): ";
        cin >> array_size;

        if (array_size > 2)
        {
            flag = true;

            numbers.create_array(array_size);
            numbers.initialize_array();

            cout << " Enter the maximum-valued integer for the numbered list to hold: ";
            cin >> max_value;
            cout << endl <<" The randomly generated numbered list is: " << endl;
            numbers.populate_array(max_value);    
            numbers.print_array();

            // get average:
            cout << " Mean of the list: " << numbers.get_mean() << endl;

            // get min:
            cout << " The minimum value is: " << numbers.get_min() << endl;

            // get max:
            cout << " The maximum value is: " << numbers.get_max() << endl;

            // sort array in ascending order:
            numbers.sort_numbers();
            cout << " The sorted numbered list (using Bubble Sort) in ascending order is: " << endl << endl;
            numbers.print_array();

            // display median:
            cout << " Median value: " << numbers.get_median() << endl << endl;

            // display mode:
            numbers.display_mode_value();

            // free dynamic memory
            numbers.clear_array();
        }
        else 
        {
            flag = false;
        }
        
    } while (flag);

    cout << " << Program Exited >> " << endl;

    return 0;
}


/* -------------------------------------------------------------------------- */
/*                            FUNCTION DEFINITIONS                            */
/* -------------------------------------------------------------------------- */

bool Dynamic_Statistics::create_array(int n_size) {

    if (numbers_list == NULL) {
        list_size = n_size; // stores n_size in list_size
        numbers_list = new int [list_size]; // creates dynamic integer array of size n_size.
        cout << " << (array successfully created)" << endl << endl;
        return true;
    }  
    else {
        delete[] numbers_list;
        list_size = n_size;
        numbers_list = new int [list_size];
        if (numbers_list == NULL) 
        {
            // if dynamic array still not created, return false
            return false;
        }
        else 
        {
            return true;
        }
    }
}

void Dynamic_Statistics::initialize_array() {

    if (create_array(list_size)) {
        for (int i = 0; i < list_size; i++) {
            numbers_list[i] = 0;
        }
    }
    else {
        cout << " Error: numbers_list has not been created... "
        << "Exiting Program." << endl;
        exit(1);
    }
}

void Dynamic_Statistics::print_array() {

    if (create_array(list_size)) {
        for(int i = 0; i < list_size; i++) {
            cout << setw(5) << (i + 1) << ":" << setw(5) << numbers_list[i] << endl; 
        }
    }
    else {
        cout << " Error: numbers_list has not been created... "
        << "Exiting Program." << endl;
        exit(1);
    }
    cout << endl << endl; // add extra whitespace before next terminal prompt
}

void Dynamic_Statistics::populate_array(int max_value) {
    
    srand(unsigned(time(NULL))); // seeds random number generator at compile time

    if (create_array(list_size)) {
        for (int i = 0; i < list_size; i++) {
            numbers_list[i] = rand() % (max_value + 1); // fills elements with integers between 0 and max_value
        }
    }
    else {
        cout << " Error: numbers_list has not been created and is set to NULL... "
        << "Exiting Program." << endl;
        exit(1);
    }
    cout << endl << endl;
}

int Dynamic_Statistics::get_mean() {
    
    double mean_value = 0; // placeholder for mean_value to be returned
    double sum = 0; // initialize sum of the elements of numbers_list

    if (create_array(list_size)) {
        for(int i = 0; i < list_size; i++) {
            sum += numbers_list[i];
        }
        return mean_value = sum / list_size; // mean value of array  = (sum of elements) / (# of elements)
    }
    else {
        cout << " Error: numbers_list has not been created and is set to NULL... "
        << "Exiting Program." << endl;
        exit(1);
    }
    cout << endl << endl;
}

int Dynamic_Statistics::get_min() {
    
    int min_value = numbers_list[0]; 

    if (create_array(list_size)) {
        for(int i = 0; i < list_size; i++)
            {
                if(min_value > numbers_list[i])
                {
                    min_value = numbers_list[i];
                    i++;
                }
            }
        return min_value;
    }
    else {
        cout << " Error: numbers_list has not been created and is set to NULL... "
        << "Exiting Program." << endl;
        exit(1);
    }
    cout << endl << endl;
}

int Dynamic_Statistics::get_max() {
        
    int max_value = numbers_list[0];

    if (create_array(list_size)) {
        for(int i = 0; i < list_size; i++)
        {
            if(max_value < numbers_list[i])
            {
                max_value = numbers_list[i];
                i++;
            }
        }
        return max_value;
    }
    else {
        cout << " Error: numbers_list has not been created and is set to NULL... "
        << "Exiting Program." << endl;
        exit(1);
    }
    cout << endl << endl;
}

void Dynamic_Statistics::sort_numbers() {

    if (create_array(list_size)) {
        for(int i = list_size - 1; i > 0; i--)
        {
            // Start at 0th element, and bubble the largest number to the right:
            for(int j = 0; j < i; j++)
            {
                // Check if the element to the right of the current element is smaller. 
                // If so, swap the numbers:
                if(numbers_list[j] > numbers_list[j + 1])
                {
                    int temp = numbers_list[j + 1];
                    numbers_list[j + 1] = numbers_list[j];
                    numbers_list[j] = temp;
                }
            }
        }
    }
    else {
        cout << " Error: numbers_list has not been created and is set to NULL... "
        << "Exiting Program." << endl;
        exit(1);
    }
    cout << endl << endl;
}

int Dynamic_Statistics::get_median() {

    if (create_array(list_size)) {    
        int median_index = int(list_size / 2); 
        int median = numbers_list[median_index];
        return median;
    }
    else {
        cout << " Error: numbers_list has not been created and is set to NULL... "
        << "Exiting Program." << endl;
        exit(1);
    }
    cout << endl << endl;
}

void Dynamic_Statistics:: display_mode_value() {
    // Initialize mode function variables:
    int mod_value = numbers_list[0];
    int mod_times = 1; 
    int current_num_count = 1; // counts the occurences of the current value in  numbers[] 

    if (create_array(list_size)) {
        for(int i = 0; i < list_size; i++)
        {
            if(numbers_list[i] == numbers_list[i + 1])
            {// if adjacent values are equal in the sorted array, increase current_num_counter
                current_num_count++;
                if(current_num_count > mod_times)
                { // if the current_num_count > occurences of mode (mod_times), set them equal and
                // equal. I.e., if the current value occurs more than the previous assumed mode, set new values.
                    mod_times = current_num_count;
                    mod_value = numbers_list[i];
                }
            }
            else
            {
                current_num_count = 1; // reset counter
            }
        }
    }
    else
    {
        cout << " Error: numbers_list has not been created and is set to NULL... "
        << "Exiting Program." << endl;
    }
     
    cout << " The first mode of the sorted list is " << mod_value << " and it appears " << mod_times << " times" << endl << endl;
}

bool Dynamic_Statistics::clear_array() {

    if (numbers_list == NULL) {
        return false;
    }
    else {
        delete[] numbers_list;
        list_size = 0;
        numbers_list = NULL; // freed memory is now not accessible
        return true;
    }

}

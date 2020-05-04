// CSC 123
// Assignment: Lab #8
// File Name: dliljewall1_lab8.cpp
// Author: David Liljewall
// Last Modified: 4/12/2020

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>

using namespace std;

// MAXIMUM SIZE for all arrays used in this programs:
#define MAX_ARRAY 10 




/* -------------------------------------------------------------------------- */
/*                            FUNCTION DECLARATIONS                           */
/* -------------------------------------------------------------------------- */
void initialize_array(int numbers[], int initial_value);
    // Takes an array parameter and integer parameter to fill a generic array with
    // an initial value for each element of that array. 

void print_array(int numbers[]);
    // Prints an array to the terminal horizontally.

void populate_array(int numbers[], int max_value);
    // Fills an array with random integers, where the maximum integer generated is max_value.

double get_mean(int numbers[]);
    // Returns the mean value of the elements in a populated array.

int get_min_or_max_value(int numbers[], bool max_flag);
    // Returns the minimum or maximum value in the elements of the array. The function passes a boolean value
    // to a flag in the function. If the flag is TRUE, the function returns the maximum value element; 
    // if FALSE, it returns the minimum value element. 

void sort_array(int numbers[]);
    // Sorts the values in the array numbers[] from min to max value via the "Bubble Sorting" algorithm.

int get_median(int numbers[]);
    // Finds the median value of the elements within numbers[]. 
    // Note: if numbers[] has an even number of elements, use the int value of the division to find this location.

void mode_value(int numbers[], int& mod_value, int& mod_times);
    // Returns the mode of the array numbers[], i.e., the value that repeats the most.
    // Note: this function only works for ascending-order sorted arrays, and will only find the first mode
    // of a multimodal array.


/* -------------------------------------------------------------------------- */
/*                             MAIN FUNCTION BODY                             */
/* -------------------------------------------------------------------------- */
int main()
{
    // Create an array with MAX_ARRAY # of elements:
    int numbers_list[MAX_ARRAY];
    int mod_value, mod_times;

    // Initialize and print result:
    initialize_array(numbers_list, 0);
    print_array(numbers_list);

    initialize_array(numbers_list, -10);
    print_array(numbers_list);

    // Populate array with random values and print result:
    populate_array(numbers_list, 20);
    print_array(numbers_list);

    // get average:
    cout << "Mean (Average) of the list: " << get_mean(numbers_list) << endl;

    // get max and min numbers:
    cout << "Max number is " << get_min_or_max_value(numbers_list, true) << " , and the Min number is "
    << get_min_or_max_value(numbers_list, false) << endl;

    // sort array in ascending order:
    sort_array(numbers_list);
    print_array(numbers_list);

    // display median:
    cout << "Median value: " << get_median(numbers_list) << endl;

    mode_value(numbers_list, mod_value, mod_times);
    cout << "Mode value: " << mod_value << " is found " << mod_times << " times in the array." << endl;

    getchar();

    return 0;
}


/* -------------------------------------------------------------------------- */
/*                            FUNCTION DEFINITIONS                            */
/* -------------------------------------------------------------------------- */
void initialize_array(int numbers[], int initial_value)
{

    for(int i = 0; i < MAX_ARRAY; i++)
    {
        numbers[i] = initial_value; // fill each element with the int initial_value
    }

}

void print_array(int numbers[])
{
    for(int i = 0; i < MAX_ARRAY; i++)
    {
        cout << numbers[i] << '\t'; // print each element horizontally
    }
    cout << endl; // add extra whitespace before next terminal prompt
}

void populate_array(int numbers[], int max_value)
{
    srand(unsigned(time(NULL))); // seeds random number generator at compile time

    for(int i = 0; i < MAX_ARRAY; i++)
    {
        numbers[i] = rand() % max_value; // fills elements with integers between 0 and (max_value - 1)
    }
}

double get_mean(int numbers[])
{
    double mean_value = 0; // placeholder for mean_value to be returned
    double sum = 0; // initialize sum of numbers[] array elements

    for(int i = 0; i < MAX_ARRAY; i++)
    {
        sum += numbers[i];
    }

    return mean_value = sum / MAX_ARRAY; // mean value of array  = (sum of elements) / (# of elements)
}

int get_min_or_max_value(int numbers[], bool max_flag)
{   
    int max_value = numbers[0], min_value = numbers[0]; // initialize min and max values to first element of numbers[]
    
    // Max value finder:
    if(max_flag == true)
    {
        for(int i = 0; i < MAX_ARRAY; i++)
        {
            if(max_value < numbers[i])
            {
                max_value = numbers[i];
                i++;
            }
        }
        return max_value;
    }
    // Min value finder:
    else if(max_flag == false)
    {
        for(int i = 0; i < MAX_ARRAY; i++)
        {
            if(min_value > numbers[i])
            {
                min_value = numbers[i];
                i++;
            }
        }
        return min_value;
    }
}

void sort_array(int numbers[])
{
    for(int i = MAX_ARRAY - 1; i > 0; i--)
    {
        // Start at 0th element, and bubble the largest number to the right:
        for(int j = 0; j < i; j++)
        {
            // Check if the element to the right of the current element is smaller. 
            // If so, swap the numbers:
            if(numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j + 1];
                numbers[j + 1] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

}

int get_median(int numbers[])
{
    int median_index = int(MAX_ARRAY / 2); 
    int median = numbers[median_index];
    return median;
}

void mode_value(int numbers[], int& mod_value, int& mod_times)
{
    // Initialize mode function variables:
    mod_value = numbers[0];
    mod_times = 1; 
    int current_num_count = 1; // counts the occurences of the current value in  numbers[] 

    for(int i = 0; i < MAX_ARRAY; i++)
    {
        if(numbers[i] == numbers[i + 1])
        {// if adjacent values are equal in the sorted array, increase current_num_counter
            current_num_count++;
            if(current_num_count > mod_times)
            { // if the current_num_count > occurences of mode (mod_times), set them equal and
            // equal. I.e., if the current value occurs more than the previous assumed mode, set new values.
                mod_times = current_num_count;
                mod_value = numbers[i];
            }
        }
        else
        {
            current_num_count = 1; // reset counter
        }
    }    
}
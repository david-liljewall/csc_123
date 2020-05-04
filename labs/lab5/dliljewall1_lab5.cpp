// CSC 123
// Assignment: Lab #5
// File Name: dliljewall1_lab4.cpp
// Author: David Liljewall
// Last Modified: 3/7/2020

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;


/// ----- FUNCTION DECLARATIONS ----- ///
int menu();

void range_numbers(int max_number);
void range_numbers(int max_number, int increment); 
void range_numbers(float max_number, float increment);

void rand_numbers(int n_rand, int max_limit);
void rand_numbers(int n_rand, int min_limit, int max_limit);



/// ----- MAIN CODE BODY ----- ///
int main(){

    int choice = menu(); //sets variable "choice" to menu_option from int menu() func.

    if(choice == 1){
    //range with max number
        int maximum;
        cout << "1) Range with Max Number " << endl;
        cout << "Enter the max number to display: " << endl;
        cin >> maximum;
        cout << "Range from " << "(" << "0 , " << maximum << "): " << endl;
        
        //function call
        range_numbers(maximum); //passing maximum as max_number to function
    }
    else if(choice == 2){
    //range with max number & incrememnt type (int)
        int maximum;
        int step_size;

        cout << "2) Range with Max Number and Increment (int) " << endl;
        cout << "Enter the max number to display: " << endl;
        cin >> maximum;
        cout << "Enter the increment to use:" << endl;
        cin >> step_size;
        cout << "Range from " << "(" << "0 , " << maximum 
        << ") " << "using increments of " << step_size 
        << ": " << endl;
        
        //function call
        range_numbers(maximum, step_size); //passing maximum as max_number to function
    }
    else if(choice == 3){
    //range with max number  & incrememt type (float)
        float maximum;
        float step_size;

        cout << "3) Range with Max Number and Increment (float) " << endl;
        cout << "Enter the max number to display: " << endl;
        cin >> maximum;
        cout << "Enter the increment to use:" << endl;
        cin >> step_size;
        cout << "Range from " << "(" << "0 , " << maximum 
        << ") " << "using increments of " << step_size 
        << ": " << endl;
        
        //function call
        range_numbers(maximum, step_size); //passing maximum as max_number to function
    }
    else if(choice == 4){
    //random numbers: N & max limit
        int n, limit;
        
        cout << "4) Random Numbers with max limit: " << endl;
        cout << "Enter how many numbers to generate: " << endl;
        cin >> n;
        cout << "Enter the upper limit to generate: " << endl;
        cin >> limit;
        cout << "Displaying " << n << " numbers from " 
        << "( " << "0, " << limit << "): " << endl; 

        //function call
        rand_numbers(n, limit);
}
    else if(choice == 5){
    //random numbers: N, min limit & max limit
        int n, lower_limit, upper_limit;
        
        cout << "5) Random Numbers with min and max limits: " << endl;
        cout << "Enter how many numbers to generate: " << endl;
        cin >> n;
        cout << "Enter the min number to generate: " << endl;
        cin >> lower_limit;
        cout << "Enter the max number to generate: " << endl;
        cin >> upper_limit;
        cout << "Displaying " << n << " numbers from " 
        << "( " << lower_limit << ", " << upper_limit
        << "): " << endl; 

        //function call
        rand_numbers(n, lower_limit, upper_limit);  
    }
}

/// ----- FUNCTION DEFINITIONS ----- ///
int menu(){
//menu that continously prompts user till valid option is picked

    int menu_option = 1;

    if(menu_option > 0 && menu_option < 7){
        cout << "== Menu == " << endl;
        cout << "1. Range with Max Number" << endl;
        cout << "2. Range with Max Number & Increment (Int)" << endl;
        cout << "3. Range with Max Number & Incremenet (Float)" << endl;
        cout << "4. Random Numbers: N & Max Limit" << endl;
        cout << "5. Random Numbers: N, Min Limit & Max Limit" << endl;
        cout << "6. Exit" << endl << endl;
        cout << "Enter your option: " << endl;
        cin >> menu_option;
        if(menu_option > 0 && menu_option < 7){
            //do nothing
        }
        else{
            cout << "Invalid entry, please try again" << endl;
            cout << "== Menu == " << endl;
            cout << "1. Range with Max Number" << endl;
            cout << "2. Range with Max Number & Increment (Int)" << endl;
            cout << "3. Range with Max Number & Incremenet (Float)" << endl;
            cout << "4. Random Numbers: N & Max Limit" << endl;
            cout << "5. Random Numbers: N, Min Limit & Max Limit" << endl;
            cout << "6. Exit" << endl << endl;
            cout << "Enter your option: " << endl << endl;
            cin >> menu_option;
        
        }
    }

    return menu_option;

}

void range_numbers(int max_number){
//generates sequential integers between 0 and max_number

    for(int i = 0; i <= max_number; i++){
        cout << i << "\t"; // the "\t" will print things horizontally
    }
    
    cout << endl; //adds extra empty line for better viewing on terminal
}

void range_numbers(int max_number, int increment){
//genereates sequential integers between 0 and max_number in desired increments

    int i = 0;
    while(i <= max_number){
        cout << i << "\t"; 
        i += increment;
    }
    cout << endl;
}

void range_numbers(float max_number, float increment){
//generates sequential  floats between 0 and max_number in desired increments  
    
    float i = 0;
    while(i <= max_number){
        cout << i << "\t";
        i += increment;
    }
    cout << endl;
}

void rand_numbers(int n_rand, int max_limit){
//generates a set of random numbers from 0 to the max_limit
    int rand_int;
    srand((unsigned)time(0)); //start the seed for random number generator

    for(int i = 0; i < n_rand; i++){
        rand_int = (rand() % max_limit) + 1; //generates random int 0 -> max_limit
        cout << rand_int << "\t";
    }
    cout << endl;
}

void rand_numbers(int n_rand, int min_limit, int max_limit){
//generates a set of random numbers from lower min_limit to max_limit
    int rand_int;
    srand(unsigned(time(0))); //start the seed for random number generator

    for(int i = 0; i < n_rand; i++){
        rand_int = (rand() % (max_limit - min_limit)) + min_limit; //generates random int min_limit -> max_limit
        cout << rand_int << "\t";
    }
    cout << endl;
}

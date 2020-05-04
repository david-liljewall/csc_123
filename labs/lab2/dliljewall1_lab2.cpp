// CSC 123
// Assignment: Lab #2
// File Name: lab2.cpp
// Author: David Liljewall
// Last Modified: 2/16/2020


#include <iostream>
#include <string>
using namespace std;


int main(){
    
    string option; //the string "option" will be the placeholder for the operations
    //Print the menu to terminal and prompt user to choosee which operation to use
    string operation; //placeholder for assignging a string statement to each operation type
    cout << "(A)dd" << endl;
    cout << "(S)ubtract" << endl;
    cout << "(M)ultiply" << endl;
    cout << "(D)ivide" << endl;
    cout << "M(O)D Operation" << endl;
    cout << endl << "Please enter the character inside the parenthesis of the "
                    "mathematical operation you want to perform. "
                    "For example: enter 'A' or 'a' for addition, or "
                    " 'S' or 's' for subtraction, etc." << endl;
    cin >> option; //user enters character into the terminal

    float number_1, number_2, result; //variables for the user-entered numbers, as well as the result value.
    //Prompt use for input on two numbers to perform the chosen operation on
    cout << "Now that you have chosen an operation to perform, please enter "
            "two numbers that you would like to perform the operation on..." << endl;
    cout << "Please enter the first number: " << endl;
    cin >> number_1;
    cout << "Please enter the second number: " << endl;
    cin >> number_2;


    //conditional statements to determine which operation to perform based on the user-entered character
    if (option == "A" || option == "a"){
        //add
        result = number_1 + number_2;
        operation = "added to ";
    }
    else if(option == "S" || option == "s"){
        //subtract
        result = number_1 - number_2;
        operation = "subtracted by ";
    }
    else if(option == "M" || option == "m"){
        //multiply
        result = number_1 * number_2;
        operation = "multiplied by ";
    }
    else if(option == "D" || option == "d"){
        //divide
        result = number_1 / number_2;
        operation = "divided by ";
    }
    else if(option == "O" || option == "o"){
        //mod operation --> only takes integers! Must force number_1 and number_2 to integers.
        result = int(number_1) % int(number_2);
        operation = "modulo ";
    }

    //print result to terminal
    cout << number_1 << " " << operation << number_2 
    << " is: " << result << endl;


    return 0;

    //NOTE: Though it is beyond where CSC123 at the time of writing, added functionality of checking whether or not
    //the user inputs to the terminal are of the correct type before proceeding, i.e., do not proceed if instead of a character
    //the user entered a number for the variable "option". This would allow the program to be more robust against and errors and
    //could prompt the user to fix their mistake if they entered the wrong data type.
}
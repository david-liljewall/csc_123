// CSC 123
// Assignment: Lab #3
// File Name: lab3.cpp
// Author: David Liljewall
// Last Modified: 2/24/2020

#include <iostream>
#include <string>
using namespace std;


int main(){

    /// INITILIAZE VARIABLES (in global scope, to be used in cases and loops) ///
    int option; //used
    int stored_number = -1; //-1 will assume no correct value has been assigned by the user
    // int stored_number_array[0];
    //do-while loop that runs till option is picked
    do{
        /// MENU PRINTOUT ///
        cout << " -------- " << endl;
        cout << "1 - Store Number" << endl;
        cout << "2 - Clear Number" << endl;
        cout << "3 - Display Number" << endl;
        cout << "4 - Even/Odd" << endl;
        cout << "5 - Even/Odd List" << endl;
        cout << "6 - Column Display" << endl;
        cout << "7 - Exit" << endl;
        cout << "Enter your option: " << endl;
        cout << endl << endl;
        //user input to select menu option
        cin >> option;

        //switch b/w options based on user-input
        
        switch(option){
            case 1:{
                //store number
                cout << "Please enter an integer to store for future operations: " << "\n" << endl;
                cin >> stored_number;
                break;
            }
            case 2:{
                //clear number
                stored_number = -1; //treat -1 as "invalid"
                cout << "Clear Stored Number " << "\n" <<endl;
                break;
            }
            case 3:{
                //display number
                if(stored_number != -1){
                    cout << "Display Stored Number: " << stored_number << endl;
                }
                else{
                    cout << "Display Stored Number: " <<
                    "Value has not been set up" << endl;
                }
                break;
            }
            case 4:{
                //even
                if(stored_number % 2 == 0){
                    cout << "Stored Number: " << stored_number <<
                    " is even" << endl; 
                }
                //odd
                else{
                    cout << "Stored Number: " << stored_number <<
                    " is odd" << endl;
                }
                break;
            }
            case 5:{
                cout << "Display even/odds; " << 
                "Select (1) even / (2) odd to be displayed: " << endl;
                int stored_number_array[0];
                /// fills array with all integers from 0 to stored_number ///
                for(int i = 0; i < stored_number + 1; i++){
                    stored_number_array[i] = i;
                }
                //fills an array with either the even or odd integers up to stored_number
                int even_odd_option;
                cin >> even_odd_option;
                int even_list[0], odd_list[0];

                if(even_odd_option == 1){
                    for(int l = 0; l < stored_number +1; l = l + 2){
                    even_list[l] = stored_number_array[l];
                    cout << "---" << even_list[l] << "---" << endl;
                    }
                }
                else{
                    for(int l = 1; l < stored_number + 1; l = l + 2){
                    odd_list[l] = stored_number_array[l];
                    cout << "---" << odd_list[l] << "---" << endl;
                    }
                }
                break;
            }

            case 6:{ 
                //column display. user enteres # of columns to display 0-stored_number

                int stored_number_array[0];
                /// fills array with all integers from 0 to stored_number ///
                for(int i = 0; i < stored_number + 1; i++){
                    stored_number_array[i] = i;
                    // cout << stored_number_array[i] << endl;
                }

                int end = stored_number;
                int n_columns;
                cout << "Enter the number of columns to use: " << endl;
                cin >> n_columns;
                int rows = int((end - 1)/n_columns) + 1; 
                cout << endl;
                int column_array[rows][n_columns];
                int q = 0; //loop counter
                for(int j = 0; j < rows; j++){
                    for(int k = 0; k < n_columns; k++, q++){
                        column_array[j][k] = stored_number_array[q];
                        cout << column_array[j][k] << endl;
                        }                    
                }

                break;
            }

            case 7:{
                // exit
                goto EXIT_PROGRAM;
                break;
            }

            default:{
                // invalid option
                cout << "Error: Invalid Option" << endl;
                break;
            }
        }
    }
    while (option < 8);
    EXIT_PROGRAM: cout << "Program Exited ---" << endl;
}
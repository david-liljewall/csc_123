// CSC 123
// Assignment: Lab #7
// File Name: dliljewall1_lab7.cpp
// Author: David Liljewall
// Last Modified: 4/5/2020

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>

using namespace std;


/// ----- FUNCTION DECLARATIONS ----- ///
void display_letter_by_line(string& text);
    // Takes a single string reference parameter and prints one letter of the string per line.

void display_string_ASCII_value(string& text);
    // Takes a string and converts each character in the string to an ASCII integer value.

void display_string_ASCII_value(string& text, int offset);
    // Same as above function, except an integer offset is added to the ascii key corresponding to each character.
    // E.g. 'D' maps to the ascii integer 84, and this function will print 84 + offset.

void store_string_ASCII_to_file(string& text, string file_name, int offset);
    // Takes a string, the name of the file that the string will be saved to, and the offset applied to the
    // string to be encoded.

string load_string_ASCII_to_memory(string file_name, int offset);
    // Returns a string which has been loaded from the encrypted file.

    

/// ----- MAIN CODE BODY ----- ///
int main(){

    string test_variable;

    test_variable = "This message must be encoded";

    cout << endl << "Displaying test_variable content by line:" << endl;
    display_letter_by_line(test_variable);
    cout << endl;

    cout << endl << "Display string ASCII value:" << endl;
    display_string_ASCII_value(test_variable);
    cout << endl;

    cout << endl << "Display string ASCII value with offset:" << endl;
    display_string_ASCII_value(test_variable, 10);
    cout << endl;

    cout << endl << "Storing string to text file:" << endl;
    store_string_ASCII_to_file(test_variable, "RESULT.txt", 10);
    cout << endl;

    cout << endl << "Loading string from text file:" << endl;
    cout << "MESSAGE:"  << load_string_ASCII_to_memory("RESULT.txt", 10) << endl << endl;

    system("pause");

}


/// ----- FUNCTION DEFINITIONS ----- ///
void display_letter_by_line(string& text){
    // Treating the string object as an array, print out each character (array element) 
    // per line. 
    for(int i = 0; i < text.length(); i++){
        cout << text[i] << endl;
    }
}

void display_string_ASCII_value(string& text){
    for(int i = 0; i < text.length(); i++){
        char test_char = text[i]; // Maps the character test_char to each character of string& text
        cout << int(test_char) << '\t'; // Prints the ascii integer for each character horizontally 
    }
}

void display_string_ASCII_value(string& text, int offset){
     for(int i = 0; i < text.length(); i++){
        char test_char = text[i]; // Maps the character test_char to each character of string& text
        char encrypted_char = int(test_char) + offset;
        int encrypted_int = int(encrypted_char);

        cout << encrypted_int << '\t'; //prints the encrypted ascii integer
    }
}

void store_string_ASCII_to_file(string& text, string file_name, int offset){
    //create output file object variable
    ofstream output_file;

    output_file.open(file_name, ios::out);

    if(output_file.fail()){
        cout << "Output file did not open properly..." << endl;
        exit(1);
    }

    //create encrypted characters to be saved to output_file
    for(int i = 0; i < text.length(); i++){
        char test_char = text[i]; // Maps the character test_char to each character of string& text
        char encrypted_char = int(test_char) + offset;  
        int encrypted_int = int(encrypted_char); // convertst to ascii integer
        
        output_file << encrypted_int << endl;// Output each encrypted ascii int per line of output file
    }

    output_file.close();
    
    getchar();
}

string load_string_ASCII_to_memory(string file_name, int offset){
    ifstream input_file;

    input_file.open(file_name, ios::in);
    if(input_file.fail()){
        cout << "Input file did not open properly..." << endl;
        exit(1);
    }

    // variables used to store data from input_file
    int encrypted_int;
    string decrypted_string = ""; // initailize like this, good practice!
    
    //** EOF Method: */
    // input_file >> encrypted_int; //"prime" read the input_file
    // //while loop to __ till end of file (do while NOT end of file, i.e., !input_file.eof() )
    // while(!input_file.eof()){
    //     decrypted_string += char(encrypted_int - offset); // subtract offset to get decrypted ascii int
    //     // then convert to char
    //     input_file >> encrypted_int; // read encrypted ascii integer from input_file

    // }

    //** ANCHOR: Input Read Method: */ --> This is the optimal method for reading from a file to it ends. The .eof() almost ends up copying the last line because
    //* of how it stores the data before flagging that the file has now been read through completely
    while(input_file >> encrypted_int){
        decrypted_string += char(encrypted_int - offset); 

    }

    
    return decrypted_string;
    input_file.close();

    getchar();

}
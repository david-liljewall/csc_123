// CSC 123
// Author: David Liljewall
// Last Modified: 3/27/2020

#include <iostream>
#include <string>
#include <fstream> //NOTE: library to do file I/O
#include <cstdlib>

using namespace std;


int main() 
{   
 // create input and output file object variables 
 ifstream input_file; 
 ofstream output_file; 
 
 // variables used to store the information that will be used to write to the output file
 int value1 = 0, value2 = 0; 
 int result; 
 
 // open the file for input (change the location to work on your txt file)
 // The declared input stream variable (input_file) connects to the file you want via the .open function call
//  input_file.open("hello.txt", ios::in); 
input_file.open("/mnt/c/git-environment/csc123/hello.txt", ios::in); 
 
 // simple check to see if the file is open or not, if it is not open 
 // then the a message is displayed and then the program exits. 
 if (input_file.fail()) 
 { 
  cout.width(4);
  cout << "Input file did not open properly" << endl; 
  exit(1); // #include <cstdlib> required for exit() to be called which immediately ends the program
           // Any Integer_Value may be used, but by convention, 1 is used for a call to exit that is caused by an error, and 0 is used in other cases
 } 

 
 // we know the format of the file so we just read the numbers in sequence 
 input_file >> value1; //first line of input_file maps to value1
 //when input_file is called below, the stream automatically goes to the next line
 input_file >> value2; //second line of input_file maps to value2
 
  
 // open the file to save the result (change the location to work on your txt file) 
//  output_file.open("output.txt", ios::out);
output_file.open("/mnt/c/git-environment/csc123/output.txt", ios::out);
 // output_file.open check:
 if(output_file.fail()){
    cout.width(4);
    cout << "Output file did not open properly" << endl;
    exit(1);
 } 
 cout << value1 << " " << value2 << endl; 
 result = value1 + value2; 
 
 // writing to the file 
 output_file << result; 
  
 // close the files 
 input_file.close(); 
 output_file.close(); 
 
 getchar(); //pauses terminal. Next user terminal key input continues the script below this, which in this case just ends the program
 return 0; 
} 
 
/*
Author: David Liljewall
Course: CSC 123
Date: 2/4/2020
Assignment: Lab 1
first start with the standard cpp libraries that are required for strings and inputs-outputs
*/

/* Lab 1 PROMPT:
Print the following to the terminal:
Your Name
Your Major of Study
Your C++ IDE
Your Hobby ( hobbies )
*/

#include<string> /*allows for use of strings in cpp */
#include<iostream> /*allows for use of input-output functions in cpp */


/* initialize main function that will print various strings to the terminal */
int main()
{
    /* define string variables that will be output (calling iostream) into the terminal */
    std::string Name = "David";
    std::string Major = "Aerospace Engineering";
    std::string Cpp_IDE = "VSCode Insiders";
    std::string Hobby = "Writing/playing music, photography, reading, movies";

    /* below lines print the above string variables as text in the terminal*/
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Major: " << Major << std::endl; 
    std::cout << "IDE: " << Cpp_IDE << std::endl;
    std::cout << "Hobbies: " << Hobby << std::endl;
    
    return 0;
}

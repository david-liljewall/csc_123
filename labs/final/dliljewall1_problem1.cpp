// CSC 123
// Assignment: Final Exam Problem #1
// File Name: dliljewall1_problem1.cpp
// Author: David Liljewall
// Last Modified: 5/16/2020

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

//* PROGRAM DESCRIPTION:
//* Calculate the "weight" of a word by adding up the ASCII values for each character of 
//* the word. Uses two vectors -- 1) for odd characters, and 2) for even characters
//* The program prints the word, one character at a time with its ASCII value underneath,
//* and then prints the total odd vector sum, and the tatal even vector sum, then the total
//* sum for the entire word.
// NOTE: remember that the syntax int(char) converts a char to the ASCII value //


/* -------------------------------------------------------------------------- */
/*                            FUNCTION DECLARATIONS                           */
/* -------------------------------------------------------------------------- */
void string_to_vector(string& sample, vector<char>& even_chars, vector<char>& odd_chars);
    //
void calculate_weights(string& user_word, vector<char>& even_chars, vector<char>& odd_chars);
    //
void print_vector(string& user_word, vector<char>& even_chars, vector<char>& odd_chars);
    //


/* -------------------------------------------------------------------------- */
/*                                MAIN FUNCTION                               */
/* -------------------------------------------------------------------------- */
int main() {

    string word; // defines an empty vector that will hold a string type
    vector<char> even(1); vector<char> odd(1);

    cout << " --> Enter the word you want the find the value for: ";
    cin >> word;
    string_to_vector(word, even, odd);
    calculate_weights(word, even, odd);
    print_vector(word, even, odd);

    //then print the characters with ascii values underneath, and the summed weights


}

/* -------------------------------------------------------------------------- */
/*                            FUNCTION DEFINITIONS                            */
/* -------------------------------------------------------------------------- */
void string_to_vector(string& user_word, vector<char>& even_chars, vector<char>& odd_chars) {

    // print characters of user-entered string:
    for (int i = 0; i < user_word.length(); i++) {
        cout << setw(5) << user_word[i] << '\t';
    }
    cout << endl;

    for (int i = 0; i < user_word.length(); i++) {
        cout << setw(6) << int(user_word[i]) << '\t';
    }
    cout << endl << endl;

    // fill even_chars and odd_char vectors
    for (int i = 0; i < user_word.length(); i++) {

        if (int(user_word[i]) % 2 == 0) {
            even_chars.push_back(user_word[i]);
        }
        else if (int(user_word[i]) % 2 != 0) {
            odd_chars.push_back(user_word[i]);
        }

    } 

}

void calculate_weights(string& user_word, vector<char>& even_chars, vector<char>& odd_chars) {
    
    int even_sum = 0, odd_sum = 0; // even and odd character ascii value sums

    // calculate even and odd weights:
    for (int i = 0; i < even_chars.size(); i++) {
        even_sum += int(even_chars[i]);
    }

    for (int i = 0; i < odd_chars.size(); i++) {
        odd_sum += int(odd_chars[i]);
    }

    cout << "Total Weight of the word: " << even_sum + odd_sum << endl;

    // print even characters and their ascii values:
    cout << "Total Even value: " << even_sum << endl;
    cout << "Even-valued characters: " << endl;
    for (int i = 0; i < even_chars.size(); i++) {
        cout << even_chars[i] << '\t';
    }
    cout << endl << endl;

    // print odd characters and their ascii values:
    cout << "Total odd value: " << odd_sum << endl;
    cout << "Odd-valued characters: " << endl;
    for (int i = 0; i < odd_chars.size(); i++) {
        cout << odd_chars[i] << '\t';
    }
    cout << endl;
}

void print_vector(string& user_word, vector<char>& even_chars, vector<char>& odd_chars) {

}

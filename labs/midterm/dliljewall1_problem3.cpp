// CSC 123
// Assignment: Midterm Exam, Problem 3
// File Name: dliljewall1_problem3.cpp
// Author: David Liljewall
// Last Modified: 3/25/2020

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;


/// ----- FUNCTION DECLARATIONS ----- ///
void half_sums(int& lower_sum, int& upper_sum, int max_value);
//Takes a dictated max_value to find a middle point to break a list of numbers from
//1 to max_value into 2 equally-sized lists of numbers. The function calculates the
//sum of the numbers below and above the middle point (lower_sum & upper_sum).
//If there is not a middle point (i.e., if max_value is EVEN), the function splits the
//numbers into two equal-length lists. The sum of each list is then displayed.



/// ----- MAIN CODE BODY ----- ///
int main(){
    int l_sum = 0, u_sum = 0;

    half_sums(l_sum, u_sum, 7);
    cout << endl << "Low Sum: " << l_sum << " ---- " << "High Sum: " << u_sum << endl << endl;
    cout << "check for 7 >> values should be 6 - 18";

    half_sums(l_sum, u_sum, 26);
    cout << endl << "Low Sum: " << l_sum << " ---- " << "High Sum: " << u_sum << endl << endl;
    cout << "check for 26 >> values should be 91 - 260";

    half_sums(l_sum, u_sum, 15);
    cout << endl << "Low Sum: " << l_sum << " ---- " << "High Sum: " << u_sum << endl << endl;
    cout << "check for 15 >> values should be 28 - 84";

    half_sums(l_sum, u_sum, 18);
    cout << endl << "Low Sum: " << l_sum << " ---- " << "High Sum: " << u_sum << endl << endl;
    cout << "check for 18 >> values should be 45 - 126" << endl << endl;

    return 0;

}

/// ----- FUNCTION DEFINITIONS ----- ///
void half_sums(int& lower_sum, int& upper_sum, int max_value){

    int half_value;
    lower_sum = 0, upper_sum = 0; //initialize reference parameters to 0
    int counter;

    cout << endl << endl << "Counting Start >> " << endl << "> Max Value = " << max_value << endl;

    if(max_value % 2 != 0){
    //ODD case:
        counter = 1;
        half_value = (max_value / 2) + 1;
        
        cout << "> Middle Value: " << half_value << endl << "- Lower -" << "\t" << "- Higher -"  << endl;

        do{
            lower_sum += half_value - counter;
            upper_sum += half_value + counter;

            cout << half_value - counter << "\t\t" << half_value + counter << endl;

            counter++;
            

        } while(counter < half_value);
    }
    else{
    //EVEN case:
        half_value = max_value / 2;
        
        cout << "- Lower -" << "\t" << "- Higher -"  << endl;

        for(int i = 1; i <= half_value; i++){
            lower_sum += (half_value - i) + 1;
            upper_sum += half_value + i;
            cout << (half_value - i) + 1 << "\t\t" << half_value + i << endl;
        }     
    }
}

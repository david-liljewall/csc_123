#include <iostream>
#include <string>

using namespace std;

int main(){

    /* the following commands set the precision of doubles to be 
    whatever is inside the precision() command. In this case, a direct
    input from the terminal user*/

    int precision_of_decimals;
    cout << "Please enter the decimal precision you want for doubles: ";
    cin >> precision_of_decimals;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(precision_of_decimals);

    double number = 20.512354924893580945093534;

    cout << number << endl;
    
}

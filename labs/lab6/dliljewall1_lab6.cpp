// CSC 123
// Assignment: Lab #6
// File Name: dliljewall1_lab6.cpp
// Author: David Liljewall
// Last Modified: 3/15/2020

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

#define NDEBUG
    //the above #define automatically disables all asssert() statements in the entire .cpp file
#include <cassert>


/// ----- FUNCTION DECLARATIONS ----- ///
void set_values(int& tank_x, int value_x, int& tank_y, int value_y, int& tank_z, int value_z);
    //Function assigns the correspondant values to each fuel tank (x,y,z).
    //After the function is called all tanks must have the correspondant fuel tank assigned to it.

void add_to_all(int& tank_x, int& tank_y, int& tank_z, int value);
    //Function adds the integer "value" to each tank.
    //After the function is called all tanks must have this int value added to the original fuel value.

void directional_swap(int& tank_x, int& tank_y, int& tank_z, bool direction);
    //Function takes three fuel tanks and a direction to make a swap. The specifics swap condition is given
    //in the function definition below.

void distribute_to_others(int& tank_x, int value, int& tank_y, int& tank_z);
    //Function takes a source fuel tank, the amount of fuel to be taken out, and the two tanks that will
    //receive half of the fuel amount each. Fuel amount must be divisible by 2 - if it is not, error message
    //displayed

void randomize_tanks(int& tank_x, int& tank_y, int& tank_z, int limit);
    //Function takes 3 tanks and a limit value. Each tank gets assigned a new random value based on
    //the limit provided.


/// ----- MAIN CODE BODY ----- ///
int main()
{
    int left_tank = 0, middle_tank = 0, right_tank = 0; //initializes local variables
        //NOTE: left_tank ~ tank_x, middle_tank ~ tank_y, right_tank ~ tank_z

    srand(time(NULL)); //seeds random # generator with time at compile

    cout << " << START SIMULATION >> " << endl;
    cout << "Initial Values: LT=" << left_tank << " - MT:" << middle_tank << " - RT:" << right_tank << endl;

    cout << endl << "Set initial value of all tanks to  [50,100,25]" << endl;
    set_values(left_tank, 50, middle_tank, 100, right_tank, 25);
    cout << "Tank Values after set_values call: LT=" << left_tank << " - MT:" << middle_tank << " - RT:" << right_tank << endl;

    cout << endl << "Adding 30 to all tanks" << endl;
    add_to_all(left_tank, middle_tank, right_tank, 30);
    cout << "After Add to All call LT=" << left_tank << " - MT:" << middle_tank << " - RT:" << right_tank << endl;

    cout << endl << "Adding -21 to all tanks" << endl;
    add_to_all(left_tank, middle_tank, right_tank, -21);
    cout << "After Add to All call LT=" << left_tank << " - MT:" << middle_tank << " - RT:" << right_tank << endl;

    cout << endl << "Swap tanks contents to the right" << endl;
    directional_swap(left_tank, middle_tank, right_tank, true);
    cout << "After switching content to the right LT=" << left_tank << " - MT:" << middle_tank << " - RT:" << right_tank << endl;

    cout << endl << "Adding 17 to all tanks" << endl;
    add_to_all(left_tank, middle_tank, right_tank, 17);
    cout << "After Add to All call LT=" << left_tank << " - MT:" << middle_tank << " - RT:" << right_tank << endl;

    cout << endl << "Swap tanks contents to the left" << endl;
    directional_swap(left_tank, middle_tank, right_tank, false);
    cout << "After switching content to the left LT=" << left_tank << " - MT:" << middle_tank << " - RT:" << right_tank << endl;

    cout << endl << "Swap tanks contents to the left" << endl;
    directional_swap(left_tank, middle_tank, right_tank, false);
    cout << "After switching content to the left LT=" << left_tank << " - MT:" << middle_tank << " - RT:" << right_tank << endl;

    cout << endl << "Distribute from one tank to the others (  value 5, TESTING ERROR - nothing changes )" << endl;
    distribute_to_others(left_tank, 5, middle_tank, right_tank);
    cout << "After trying to distribute a value not divisible by 2 LT=" << left_tank << " - MT:" << middle_tank << " - RT:" << right_tank << endl;

    cout << endl << "Distribute from left_tank to the others ( Correct value 46 )" << endl;
    distribute_to_others(left_tank, 46, middle_tank, right_tank);
    cout << "After trying to distribute a value that is divisible by 2 LT=" << left_tank << " - MT:" << middle_tank << " - RT:" << right_tank << endl;

    cout << endl << "Distribute from right_tank to the others ( Correct value 60 )" << endl;
    distribute_to_others(right_tank, 60, middle_tank, left_tank);
    cout << "After trying to distribute a value that is divisible by 2 LT=" << left_tank << " - MT:" << middle_tank << " - RT:" << right_tank << endl;

    cout << endl << "Randomize tank values for all tanks with a max value of 100" << endl;
    randomize_tanks(left_tank, middle_tank, right_tank, 100);
    cout << "After randomization LT=" << left_tank << " - MT:" << middle_tank << " - RT:" << right_tank << endl;

    cout << "<< END-ERZ >>" << endl;

    return 0;

}


/// ----- FUNCTION DEFINITIONS ----- ///
void set_values(int& tank_x, int value_x, int& tank_y, int value_y, int& tank_z, int value_z){

    tank_x = value_x; //sets the value of the variable at this memory location (tank_x) to value_x.
    tank_y = value_y;
    tank_z = value_z;

}

void add_to_all(int& tank_x, int& tank_y, int& tank_z, int value){

    tank_x += value; //adds the int "value" to the value of the variable at mem. loc. corresponding to tank_x
    tank_y += value;
    tank_z += value;

}

void directional_swap(int& tank_x, int& tank_y, int& tank_z, bool direction){

    int temp1 = tank_x; //temp1 set to value of tank_x at function call
    int temp2 = tank_y; //temp2 set to value of tank_y at function call
    int temp3 = tank_z; //temp3 set to value of tank_z at function call

    //moves tank values to the right:
    if(direction == true){
        tank_x = temp3; //swap tank_x with tank_z
        tank_y = temp1; //swap tank_y with tank_x
        tank_z = temp2; //swap tank_z with tank_y
    }
    //moves tank values to the left:
    else{
       tank_x = temp2; //swap tank_x with tank_y
       tank_y = temp3; //swap tank_y with tank_z
       tank_z = temp1; //swap tank_z with tank_x
    }

}

void distribute_to_others(int& tank_x, int value, int& tank_y, int& tank_z){

    //takes .5*value from tank_x (source) and distributes it between the non-source tanks
    if(value % 2 == 0){
        tank_x -= value; //amount of fuel in tank_x decreases by value
        tank_y += 0.5*value; //amount of fuel in tank_y increases by .5*value
        tank_z += 0.5*value; //amount of fuel in tank_z increases by .5*value
    }
    //nothing changes:
    else{
        tank_x = tank_x;
        tank_y = tank_y;
        tank_z = tank_z;
    }
}

void randomize_tanks(int& tank_x, int& tank_y, int& tank_z, int limit){

    tank_x = (rand() % limit); //randomizes value of tank_x up the limit
    tank_y = (rand() % limit);
    tank_z = (rand() % limit); 
}

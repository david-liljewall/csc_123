// CSC 123
// Assignment: Midterm Exam, Problem 4
// File Name: dliljewall1_problem4.cpp
// Author: David Liljewall
// Last Modified: 3/25/2020

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;


/// ----- FUNCTION DECLARATIONS ----- ///
int get_year_event();
    // Returns a random integer between 0 and 4 --> This is the "Event ID"
    // Event ID's are defined as follows:
    // 0 --> Add 5 UOFs (Units of Fuel) to all 3 tanks.
    // 1 --> Reduce all tanks by half.
    // 2 --> Left or Right tank set to 0.
    // 3 --> Randomize all tank UOFs.
    // 4 --> Remove 15 units from all tanks.
    // After each year & event, the tanks are checked for negative UOF values; if negative, they are set to 0
    // LOSE = All tanks are empty, player doesn't reach Magrathea
    // WIN = 10 light years have been traversed and the player reaches Magrathea

void set_values(int& tank_x, int value_x, int& tank_y, int value_y, int& tank_z, int value_z);
    //Function assigns the correspondant values to each fuel tank (x,y,z).
    //After the function is called all tanks must have the correspondant fuel tank assigned to it.

void add_5_UOFs(int& tank_x, int& tank_y, int& tank_z);
    //Function adds 5 UOFs to all 3 tanks
void subtract_15_UOFs(int& tank_x, int& tank_y, int& tank_z);
    //Function subtracts 15 UOFs from each tank.
void halve_tank_UOFs(int& tank_x, int& tank_y, int& tank_z);
    //Function reduces all tank UOFs to half their value
void zero_tank_UOFs(int& tank_x, int& tank_z);
    //Function zeros either the left or right tank


void directional_swap(int& tank_x, int& tank_y, int& tank_z, bool direction);
    //Function takes three fuel tanks and a direction to make a swap. The specifics swap condition is given
    //in the function definition below.
void distribute_to_others(int& tank_x, int value, int& tank_y, int& tank_z);
    //Function takes a source fuel tank (tank_x), the amount of fuel to be taken out, and the two tanks that will
    //receive half of the fuel amount each. Fuel amount must be divisible by 2 - if it is not, error message
    //displayed
void randomize_tanks(int& tank_x, int& tank_y, int& tank_z);
    //Function takes 3 tanks and a limit value. Each tank gets assigned a new random value based on
    //the limit provided.

/// ----- MAIN CODE BODY ----- ///
int main(){
    srand(time(NULL)); //seeds random # generator with time at compile
    
    int left_tank = 0, middle_tank = 0, right_tank = 0; //initializes tank variables
        //NOTE: left_tank ~ tank_x, middle_tank ~ tank_y, right_tank ~ tank_z
    int travel_time_remaining = 10;
        //travel time remaining in years. 


    cout << " << START SIMULATION >> " << endl;
    set_values(left_tank, 50, middle_tank, 100, right_tank, 50);
    cout << "Initializing Warping Fuel Tanks: ( " << left_tank << ", " << middle_tank << ", " << right_tank 
    << " ) Units" <<  endl << endl;

    //perform the following till arrival
    while(travel_time_remaining > 0){
        if(left_tank > 0 || middle_tank > 0 || right_tank > 0){
        //perform the following while there is still available fuel
            //randomize the event_id, and perform the corresponding case below:
            int event_id = get_year_event();
            switch(event_id){
                case 0:{
                // Add 5 UOFs to all 3 tanks
                    cout << endl << "Years to Arrival: " << travel_time_remaining << endl;

                    cout << "\t\t You travel the light year without any problems." << endl
                    << "\t\t You only used half of your fuel for this year. 5 Units of Fuel added " 
                    << "to each tank." << endl;

                    add_5_UOFs(left_tank, middle_tank, right_tank);

                    cout << "Warping Fuel Tanks status:" << endl
                    << "Left Tank (LT): " << left_tank << endl
                    << "Middle Tank (MT): " << middle_tank << endl
                    << "Right Tank (RT): " << right_tank << endl
                    << endl;

                    travel_time_remaining--; // 1 year elapsed
                    break;
                }
                case 1:{
                // Reduce all tanks by half
                    cout << endl << "Years to Arrival: " << travel_time_remaining << endl;

                    cout << "\t\t You travel the light year but your spaceship encountered pirates." << endl
                    << "\t\t They stole half of the Fuel Units from each tank." 
                    << endl << endl;

                    halve_tank_UOFs(left_tank, middle_tank, right_tank);

                    cout << "Warping Fuel Tanks status:" << endl
                    << "Left Tank (LT): " << left_tank << endl
                    << "Middle Tank (MT): " << middle_tank << endl
                    << "Right Tank (RT): " << right_tank << endl
                    << endl;

                    travel_time_remaining--; // 1 year elapsed
                    break;
                }
                case 2:{
                // Left or Right tank is set to 0
                    cout << endl << "Years to Arrival: " << travel_time_remaining << endl;

                    zero_tank_UOFs(left_tank, right_tank);

                    if(left_tank == 0){
                        cout << "\t\t You travel the light year through a meteor belt. " << endl
                        << "\t\t One of your tanks lost all its Fuel Units." << endl
                        <<" \t\t You lost all Fuel Units in the left tank!" << endl << endl;
                    }
                    else if(right_tank == 0){
                        cout << "\t\t You travel the light year through a meteor belt. " << endl
                        << "\t\t One of your tanks lost all its Fuel Units." << endl
                        <<" \t\t You lost all Fuel Units in the right tank!" 
                        << endl << endl;
                    }

                    cout << "Warping Fuel Tanks status:" << endl
                    << "Left Tank (LT): " << left_tank << endl
                    << "Middle Tank (MT): " << middle_tank << endl
                    << "Right Tank (RT): " << right_tank << endl
                    << endl;

                    travel_time_remaining--; // 1 year elapsed
                    break;
                }
                case 3:{
                // Randomize all tank UOFs
                    cout << endl << "Years to Arrival: " << travel_time_remaining << endl;

                    cout << "\t\t A jump in space!! " << endl
                    << "\t\t Your ship went through a collapsing neutron star inside an Einstein-Rosen bridge." 
                    << endl << "\t\t Reality has changed and all your tanks have random Fuel Units with a max value of 20"
                    << endl << endl;

                    randomize_tanks(left_tank, middle_tank, right_tank);

                    cout << "Warping Fuel Tanks status:" << endl
                    << "Left Tank (LT): " << left_tank << endl
                    << "Middle Tank (MT): " << middle_tank << endl
                    << "Right Tank (RT): " << right_tank << endl
                    << endl;

                    travel_time_remaining--; // 1 year elapsed
                    break;
                }
                case 4:{
                // Remove 15 UOFs from all tanks
                    cout << endl << "Years to Arrival: " << travel_time_remaining << endl;

                    cout << "\t\t DANGER!!! DANGER!!! " << endl
                    << "\t\t Your ship traveled too close to a Black Hole!" << endl
                    << "\t\t The gravitational pull caused all your tanks to lose 15 Fuel Units each." 
                    << endl << endl;


                    subtract_15_UOFs(left_tank, middle_tank, right_tank);

                    //the below checks are to set tanks to 0 if they go negative from fuel subtraction
                    if(left_tank < 0){
                        left_tank = 0;
                    }
                    if(middle_tank < 0){
                        middle_tank = 0;
                    }
                    if(right_tank < 0){
                        right_tank = 0;
                    }

                    cout << "Warping Fuel Tanks status:" << endl
                    << "Left Tank (LT): " << left_tank << endl
                    << "Middle Tank (MT): " << middle_tank << endl
                    << "Right Tank (RT): " << right_tank << endl
                    << endl;

                    travel_time_remaining--; // 1 year elapsed
                    break;
                }
            }
        }
        else if(left_tank == 0 && middle_tank == 0 && right_tank == 0){
        //ran out of fuel, mission failed!
            cout << "You failed!" << endl
            << "<< END-ERZ >> " << endl << endl;
        }
        //Prompt user to choose between two options before performing next light-year jump:
        MENU_PROMPT: //if user enters invalid option, start the prompt over again by returning to this line
        int option;
        cout << "Before performing the next light-speed run, choose between the following: " << endl
        << "1) --> Distribute equally from the left_tank to the other two" << endl
        << "2) --> Shift to the left or right the contents of all 3 tanks (i.e., left swap shifts all UOF values of the "
        << " tanks to the left-adjacent tank; right_tank to middle_tank, etc." << endl;
        cin >> option;
        cout << endl;

        if(option == 1){
            DISTRIBUTE_PROMPT: //if user enters a non-even number for fuel_value, prompt them again
            cout << "Please enter the total amount of fuel you want to distribute evenly from LT to the other two tanks (NOTE: must be an even integer): "
            << endl << endl;
            int fuel_value; //amount of fuel to be distributed
            cin >> fuel_value;
            if(fuel_value % 2 == 0){
            //even case:
                distribute_to_others(left_tank, fuel_value, middle_tank, right_tank);
            }
            else{
                //odd case:
                goto DISTRIBUTE_PROMPT;
            }
            
            //the below checks are to set tanks to 0 if they go negative from fuel subtraction
                if(left_tank < 0){
                    left_tank = 0;
                }
                if(middle_tank < 0){
                    middle_tank = 0;
                }
                if(right_tank < 0){
                    right_tank = 0;
                }

            cout << "Warping Fuel Tanks status:" << endl
            << "Left Tank (LT): " << left_tank << endl
            << "Middle Tank (MT): " << middle_tank << endl
            << "Right Tank (RT): " << right_tank << endl
            << endl;
        }
        else if(option == 2){
            int direction;
            cout << "Please enter the direction you want to shift the contents of the tanks" << endl
            << "1) --> Shift contents to the RIGHT" << endl
            << "2) --> Shift contents to the LEFT" << endl;
            cin >> direction;
            cout << endl;

            if(direction == 1){
                directional_swap(left_tank, middle_tank, right_tank, true);
            }
            else if(direction == 2){
                directional_swap(left_tank, middle_tank, right_tank, false);
            }
            else{
                cout << "Invalid option, please try again" << endl << endl;
                goto MENU_PROMPT;
            }

            //the below checks are to set tanks to 0 if they go negative from fuel subtraction
                if(left_tank < 0){
                    left_tank = 0;
                }
                if(middle_tank < 0){
                    middle_tank = 0;
                }
                if(right_tank < 0){
                    right_tank = 0;
                }

            cout << "Warping Fuel Tanks status:" << endl
            << "Left Tank (LT): " << left_tank << endl
            << "Middle Tank (MT): " << middle_tank << endl
            << "Right Tank (RT): " << right_tank << endl
            << endl;
        }
        else{
            //if invalid response, return to MENU_PROMPT location to repeat menu
            cout << "Invalid option, please try again" << endl << endl;
            goto MENU_PROMPT;
        } 
    }

    cout << "Magrathea! Magrathea! You reach your destination." << endl
    << "<< END-ERZ >> " << endl << endl;
}


/// ----- FUNCTION DEFINITIONS ----- ///
int get_year_event(){
    int max_value = 5;

    int id = rand() % max_value; 

    return id;
}

void set_values(int& tank_x, int value_x, int& tank_y, int value_y, int& tank_z, int value_z){
    tank_x = value_x; //sets the value of the variable at this memory location (tank_x) to value_x.
    tank_y = value_y;
    tank_z = value_z;

}

void add_5_UOFs(int& tank_x, int& tank_y, int& tank_z){
    int value = 5; 

    tank_x += value; 
    tank_y += value;
    tank_z += value;
}

void subtract_15_UOFs(int& tank_x, int& tank_y, int& tank_z){
    int value = 15; 

    tank_x -= value; 
    tank_y -= value;
    tank_z -= value;
}

void halve_tank_UOFs(int& tank_x, int& tank_y, int& tank_z){
    int(tank_x /= 2);
    int(tank_y /= 2);
    int(tank_z /= 2);
}

void zero_tank_UOFs(int& tank_x, int& tank_z){
    if(rand() % 2 == 0){
    //even case:
        tank_x = 0;
    }
    else{
    //odd case:
        tank_z = 0;
    }
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

void randomize_tanks(int& tank_x, int& tank_y, int& tank_z){
    int limit = 20; //max UOFs for each tank after randomization

    tank_x = (rand() % limit); //randomizes value of tank_x up the limit
    tank_y = (rand() % limit);
    tank_z = (rand() % limit); 
}


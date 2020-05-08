// CSC 123
// Assignment: Problem #2
// File Name: dliljewall1_problem2.cpp
// Author: David Liljewall
// Last Modified: 5/16/2020

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>

using namespace std;

#define MAX_POTS 32000 // max number of pots allowed in program

/* -------------------------------------------------------------------------- */
/*                             STRUCT DECLARATIONS                            */
/* -------------------------------------------------------------------------- */
struct Pot {
    // 
    int plant_days; // how many days since a monster plant moved in (cell was filled)
    bool is_planted; // tells whether or not pot has a monster plant in it
};



/* -------------------------------------------------------------------------- */
/*                            FUNCTION DECLARATIONS                           */
/* -------------------------------------------------------------------------- */
void initialize_pots(Pot axis[], int& pots_n, int& monsters_n);
    // Based on user-input for # of monster plants to start with, place them 
    // randomly along the line of pots.

void populate_pots(Pot axis[], int& pots_n, int& monsters_n);
    //

void update_pots(Pot axis[], int& pots_n, int& monsters_n);
    // Updates the line of pots after each day, whereby the monster plants can duplicate
    // to adjacent pots IF they are already empty.

void display_pots(Pot axis[], int& pots_n, int& monsters_n, int& days);
    // Displays the line of pots for a given day, showing whether a pot is filled with 
    // a monster plant, and the # of days since a monster plant moved in.

/* -------------------------------------------------------------------------- */
/*                                MAIN FUNCTION                               */
/* -------------------------------------------------------------------------- */
int main() {

    // NOTE: simulation goes until ALL pots are filled.
    srand(unsigned(time(NULL))); // seeds random number generator

    int n_pots(0), n_monsters(0); // tracks # of pots and # of monster plants
    int n_days(0); // tracks the number of days (for terminal display purposes)

    //* create dynamic memory for the game grid:
    struct Pot axis[n_pots]; // create a horizontal axis[] to be filled with monsters thru simulation 

    cout << " How many pots do you want to start with? (maximum of 32k)" << endl;
    cin >> n_pots;
    cout << " How many monster plants to start?" << endl;
    cin >> n_monsters;

    initialize_pots(axis, n_pots, n_monsters);
    populate_pots(axis, n_pots, n_monsters);
    
    
    // NOTE: Simulation starts below:
    do {
        display_pots(axis, n_pots, n_monsters, n_days);


        n_days++; // increment # of days

    } while (n_monsters < n_pots);

    getchar();
    
    return 0;
}

/* -------------------------------------------------------------------------- */
/*                            FUNCTION DEFINITIONS                            */
/* -------------------------------------------------------------------------- */

void initialize_pots(Pot axis[], int& pots_n, int& monsters_n) {

    for (int i = 0; i < pots_n; i++) {
        axis[i].is_planted = false;
        axis[i].plant_days = 0;
    }

}

void populate_pots(Pot axis[], int& pots_n, int& monsters_n) {
    int monster_number = 0; // initialize number of potted monster plants
    int x_rand; // randomized cubicle x index

    // populate axis with monster plants:
    while (monster_number < monsters_n) {
        x_rand = rand() % pots_n + 1;

        // if not filled with monster plant already
        if (!axis[x_rand].is_planted) {

            axis[x_rand].is_planted = true;
        }
        monster_number++;
    }
}

void update_pots(Pot axis[], int& pots_n, int& monsters_n) {
    int monster_number;

    for (int i = 0; i < pots_n; i++) {
        
        if (axis[i].is_planted) {
            
            axis[i].plant_days += 1;
        }
        else if(!axis[i].is_planted) {

        }

    }

}

void display_pots(Pot axis[], int& pots_n, int& monsters_n, int& days) {
    cout << " << Day " << days << " : " << endl;


}
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
    // struct Pot member variables defined below:

    int plant_days; // how many days since a monster plant moved in (cell was filled)
    bool is_planted; // tells whether or not pot has a monster plant in it

};



/* -------------------------------------------------------------------------- */
/*                            FUNCTION DECLARATIONS                           */
/* -------------------------------------------------------------------------- */
void initialize_pots(Pot axis[], int& pots_n, int& monsters_n);
    // Based on user-input for # of monster plants to start with, place them 
    // randomly along the line of pots.

void monster_duplication_edge(Pot axis[], int& pots_n, int& monsters_n);
    // Duplicates an existing potted monster plant to an adjacent empty pot.

void monster_duplication_middle(Pot axis[], int& pots_n, int& monsters_n);
    //

void update_pots(Pot axis[], int& pots_n);
    // Updates the line of pots after each day

void display_pots(Pot axis[], int& pots_n, int& days);
    // Displays the line of pots for a given day, showing whether a pot is filled with 
    // a monster plant, and the # of days since a monster plant moved in.

/* -------------------------------------------------------------------------- */
/*                                MAIN FUNCTION                               */
/* -------------------------------------------------------------------------- */
int main() {

    srand(unsigned(time(NULL))); // seeds random number generator

    int n_pots = 0, n_monsters = 0; // tracks # of pots and # of monster plants
    int n_days = 0; // tracks the number of days (for terminal display purposes)


    // create dynamic memory for the simulation axis:
    struct Pot *grid; // create struct object pointer which points to dynamic 1D array which defines the 1D grid of the simulation

    cout << " How many pots do you want to start with? (maximum of 32k)" << endl;
    cin >> n_pots;

    grid = new Pot[n_pots]; // initialize a dynamic array grid[]

    
    // continue to simulation only if n_pots is less than defined maximum:
    if (n_pots > MAX_POTS) {
        cout << " # of pots entered is larger than 32k... exiting simulation " << endl;
        exit(1);
    }
    else {
        cout << " How many monster plants to start?" << endl;
        cin >> n_monsters;

        cout << " << Simulation Start >> " << endl << endl;
        display_pots(grid, n_pots, n_days);        
        initialize_pots(grid, n_pots, n_monsters);

        n_days++;
        update_pots(grid, n_pots); 
        display_pots(grid, n_pots, n_days);

       
        do {
            n_days++; // increment # of days
            monster_duplication_middle(grid, n_pots, n_monsters);
            monster_duplication_edge(grid, n_pots, n_monsters);
            update_pots(grid, n_pots);
            display_pots(grid, n_pots, n_days);

        } while (n_monsters <= n_pots);

        // getchar();
    }

    // delete dynamic array grid[] and set to NULL to prevent memory leaks:
    delete[] grid;
    grid = NULL;

    getchar();

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                            FUNCTION DEFINITIONS                            */
/* -------------------------------------------------------------------------- */

void initialize_pots(Pot axis[], int& pots_n, int& monsters_n) {
    
    int monster_number = 0;
    int i_rand = 0;
    
    // initialize struct member variables before simulation starts:
    for (int i = 0; i < pots_n; i++) {

        axis[i].is_planted = false;
        axis[i].plant_days = 0;

    }

    i_rand = rand() % pots_n; // i_rand between 0 and number of pots chosen by user
    // populate axis with user-entered number of monster plants:
    while (monster_number < monsters_n) {
        

        if (!axis[i_rand].is_planted) {

            axis[i_rand].is_planted = true;
            monster_number++; // tracks how many monsters have been populated

        }

        i_rand = rand() % pots_n; // set new i_rand

    }

}

void monster_duplication_edge(Pot axis[], int& pots_n, int& monsters_n) {

    int i = 0; // left-most pot index
    if (!axis[i].is_planted) {
        // check pot to the right
        if (axis[i + 1].is_planted) {
        
        axis[i].is_planted = true;
        monsters_n++; // increment # of monster plants

        }
            
    }

    i = pots_n - 1; // right-most pot index
    if (!axis[i].is_planted) {
        // check pot to the left
        if (axis[i - 1].is_planted) {
        
        axis[i].is_planted = true;
        monsters_n++; // increment # of monster plants

        }
            
    }
    
}

void monster_duplication_middle(Pot axis[], int& pots_n, int& monsters_n) {

    // start at first non-edge pot, go till 2nd to last pot (1st and last are the edges)
    int i = 1;
    while(i < pots_n - 1) {
        if(!axis[i].is_planted) {
            // check pot to the left
            if(axis[i - 1].is_planted) {
                axis[i].is_planted = true;
                monsters_n++;
                i+=2;
            }
            // check pot to the right
            else if (axis[i + 1].is_planted) {
                axis[i].is_planted = true;
                monsters_n++;
            }
            else {
                i++;
            }
        }
        else {
            i++;
        }
    }

}

void update_pots(Pot axis[], int& pots_n) {
    
    for (int i = 0; i < pots_n; i++) {
        
        if (axis[i].is_planted) {
            
            axis[i].plant_days += 1; // incremement # of plant days on planted pots
        }
    }
}

void display_pots(Pot axis[], int& pots_n, int& days) {
    cout << " << Day " << days << ": " << endl;

    for (int i = 0; i < pots_n; i++) {

        if (axis[i].is_planted) {
            cout << "\t[ " << axis[i].plant_days << " ]";
        }
        else {
            cout << "\t[ " << "-" << " ]";
        }

    }

    cout << endl; // add extra whitespace


}
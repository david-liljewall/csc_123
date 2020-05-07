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
    int plant_days;
    bool is_planted;
};



/* -------------------------------------------------------------------------- */
/*                            FUNCTION DECLARATIONS                           */
/* -------------------------------------------------------------------------- */


/* -------------------------------------------------------------------------- */
/*                                MAIN FUNCTION                               */
/* -------------------------------------------------------------------------- */
int main() {

    struct Pot pot;
    int n_pots, n_monsters;

    cout << " How many pots do you want to start with? (maximum of 32k)" << endl;
    cin >> n_pots;

    cout << " How many monster plants to start?" << endl;
    cin >> n_monsters;
}

/* -------------------------------------------------------------------------- */
/*                            FUNCTION DEFINITIONS                            */
/* -------------------------------------------------------------------------- */
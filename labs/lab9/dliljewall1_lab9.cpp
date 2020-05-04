// CSC 123
// Assignment: Lab #9
// File Name: dliljewall1_lab9.cpp
// Author: David Liljewall
// Last Modified: 4/22/2020

//* NOTE: Anything with a "#" before it is called a PREPROCESSOR DIRECTIVE 
//* In the case of the #define lines, before the code is compiled, these values are checked within the code to ensure no illegal operations are done, 
//* i.e., that you try to use an EDGE_AREA of 6, when it is defined as 5).
//* The C++ Preprocessor program is executed before the source code is compiled

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>

// Define symbolic constants below:
#define MAX_GRID 8
#define CHECK_AREA 8
#define CORNER_AREA 3
#define EDGE_AREA 5

using namespace std;

/* -------------------------------------------------------------------------- */
/*                             STRUCT DECLARATIONS                            */
/* -------------------------------------------------------------------------- */
struct Grid_Cubicle {
    // struct Grid_Cubicle member variables defined below:
    bool has_troll;
    bool has_potion;
    bool is_visible;
    bool is_done;
    int vecinity_trolls;
    int vecinity_potions;
};

struct Wizard {
    // struct Wizard member variables defined below:
    int health;    
};



/* -------------------------------------------------------------------------- */
/*                            FUNCTION DECLARATIONS                           */
/* -------------------------------------------------------------------------- */
void populate_grid(Grid_Cubicle game_grid[][MAX_GRID], int troll_n, int potion_n);
    // Receives game_grid[][] as a reference parameter, and troll_n & potion_n as parameters by value.
    // troll_n dictates how many Trolls to add to the grid.
    // potion_n dictates how many Potions to add to the grid.
    // This function adds the number of Trolls and number of Potions to the grid with the following guidelines:
    // 1. --> 1 Troll per cubicle
    // 2. --> 1 Potion per cubicle
    // 3. --> A single cubicle CANNOT have a Troll and a Potion. It has either one, only.

void evaluate_middle_cell(Grid_Cubicle game_grid[][MAX_GRID], int x, int y, int& troll_n, int& potion_n);

void evaluate_edges_cell(Grid_Cubicle game_grid[][MAX_GRID], int x, int y, int& troll_n, int& potion_n);

void update_grid(Grid_Cubicle game_grid[][MAX_GRID]);
    // Receives game_grid[][] as a reference parameter, and checks each cubicle at a time by looking at its
    // surrounding cubicles. The function then updates the values for vecinity_trolls and vecinity_potions for 
    // each cubicle. 

void initialize_grid(Grid_Cubicle game_grid[][MAX_GRID]);
    // Recieves game_grid[][] as a parameter by reference (within the Grid_Cubicle struct).
    // Sets all member values of game_grid[][] to default values (0 or false).

void display_grid(Grid_Cubicle game_grid[][MAX_GRID], bool debug_mode);
    // Receives game_grid[][] as a paramter by reference, and a boolean variable debug_mode that displays
    // the entire grid without hiding any cell to do a quick check, or see how the player would see the board.

void display_player_health(int& health);
    // Displays current player health before each turn

void cubicle_select(Grid_Cubicle game_grid[][MAX_GRID], int& x, int& y);
    // Prompts user to select a cubicle to reveal for each turn of game

void cubicle_check(Grid_Cubicle game_grid[][MAX_GRID], int& troll_n, int& health, int& x, int& y);
    // Checks the selected cubicle to determine if the cubicle:
    // 1. Is Empty, no proximity to Troll and/or Potion
    // 2. Is Empty, but in proximity to Troll and/or Potion
    // 3. Has a potion --> increaes player health
    // 4. Has a Troll --> Reduces player health
    // Then the function makes the cubicle visible to the user.


/* -------------------------------------------------------------------------- */
/*                                MAIN FUNCTION                               */
/* -------------------------------------------------------------------------- */
int main() {
    
    struct Grid_Cubicle grid[MAX_GRID][MAX_GRID]; // create Grid_Cubicle struct variable grid[][].
    struct Wizard Ron; // create Wizard struct variable Ron
   
    srand(unsigned(time(NULL))); // seed random number generator at compile time

    initialize_grid(grid);    
    // display_grid(grid, true);
   
    populate_grid(grid, 5, 5);
    // display_grid(grid, true);

    update_grid(grid);
    // display_grid(grid, true);
    // display_grid(grid, false);


    // Initialize game variables:
    Ron.health = 10;
    int troll_count = 5;
    int turn_count = 1; // tracks how many turns the player performs
    int X, Y; 

    // NOTE: This is where the game begins:
    cout << endl << endl << " << START GAME! >> " << endl;
    cout << " << The game begins with 5 total Potions, and 5 total Trolls" << endl;
    // Play game while Ron has health and there are still trolls on the grid
    while(Ron.health > 0 && troll_count > 0){
        // Display the grid and player health at the start of each turn:
        display_player_health(Ron.health);
        display_grid(grid, false);

        cubicle_select(grid, X, Y);
        cubicle_check(grid, troll_count, Ron.health, X, Y);
        update_grid(grid);

        turn_count++;
    }
    if(troll_count == 0) {
        cout << " << Ron has defeated all of the trolls without dying. CONGRATULATIONS, YOU WIN!!" << endl << endl;

    }
    else if(Ron.health <= 0) {
        cout << " << Ron died. YOU LOST! Better luck next time." << endl << endl;

    }

    cout << " << Total # of turns was: " << turn_count << endl << endl;
    getchar();
    
}


/* -------------------------------------------------------------------------- */
/*                            FUNCTION DEFINITIONS                            */
/* -------------------------------------------------------------------------- */
void populate_grid(Grid_Cubicle game_grid[][MAX_GRID], int troll_n, int potion_n) {
    int troll_number = 0;
    int potion_number = 0;
    
    int x_rand; // randomized cubicle x index
    int y_rand; // randomized cubicle y index 


    // populate board with trolls:
    while(troll_number < troll_n) {
        x_rand = rand() % MAX_GRID;
        y_rand = rand() % MAX_GRID; 

        if(!game_grid[x_rand][y_rand].has_troll) {
            // populate cubicle with troll
            game_grid[x_rand][y_rand].has_troll = true; 
        }

        troll_number++;
    }

    // populate board with potions:
    while(potion_number < potion_n) {
        x_rand = rand() % MAX_GRID;
        y_rand = rand() % MAX_GRID;

        if((!game_grid[x_rand][y_rand].has_potion) && (!game_grid[x_rand][y_rand].has_troll) ) {
            // if empty, populate cubicle with potion
            game_grid[x_rand][y_rand].has_potion = true;

        }
        else if(game_grid[x_rand][y_rand].has_potion || (game_grid[x_rand][y_rand].has_troll) ){
            // if populated with potion or troll, go to new cubicle and populate with a potion
            x_rand = rand() % MAX_GRID;
            y_rand = rand() % MAX_GRID;

            game_grid[x_rand][y_rand].has_potion = true;
        }  

        potion_number++;
    }
}


void evaluate_middle_cell(Grid_Cubicle game_grid[][MAX_GRID], int x, int y, int& troll_n, int& potion_n) {

    int idx_x[CHECK_AREA] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int idx_y[CHECK_AREA] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int troll_counter = 0;
    int potion_counter = 0;
       
    for (int i = 0; i < CHECK_AREA; i++) {
        if (game_grid[x + idx_x[i]][y + idx_y[i]].has_troll) {
            troll_counter++;
        }
        else {
            if (game_grid[x + idx_x[i]][y + idx_y[i]].has_potion) {
                potion_counter++;
            }
        }
    }

    troll_n = troll_counter;
    potion_n = potion_counter;
}

void evaluate_edges_cell(Grid_Cubicle game_grid[][MAX_GRID], int x, int y, int& troll_n, int& potion_n) {
    int troll_counter = 0;
    int potion_counter = 0;

    // upper left corner
    if (x == 0 && y == 0) {
        
        int idx_x[CORNER_AREA] = { 1, 0, 1 };
        int idx_y[CORNER_AREA] = {0, 1, 1 };

        for (int i = 0; i < CORNER_AREA; i++) {
            if (game_grid[x + idx_x[i]][y + idx_y[i]].has_troll) {
                troll_counter++;
            }
            else {
                if (game_grid[x + idx_x[i]][y + idx_y[i]].has_potion) {
                    potion_counter++;
                }
            }
        }       
    }   

    // top middle edge
    if (x > 0 && x < ( MAX_GRID -1 ) && y == 0) {

        int idx_x[EDGE_AREA] = { -1, 1, -1, 0, 1  };
        int idx_y[EDGE_AREA] = {  0, 0,  1, 1, 1 };

        for (int i = 0; i < EDGE_AREA; i++) {
            if (game_grid[x + idx_x[i]][y + idx_y[i]].has_troll) {
                troll_counter++;
            }
            else {
                if (game_grid[x + idx_x[i]][y + idx_y[i]].has_potion) {
                    potion_counter++;
                }
            }
        }
    }

  
    // right top corner
    if (x == (MAX_GRID - 1) && y == 0) {
        int idx_x[CORNER_AREA] = { -1, -1, 0 };
        int idx_y[CORNER_AREA] = { 0, 1, 1 };

        for (int i = 0; i < CORNER_AREA; i++) {
            if (game_grid[x + idx_x[i]][y + idx_y[i]].has_troll) {
                troll_counter++;
            }
            else {
                if (game_grid[x + idx_x[i]][y + idx_y[i]].has_potion) {
                    potion_counter++;
                }
            }
        }
    }


    // left middle edge
    if (x == 0 && y > 0 && y < (MAX_GRID - 1)) {

        int idx_x[EDGE_AREA] = { 0,  1, 1, 0, 1 };
        int idx_y[EDGE_AREA] = { -1, -1, 0, 1, 1 };

        for (int i = 0; i < EDGE_AREA; i++) {
            if (game_grid[x + idx_x[i]][y + idx_y[i]].has_troll) {
                troll_counter++;
            }
            else {
                if (game_grid[x + idx_x[i]][y + idx_y[i]].has_potion) {
                    potion_counter++;
                }
            }
        }
    }

    // right middle edge
    if (x == (MAX_GRID-1) && y > 0 &&  y < (MAX_GRID - 1)) {

        int idx_x[EDGE_AREA] = { -1,  0, -1, -1, 0 };
        int idx_y[EDGE_AREA] = { -1, -1, 0, 1, 1 };

        for (int i = 0; i < EDGE_AREA; i++) {
            if (game_grid[x + idx_x[i]][y + idx_y[i]].has_troll) {
                troll_counter++;
            }
            else {
                if (game_grid[x + idx_x[i]][y + idx_y[i]].has_potion) {
                    potion_counter++;
                }
            }
        }
    }


    // bottom left corner
    if (x == 0 && y == (MAX_GRID - 1)) {
        int idx_x[CORNER_AREA] = { 0, 1, 1 };
        int idx_y[CORNER_AREA] = { -1, -1, 0 };

        for (int i = 0; i < CORNER_AREA; i++) {
            if (game_grid[x + idx_x[i]][y + idx_y[i]].has_troll) {
                troll_counter++;
            }
            else {
                if (game_grid[x + idx_x[i]][y + idx_y[i]].has_potion) {
                    potion_counter++;
                }
            }
        }
    }


    // middle edge bottom
    if (x > 0 && x < (MAX_GRID - 1) && y == (MAX_GRID - 1)) {

        int idx_x[EDGE_AREA] = { -1,  0, 1, -1, 1 };
        int idx_y[EDGE_AREA] = { -1, -1, -1, 0, 0 };

        for (int i = 0; i < EDGE_AREA; i++) {
            if (game_grid[x + idx_x[i]][y + idx_y[i]].has_troll) {
                troll_counter++;
            }
            else {
                if (game_grid[x + idx_x[i]][y + idx_y[i]].has_potion) {
                    potion_counter++;
                }
            }
        }
    }

    // bottom right corner
    if (x == (MAX_GRID - 1) && y == (MAX_GRID - 1)) {

        int idx_x[CORNER_AREA] = { -1, 0, -1 };
        int idx_y[CORNER_AREA] = { -1, -1, 0 };

        for (int i = 0; i < CORNER_AREA; i++) {
            if (game_grid[x + idx_x[i]][y + idx_y[i]].has_troll) {
                troll_counter++;
            }
            else {
                if (game_grid[x + idx_x[i]][y + idx_y[i]].has_potion) {
                    potion_counter++;
                }
            }
        }
    }

    troll_n = troll_counter;
    potion_n = potion_counter;
}


void update_grid(Grid_Cubicle game_grid[][MAX_GRID]) {

    int troll_number;
    int potion_number;
    
    for (int y = 0; y < MAX_GRID; y++) {
        for (int x = 0; x < MAX_GRID; x++) {
            if (!(game_grid[x][y].has_troll && game_grid[x][y].has_potion)) {
                if (((x > 0) && (x < (MAX_GRID - 1))) && ((y > 0) && (y < (MAX_GRID - 1)))) {
                    evaluate_middle_cell(game_grid, x, y, troll_number, potion_number); 
                    game_grid[x][y].vecinity_trolls = troll_number;
                    game_grid[x][y].vecinity_potions = potion_number;
                }            
                else {
                    evaluate_edges_cell(game_grid, x, y, troll_number, potion_number); 
                    game_grid[x][y].vecinity_trolls = troll_number;
                    game_grid[x][y].vecinity_potions = potion_number;
                }
                
            }

        }
    }

}

void initialize_grid(Grid_Cubicle game_grid[][MAX_GRID]) {
    for (int y = 0; y < MAX_GRID; y++) {
        for (int x = 0; x < MAX_GRID; x++) {
            game_grid[x][y].has_troll = false;
            game_grid[x][y].has_potion = false;
            game_grid[x][y].vecinity_trolls = 0;
            game_grid[x][y].vecinity_potions = 0;
            game_grid[x][y].is_visible = false;
            game_grid[x][y].is_done = false;
        }
    }
}

void display_grid(Grid_Cubicle game_grid[][MAX_GRID], bool debug_mode) {

    cout << " Office Grid: " << endl;

    if (debug_mode) {
        for (int x = 0; x < MAX_GRID; x++) {
            if (x == 0)
                cout << "\t|     |";

            cout << "\t|  " << x << "  |";
        }
        cout << endl;

        for (int y = 0; y < MAX_GRID; y++) {
            cout << "\t|  " << y << "  |";
            for (int x = 0; x < MAX_GRID; x++) {
                if (game_grid[x][y].has_troll) {
                    cout << "\t[--T--]";
                }
                else {
                    if (game_grid[x][y].has_potion) {
                        cout << "\t[++P++]";
                    }
                    else {
                        cout << "\t["<< game_grid[x][y].vecinity_trolls << "-(" << game_grid[x][y].vecinity_potions << ")]";
                    }
                }
            }
            cout << endl;
        }
    }
    else {
        // player mode, NOT debug mode:
        for (int x = 0; x < MAX_GRID; x++) {
            if (x == 0)
                cout << "\t|     |";
            
            cout << "\t|  " << x << "  |";
        }
        cout << endl;

        for (int y = 0; y < MAX_GRID; y++) {
            cout << "\t|  " << y << "  |";

            for (int x = 0; x < MAX_GRID; x++) {
                if (game_grid[x][y].is_visible) {
                    
                    if (game_grid[x][y].has_troll) {
                        cout << "\t[--T--]";
                    }
                    else {
                        if (game_grid[x][y].has_potion) {
                            cout << "\t[++P++]";
                        }
                        else {
                            cout << "\t[" << game_grid[x][y].vecinity_trolls << "-(" << game_grid[x][y].vecinity_potions << ")]";
                        }
                    }
                    
                }
                else {
                    cout << "\t[*****]";
                }
            }
            cout << endl;
        }
    }   

    cout << endl;
}


// MY FUNCTIONS:
void display_player_health(int& health) {
    cout << " << Ron's current health is: " << health << " Points" << endl << endl;
}

void cubicle_select(Grid_Cubicle game_grid[][MAX_GRID], int& x, int& y) {
        
    cout << " Enter an (X,Y) cubicle location for Ron to visit " << endl;
    cout << " X: ";
    cin >> x;
    cout << " Y: ";
    cin >> y;

    game_grid[x][y].is_visible = true; // make cubicle visible to user

}

void cubicle_check(Grid_Cubicle game_grid[][MAX_GRID], int& troll_n, int& health, int& x, int& y) {

    // if selected cubicle has not been visited:
    if(!game_grid[x][y].is_done) {
        // has a Troll:
        if(game_grid[x][y].has_troll) {

            troll_n -= 1; // reduce number of trolls by 1

            int rand_int = (rand() % 100) + 1; // between 1-100
            if(26 <= rand_int <= 75) {
                // land on top of troll
                cout << " << Ron has landed on top of the troll and loses 2 health points." << endl << endl;
                health -= 2;
            }
            else if(76 <= rand_int <= 100) {
                // land in front of troll
                cout << " << Ron has landed in front of the troll and loses 5 health points." << endl << endl;
                health -= 5;
            }
            else{
                cout << " << Ron has landed behind the troll and is safe! No health points lost." << endl << endl;
            }

            game_grid[x][y].is_done = true; //cubicle has now been visited
            cout << " << The Troll has been defeated." << endl << endl;
        }
        // Has a Potion:
        else if(game_grid[x][y].has_potion) {

            cout << " << Ron found a potion and receives 5 health points!" << endl << endl;

            if(game_grid[x][y].vecinity_trolls > 0){
                // take no damage and receive potion health boost, even if troll is nearby   
                health += 5; 
                // if health goes above 10, reset to 10:
                if(health > 10) {
                    health = 10;
                }
            }
            else{
                // no troll nearby
                health += 5;
                // if health goes above 10, reset to 10:
                if(health > 10) {
                    health = 10;
                }
            }

            game_grid[x][y].is_done = true; // cubicle has now been visited.
        }
        // Is Empty, no Troll/Potion in proximity
        else if(game_grid[x][y].vecinity_potions == 0 && game_grid[x][y].vecinity_trolls == 0) {

            game_grid[x][y].is_done = true; // cubicle has now been visited.

            cout << " << No Trolls or Potions nearby." << endl;

        }
        // Is Empty, Troll in proximity
        else if(game_grid[x][y].vecinity_trolls > 0) { 
            health -= game_grid[x][y].vecinity_trolls; // reduces Ron's health by value of vecinity_trolls

            game_grid[x][y].is_done = true; // cubicle has now been visited.

            cout << " << Ron is nearby a Troll and loses " << game_grid[x][y].vecinity_trolls
            << " health points!" << endl;
        }
        // Is Empty, Potion in proximity
        else if(game_grid[x][y].vecinity_potions > 0) {
            
            game_grid[x][y].is_done = true; // cubicle has now been visited.

            cout << " << Ron is nearby a Potion." << endl;
        }
    }
    else{
        cout << " << Ron has already been to this cubicle --> nothing happens." << endl;
    }

}

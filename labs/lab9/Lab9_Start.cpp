// Lab9_start.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "time.h"

#define MAX_GRID 8
#define CHECK_AREA 8
#define CORNER_AREA 3
#define EDGE_AREA 6
using namespace std;


struct Grid_Cubicle {
    bool has_troll;
    bool has_potion;
    bool is_visible;
    bool is_done;
    int vecinity_trolls;
    int vecinity_potions;
};

struct Wizard {
    int health;    
};
 
void populate_grid(Grid_Cubicle game_grid[][MAX_GRID], int n_trolls, int n_potions) {

}


void evaluate_middle_cell(Grid_Cubicle game_grid[][MAX_GRID], int x, int y, int& troll_n, int& potion_n){

    int idx_x[CHECK_AREA] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int idx_y[CHECK_AREA] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int troll_counter = 0;
    int potion_counter = 0;
       
    for (int i = 0; i < CHECK_AREA; i++) {
        if (game_grid[ x+idx_x[i] ][ y+idx_y[i] ].has_troll) {
            troll_counter++;
        }
        else {
            if (game_grid[ x+idx_x[i] ][ y+idx_y[i] ].has_potion) {
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


void update_grid( Grid_Cubicle game_grid[][MAX_GRID]) {

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


int main()
{
    struct Grid_Cubicle grid[MAX_GRID][MAX_GRID];    
    struct Wizard player_w;
   
    srand(unsigned(time(NULL)));

    initialize_grid(grid);    
    display_grid(grid, true);
   
    populate_grid(grid, 5, 5);
    display_grid(grid, true);

    update_grid(grid);
    display_grid(grid, true);
    display_grid(grid, false);

    getchar();

    //system("pause");  //for windows users
}

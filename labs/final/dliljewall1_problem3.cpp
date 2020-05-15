// CSC 123
// Assignment: Final Exam Problem #3
// File Name: dliljewall1_problem3.cpp
// Author: David Liljewall
// Last Modified: 5/6/2020

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;


/* -------------------------------------------------------------------------- */
/*                              CLASS DEFINITIONS                             */
/* -------------------------------------------------------------------------- */
class Movie {
    // contains information about the movie: name, length, favorite

    private:
        // string name; // stores the name of a movie
        // int length; // stores the number of minutes the movie is played for 
        // int favorite; // takes values between 0 - 10, gets incremented by 1 every time a movie is searched for

    public:
        string name; // stores the name of a movie
        int length; // stores the number of minutes the movie is played for 
        int favorite; // takes values between 0 - 10, gets incremented by 1 every time a movie is searched for

        Movie() {
            // initialize length and favorite value to 0
            length = 0;
            favorite = 0;
        }

        ~Movie() {
            // intentionally left blank
        }
};


class List {
    // contains a list/vector of objects of class-type Movie

private:
    vector<Movie> movie_list; // movie viewing list -- contains a dynamic list of Movie class objects

public:
    List() {
        // intentionally left blank
    }

    ~List() {
        // deletes all elements of movie_list vector, making it size 0
        movie_list.clear();

    }


/* ----------------------------- Class Functions ---------------------------- */
    void add_movie(Movie& movie);
        // user manually enters movies they want to watch or keep in their viewing list
    void remove_movie(Movie& movie);
        // user removes a movie from the list by entering the name
    void search_movie(Movie& movie);
        // user enters name of movie and searches the list
    void display_list(Movie& movie);
        // user picks whether to display the viewing list BY NAME or by FAVORITE VALUE (both are sorted)
    void save_data();
        // saves the current viewing list to a file saving each movie information one line at a time:
	    // 1. Name
	    // 2. Length
	    // 3. Favorite

    void disney_welcome();
        // prints mickey mouse and welcomes user to Disney plus plus

    void print_vector();
        // NOTE: FOR DEBUGGING ONLY
        // prints the movie_list vector

    void sort_vector();
        // Bubble Sorts vector movie_list
};



/* -------------------------------------------------------------------------- */
/*                                MAIN FUNCTION                               */
/* -------------------------------------------------------------------------- */
int main() {

    List list; // create List class object
    Movie film; // create Movie class object

    int option; // user-selected option -- implemented to switch between menu options

    // show Disney++ welcome prompt:
    list.disney_welcome();

    
    do {
        // start looping menu prompt:
        MENU_PROMPT: cout << endl << " << MENU >> " << endl;

        cout << endl << " Which option would you like to perform? " << endl << endl
        << " 1) Add a Movie to Your List" << endl
        << " 2) Remove a Movie from Your List" << endl
        << " 3) Search for a Movie in Your List" << endl
        << " 4) Save Your List Data" << endl
        << " 5) Exit Disney++" << endl << endl;
        cin >> option;

        if (!cin.fail()) {
            switch (option) {
            case 1:
                // add movie to list
                list.add_movie(film);
                list.print_vector(); // for debugging 
                break;
            
            case 2: 
                // remove movie from list
                list.remove_movie(film);
                list.print_vector(); // for debugging 
                break;
            
            case 3: 
                // search for movie in list
                list.search_movie(film);
                break;

            // case 4:
            //     // save list data
            //     list.save_data();
            //     break;

            case 5:
                // exit program
                cout << " << You have successfully exited Disney++." << endl
                << " Thanks for using our service, and we hope to see you back soon!" << endl << endl;
                break;

            default:
                cout << endl << " Error: option entered is invalid... Please try again" << endl << endl
                << " --- " << endl << endl;
                goto MENU_PROMPT;

            }
        }
        else {

            cout << endl << " Error: option entered is invalid... Please try again" << endl << endl
            << " --- " << endl << endl;
            goto MENU_PROMPT;

        }

    } while (option < 5);

    return 0;
}


/* -------------------------------------------------------------------------- */
/*                            FUNCTION DEFINITIONS                            */
/* -------------------------------------------------------------------------- */
void List::add_movie(Movie& movie) {

    string input; // stores user-input from terminal

    cout << " << You have selected the ADD MOVIE menu option" << endl << endl;

    // begin looping menu prompt:
    do {

        cout << " Please enter the title of the movie you want to add to your viewing list: ";
        getline(cin >> ws, movie.name); // getline(cin >> ws variable) allows for spaces to be entered in terminal
        cout << " Please enter the length of the movie in minutes: ";
        cin >> movie.length;

        // add entered data into movie_list vector
        movie_list.push_back(movie); 


        cout << endl << " --> " << movie.name << " <-- " << " has been added to your list! " 
        << " It has a runtime of " << movie.length << " minutes" << endl;

        cout << " Would you like to add an additional movie to your viewing list? (type y or n)" << endl;
        cin >> input;
        if (input == "y") {
            // do nothing, repeat prompt loop
        }
        else if (input == "n") {
            break;
        }

    } while (input != "n");

    cout << endl; // add extra whitespace
        
}

void List::remove_movie(Movie& movie) {

    string input; // stores user-input from terminal

    cout << " << You have selected the REMOVE MOVIE menu option" << endl << endl;

    // begin looping menu prompt:
    do {

        cout << " Please enter the title of the movie you want to remove from your viewing list: ";
        getline(cin >> ws, movie.name); // getline(cin >> ws variable) allows for spaces to be entered in terminal
        
        // remove name from list
        for (int i = 0; i < movie_list.size(); i++) {
            if (movie_list[i].name.compare(movie.name) == 0) {
                // if user input matches existing string in movie_list vector:
                movie_list.erase(movie_list.begin() + i); // deletes the ith element; the element that matches the searched movie name
            }
            else {
                cout << movie.name << " is not in your list. Please try again" << endl;
            }
        }

        cout << " --> " << movie.name << " <-- " << " has been removed from your list!" << endl;

        cout << " Would you like to remove any additional movies from your viewing list? (type y or n)" << endl;
        cin >> input;
        if (input == "y") {
            // do nothing, repeat prompt loop
        }
        else if (input == "n") {
            break;
        }

    } while (input != "n");

    cout << endl; // add extra whitespace
}

void List::search_movie(Movie& movie) {

    string input; // stores user-input from terminal

    cout << " << You have selected the SEARCH MOVIE menu option" << endl << endl;

    // begin looping menu prompt:
    do {

        cout << " Please enter the title of the movie you want to find in your viewing list: ";
        getline(cin >> ws, movie.name); // getline(cin >> ws variable) allows for spaces to be entered in terminal
        
        // search for title in list
        for (int i = 0; i < movie_list.size(); i++) {
            if (movie_list[i].name.compare(movie.name) == 0) {
                // if user input matches existing string in movie_list vector:

                movie.favorite++; // incremement favorite value

                cout << " The movie you searched is: " << " --> " << movie.name << " <-- " << " and it is in your list." << endl;
            }
            else {
                cout << " --> " << movie.name << " <--" << " is not in your list. Please try again" << endl;
            }
        }

        cout << " Would you like to search any additional movies from your viewing list? (type y or n)" << endl;
        cin >> input;
        if (input == "y") {
            // do nothing, repeat prompt loop
        }
        else if (input == "n") {
            break;
        }

    } while (input != "n");

    cout << endl; // add extra whitespace

}

void List::display_list(Movie& movie) {

    string input; // stores user-input from terminal
    int option;

    cout << " << You have selected the DISPLAY LIST menu option " << endl << endl;

    do { 
        
        cout << " 1) Display your viewing list, sorted by --> MOVIE TITLE" <<
        endl << " 2) Display your viewing list, sorted by --> RUNTIME" << endl;
        cin >> option;

        if (option == 1) {
            // display list of movie titles, sorted



        }
        else if (option == 2) {
            // display list of movie runtimes, sorted 
            

        }
        else {

            cout << endl << " Error: option entered is invalid... Please try again." << endl;

        }

    } while (input != "n");

}

void List::save_data() {

}


/* ----------------------------- Misc Functions ----------------------------- */
void List::disney_welcome() {
    // Print Disney++ Logo:
    cout << endl << R"( WELCOME TO DISNEY++!

                    .d88888888bo.
                    .d8888888888888b.
                    8888888888888888b
                    888888888888888888
                    888888888888888888
                    Y8888888888888888
                ,od888888888888888888P
            .'`Y8P'```'Y8888888888P'
        .'_   `  _     'Y88888888b                   
        /  _`    _ `      Y88888888b   ____
    _  | /  \  /  \      8888888888.d888888b.
    d8b | | /|  | /|      8888888888d8888888888b
    8888_\ \_|/  \_|/      d888888888888888888888b
    .Y8P  `'-.            d88888888888888888888888
    /          `          `      `Y8888888888888888
    |                        __    888888888888888P
    \                       / `   dPY8888888888P'
    '._                  .'     .'  `Y888888P`
        `"'-.,__    ___.-'    .-'
                `-._````  __..--'`
        
        )" << endl << endl;
}

void List::print_vector() {

    for (int i = 0; i < movie_list.size(); i++) {
        cout << "movie " << i << " is: " << movie_list[i].name
        << " -- with a runtime of: " << movie_list[i].length << " minutes" << endl;
    }

}


void List::sort_vector() {

}

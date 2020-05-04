#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>

using namespace std;

class Dynamic_Statistics 
{
    private:
    int list_size; // size of current dynamic array
    int *numbers_list = NULL; // initialize array pointer to NULL
    
    public:
    Dynamic_Statistics()
    {
       // 
    }
    void print_array();
    void create_array(int n_size);
    void populate_array(int max_value);
    void delete_array();

};


int main() 
{
    Dynamic_Statistics numbers; 

    int array_size, max;

    numbers.create_array(10);
    numbers.populate_array(100);
    numbers.print_array();
    numbers.delete_array();
}

void Dynamic_Statistics::create_array(int n_size)
{
    list_size = n_size;
    if (numbers_list == NULL) {
        numbers_list = new int [n_size]; // creates dynamic integer array of size n_size.
            cout << "array created" << endl;

    }  
    else {
    }
}

void Dynamic_Statistics::populate_array(int max_value) 
{
    srand(unsigned(time(NULL)));

    for (int i = 0; i < list_size; i++)
    {
        numbers_list[i] = rand() % (max_value + 1);
    }
}

void Dynamic_Statistics::print_array()
{
    for (int i = 0; i < list_size; i++) 
    {
        cout << numbers_list[i] << '\t';
    }
    cout << endl << endl;
    
}

void Dynamic_Statistics::delete_array()
{
    delete[] numbers_list;
    numbers_list = NULL;
}
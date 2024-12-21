/***************************************************************************************************
 * Program: run_pokemon.cpp
 * Author: Bryan Piedra
 * Date: 12/19/2024
 * Description:
 **************************************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <fstream>

#include "pokemon.h"

using namespace std;


// Check validity of user input
bool checkCin() {
    if(cin.fail()) {
        cout << "\nPlease input a valid input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    return true;
}

bool printOrWrite() {

    int output;

    cout << "\nPrint    [1]";
    cout << "\nDisplay  [2]";
    cout << endl << "Please enter if you want to print or write data to a file:";

    cin >> output;

    checkCin();

    return output;
}


// Write pokemon to file
void writeToFile(Pokemon pokemon) {
    

}

// Search for a pokemon based on user input of pokedex number
void searchDexNumber(Pokedex& pokedex) {

    // Initiate dex number variable
    int dexNumber;

    // Infinite loop until user input is valid
    while(1) {

        // Prompt user to enter pokedex number
        cout << "Please Enter the Pokedex Number: ";
        cin >> dexNumber;

        if(checkCin()) {
            // Break out of while loop if input is valid
            break;
        }
    }
    
    // User decision on print or write
    int output = printOrWrite();

    // Iniitate boolean variable that tracks if a pokemon was found with user input
    bool found = false;

    // Loop through pokemons
    for(int i = 0; i < pokedex.num_pokemon; i++) {
        // If user input dex number matches a pokemons dex number, print pokemon info
        if((dexNumber == pokedex.dex[i].dex_num) && output == 1) {
            display_pokemon(pokedex.dex[i]);
            // Set boolean to true indicating a pokemon was found
            found = true;
        }
        
        else if((dexNumber == pokedex.dex[i].dex_num) && output == 2) {
            writeToFile(pokedex.dex[i]);
            // Set boolean to true indicating a pokemon was found
            found = true;
        }
    }

    // Display error message that a pokemon wasn't found with user input if no pokemon found
    if(found == false) {
        cout << "\nPokemon was not found with given dex number, please try searching again\n";
    }

}

// Search for a pokemon based on user input of name
void searchByName(Pokedex& pokedex) {

    // Initiate name variable
    string name;

    // Loop until valid name input
    while(1) {

        // Prompt user to enter pokemon name
        cout << "Please Enter the Pokemon name: ";
        cin >> name;

         if(checkCin()) {
            // Break out of while loop if input is valid
            break;
        }

    }

    // User decision on print or write
    int output = printOrWrite();

    // Initiate boolean value that keeps track if a pokemon was found with user input
    bool found = false;

    // Loop through array of pokemons
    for(int i = 0; i < pokedex.num_pokemon; i++) {
        // If user input matches a pokemon name, display pokemon values
        if((name == pokedex.dex[i].name) && output == 1) {
            display_pokemon(pokedex.dex[i]);
            // Set boolean to true to indicate that a pokemon was found
            found = true;
        }

        else if((name == pokedex.dex[i].name) && output == 2) {
            writeToFile(pokedex.dex[i]);
            // Set boolean to true to indicate that a pokemon was found
            found = true;
        }
    }

    // Display error message that a pokemon with user input wasn't found
    if(found == false) {
        cout << "\nPokemon not found with given name, please try searching again\n";
    }
}

// Search for a pokemon with user input of type
void searchByType(Pokedex& pokedex) {

    // Initiate type
    string type;

    // Loop through until a valid type is given
    while(1) {
        
        // Prompt user to enter type
        cout << "Please Enter the Pokemon type: ";
        cin >> type;

        if(checkCin()) {
            // Break out of while loop if input is valid
            break;
        }
    }

     // User decision on print or write
    int output = printOrWrite();

    // Iniitiate boolean value to keep track if a pokemon is found with user input
    bool found = false;

    // Loop through in search of pokemon
    for(int i = 0; i < pokedex.num_pokemon; i++) {
        // If user input matches a pokemon type, print pokemon information
        if((type == pokedex.dex[i].type) && output == 1) {
            display_pokemon(pokedex.dex[i]);
            // Set boolean to true to indicate that a pokemon was found with the users input
            found = true;
        }

        else if((type == pokedex.dex[i].type && output == 2)) {
            writeToFile(pokedex.dex[i]);
            // Set boolean to true to indicate that a pokemon was found with the users input
            found = true;
        }
    }

    // Display error message that a pokemon was not found with user input if a pokemon wasn't found
    if(found == false) {
        cout << "\nPokemon not found with given type, please try searching again\n";
    }
}

// Display user search options
void display_options() {
    cout << endl;
    cout << "Search by Dex Number   [1]\n";
    cout << "Search by Name         [2]\n";
    cout << "Search by Type         [3]\n";
    cout << "Quit                   [4]\n\n";
    cout << "Please Select from the options above: ";
}


// Pokedex program that allows user to search for pokemons and write them to a new or existing file
int main() {

    // Greet user
    cout << "Welcome to Pokemon Encyclopedia!" << endl;

    // Receive txt file with pokemon data
    string userFile;

    cout << "Please enter the necessary .txt file here: ";
    cin >> userFile;

    ifstream file;
    file.open(userFile);

    // Verify that file was able to be opened
    if(!file.is_open()) {
        cout << "Error opening the file..." << endl;
        return 1;
    }

    cout << "File opened successfully" << endl;


    // Initialize Pokedex with pokemons from txt file
    Pokedex* pokedex = new Pokedex;
    populate_pokedex_data(*pokedex, file);

    // Close file
    file.close();
    
    // Initialize user input for search method
    int userInput = 0;

    // Loop through options until user decides to quit
    while(userInput != 4) {
        
        // Display search options
        display_options();
        cin >> userInput;

        // Check if input is valid
        if(!checkCin()) {
            continue;
        }

        // Validate input range
        if(userInput < 1 || userInput > 4) {    
            cout << endl << "Please provide a number within the given range" << endl;
            continue;
        }

        // Switch between user input based on corresponding search technique
        switch(userInput) {

            // 1. Search Dex Number
            case 1:
                searchDexNumber(*pokedex);
                break;

            // 2. Search by Name
            case 2:
                searchByName(*pokedex);
                break;

            // 3. Search by Type
            case 3:
                searchByType(*pokedex);
                break;

            // 4. Quit;
            case 4:
                return 0;
        }
    }
}
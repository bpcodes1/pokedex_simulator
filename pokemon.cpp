#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#include "pokemon.h"

using namespace std;


void display_pokemon(Pokemon& pokemon) {
    cout << "--------------------------------------" << endl;
    cout << "Dex #: " << pokemon.dex_num << endl;
    cout << "Name:  " << pokemon.name << endl;
    cout << "Type:  " << pokemon.type << endl;
    cout << "Moves: ";
    for(int i = 0; i < pokemon.num_moves; i++) {
        cout << pokemon.moves[i] << " , ";
    }
    cout << endl << endl;
}

Pokemon* create_pokemons(int size) {
    Pokemon* pokemon = new Pokemon [size];
    return pokemon;
}

string* create_moves(int size) {
    string* move = new string [size];
    return move;
}

void populate_pokedex_data(Pokedex& pokedex, ifstream& file) {

    // Get the number of Pokemon from first line of file
    int size = 0;
    file >> size;

    // Set pokedex trainer name
    pokedex.trainer = "Ash Ketchum";

    // Get the number of pokemon
    pokedex.num_pokemon = size;

    // Create Pokemon array with number of pokemons in txt file
    pokedex.dex = create_pokemons(size);

    // Populate Pokemon Data
    for(int i = 0; i < size; i++) {
        populate_pokemon(pokedex.dex[i], file);
    }

    // Print Pokemon (for debugging)
    for(int i = 0; i < size; i++) {
        display_pokemon(pokedex.dex[i]);
    }
}

void populate_pokemon(Pokemon& pokemon, ifstream& file) {

    file >> pokemon.dex_num >> pokemon.name >> pokemon.type >> pokemon.num_moves;

    pokemon.moves = create_moves(pokemon.num_moves);
    for(int i = 0; i < pokemon.num_moves; i++) {
        file >> pokemon.moves[i];
    }

}

void delete_info(Pokedex& pokedex) {


}
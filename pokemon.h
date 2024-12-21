#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Pokemon {
    int dex_num;
    string name;
    string type;
    int num_moves;
    string* moves;
};

struct Pokedex {
    string trainer;
    int num_pokemon;
    Pokemon* dex;
};

Pokemon* create_pokemons(int size);
string* create_moves(int size);
void populate_pokedex_data(Pokedex& pokedex, ifstream& file);
void populate_pokemon(Pokemon& pokemon, ifstream& file);
void delete_info(Pokedex& pokedex);
void display_pokemon(Pokemon& pokemon);

#endif
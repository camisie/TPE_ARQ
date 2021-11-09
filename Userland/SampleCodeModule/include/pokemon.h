#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <string.h>

//Imprime el logo de pokemon
void printLogo(void);

//Imprime el logo para la version de pantalla chica
void printMiniLogo();

//Imprime una pokebola
void printPokeball();

//Dependiendo del nro seleccionado, imprime el pokemon que encuentra cuando gana el juego
void iChooseYou(int num);

#endif /* pokemon_h */

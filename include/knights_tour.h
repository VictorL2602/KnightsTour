#ifndef KNIGHTS_TOUR_H // gør så filen kun bliver brugt én gang
#define KNIGHTS_TOUR_H

#include <stdbool.h> // så man kan bruge bool til true/false
#include <stddef.h>  // så man kan bruge size_t til tællere

#define SIZE 8 // hvor stort brættet er, i dette tilfælde 8x8 (men kan ændres)
#define MOVE_COUNT 8 // ridderen har 8 mulige træk

// de to arrays her fortæller hvordan ridderen bevæger sig
// fx MOVES_X[0] = 2 og MOVES_Y[0] = 1 betyder 2 til højre og 1 op
extern const int MOVES_X[MOVE_COUNT];
extern const int MOVES_Y[MOVE_COUNT];

// board_t er bare et bræt med tal i
// 0 betyder feltet ikke er besøgt
// hvis der står fx 5, betyder det ridderen var her som nr. 5
typedef unsigned int board_t[SIZE][SIZE];

// tjekker om et træk er muligt fra positionen (x, y)
bool move_is_possible(size_t move_id, size_t x, size_t y, board_t visited);

// kører en riddertur der bare tager det første træk der virker hver gang
// returnerer hvor mange felter ridderen nåede at besøge
unsigned int tour_greedy(size_t start_x, size_t start_y);

// prøver at køre ridderturen fra alle felter og printer hvor langt den kommer
// fra hver
void greedy_tour_from_each_square(void);

#endif // slut på header-filen

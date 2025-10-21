#include "knights_tour.h" // jeg henter alt fra header-filen
#include <stdbool.h>      // så jeg kan bruge true og false
#include <stdio.h>        // så jeg kan printe ting ud

// her siger jeg hvordan ridderen kan flytte sig på brættet
// de to arrays hænger sammen, så (2,1) betyder "2 til højre og 1 op"
const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};

// tjekker om ridderen kan lave et bestemt træk fra positionen (x, y)
bool move_is_possible(size_t move_id, size_t x, size_t y, board_t visited) {
  int next_x =
      (int)x +
      MOVES_X[move_id]; // her regner jeg ud hvor ridderen lander i x-retning
  int next_y = (int)y + MOVES_Y[move_id]; // og her hvor den lander i y-retning

  // nu tjekker jeg om ridderen lander udenfor brættet
  if (next_x < 0)
    return false;
  if (next_y < 0)
    return false;
  if (next_x >= (int)SIZE)
    return false;
  if (next_y >= (int)SIZE)
    return false;

  // her tjekker jeg om feltet allerede er besøgt (så må den ikke lande der)
  if (visited[(size_t)next_x][(size_t)next_y] != 0)
    return false;

  return true; // hvis alt er ok, så er trækket muligt
}

// her laver jeg selve turen som bare tager det første træk der virker
unsigned int tour_greedy(size_t start_x, size_t start_y) {
  board_t visited; // her laver jeg brættet (hvor vi markerer de besøgte felter)
  size_t x, y;     // ridderens nuværende placering
  unsigned int step; // hvor mange felter vi har besøgt
  size_t i, j;       // bruges bare i for-løkkerne

  // her sætter jeg alle felter til 0 (ingen besøgt endnu)
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      visited[i][j] = 0;
    }
  }

  // hvis startfeltet er udenfor brættet, stopper vi bare
  if (start_x >= SIZE || start_y >= SIZE)
    return 0;

  // vi starter på startfeltet
  x = start_x;
  y = start_y;
  step = 1;
  visited[x][y] = step; // marker det første felt som besøgt

  // her gentager vi så længe ridderen stadig kan bevæge sig
  while (step < (unsigned)(SIZE * SIZE)) {
    bool moved = false; // holder styr på om vi faktisk flyttede os

    // vi prøver alle 8 mulige træk en efter en
    for (size_t m = 0; m < MOVE_COUNT; m++) {
      // hvis et træk er muligt, så flytter vi ridderen derhen
      if (move_is_possible(m, x, y, visited)) {
        int next_x = (int)x + MOVES_X[m]; // beregn hvor den skal hen i x
        int next_y = (int)y + MOVES_Y[m]; // beregn hvor den skal hen i y
        x = (size_t)next_x;               // flyt ridderen i x
        y = (size_t)next_y;               // flyt ridderen i y
        step = step + 1;                  // vi har besøgt ét felt mere
        visited[x][y] = step;             // marker feltet som besøgt
        moved = true;                     // vi har flyttet os
        break; // stop efter første mulige træk (greedy)
      }
    }

    // hvis ridderen ikke kunne flytte sig, så stopper vi løkken
    if (!moved)
      break;
  }

  return step; // til sidst fortæller vi hvor mange felter der blev besøgt
}

// her kører vi ridderturen fra hvert eneste startfelt og printer resultatet
void greedy_tour_from_each_square(void) {
  for (size_t y = 0; y < SIZE; y++) {       // y er rækker
    for (size_t x = 0; x < SIZE; x++) {     // x er kolonner
      unsigned int len = tour_greedy(x, y); // kør turen fra (x, y)
      printf("%2u ", len); // print hvor mange felter der blev besøgt
    }
    putchar('\n'); // ny linje efter hver række så det ligner et bræt
  }
}

#include "knights_tour.h" // henter alt fra header-filen (funktioner og konstanter)

// main er det første der bliver kørt når programmet starter
int main(void) {
  // her kalder jeg funktionen der kører ridderturen fra alle startfelter
  // den printer hvor mange felter ridderen når fra hvert felt på brættet
  greedy_tour_from_each_square();

  return 0; // fortæller at programmet sluttede uden fejl
}

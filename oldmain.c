#include <stdbool.h>
#include <stdio.h>

#define SIZE 8
void generate_and_print_a_board(unsigned int w, unsigned h) {
  for (unsigned int row = 0; row < h; ++row) {
    for (unsigned int col = 0; col < w; ++col)
      printf("%d%d ", row, col);
    puts("");
  }
}
#define MOVE_COUNT 8 /**< Number of moves that a knight can make */
const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};

bool make_a_move(size_t move_id, size_t x, size_t y, bool board[SIZE][SIZE]) {
  x += MOVES_X[move_id];
  y += MOVES_Y[move_id];
  if (x < SIZE && y < SIZE && x > 0 && y > 0 && board[x][y] == false)
    board[x][y] = true;
  return true;
}

bool board[SIZE][SIZE] = {0};
unsigned int tour_greedy(size_t start_x, size_t start_y) {}

int main() { generate_and_print_a_board(SIZE, SIZE); }

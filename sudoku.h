#include "grid.h"



Grid_T sudoku_read(void);


void sudoku_print(FILE *s, Grid_T g);
void sudoku_print_errors(Grid_T g);
int sudoku_is_correct(Grid_T g);
Grid_T sudoku_solve(Grid_T g);
int sudoku_solution_is_unique(Grid_T g);
Grid_T sudoku_generate(int nelts);

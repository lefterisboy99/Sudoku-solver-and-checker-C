#include <stdio.h>
#include<assert.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct Grid {
int is_only;
struct { 
 int element;       
    struct {         
          int plithos;    
        int num[10];
    }cell;
  } cells[9][9];   
} Grid_T;


void update_elem (Grid_T *g,int i,int j,int n);
int   return_elem(Grid_T g,int i,int j);
int read_if_is_only(Grid_T *g);
void set_the_is_only(Grid_T *g);
void delete_is_only(Grid_T *g);
int return_plithos(Grid_T *g,int i,int j);
void set_plithos(Grid_T *g,int i,int j,int n);
void clear_plithos(Grid_T *g,int i,int j);
void set_cell(Grid_T *g,int i,int j,int n);
void clear_cell(Grid_T *g, int i,int j,int n);
int cell_valid(Grid_T *g,int i,int j,int n);
void delete_cell(Grid_T *g,int i,int j,int n);
void grid_set_choice(Grid_T *g, int row, int col, int n);
void grid_clear_choice(Grid_T *g ); 


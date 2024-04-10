#include "grid.h"





void update_elem (Grid_T *g,int i,int j,int n){
    assert(g);
     assert(i>=0&&j>=0&&i<=9&&j<=9);
     assert(n>=0&&n<=9);
    g->cells[i][j].element=n;
}
int   return_elem(Grid_T g,int i,int j){
    /*assert(g);
     //assert(i<0||j<0||i>=9||j>=9);
    //printf(" i) %d , j)%d , element: %d", i , j  , g.cells[i][j].element);*/
    return g.cells[i][j].element;
}
int read_if_is_only(Grid_T *g){
    assert(g);
 if(g->is_only==1) return 1;
    return 0;
}
void set_the_is_only(Grid_T *g){
    assert(g);
     g->is_only = 1;
}
void delete_is_only(Grid_T *g){
    assert(g);
        g->is_only = 1;
}
int return_plithos(Grid_T *g,int i,int j){
    assert(g);
     assert(i>=0&&j>=0&&i<=9&&j<=9);
  return  g->cells[i][j].cell.plithos;
}

void set_plithos(Grid_T *g,int i,int j,int n){
    assert(g);
     assert(n>=0);
     assert(i>=0&&j>=0&&i<=9&&j<=9);
g->cells[i][j].cell.plithos = n;
}
void clear_plithos(Grid_T *g,int i,int j){
    assert(g);
     assert(i>=0&&j>=0&&i<=9&&j<=9);
g->cells[i][j].cell.plithos = 0;
}
void set_cell(Grid_T *g,int i,int j,int n){
    assert(g);
     assert(i>=0&&j>=0&&i<=9&&j<=9);
      assert(n>=0&&n<=9);
g->cells[i][j].cell.num[n]=1;
}
void clear_cell(Grid_T *g, int i,int j,int n){
    assert(g);
     assert(i>=0&&j>=0&&i<=9&&j<=9);
      assert(n>=0&&n<=9);
g->cells[i][j].cell.num[n] = 0;
}
int cell_valid(Grid_T *g,int i,int j,int n){
    assert(g);
     assert(i>=0&&j>=0&&i<=9&&j<=9);
      assert(n>=0&&n<=9);
    if(g->cells[i][j].cell.num[n]==1)return 1;
    return 0;
}
void delete_cell(Grid_T *g,int i,int j,int n){
    assert(g);
    assert(i>=0&&j>=0&&i<=9&&j<=9);
     assert(n>=0&&n<=9);
    g->cells[i][j].cell.num[n] = 0;
if(g->cells[i][j].cell.num[n]) 
    g->cells[i][j].cell.plithos=g->cells[i][j].cell.plithos-1; 
}


void grid_clear_choice( Grid_T *g ){

}


void grid_set_choice( Grid_T *g , int i , int j ,int n){

}

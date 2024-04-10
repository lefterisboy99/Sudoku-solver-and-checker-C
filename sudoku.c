#include "sudoku.h"




Grid_T sudoku_read(void){
    Grid_T *g=malloc(sizeof(Grid_T));
    int i=0;
    int j=0;
    int ar=0;
    assert(g);
    g->is_only=1;
while(i<9){
  
if(j==9){
       i++;
       j=0;
   }
   if(i==9)return *g;
   scanf("%d",&ar);
  /*printf("%d %d %d",ar,i,j);*/
   update_elem(g,i,j,ar);
   j++;
}

return *g;
}

/*check if all elemnts are diff and more than 9 and less than 1*/
int check(int arr[]){
    int i,k;
    
      /*/  printf("%d",arr[i]);
   //// printf("lala");*/
    for (i = 0; i < 9; i++)
    for ( k = i + 1; k < 9; k++)
        if (arr[i] == arr[k]){
           /*/ printf("%d %d",arr[i],arr[k]);*/
            return 0;
        }
    for( i=0;i<9;i++)
        if(arr[i]>9||arr[i]<=0)return 0;
   /* printf("daaec");*/
return 1;
}


void sudoku_print(FILE *s, Grid_T g){
    int i=0;
    int j=0;
    assert(s );
    /*assert(g);*/
 for( i=0;i<9;i++){
 for(j=0;j<9;j++)
     fprintf(s,"%d ", return_elem(g,i,j));
    fprintf(s,"\n");   
    }
}

/*check if all elemnts are diff and more than 9 and less than 1*/
int Check_little_box(Grid_T g,int i,int j){
        int k,l,s=0;
        int ar[9];
        k=i;
        l=j;
 while(k<i+3){
  while(l<j+3){
     ar[s]=return_elem(g,k,l);        
    s++;
    l++;
    }
k++;
 l=j;
 }
    return check(ar);
}


int sudoku_is_correct(Grid_T g){
    int sum=0;
    int ar[9];
    int i=0;
    int o = 0;
    int j=0;
    int k;
    /*rows*/
    for(i=0;i<9;i++){
       
        for(j=0;j<9;j++) 
          ar[j] = return_elem(g,i,j);
       /*printf("\n");*/
        if(!check(ar)) return 0;
        
    }
    /*columns*/
    
    for(j=0;j<9;j++){
        for(i=0;i<9;i++) ar[i] = return_elem(g,i,j); 
            if(!check(ar)){
                return 0;
            } 
        }

    /*little box*/
    for(i=0;i<9;i+=3){
        for(j=0;j<9;j+=3){
         fflush(stdout);
        if( !Check_little_box(g,i,j)) 
          return 0;
        }
    }
  
        return 1;
}



void sudoku_print_errors(Grid_T g){
    int sum=0,i,j;
    int k;
    int ar[9];
 
    printf("Errors:\n");
    /*rows */
    for(i=0;i<9;i++){
        sum=0;
        for(j=0;j<9;j++) {
            ar[sum] = return_elem(g,i,j);
            sum++;
        }
      
        if(!check(ar)) printf("In row %d and column %d\n",i+1,j+1);
        
    }
    /*columns*/
    for(j=0;j<9;j++){
        sum=0;
        for(i=0;i<9;i++) {
            ar[sum] = return_elem(g,i,j);
            sum++;
        }
        if(!check(ar)) printf("In row %d and column %d\n",i+1,j+1);
        
        }
    
    /*Blocks*/
    for(i=0;i<9;i+=3){
        for(j=0;j<9;j+=3){
           if( !Check_little_box(g,i,j)){
            printf("Block %d\n",i+1+(j/3));
           }
        }
    }
}

int isAvailable(int puzzle[][9], int row, int col, int num)
{
   int colF = (col/3) * 3;
   int rowF = (row/3) * 3;
   int i, j;

 for(i=0; i<9; ++i) {
    if (puzzle[row][i] == num) 
        return 0;
 if (puzzle[i][col] == num) 
        return 0;
  if (puzzle[rowF+(i%3)][colF+(i/3)] == num) 
    return 0; 
  }
   return 1;
}

int sudoku_solution(int puzzle[][9], int row, int col)
{
    int i;
 if(row<9 && col<9)/*check if row and columns are is right values*/ {
     if(puzzle[row][col] != 0)  {
  if((col+1)<9) return sudoku_solution(puzzle, row, col+1);
     else if((row+1)<9) return sudoku_solution(puzzle, row+1, 0);
         else return 1;
       }else
       {
    for(i=0; i<9; ++i)   {
    if(isAvailable(puzzle, row, col, i+1)){/*check grammical if elements are right*/
      puzzle[row][col] = i+1;
         if((col+1)<9){
    if(sudoku_solution(puzzle, row, col +1)) return 1;
      else puzzle[row][col] = 0;
       }
     else if((row+1)<9)
        {
       if(sudoku_solution(puzzle, row+1, 0)) return 1;
         else puzzle[row][col] = 0;
           }
  else return 1;
}
}
}
       return 0;
    }
    else return 1;
}

 Grid_T sudoku_solve_next(Grid_T g,int row,int col){
     int puzzle[9][9],i,j;
    for(i=0;i<9;i++)
       for(j=0;j<9;j++)
           puzzle[i][j]=return_elem(g,i,j);
 if(!sudoku_solution(puzzle, 0, 0)){
                printf("NO SOLUTION\n");
        exit(-1);
    }
    
     for(i=0;i<9;i++)
        for(j=0;j<9;j++)
           update_elem(&g,i,j,puzzle[i][j]);
    return g;

 }

Grid_T sudoku_solve(Grid_T g){

	g = sudoku_solve_next( g , 0 , 0  ) ;
   
	return g;
}


static int solve(int i, int j, int puzzle[][9], int count) {
    int val;
  if (i == 9) {
    i = 0;
    j++;
     if (j == 9)
     return 1+count;
    }
  if (puzzle[i][j] != 0)  /* agnoo ta 0 kelia*/
      return solve(i+1,j,puzzle, count);
    /*/ psaxno an iparxei allh lisi ektos 1
    // break an vro 2h lush*/
    for (val = 1; val <= 9 && count < 2; val++) {
        if (isAvailable(puzzle,i,j,val)) {
            puzzle[i][j] = val;
            /* prostheto epipleon luseis*/
            count = solve(i+1,j,puzzle, count);
        }
    }
    puzzle[i][j] = 0; /* reset ksana sto backtrack*/
    return count;
}


int sudoku_solution_is_unique(Grid_T g){
    int array[9][9];
    int i,j;
    int count;
for(i=0;i<9;i++)
    for(j=0;j<9;j++) array[i][j]=return_elem(g,i,j);
count=solve(0,0,array,0);
return count;
}


Grid_T sudoku_generate_complete(){
    Grid_T g;
    int i,j;
 for(i=0;i<9;i++)
for(j=0;j<9;j++)
     update_elem(&g,i,j,0);
    
    return sudoku_solve(g);
}

Grid_T sudoku_generate(int nelts){
 Grid_T g;
 
  int n,i,j,k,l,ar;
  int sum=81-nelts;
   i= rand();
    j= rand();
  if( nelts > 81 ){
		fprintf(stderr, "The nelts can't be more than 81.\n" );
		fflush(stderr);
		exit(0);
	}
	if( nelts < 0 ){
		fprintf(stderr, "The nelts can't be less than 0.\n" );
		fflush(stderr);
		exit(0);
	}
  g = sudoku_generate_complete();
    for(n=0;n<sum;n++){
        do{
    k= rand();
    l= rand();
     i=k%9;
     j=l%9;
    ar=return_elem(g,i,j);
    }while(ar==0);
     update_elem(&g,i,j,0);
    }
    return g;
}


int main(int argc, char *argv[]){
    Grid_T g;
    int if_solve;
    srand(getpid());
    if( argc==2){
            if(strcmp(argv[1] ,"-c")) return 0;
            printf("Give me puzzle:\n");
            g = sudoku_read();
            sudoku_print(stderr,g);
            if(!sudoku_is_correct(g)){
                fprintf(stderr,"Sudoku is not correct\n");
                sudoku_print_errors(g);
            }else printf("Sudoku is correct\n");
           }

         else if( argc==3){
            if(strcmp(argv[1] ,"-g")) return 0;
            sudoku_print(stdout, sudoku_generate( atoi(argv[2]) ));
            }
      else{
            printf("Solving:\n");
            g = sudoku_read();
            if_solve=sudoku_solution_is_unique(g);
            sudoku_print(stderr,g);
            
            g = sudoku_solve(g);
            if(!sudoku_is_correct(g)){
                sudoku_print_errors(g);
              return 0;
            }else{    
                printf("Puzzle has a ");
                if(if_solve==1) printf("(unique choice) ");
                if(if_solve>1) printf("(multiple choices) ");
                printf("solution:\n");
            }
            sudoku_print(stdout,g);
            printf("Puzzle solution is correct.\n");
    }
    return 0;
}

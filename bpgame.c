

// file:  bpgame.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bpgame.h"


/** TYPEDEFS / STRUCTs HERE ***/


typedef struct BPGame {

   char **board;
   int row;
   int col;
} BPGame;




/**
* Function:  bp_create
* Parameters: number of rows and columns
* Description: returns pointer to newly created
*              board with given number of rows
*              and columns.
*
*              Populates board with random balloons.
*
*              If nrows or ncols is out of range, 
*              an error message is printed to stderr
*              and NULL is returned.
*
*/
extern BPGame * bp_create(int nrows, int ncols){

   BPGame *board;
   if(nrows > MAX_ROWS || ncols > MAX_COLS){
      printf("ERROR TOO LARGE\n");
      return NULL;
   }
   else{
      board->board = malloc(nrows*sizeof(char *));
      for(int i = 0; i < nrows; i++){
         board->board[i] = malloc(sizeof(char) * ncols);
      }
      char Balloons[] = {None, Red, Blue, Green, Yellow};
      for(int i = 0; i < nrows; i++){
         for(int j = 0; j < ncols; i++){
            int balloonColor = rand() % 5;
            board->board[i][j] = Balloons[balloonColor];
         }
      }
   }
    return board;
   
}

/**
* Function:  bp_create_from_mtx
* Parameters: number of rows and columns and 2D array of char
* Description: returns pointer to newly created
*              board with given number of rows
*              and columns.
*
*              Populates board contents of given 2D matrix (assumes
*	       given dimensions).
*
*	       Error conditions:
*              		If nrows or ncols is out of range, an error message 
*			is printed to stderr and NULL is returned.
*
*			If any element in the matrix is not one of the understood
*			color symbols (from the #define-s at top of this file),
*			an error message is pritnted to stderr and NULL is returned.
*			
*/
extern BPGame * bp_create_from_mtx(char mtx[][MAX_COLS], int nrows, int ncols){

   
   if(nrows <= MAX_ROWS && ncols <= MAX_COLS){
      
      BPGame *board;
      board->board = malloc(nrows*sizeof(char *));
      for(int i = 0; i < nrows; i++){
         board->board[i] = malloc(sizeof(char) * ncols);
      }

      for(int i = 0; i < nrows; i++){
         for(int j = 0; j< ncols; j++){
            if(mtx[i][j] != None || mtx[i][j] != Red || mtx[i][j] != Blue ||
               mtx[i][j] != Green || mtx[i][j] != Yellow ){
                  printf("ERRO\n");
                  return NULL;
               }
               else{
                  board->board[i][j] = mtx [i][j];
               }
         }
      }
      return board;
   } else {
      printf("ERROR\n");
      return NULL;
   }
}


/*** IMPLEMENTATION OF bp_XXXX FUNCTIONS HERE  ****/


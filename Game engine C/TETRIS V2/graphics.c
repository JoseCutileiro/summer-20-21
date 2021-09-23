#include <stdio.h>
#include "graphics.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

char buffer_delete() {
    char key;
    if (!kbhit()) 
        return '+';
	while (kbhit())
        key = getchar();
    return key;
}

// Delay the frame rate
void delay(int number_of_miliseconds)
{
    // Converting time into milli_seconds
    int milli_seconds = number_of_miliseconds;
  
    // Storing start time
    clock_t start_time = clock();
    
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

// Clean frame
void init_map(char map[screenH][screenW]){
  int i,j;

  for (i=0;i<screenH;i++){
    for (j=0;j<screenW;j++){
      if (j==0 || j== screenW-2){
        map[i][j] = '|';
      }
      if (i==0 || i == screenH-2){
        map[i][j] = '_';
      }
      if (j== screenW-1){
        map[i][j] = '\0';
      }
      if (j>0 && j<screenW-2 && i>0 && i<screenH-2){
        map[i][j] = ' ';
      
        if ((j==54 || j==96) && i<screenH-10){
          map[i][j] = '|';
        }

      if (i==screenH-10){
        map[i][j] = 'O';
        }
      
      }
    }
  }
}

// Print a frame
void print_map(char map[screenH][screenW]){
  int i;
  for (i=0;i<screenH;i++){
    if (i!= screenH-2)
      printf("%s\n",map[i]);
    else
      printf("%s",map[i]);
  }
}

// Sprites general behaviour

void draw_shape(int x,int y, Sprite shape,char map[screenH][screenW]){
  int i,j,k=0;
  for (i=0;i<shape.sqrt_size;i++){
    for (j=0;j<shape.sqrt_size;j++){
      if (shape.info[k] != ','){
        map[y+i][x+j] = shape.info[k];
      }
      k++;
    }
  }
}

void erase_shape(int x,int y, Sprite shape,char map[screenH][screenW]){
  int i,j,k=0;
  for (i=0;i<shape.sqrt_size;i++){
    for (j=0;j<shape.sqrt_size;j++){
      if (shape.info[k] != ','){
        map[y+i][x+j] = ' ';
      }
      k++;
    }
  }
}




// initialize object

Obj init_obj(int x,int y,Sprite shape[4]){
    Obj obj;
    obj.x = x;
    obj.y = y;
    obj.i = 0;
    obj.shapes[0] = shape[0];
    obj.shapes[1] = shape[1];
    obj.shapes[2] = shape[2];
    obj.shapes[3] = shape[3];

    return obj;    
}



void peace_set(int x,int y,Sprite shape,char map[screenH][screenW]){
  int i;
  for (i=0;i<shape.size;i++){
    if (shape.info[i]!=','){
      map[y+i/4][x+i%4] = 'O';
    }
  }
}



int main(void)
{

  // RANDOMIZE()
       int del=0;
       srand(time(0));

  // INITS VARS 
      char map[screenH][screenW];
      char key='+';
      SPRITES memory = load_sprites();
  
  // SPRITES
  
     Sprite SQUARE[4] = {memory[SQUARE_0],memory[SQUARE_0],memory[SQUARE_0],memory[SQUARE_0]};
     Sprite I[4] = {memory[I_0],memory[I_1],memory[I_2],memory[I_3]};
     Sprite L[4] = {memory[L_0],memory[L_1],memory[L_2],memory[L_3]};
     Sprite J[4] = {memory[J_0],memory[J_1],memory[J_2],memory[J_3]};
     Sprite Z[4] = {memory[Z_0],memory[Z_1],memory[Z_2],memory[Z_3]};
     Sprite _5[4] = {memory[_5_0],memory[_5_1],memory[_5_2],memory[_5_3]};
     Sprite T[4] = {memory[T_0],memory[T_1],memory[T_2],memory[T_3]};

     Sprite *ALL[7] = {SQUARE,I,L,J,Z,_5,T};

  // TESTE
  int x=5,y=1;

  // OBJECTS INIT
        Obj piece = init_obj(75, 1, SQUARE);

  // INIT MAP
        init_map(map);

  // SPAWN
       move_obj(RIGHT, 0, &piece.x, &piece.y, piece.shapes[piece.i], map);


  while(key!='_'){
        
        print_map(map);
        delay(6000);
        key = buffer_delete();
        if (!peace_movement(key, &piece.x, &piece.y, piece.shapes[piece.i], map,&del)){
            peace_set(piece.x,piece.y,piece.shapes[piece.i],map);
            piece = init_obj(75, 1, ALL[rand()%7]);
        }

        if (key=='o'){
          erase_shape(piece.x, piece.y, piece.shapes[piece.i], map);
          piece.i += 1;
          piece.i %= 4;
        }


        // SIGNATURE TEST
        
        move_obj(RIGHT, 0, &x, &y, memory[25], map);
  }

  return 0;
}

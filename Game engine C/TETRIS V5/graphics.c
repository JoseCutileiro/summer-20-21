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
      
        if ((j==74 || j==86) && i<screenH-10){
          map[i][j] = '|';
        }

      if (i==screenH-10){
        map[i][j] = 'O';
        }
      
      }
    }
  }
}

void reset_map(char map[screenH][screenW]){

    int i,j;

  for (i=0;i<screenH;i++){
    for (j=0;j<screenW;j++){
      if ((j==74 || j==86) && i<screenH-10){
        map[i][j] = '|';
        }
      if (i==screenH-10){
        map[i][j] = 'O';
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

// CLEAN LINE

void clean_line(char map[screenH][screenW]){

  int i,j,clean=1;
  int i2,j2;

  for (i=0;i<screenH-10;i++){
    clean = 1;
    for (j=75;j<86;j++)
      if (map[i][j] != 'O')
        clean=0;
    if (clean){

      for (j2=75;j2<=85;j2++)
        map[i][j2] = '=';

      print_map(map);
      delay(600000);

      for (i2=i;i2>1;i2--)
        for (j2=75;j2<=85;j2++)
          map[i2][j2] = map[i2-1][j2];
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

int check_rot(Obj piece,char map[screenH][screenW]){
  int i;
  int var = piece.i;
  var+=1;
  var%=4;
  Sprite val = piece.shapes[var];
  for (i=0;i<val.size;i++){
    if (val.info[i]!=',' && (map[piece.y+i/4][piece.x+i%4] == 'O' || (map[piece.y+i/4][piece.x+i%4] == '|' )))
      return 0;
  }

  return 1;
}

int main(void)
{


  // RANDOMIZE()
       int del=0,set = 200;
       int delay_controler = 6000;
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
        Obj piece = init_obj(75, 1, ALL[rand()%7]);

  // INIT MAP
        init_map(map);

  // SPAWN
       move_obj(RIGHT, 0, &piece.x, &piece.y, piece.shapes[piece.i], map);


  while(key!='_'){
        
        print_map(map);
        delay(delay_controler);
        key = buffer_delete();
        if (!peace_movement(key, &piece.x, &piece.y, piece.shapes[piece.i], map,&del,&set)){
              peace_set(piece.x,piece.y,piece.shapes[piece.i],map);
              clean_line(map);
              piece = init_obj(75, 1, ALL[rand()%7]);
              delay_controler = 6000;
            }

        if (key=='o' && check_rot(piece, map)){
          erase_shape(piece.x, piece.y, piece.shapes[piece.i], map);
          piece.i += 1;
          piece.i %= 4;
        }

        if (key=='w')
          delay_controler = 0;


        // SIGNATURE TEST
        
        move_obj(RIGHT, 0, &x, &y, memory[25], map);
  }

  return 0;
}

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


// Load sprites

SPRITES load_sprites(){
    SPRITES memory;

    memory = malloc(2*sizeof(Sprite));

    // {SHIP}
        memory[SHIP].size = 16;
        memory[SHIP].sqrt_size = 4;
        memory[SHIP].info = malloc(memory[SHIP].size+1);
        strcpy(memory[SHIP].info,",/\\,,__,/XX\\/XX\\");
    
    // {MISSIL}
        memory[MISSIL].size = 4;
        memory[MISSIL].sqrt_size = 2;
        memory[MISSIL].info = malloc(memory[MISSIL].size+1);
        strcpy(memory[MISSIL].info, "^^||");

        
    return memory;
}

// initialize object

Obj init_obj(int x,int y,Sprite shape){
    Obj obj;
    obj.x = x;
    obj.y = y;
    obj.shape = shape;
    return obj;    
}

Contador init_counter(){
  int i;
  Contador counter;
  counter.misseis = 0;
  for (i=0;i<10;i++){
    counter.coordenadas_misseis_x[i] = 0;
    counter.coordenadas_misseis_y[i] = 0;
  }
  return counter;
}

void disparar(char key,Contador *counter,int *x,int *y,Sprite shape, char map[screenH][screenW]){
  int i;
  int var = counter->misseis;
  for (i=0;i<10;i++){
    if (counter->coordenadas_misseis_y[i]>1)
      move_obj(UP,1,&counter->coordenadas_misseis_x[i], &counter->coordenadas_misseis_y[i],shape, map);
    else
      erase_shape(counter->coordenadas_misseis_x[i], counter->coordenadas_misseis_y[i],shape, map);

  }
  if (key == 'o'){
    counter->misseis+=1;
    counter->misseis%=10;
    counter->coordenadas_misseis_x[var] = *x+1;
    counter->coordenadas_misseis_y[var] = *y-1;
  }
}

int main(void)
{
  char map[screenH][screenW];
  char key='+';
  int ciclo_missil=0,missil_fired=0;
  SPRITES memory = load_sprites();
  Contador counter = init_counter();

  // OBJECTS INIT
        Obj ship = init_obj(100, 30, memory[SHIP]);
  
  // INIT MAP
        init_map(map);

  // SPAWN
       move_obj(RIGHT, 0, &ship.x, &ship.y, ship.shape, map);


  while(key!='_'){
        
        print_map(map);
        delay(6000);
        key = buffer_delete();
        ship_movement(key, &ship.x, &ship.y, ship.shape, map);
        if (key == 'o')
          missil_fired = 1;
        // MISSIL BEHAVIOR
        if (!ciclo_missil){
          if (missil_fired)
            disparar('o',&counter,&ship.x,&ship.y,memory[MISSIL],map);
          else
            disparar(key,&counter,&ship.x,&ship.y,memory[MISSIL],map);
          missil_fired = 0;
        }
        ciclo_missil+=1;
        ciclo_missil%=3;
        
  }

  return 0;
}

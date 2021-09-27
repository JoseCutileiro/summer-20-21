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
        map[i][j] = WALL;
      }
      if (i==0 || i == screenH-2){
        map[i][j] = WALL;
      }
      if (j== screenW-1){
        map[i][j] = '\0';
      }
      if (j>0 && j<screenW-2 && i>0 && i<screenH-2){
        map[i][j] = VOID;
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

Obj init_obj(int x,int y,Sprite shape){
    Obj obj;
    obj.x = x;
    obj.y = y;
    obj.i = 0;
    obj.size = 1;
    obj.shape = shape;
    return obj;
}

int add_size(int *score,Worm worm,SPRITES memory){
  int added_x=0;
  int added_y=0;
  *score+=1;
  
  

  worm[*score].i = worm[*score-1].i;

  if (*score%2==0)
    worm[*score] = init_obj(worm[*score-1].x+added_x, worm[*score-1].y+added_y, worm[0].shape);
  if (*score%2==1)
    worm[*score] = init_obj(worm[*score-1].x+added_x, worm[*score-1].y+added_y, memory[2]);
  worm[0].size+=1;
  return 0;


}


int main(void)
{
  int test = 30;
  int score = 0;
  int lose = 0;
  // RANDOMIZE()
       int delay_controler = 60000;
       srand(time(0));

  // INITS VARS 
      char map[screenH][screenW];
      char key='+';
      SPRITES memory = load_sprites();
  
  // SPRITES
  

  // TESTE
  int x=5,y=1;

  // OBJECTS INIT
  
  Worm worm = malloc(sizeof(Obj));
  worm[score] = init_obj(30, 10, memory[0]); 

  // INIT MAP
        init_map(map);

  // SPAWN

  while(key!='_' && !lose){
        
        print_map(map);
        
        delay(delay_controler);
        key = buffer_delete();

        snake_movemment(key, worm, map);
        snake_move(worm,map);
        printf("X: %d//Y: %d\n",worm[score-1].x,worm[score-1].y);
        printf("X: %d//Y: %d\n",worm[score].x,worm[score].y);
  
  // CONTROLED EXPANSION

        if (score){

        if (worm[score-1].i==0){
          worm[score].x = worm[score-1].x-1;
          worm[score].y = worm[score-1].y;
        }

        if (worm[score-1].i==1){
          worm[score].x = worm[score-1].x;
          worm[score].y = worm[score-1].y+1;
        }

        if (worm[score-1].i==2){
          worm[score].x = worm[score-1].x+1;
          worm[score].y = worm[score-1].y;
        }

       if (worm[score-1].i==3){
          worm[score].x = worm[score-1].x;
          worm[score].y = worm[score-1].y-1;
        }


        }



          if (!(rand()%7)){
          worm = realloc(worm,(score+2)*sizeof(Obj));
          add_size(&score,worm,memory);
          test -= 1;
          }



        // SIGNATURE TEST
        
        move_obj(RIGHT, 0, &x, &y, memory[1], map);
  }
  
  printf("SCORE: %d\n",score);

  return 0;
}

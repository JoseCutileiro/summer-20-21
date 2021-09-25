#ifndef _GRAPH_
#define _GRAPH_

#define screenH 36
#define screenW 146

// Movement

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3


// Graphics

#define WALL ':'
#define VOID ' '


// structs

typedef struct sprite{
  int size;
  int sqrt_size;
  char *info;
} Sprite,*SPRITES;

typedef struct wormy{
  int x;
  int y;
  int i;          // orientation = i*90º
  int size;
  Sprite shape;
} Obj,*Worm,*Objs;


// Graphics.c

int kbhit();
void draw_shape(int x,int y, Sprite shape,char map[screenH][screenW]);
void erase_shape(int x,int y, Sprite shape,char map[screenH][screenW]);
SPRITES load_sprites();

// Move.c 

void move_obj(int orientation,int speed,int *x,int *y,Sprite shape,char map[screenH][screenW]);
int snake_movemment(char key,Worm snake, char map[screenH][screenW]);
int snake_move(Worm snake, char map[screenH][screenW]);

// Collision.char

int colision(Obj obj1, Obj obj2);



#endif

#ifndef _GRAPH_
#define _GRAPH_

#define screenH 36
#define screenW 146

// Movement

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// Sprite memory index

#define SHIP 0
#define MISSIL 1

// Limitações de instancias

#define LIM_MISSIL 10

// structs

typedef struct sprite{
  int size;
  int sqrt_size;
  char *info;
} Sprite,*SPRITES;

typedef struct obj{
  int x;
  int y;
  Sprite shape;
} Obj,*Objs;

typedef struct contador{
  int misseis;
  int coordenadas_misseis_x[LIM_MISSIL];
  int coordenadas_misseis_y[LIM_MISSIL];
} Contador;

// Graphics.c

int khhit();
void draw_shape(int x,int y, Sprite shape,char map[screenH][screenW]);
void erase_shape(int x,int y, Sprite shape,char map[screenH][screenW]);


// Move.c 

void move_obj(int orientation,int speed,int *x,int *y,Sprite shape,char map[screenH][screenW]);
void ship_movement(char key,int *x,int *y,Sprite shape,char map[screenH][screenW]);



#endif

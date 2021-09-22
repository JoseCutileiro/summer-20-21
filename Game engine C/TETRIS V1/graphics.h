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

#define SQUARE_0 0

#define I_0 1
#define I_1 2
#define I_2 3
#define I_3 4

#define L_0 5
#define L_1 6
#define L_2 7
#define L_3 8

#define J_0 9
#define J_1 10
#define J_2 11
#define J_3 12

#define Z_0 13
#define Z_1 14
#define Z_2 15
#define Z_3 16

#define _5_0 17
#define _5_1 18
#define _5_2 19
#define _5_3 20

#define T_0 21
#define T_1 22
#define T_2 23
#define T_3 24







// structs

typedef struct sprite{
  int size;
  int sqrt_size;
  char *info;
} Sprite,*SPRITES;

typedef struct obj{
  int x;
  int y;
  int i;              // orientation
  Sprite shapes[4];   // e.g. i=1 => 90º
} Obj,*Objs;


// Graphics.c

int kbhit();
void draw_shape(int x,int y, Sprite shape,char map[screenH][screenW]);
void erase_shape(int x,int y, Sprite shape,char map[screenH][screenW]);
SPRITES load_sprites();

// Move.c 

void move_obj(int orientation,int speed,int *x,int *y,Sprite shape,char map[screenH][screenW]);
int peace_movement(char key,int *x,int *y,Sprite shape,char map[screenH][screenW],int *del);

// Collision.char

int colision(Obj obj1, Obj obj2);



#endif

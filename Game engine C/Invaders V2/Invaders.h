#ifndef _INV_
#define _INV

// Screen info

#define screenW 205
#define screenH 47

// direction

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// SPRITE INDEX

#define SHIP 0

// Sprite definitions

typedef struct sprite{
    int size;
    int sqrt_size;
    char *info;
} Sprite,*SPRITES;

typedef struct obj{
    int x;
    int y;
}Obj;


// Func defenition -> Invaders.c

char buffer_delete();
void delay(int number_of_miliseconds);
void keyboard_check(char *key);
void init_map(char map[screenW][screenH]);
void draw_shape(int x,int y,Sprite shape,char map[screenW][screenH]);
void erase_shape(int x,int y,Sprite shape,char map[screenW][screenH]);
void draw_map(char map[screenW][screenH]);

// Func defenition -> Movement.c

void move_obj(int orientation,int speed,int *x,int *y,Sprite shape,char map[screenW][screenH]);

#endif
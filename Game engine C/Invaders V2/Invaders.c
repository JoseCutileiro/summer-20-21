#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "Invaders.h"
#include <string.h>
#include <math.h>

// DEFINES

#define screenW 205
#define screenH 47

// Delete keyboard buffer
char
buffer_delete() {
    char key;
    if (!kbhit()) 
        return '+';
	while (kbhit())
        key = getch();
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

// Read keyboard input
void keyboard_check(char *key){
    *key = getch();
}

// initialize map

void init_map(char map[screenW][screenH]){
    int i,j;
    for (i=0;i<screenH;i++){
        for (j=0;j<screenW;j++){
            if (i==0 || i==screenH-1){
                map[j][i] = '_';
            }
            if (j==0 || j==screenW-1){
                map[j][i] = '|';
            }
            else{
                if (i!=0 && i!=screenH-1)
                    map[j][i] = ' ';
            }
        }
    }
}

// shape general behavior

void draw_shape(int x,int y,Sprite shape,char map[screenW][screenH]){
    int i,j,k=0;
    for (i=0;i<shape.sqrt_size;i++){
        for (j=0;j<shape.sqrt_size;j++){
            if (shape.info[k] != ','){
                map[x+i][y+j] = shape.info[k];
            }
            k++;
        }
    }
}

void erase_shape(int x,int y,Sprite shape,char map[screenW][screenH]){
    int i,j,k=0;
    for (i=0;i<shape.sqrt_size;i++){
        for (j=0;j<shape.sqrt_size;j++){
            if (shape.info[k] != ','){
                map[x+i][y+j] = ' ';
            }
            k++;
        }
    }
}


// Map design
void draw_map(char map[screenW][screenH]){
    int i,j;
    for(i=0;i<screenH;i++){
        for(j=0;j<screenW;j++){
            printf("%c",map[j][i]);
        }
        printf("\n");
    }
}

void draw_map_evolved(char map[screenW][screenH]){
    int i;
    strcpy(map[2],"OLAdwfdjaopwifjpawjfa");
    for (i=0;i<screenH;i++){
        printf("%s\n",map[i]);
    }
}


// Load sprites

SPRITES load_sprites(){
    SPRITES memory;
    // SHIP
        memory = malloc(2*sizeof(Sprite));
        memory[0].size = 16;
        memory[0].sqrt_size = 4;
        memory[0].info = malloc(memory[0].size+1);
        strcpy(memory[0].info,",,///|XX\\|XX,,\\\\");
    
    // {next figure}

    return memory;
}

// initialize object

Obj init_obj(int x,int y){
    Obj obj;
    obj.x = x;
    obj.y = y;
    return obj;    
}

// Main loop
int main(){
    char key='+';
    char map[screenW][screenH];
    SPRITES memory = load_sprites();
    Obj ship = init_obj(100,35);
    init_map(map);
    while (key != '-')
    {
        draw_map(map);
        delay(250);
        key = buffer_delete();
        move_obj(RIGHT,0,&ship.x,&ship.y,memory[SHIP],map);
        if (key == 'd'){
            move_obj(RIGHT,6,&ship.x,&ship.y,memory[SHIP],map);
        }
        if (key == 'a'){
            move_obj(LEFT,6,&ship.x,&ship.y,memory[SHIP],map);
        }
        if (key == 'w'){
                move_obj(UP,3,&ship.x,&ship.y,memory[SHIP],map);
        }
        if (key == 's'){
            move_obj(DOWN,3,&ship.x,&ship.y,memory[SHIP],map);
        }
    
    }
}


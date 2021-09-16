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

// Action

void cria_ship(int x,int y,char map[screenW][screenH]){
    Sprite ship;
    ship.size = 16;
    ship.sqrt_size = 4;
    ship.info = malloc(ship.size+1);
    strcpy(ship.info,",,///|XX\\|XX,,\\\\");
    draw_shape(x,y,ship,map);
    free(ship.info);
}

void apaga_ship(int x,int y,char map[screenW][screenH]){
    Sprite ship;
    ship.size = 16;
    ship.sqrt_size = 4;
    ship.info = malloc(ship.size+1);
    strcpy(ship.info,",,///|XX\\|XX,,\\\\");
    erase_shape(x,y,ship,map);
    free(ship.info);
}

// Main loop
int main(){
    int x=50,y=30;
    char key='+';
    char map[screenW][screenH];
    srand(time(NULL));
    init_map(map);
    while (key != '-')
    {
        draw_map(map);
        delay(200);
        key = buffer_delete();
        cria_ship(x,y,map);
        if (key == 'd'){
            apaga_ship(x,y,map);
            x+=6;
            cria_ship(x,y,map);
        }
        if (key == 'a'){
            apaga_ship(x,y,map);
            x-=6;
            cria_ship(x,y,map);
        }
    }
}


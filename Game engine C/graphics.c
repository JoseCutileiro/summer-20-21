#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

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

// Square

void square(int x,int y,char map[screenW][screenH]){
    int i,j;
    for (i=-1;i<=1;i++){
        for(j=-1;j<=1;j++){
            map[x+i][y+j] = 'X';
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


// Main loop
int main(){
    int x=100,y=3;
    char key='+';
    char map[screenW][screenH];
    srand(time(NULL));
    init_map(map);
    while (key != '-')
    {
        draw_map(map);
        delay(100);
        key = buffer_delete();

        if (key == 'd'){
            if (y<screenH-3)
                y+=3;
            square(x,y,map);
        }
    }
}


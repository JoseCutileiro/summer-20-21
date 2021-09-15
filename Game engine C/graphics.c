#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

// DEFINES


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

void init_map(char map[205][47]){
    int i,j;
    for (i=0;i<47;i++){
        for (j=0;j<205;j++){
            if (i==0 || i==46){
                map[j][i] = '_';
            }
            if (j==0 || j==204){
                map[j][i] = '|';
            }
            else{
                if (i!=0 && i!=46)
                    map[j][i] = ' ';
            }
        }
    }
}

// Square

void square(int x,int y,char map[205][47]){
    int i,j;
    for (i=-1;i<=1;i++){
        for(j=-1;j<=1;j++){
            map[x+i][y+j] = 'X';
        }
    }
}

// Map design
void draw_map(char map[205][47]){
    int i,j;
    for(i=0;i<47;i++){
        for(j=0;j<205;j++){
            printf("%c",map[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

// Action


// Main loop
int main(){
    int x=100,y=2;
    char key='+';
    char map[205][47];
    srand(time(NULL));
    init_map(map);
    while (key != '-')
    {
        draw_map(map);
        delay(100);
        key = buffer_delete();

        if (key == 'd'){
            y+=2;
            square(x,y,map);
        }
    }
}


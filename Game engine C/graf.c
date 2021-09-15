#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

/* Delete keyboard buffer */
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

// Map design
void draw_map(char key){
    int i,j;
    for(i=0;i<47;i++){
        for(j=0;j<47;j++){
            if (j==0 || j==46)
                printf("|");
            if (i==0 || i==46)
                printf("_");
            else{
                if (i<=35 && i>=20 && j>=20 && j<=35)
                    printf("%c",key);
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
}


// Main loop
int main(){
    char key='+';
    while (key != '-')
    {
        draw_map(key);
        delay(200);
        key = buffer_delete();
    }
}


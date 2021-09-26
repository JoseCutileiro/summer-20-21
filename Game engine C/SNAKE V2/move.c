#include "graphics.h"
#include <stdlib.h>
#include <stdio.h>

void move_obj(int orientation,int speed,int *x,int *y,Sprite shape,char map[screenH][screenW]){
    erase_shape(*x,*y,shape,map);
    switch (orientation)
    {
    case UP:
        *y -= speed;
        draw_shape(*x,*y,shape,map);
        break;
    
    case DOWN:
        *y += speed;
        draw_shape(*x,*y,shape,map);
        break;
    
    case LEFT:
        *x -= speed;
        draw_shape(*x,*y,shape,map);
        break;
    
    case RIGHT:
        *x += speed;
        draw_shape(*x,*y,shape,map);
        break;
    }
}

int snake_movemment(char key,Worm snake, char map[screenH][screenW]){
    
    int i=0;

    for (i=snake[0].size-1;i>=0;i--){
        if (i==0){
            if (key=='a'&& snake[0].i!=0){
                snake[0].i=2;
            }
            if (key =='s' && snake[0].i!=1){
                snake[0].i=3;
            }
            if (key=='d' && snake[0].i!=2){
                snake[0].i=0;
            }
            if (key == 'w' && snake[0].i!=3){
                snake[0].i=1;
            }
        }
        else{
            snake[i].i = snake[i-1].i;
        }
    }
    return 0;
}

int snake_move(Worm snake, char map[screenH][screenW]){
    
    int i=0;
    int orientation;

    for (i=0;i<snake[0].size-1;i++){
            if (snake[i].i==0)
                orientation = RIGHT;
            if (snake[i].i==1)
                orientation = UP;
            if (snake[i].i==2)
                orientation = LEFT;
            if (snake[i].i == 3)
                orientation = DOWN;

            move_obj(orientation, 1, &snake[i].x,&snake[i].y,snake[i].shape, map);

    }

    return 0;
}




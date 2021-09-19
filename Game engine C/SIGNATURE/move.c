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


void ship_movement(char key,int *x,int *y,Sprite shape,char map[screenH][screenW]){

        move_obj(RIGHT,0,x,y,shape,map);
        if (key == 'd'){
            if (*x < screenW-6) 
              move_obj(RIGHT,1,x,y,shape,map);
        }
        if (key == 'a'){
            if (*x > 1)
              move_obj(LEFT,1,x,y,shape,map);
        }
        if (key == 'w'){
            if (*y > 1)
                move_obj(UP,1,x,y,shape,map);
        }
        if (key == 's'){
            if (*y < screenH-6)
              move_obj(DOWN,1,x,y,shape,map);
        }
}


void et_movement(int *x,int *y,Sprite shape, char map[screenH][screenW]){
    if (*y>2 && *y<screenH-8)
        move_obj(UP, rand()%3-1, x,y,shape, map);
    else{
        if (*y>2)
            move_obj(UP, rand()%2, x, y, shape, map);
        else
            move_obj(UP, rand()%2-1, x, y, shape, map);
    }

    if (*x>2 && *x<screenW-8)
        move_obj(RIGHT, rand()%3-1, x,y,shape, map);
    else{
        if (*x>2)
            move_obj(RIGHT, rand()%2-1, x, y, shape, map);
        else
            move_obj(RIGHT, rand()%2, x, y, shape, map);
    }
}


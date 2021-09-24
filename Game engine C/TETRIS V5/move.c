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


int peace_movement(char key,int *x,int *y,Sprite shape,char map[screenH][screenW],int *del,int *set){
        
        int i;
        int var;
        int check_down = 1;
        int return_info = 1;
        *del +=1;
        *del %=50;
        move_obj(RIGHT,0,x,y,shape,map);

        if (key == 'd'){
            for(i=0;i<shape.size;i++)
                if (shape.info[i]!=',' && (map[*y+i/4][*x+i%4+1]=='O' || map[*y+i/4][*x+i%4+1]=='|'))
                    var=0;
            if (var){
                move_obj(RIGHT, 1, x, y, shape, map);
            }
        }

        if (key == 'a'){
            for(i=0;i<shape.size;i++)
                if (shape.info[i]!=',' && (map[*y+i/4][*x+i%4-1]=='O'  || map[*y+i/4][*x+i%4-1]=='|'))
                    var=0;
            if (var){
                move_obj(LEFT, 1, x, y, shape, map);
            }
        }


        if (key == 's')
            *del = 0;
        
        for(i=0;i<shape.size;i++){
            if (shape.info[i]!=',' && map[*y+i/4+1][*x+i%4] == 'O' ){
                check_down = 0;
            }
        }

        if (!(*del) && check_down)
            move_obj(DOWN,1, x, y, shape, map);

        else
            if (key!='a' && key!='d' && !check_down && *del){
                *set -= 1;      
                if (!(*set)){
                    return_info = 0;
                    *set = 200;
                }

            }
                

        return return_info;
}



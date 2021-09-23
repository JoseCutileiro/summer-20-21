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


int peace_movement(char key,int *x,int *y,Sprite shape,char map[screenH][screenW],int *del){
        
        int i;
        int var;
        *del +=1;
        *del %=30;
        move_obj(RIGHT,0,x,y,shape,map);

        if (key == 'd'){

            for(i=0;i<shape.size;i++)
                if (shape.info[i]!=',' && (map[*y+i/4][*x+i%4+1]=='O' || map[*y+i/4][*x+i%4+1]=='|'))
                    var=0;
            if (var)
                move_obj(RIGHT, 1, x, y, shape, map);
        }

        if (key == 'a'){

            for(i=0;i<shape.size;i++)
                if (shape.info[i]!=',' && (map[*y+i/4][*x+i%4-1]=='O'  || map[*y+i/4][*x+i%4-1]=='|'))
                    var=0;
            if (var)
                move_obj(LEFT, 1, x, y, shape, map);
        }


        if (!(*del))
            move_obj(DOWN,1, x, y, shape, map);
        
        for(i=0;i<shape.size;i++){
            if (shape.info[i]!=',' && map[*y+i/4+1][*x+i%4] == 'O' )
                return 0;
        }


        return 1;
}



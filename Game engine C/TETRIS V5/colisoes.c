#include "graphics.h"
#include <stdlib.h>

int colision(Obj obj1, Obj obj2){
    int i,j,size_1,size_2,sqrt_size_1,sqrt_size_2;

    size_1 = obj1.shapes[obj1.i].size;
    size_2 = obj2.shapes[obj2.i].size;
    sqrt_size_1 = obj1.shapes[obj1.i].sqrt_size;
    sqrt_size_2 = obj2.shapes[obj2.i].sqrt_size;

    for (i=0;i<size_1;i++){
        for(j=0;j<size_2;j++){
            if (obj1.shapes[obj1.i].info[i]!=',' && obj2.shapes[obj2.i].info[j]!=',' 
            && (obj1.x + i%sqrt_size_1) == (obj2.x + j%sqrt_size_2) 
            && (obj1.y + i/sqrt_size_1) == (obj2.y + j/sqrt_size_2) )
                return 1;
        }
    }

    return 0;

}

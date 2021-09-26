#include "graphics.h"
#include <stdlib.h>
#include <string.h>

// Load sprites

SPRITES load_sprites(){
    SPRITES memory;

    memory = malloc(2*sizeof(Sprite));

    ///////////////////////// {WORM BLOCK} /////////////////////////////////////

    memory[0].size = 1;
    memory[0].sqrt_size = 1;
    memory[0].info = malloc(memory[0].size+1);
    strcpy(memory[0].info,">");

    memory[2].size = 1;
    memory[2].sqrt_size = 1;
    memory[2].info = malloc(memory[2].size+1);
    strcpy(memory[2].info, "<");

    //////////////////////// {SIGNATURE} //////////////////////////////////////
        memory[1].size = 81;
        memory[1].sqrt_size = 9;
        memory[1].info = malloc(memory[1].size+1);
        strcpy(memory[1].info, "__,,_,,,,,/,|_,,,,/__|_,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,");
    

    return memory;
}

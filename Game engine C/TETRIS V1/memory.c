#include "graphics.h"
#include <stdlib.h>
#include <string.h>

// Load sprites

SPRITES load_sprites(){
    SPRITES memory;

    memory = malloc(26*sizeof(Sprite));

    /////////////////////////// {SQUARE} /////////////////////////////

        memory[SQUARE_0].size = 16;
        memory[SQUARE_0].sqrt_size = 4;
        memory[SQUARE_0].info = malloc(memory[SQUARE_0].size+1);
        strcpy(memory[SQUARE_0].info,",,,,,XX,,XX,,,,,");
    

    /////////////////////// {I} ////////////////////////////

        // {0}

        memory[I_0].size = 16;
        memory[I_0].sqrt_size = 4;
        memory[I_0].info = malloc(memory[L_0].size+1);
        strcpy(memory[I_0].info,",X,,,X,,,X,,,X,,");
      
      // {1}

        memory[I_1].size = 16;
        memory[I_1].sqrt_size = 4;
        memory[I_1].info = malloc(memory[L_0].size+1);
        strcpy(memory[I_1].info,",,,,,,,,XXXX,,,,");

      // {2}

        memory[I_2].size = 16;
        memory[I_2].sqrt_size = 4;
        memory[I_2].info = malloc(memory[L_0].size+1);
        strcpy(memory[I_0].info,",,X,,,X,,,X,,,X,");

      // {3}

        memory[I_3].size = 16;
        memory[I_3].sqrt_size = 4;
        memory[I_3].info = malloc(memory[L_0].size+1);
        strcpy(memory[I_3].info,",,,,XXXX,,,,,,,,");




    /////////////////////// {L} ////////////////////////////

        // {0}

        memory[L_0].size = 16;
        memory[L_0].sqrt_size = 4;
        memory[L_0].info = malloc(memory[L_0].size+1);
        strcpy(memory[L_0].info,",X,,,X,,,XX,,,,,");
      
      // {1}

        memory[L_1].size = 16;
        memory[L_1].sqrt_size = 4;
        memory[L_1].info = malloc(memory[L_0].size+1);
        strcpy(memory[L_1].info,",,,,,,X,XXX,,,,,");

      // {2}

        memory[L_2].size = 16;
        memory[L_2].sqrt_size = 4;
        memory[L_2].info = malloc(memory[L_0].size+1);
        strcpy(memory[L_0].info,",,,,,XX,,,X,,,X,");

      // {3}

        memory[L_3].size = 16;
        memory[L_3].sqrt_size = 4;
        memory[L_3].info = malloc(memory[L_0].size+1);
        strcpy(memory[L_3].info,",,,,,XXX,X,,,,,,");

    //////////////////////// {J} /////////////////////////////

        // {0}

        memory[J_0].size = 16;
        memory[J_0].sqrt_size = 4;
        memory[J_0].info = malloc(memory[L_0].size+1);
        strcpy(memory[J_0].info,",,X,,,X,,XX,,,,,");
      
      // {1}

        memory[J_1].size = 16;
        memory[J_1].sqrt_size = 4;
        memory[J_1].info = malloc(memory[L_0].size+1);
        strcpy(memory[J_1].info,",,,,XXX,,,X,,,,,");

      // {2}

        memory[J_2].size = 16;
        memory[J_2].sqrt_size = 4;
        memory[J_2].info = malloc(memory[L_0].size+1);
        strcpy(memory[J_0].info,",,,,,XX,,X,,,X,,");

      // {3}

        memory[J_3].size = 16;
        memory[J_3].sqrt_size = 4;
        memory[J_3].info = malloc(memory[L_0].size+1);
        strcpy(memory[J_3].info,",,,,,X,,,XXX,,,,");


    //////////////////////// {Z} /////////////////////////////

        // {0}

        memory[Z_0].size = 16;
        memory[Z_0].sqrt_size = 4;
        memory[Z_0].info = malloc(memory[L_0].size+1);
        strcpy(memory[Z_0].info,",,,,,XX,,,XX,,,,");
      
      // {1}

        memory[Z_1].size = 16;
        memory[Z_1].sqrt_size = 4;
        memory[Z_1].info = malloc(memory[L_0].size+1);
        strcpy(memory[Z_1].info,",,X,,XX,,X,,,,,,");

      // {2}

        memory[Z_2].size = 16;
        memory[Z_2].sqrt_size = 4;
        memory[Z_2].info = malloc(memory[L_0].size+1);
        strcpy(memory[Z_0].info,",,,,XX,,,XX,,,,,");

      // {3}

        memory[Z_3].size = 16;
        memory[Z_3].sqrt_size = 4;
        memory[Z_3].info = malloc(memory[L_0].size+1);
        strcpy(memory[Z_3].info,",,,,,,X,,XX,,X,,");



   //////////////////////// {5} /////////////////////////////

        // {0}

        memory[_5_0].size = 16;
        memory[_5_0].sqrt_size = 4;
        memory[_5_0].info = malloc(memory[L_0].size+1);
        strcpy(memory[_5_0].info,",,,,,XX,XX,,,,,,");
      
      // {1}

        memory[_5_1].size = 16;
        memory[_5_1].sqrt_size = 4;
        memory[_5_1].info = malloc(memory[L_0].size+1);
        strcpy(memory[_5_1].info,",,,,,X,,,XX,,,X,");

      // {2}

        memory[_5_2].size = 16;
        memory[_5_2].sqrt_size = 4;
        memory[_5_2].info = malloc(memory[L_0].size+1);
        strcpy(memory[_5_0].info,",,,,,,XX,XX,,,,,");

      // {3}

        memory[_5_3].size = 16;
        memory[_5_3].sqrt_size = 4;
        memory[_5_3].info = malloc(memory[L_0].size+1);
        strcpy(memory[_5_3].info,",X,,,XX,,,X,,,,,");



   //////////////////////// {T} /////////////////////////////

        // {0}

        memory[T_0].size = 16;
        memory[T_0].sqrt_size = 4;
        memory[T_0].info = malloc(memory[L_0].size+1);
        strcpy(memory[T_0].info,",,,,,,X,,XXX,,,,");
      
      // {1}

        memory[T_1].size = 16;
        memory[T_1].sqrt_size = 4;
        memory[T_1].info = malloc(memory[L_0].size+1);
        strcpy(memory[T_1].info,",,X,,XX,,,X,,,,,");

      // {2}

        memory[T_2].size = 16;
        memory[T_2].sqrt_size = 4;
        memory[T_2].info = malloc(memory[L_0].size+1);
        strcpy(memory[T_0].info,",,,,XXX,,X,,,,,,");

      // {3}

        memory[T_3].size = 16;
        memory[T_3].sqrt_size = 4;
        memory[T_3].info = malloc(memory[L_0].size+1);
        strcpy(memory[T_3].info,",,,,,X,,,XX,,X,,");

    //////////////////////// {SIGNATURE} //////////////////////////////////////
        memory[25].size = 81;
        memory[25].sqrt_size = 9;
        memory[25].info = malloc(memory[25].size+1);
        strcpy(memory[25].info, "__,,_,,,,,/,|_,,,,/__|_,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,");
    

    return memory;
}

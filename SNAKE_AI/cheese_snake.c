//
// Created by ryang on 2020-04-08.
//
#include <unistd.h>
#include <stdio.h>
#include "new_API.h"
void play_game() {
    printf("starting\n");
    //board initialized, struct has pointer to snek
    GameBoard* board = init_board();
    show_board(board);

    int axis = AXIS_X;
    int direction = DIR_INIT;

    int play_on = 1;
    int coord[2];

    int stage_1 = 0;
    int stage_2 = 0;
    int stage_3 = 0;
    int stage_4 = 0;
    int stage_5 = 0;
    int stage_6 = 0;
    int stage_7 = 0;
    int stage_8 = 0;
    int stage_9 = 0;
    int stage_10 = 0;

    int E = BOARD_SIZE - 1;

    while (play_on){
        coord[x] = board->snek->head->coord[x];
        coord[y] = board->snek->head->coord[y];


        if (stage_1 == 0){
            if (coord[x] == E && coord[y] == 0){
                stage_1 = 1;
            } else {
                axis = AXIS_X;
                direction = RIGHT;
            }
        }

        if (stage_1 == 1 && stage_2 == 0){
            if (coord[x] == E && coord[y] == E){
                stage_2 = 1;
            } else {
                axis = AXIS_Y;
                direction = DOWN;
            }
        }

        if (stage_1 == 1 && stage_2 == 1 && stage_3 == 0){
            if (coord[x] == 0 && coord[y] == E){
                stage_3 = 1;
            } else {
                axis = AXIS_X;
                direction = LEFT;
            }
        }

        if (stage_3 == 1){
            if (coord[x] == 0 && coord[y] == 1){
                axis = AXIS_Y;
                direction = UP;
                stage_1 = 0;
                stage_2 = 0;
                stage_3 = 0;
            } else {
                if (stage_4 == 0){
                    axis = AXIS_Y;
                    direction = UP;
                    stage_4 = 1;
                } else if (stage_4 == 1 && stage_5 == 0){
                    if (coord[x] == E-2){
                        stage_5 = 1;
                    } else {
                        axis = AXIS_X;
                        direction = RIGHT;
                    }
                } else if (stage_4 == 1 && stage_5 == 1 && stage_6 == 0){///////////////////////////////////////////////////////////////
                    axis = AXIS_Y;
                    direction = UP;
                    stage_6 = 1;
                } else if (stage_4 == 1 && stage_5 == 1 && stage_6 == 1 && stage_7 == 0){
                    if (coord[x] == 1){
                        stage_7 = 1;
                    } else {
                        axis = AXIS_X;
                        direction = LEFT;
                    }
                } else if (stage_4 == 1 && stage_5 == 1 && stage_6 == 1 && stage_7 == 1 && stage_8 == 0){
                    axis = AXIS_Y;
                    direction = UP;
                    //stage_4 = 0;
                    stage_5 = 0;
                    stage_6 = 0;
                    stage_7 = 0;
                    stage_8 = 0;
                }

            }
        }

        show_board(board);
        play_on = advance_frame(axis, direction, board);
        printf("Going ");

        if (axis == AXIS_X){
            if (direction == RIGHT){
                printf("RIGHT");
            } else {
                printf("LEFT");
            }
        } else {
            if (direction == UP){
                printf("UP");
            } else {
                printf("DOWN");
            }
        } printf("\n");
        printf("----------------------------------------------------------------------\n");
        usleep(50000);
    }
    end_game(&board);

}

int main(){
    play_game();
    return 0;
}

// Pseudocode for switch length implementation
int switch_length = 10;
if(snake->length < switch_length){
    // perform heuristic
}else{
    // perform hamiltonian
}

// Numerical simulation of Monty Hall problem

#include <stdio.h>

int main(void) {

    void init_genrand64(unsigned long long seed);
    unsigned long long genrand64_int64(void);

    int choice, reveal, prize;
    int draw, draws, wins;

    draws = 1000000;
    int change = 1;

    init_genrand64(12345);

    draw = 0;
    wins = 0;
    while(draw < draws) {

        prize = genrand64_int64()%3;
        choice = genrand64_int64()%3;

        // Choose door to reveal
        reveal = genrand64_int64()%2;
        if(prize == 0) {
            if(choice == 0) {
                reveal = 1 + reveal;
            } else if(choice == 1) {
                reveal = 2;
            } else {
                reveal = 1;
            }
        } else if(prize == 1) {
            if(choice == 0) {
                reveal = 2;
            } else if(choice == 1) {
                if(reveal == 1) {
                    reveal = 2;
                }
            } else {
                reveal = 0;
            }
        } else {
            if(choice == 0) {
                reveal = 1;
            } else if(choice == 1) {
                reveal = 0;
            } else {
                reveal = 1 - reveal;
            }
        }

        // Player switch or no switch
        if(change) {
            if(choice == 0) {
                if(reveal == 1) {
                    choice = 2;
                } else {
                    choice = 1;
                }
            } else if(choice == 1) {
                if(reveal == 0) {
                    choice = 2;
                } else {
                    choice = 0;
                }
            } else {
                if(reveal == 0) {
                    choice = 1;
                } else {
                    choice = 0;
                }
            }
        }

        if(choice == prize) {
            ++wins;
        }
        ++draw;
    }

    printf("Win rate = %f\n", (double)wins/(double)draws);

    return(0);
}

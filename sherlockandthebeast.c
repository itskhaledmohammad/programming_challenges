/* AUTHOR: Khaled Mohammad
 * DATED: October 26, 2016.
 * git: https://github.com/itskhaledmohammad
 * twitter: https://twitter.com/itskhaledmd (@itskhaledmd)
 *
 * It is a programming contest practice problem from HackerRank.
 * Link to Problem: https://www.hackerrank.com/challenges/sherlock-and-the-beast
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Initialization
    int t = 0, n = 0,fives = 0, threes = 0;

    // Taking T number of cases.
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        fives = 0, threes = 0;
        scanf("%d", &n);

        // If we can fit all the fives then do it.
        if(n % 3 == 0){
            fives = n;
        }

        // Else try to fit as much fives as possible.
        else{

            fives = (n / 3) * 3;    // Total number of fives.
            threes = n - fives;     // Total number of threes.

            while(fives > -3){

                // If number of fives and threes matches the problem defination.
                if((fives % 3) == 0 && (threes % 5) == 0){
                    break;
                }

                // If no fives can be fit, only threes.
                else if(fives == 0 && (threes % 5 == 0)){
                    threes = n;
                    break;
                }

                // Else continue decrementing fives. 
                else{
                    fives -= 3;
                    threes = n - fives;
                }
            }
        }

        // If we found a DECENT number print it.
        if(fives >= 0){
            for(int i = 0; i < fives; i++){
                printf("5");
            }
            for(int j = 0; j < threes; j++){
                printf("3");
            }
            printf("\n");
        }

        // If not then print -1.
        else{
            printf("-1\n");
        }

    }
}

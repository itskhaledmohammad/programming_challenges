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
    int t = 0, n = 0,fives = 0, threes = 0;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        fives = 0, threes = 0;
        scanf("%d", &n);
        if(n % 3 == 0){
            fives = n;
        }
        else{
            fives = (n / 3) * 3;
            threes = n - fives;
            while(fives > -3){
                if((fives % 3) == 0 && (threes % 5) == 0){
                    break;
                }
                else if(fives == 0 && (threes % 5 == 0)){
                    threes = n;
                    break;
                }
                else{
                    fives -= 3;
                    threes = n - fives;
                }
            }
        }

        if(fives >= 0){
            for(int i = 0; i < fives; i++){
                printf("5");
            }
            for(int j = 0; j < threes; j++){
                printf("3");
            }
            printf("\n");
        }
        else{
            printf("-1\n");
        }

    }
}

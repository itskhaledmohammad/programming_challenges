/* AUTHOR: Khaled Mohammad
 * DATED: October 23, 2016.
 * git: https://github.com/itskhaledmohammad
 * twitter: https://twitter.com/itskhaledmd (@itskhaledmd)
 *
 * It is a programming contest practice problem from HackerRank.
 * Link to Problem: https://www.hackerrank.com/challenges/angry-professor
 *
 */

#include <stdio.h>
#include <stdlib.h>
int main(void){

    // Initialization.
    int n = 0, k = 0, a = 0, t = 0, totalStudent = 0;

           // Getting the value of t.
           scanf("%d", &t);

           // Taking n number of cases.
           for(int i = 0; i < t; i++){

               // Taking the value of n and k.
               scanf("%d %d", &n, &k);
               totalStudent = 0;

              // Checking number of students present in class on time.
               for(int j = 0; j < n; j++){
                   scanf("%d", &a);
                   if(a <= 0){
                       totalStudent++;
                   }
               }

               if(totalStudent < k){
                   printf("YES\n");
               }
               else{
                   printf("NO\n");
               }
           }
}

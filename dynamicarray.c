/*
 * AUTHOR: Khaled Mohammad
 * DATED: May 9, 2017.
 * git: https://github.com/itskhaledmohammad
 * twitter: https://twitter.com/itskhaledmd (@itskhaledmd)
 *
 * It is practice problem which requires a implementation of dynamic array.
 * Link to Problem: https://www.hackerrank.com/challenges/dynamic-array
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// We will be saving some huge integers.
typedef unsigned long long int LLT;

int main()
{
    // Initialization.
    LLT x = 0, y = 0, lastAns = 0, inx = 0, n = 0, q = 0, opt = 0, newSize = 1;

    // Taking N and Q.
    scanf("%llu %llu", &n, &q);

    // Allocating a multidimensional array.
    LLT **seqList = (LLT**) malloc(sizeof(LLT*) * n);
    if(seqList == NULL){
        free(seqList);
        printf("Couldn't allocate memory.");
        return 432;
    }
    for(LLT i = 0; i < n; i++){
        seqList[i] = (LLT*) malloc(sizeof(LLT));
        if(seqList[i] == NULL){
            free(seqList[i]);
            printf("Couldn't allocate memory.");
            return 432;
        }
        seqList[i][0] = 1; // Setting the size of the array.
    }

    for(LLT i = 0; i < q; i++){
        scanf("%llu %llu %llu", &opt, &x, &y);
        inx = (x ^ lastAns) % n;
        assert(inx >= 0);  // If the index is non-integer, kill it!
        if(opt == 1){

            seqList[inx][0] += 1;     // Increase the size by 1.
            newSize = seqList[inx][0];

            // Reallocate memory for another LLT to fit.
            LLT* buffer = (LLT*) realloc(seqList[inx], newSize * sizeof(LLT));
            if (buffer == NULL){
                free(seqList[inx]);
                printf("Couldn't allocate memory.");
                return 432;
            }
            seqList[inx] = buffer;
            seqList[inx][newSize - 1]  = y;

       }
        else{
            // let lastAns be in the range from index 1 to size of the specific inx.
            lastAns = seqList[inx][(y % ((seqList[inx][0] - 1) + 1 - 1)  + 1)];
            printf("%llu\n", lastAns);
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned long long int LLT;
int main()
{
    LLT x = 0, y = 0, lastAns = 0, inx = 0, n = 0, q = 0, temp = 0, newSize = 1;
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
        scanf("%llu %llu %llu", &temp, &x, &y);
        inx = (x ^ lastAns) % n;
        assert(inx >= 0);
        if(temp == 1){
            seqList[inx][0] += 1;
            newSize = seqList[inx][0];
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
            lastAns = seqList[inx][(y % ((seqList[inx][0] - 1) + 1 - 1)  + 1)];
            printf("%llu\n", lastAns);
        }
    }
}

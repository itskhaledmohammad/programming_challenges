/* AUTHOR: Khaled Mohammad
 * DATED: September 5, 2015.
 * git: https://github.com/itskhaledmohammad
 * twitter: https://twitter.com/itskhaledmd (@itskhaledmd)
 * This is a very simple challenge which was given to be solved
 * in a programmer recruitment interview.There is only one rule.You
 * can use only one loop for sorting the numbers.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * This functions displays the content
 * of an given array.
 */
void displayarr(int sizeA, int arr[])
{
    // Going through each element of the array and printing it.
    for(int i = 0; i < sizeA; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n"); // Printing the lines.
}

/*
 * This function splits a string of number
 * into individual digits and saves
 * it to an array.
 */
void splitInput(int arr[], int sizeArr, char num[])
{
    for(int i = 0; i < sizeArr; i++)
        // We are subtracting 48 because the numbers in ASCII starts at 48.
        arr[i] = (int)num[i] - 48;
}

int main(void)
{
    // Initialization.
    int numArr[11] , pos = 0;
    int arrSize = sizeof(numArr) / sizeof(int);
    char number[11];

    // Take input.
    printf("Enter your number > ");
    scanf("%s", number);
    splitInput(numArr, arrSize, number);

    // Display our Current array.
    printf("Our Current Array: ");
    displayarr(arrSize, numArr);

    // Shifting the non zero numbers to front.
    for(int i = 0; i < arrSize; i++){
        if(numArr[i] != 0){             // Checking if it is a non-zero number.
            numArr[pos] = numArr[i];    // Putting the non-zero number in position of our cursor.
            numArr[i] = 0;              // Putting zero in the previous place of the non-zero number.
            pos++;                      // Setting our cursor to the next position.
        }
    }
    displayarr(arrSize, numArr);        // Display our sorted array.
}


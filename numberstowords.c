/* AUTHOR: Khaled Mohammad
 * DATED: August 29, 2015.
 * git: https://github.com/itskhaledmohammad
 * twitter: https://twitter.com/itskhaledmd (@itskhaledmd)
 *
 * This program was written as challenge I found on the the internet.It looked fun so I did it!
 * Link to Problem: http://www.cprogramming.com/challenges/integer-to-english.html
 *
 * NOTE: It supports up to 999999999.
 * Because the integer can hold about roughly that number.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Macros.
#define OUT_OF_RANGE 101
#define MAX_RANGE 999999999

// Our Numbers in words.
char *units[5] = {"Hundred", "Thousand", "Million", "Billion", "Trillion", "Quadrillion"};
char *numbers[9] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
char *tens[9] = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char *teens[9] ={"Eleven", "Tweleve","Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

/*
 * This function is used to find a length
 * the length of an integer.
 */
int findLength(int Num)
{
    // Initialization.
    int length = 0;

    // Counting the number of times we are going through
    // loop until number is greater than 0.That is our length.
    while(Num > 0){
        Num /= 10;
        length++;
    }
    return length;
}

/*
 * This function converts integer in
 * between hundred and turns them in to
 * words.
 */
void toHundreds(int number, int length)
{
    // Initialization.
    int currnum = number, powed = 0, nextnum = 0;

    while(length != 0){

        powed = ceil(pow(10, length - 1)); // Calculating the power of 10 we need.
        nextnum = currnum % powed;         // Getting the first digit of the number.
        currnum = currnum / powed;         // Removing the first digit from the number and storing the rest.

        // If the number is in Hundreds.
        if(length == 3){
            printf("%s ", numbers[currnum - 1]);
            printf("%s ", units[length - 3]);
        }

        // If the number is in Tens.
        else if(length == 2){

            // If the number is between 11 - 19.
            if(currnum == 1 && nextnum > 0){
                printf("%s ", teens[nextnum - 1]);
            }

            // Any number other than 11 - 19.
            else{
                printf("%s ", tens[currnum - 1]);
            }
        }

        // If the number is in units.
        else{
            printf("%s ", numbers[currnum - 1]);
        }

        // Setting the rest of the number as the current number to deal with.
        currnum = nextnum;

        length--; // Decrementing the length.
    }

}

/*
 * This function converts integer in
 * between thousand and million and turns
 * them in to words.
 */
void upHundrends(int currNum, int power, char *unit, int *nextNum, int *lengthNum)
{
    // Initialization.
    int powed = 0, temp = 0, len = 0;


    powed = ceil(pow(10, power)); // Calculating the power of 10 we need.
    temp = currNum / powed;       // Getting or current number.
    len = findLength(temp);       // finding the length of the number we extracted.
    toHundreds(temp, len);        // Converting our numbers to words in hundreds.
    *lengthNum -= len;            // Removing the length of our current number from the original length.
    *nextNum = currNum % powed;   // Extracting the rest of our numbers we didn't use.
    printf("%s ", unit);          // Printing our units.
}

int main(void)
{
    // Initialization.
    int currNum = 0, nextNum = 0
       ,num = 0, lengthNum = 0, temp = 0, powed = 0, templen = 0, powed2 = 0;

    // Take our Input.
    printf("Please type in your number > ");
    scanf("%d", &num);

    // Checking if the number is greater than our Maximum range.
    if(num > MAX_RANGE){
        printf("Sorry your number is out of range.\n");
        return OUT_OF_RANGE;
    }

    // Calculate the length of our number.
    lengthNum = findLength(num);

    // Our loop to convert number to words.
    printf("In Words: ");

    currNum = num;                      // Setting our current number to our input.
    lengthNum = findLength(currNum);    // Finding the current length.

    while(lengthNum > 0){

        // Hundreds.
        if (lengthNum <= 3){
                toHundreds(currNum, lengthNum);
                lengthNum = lengthNum - 3;
        }

        // Thousands
        else if (lengthNum > 3 && lengthNum <= 6)
            upHundrends(currNum, 3, "Thousand", &nextNum, &lengthNum);

        // Million.
        else if(lengthNum > 6 && lengthNum <= 9)
            upHundrends(currNum, 6, "Million", &nextNum, &lengthNum);

        // Setting the rest of the number as the current number to deal with.
        currNum = nextNum;
    }
}

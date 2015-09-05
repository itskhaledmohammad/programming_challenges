/*
 * AUTHOR: Khaled Mohammad
 * DATED: September 5, 2015.
 * git: https://github.com/itskhaledmohammad
 * twitter: https://twitter.com/itskhaledmd (@itskhaledmd)
 *
 * This is a challenge where you have to printout the the
 * Pascal Triangle.
 * Wiki: https://en.wikipedia.org/wiki/Pascal%27s_triangle
 *
 */

#include <stdio.h>
#include <stdlib.h>

// Macros.
#define SPACES " "
#define COMBERR 56789
#define FACTERR 56777


/*
 * This function calculates
 * the factorial of any number.
 */
int mathFact(int number)
{
  int fact = 1;
  for(int i = number; i > 0; i--)
    fact = fact * i;
  return fact;
}

/*
 * This function calculates
 * the combination of any given values of n and r.
 * example: 4C4
 */
int mathComb(int n, int r)
{
  // Initialization.
  int result = 0;

  // Checking if the input is correct.
  if (n < r)
    return COMBERR;

  // Perform the combination formula.
  // Formula: n! / r!(n - r)!
  result = mathFact(n) / (mathFact(n - r) * mathFact(r));

  // Return the result.
  return result;
}

int main(void)
{
  // Initialization.
  int height = 0, rows = 0 ,pos = 0,spaces = 0;

  // Taking our input of the height.
  printf("Type the height of the pyramid: ");
  scanf("%d", &height);

  // Make our pyramid.
  for(rows = 0; rows < height; rows++){

    // Making things pretty.
    for(spaces = height - rows;spaces > 0; spaces--)
      printf(SPACES);   // Print the spaces.

    // Print in the numbers according to their position.
    for(pos = 0; pos <= rows; pos++)
      printf("%d ",mathComb(rows, pos));

    printf("\n");
  }

  printf("\n"); // Printing a new line.Just making things pretty.
}

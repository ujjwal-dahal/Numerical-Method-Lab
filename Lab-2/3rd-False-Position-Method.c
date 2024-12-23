/*
Solve this Equation using False Position Method in C : xlog10(x) - 1.2

Theory:
The False Position Method is a numerical method to find the root of a nonlinear equation.
It improves upon the Bisection Method by using a secant line to estimate the root.
This method requires two initial guesses, x0 and x1, such that f(x0) * f(x1) < 0.

Formula:
    c = ( a * f(b) - b * f(a)) / f(b) - f(a)
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) ((x) * log10(x) - 1.2)

int main()
{
  float a, b, c, fa, fb, fc, e;
  int Iteration = 1, N;

  // Title of the program
  printf("\nC Program using False Position Method By UJJWAL DAHAL on 2081-09-08\n\n");

  // Input values
  printf("Enter Lower Initial Guess (x0), Upper Initial Guess (x1), Tolerance (e), and Maximum Iterations: ");
  scanf("%f %f %f %d", &a, &b, &e, &N);

  // Check for valid initial guesses
  fa = f(a);
  fb = f(b);
  if (fa * fb > 0.0)
  {
    printf("\nWrong Initial Guesses! The function must have opposite signs at a and b.\n");
    exit(0);
  }

  if (fa == fb)
  {
    printf("\n False Position Method Error");
  }

  // Table header
  printf("\n---------------------------------------------------------------------------------------------------\n");
  printf("Iteration \t a \t\t\t b \t\t\t c \t\t\t f(c)\n");
  printf("---------------------------------------------------------------------------------------------------\n");

  // False Position Method
  do
  {
    fa = f(a);
    fb = f(b);

    // Apply the formula for False Position Method
    c = ((a * f(b) - (b * f(a))) / (f(b) - f(a)));
    fc = f(c);

    // Print the current iteration
    printf("%d \t\t %0.6f \t\t %0.6f \t\t %0.6f \t\t %0.6f\n", Iteration, a, b, c, f(c));

    // Update the bounds
    if (fa * fb < 0.0)
    {
      if ((fa < 0.0 && fc < 0.0) || (fa > 0.0 && fc > 0.0))
      {
        a = c;
      }
      else if ((fb < 0.0 && fc < 0.0) || (fb > 0.0 && fc > 0.0))
      {
        b = c;
      }
    }

    Iteration++;

    // Check for iteration limit
    if (Iteration > N)
    {
      printf("\nThe method did not converge within the maximum number of iterations.\n");
      exit(0);
    }

  } while (fabs(fc) > e); // Check for convergence

  // Result
  printf("\n---------------------------------------------------------------------------------------------------\n");
  printf("\nThe required root is: %.6f\n\n", c);

  return 0;
}


/*
Pseudo Code

1. Start
2. Initialize a, b, tolerance (e), and maximum iterations (N)
3. Calculate f(a) and f(b)
4. If f(a) * f(b) > 0, exit (Invalid initial guesses)
5. Repeat until convergence:
    a. Calculate c = (a * f(b) - b * f(a)) / (f(b) - f(a))
    b. Calculate f(c)
    c. Print the current iteration: a, b, c, f(c)
    d. If |f(c)| < tolerance, exit
    e. If f(a) * f(c) < 0, set b = c
    f. Otherwise, set a = c
    g. Increment iteration count
6. Output the root approximation c
7. End


*/
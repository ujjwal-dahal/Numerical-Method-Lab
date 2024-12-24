

/*
Theory:

The Fixed Point Iteration Method is a numerical method used to find the root of an equation of the form f(x) = 0.
It is based on the idea that a root r of the equation f(x) = 0 can be expressed as x = g(x), where g(x) is a function derived from f(x).

The iteration formula is:
    x_{n+1} = g(x_n) = cos(x_n) * e^(-x_n)

Formula:
Rearranging the given equation x * e^x - cos(x) = 0:
    x = cos(x) * e^(-x)

So, the iteration method will update x using:
    x_{n+1} = cos(x_n) * e^(-x_n)
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) (x * exp(x) - cos(x))
#define g(x) (cos(x) * exp(-x))

// #define f(x) (sin(x) + (3 * x) - 2)
// #define g(x) (2 - sin(x)) / 3

int main()
{
  float x0, x1, e;
  int N, iteration = 1;

  // Title of the program
  printf("\nC Program By Fixed Point Iteration Method By UJJWAL DAHAL on 2081-09-08\n\n");

  float a, b, fa, fb, difference;
  printf("\n Enter Two Initial Guess : ");
  scanf("%f %f", &a, &b);
  printf("\n Enter Value of e & N : ");
  scanf("%f %d", &e, &N);
  fa = f(a);
  fb = f(b);

  if (fa * fb > 0.0)
  {
    printf("\n Wrong Guess \n");
    exit(0);
  }

  x0 = (a + b) / 2;

  // Start with x1 = g(x0)
  x1 = g(x0);

  // Print header for output
  printf("Iteration \t x_n \t\t x_{n+1} \t Difference\n");
  printf("----------------------------------------------------------\n");

  // Fixed Point Iteration
  do
  {
    // Update x0 to x1
    x0 = x1;

    // Apply the iteration formula
    x1 = g(x0);

    // Calculate the difference between x1 and x0
    float difference = fabs(x1 - x0);

    // Print the results of the current iteration
    printf("%d \t\t %.6f \t %.6f \t %.6f\n", iteration, x0, x1, difference);
    iteration++;

    // Check for convergence
    if (difference < e)
    {
      break;
    }

  } while (iteration <= N); // Check if iteration limit is reached

  // Check if the method converged
  if (fabs(x1 - x0) < e)
  {
    printf("\nThe root is approximately: %.6f\n", x1);
  }
  else
  {
    printf("\nThe method did not converge within %d iterations.\n", N);
  }

  return 0;
}

/*
-> Pseudo Code

1. Start
2. Input two initial guesses a and b, tolerance e, and maximum iterations N
3. Calculate f(a) and f(b)
4. If f(a) * f(b) > 0, print "Wrong Guess" and exit
5. Compute x0 = (a + b) / 2
6. Start with x1 = g(x0)
7. Repeat until convergence or iteration limit:
    a. Set x0 = x1
    b. Compute x1 = g(x0)
    c. Calculate difference = |x1 - x0|
    d. Print iteration, x_n, x_{n+1}, and difference
    e. If difference < e, exit (convergence achieved)
8. If |x1 - x0| < e, print the root. Otherwise, print that the method did not converge
9. End


*/

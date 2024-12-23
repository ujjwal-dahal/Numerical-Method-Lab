/*
Use Secant Method to Solve ((3 * (x)) - exp(x) + sin(x))

Formula: x2 = ((f1 * x0) - (f0 * x1)) / (f1 - f0)
*/

#include <stdio.h> // Standard Input Output Library
#include <math.h>  // Import always for Numerical Method Problems
#include <stdlib.h>

#define f(x) ((3 * (x)) - exp(x) + sin(x))

void main()
{
  float x0, x1, x2, f0, f1, f2, e;
  int Iteration = 1, N;

  printf("\nC Program for Secant Method by Ujjwal Dahal on 2081-09-08\n");

  // Input initial guesses, maximum iterations, and tolerance
  printf("\nEnter initial guesses (x0, x1), maximum iterations (N), and Tolerance (e): ");
  scanf("%f %f %d %f", &x0, &x1, &N, &e);

  // Print table headers
  printf("\n_________________________________________________________________\n");
  printf("Iteration\t\tx0\t\tx1\t\tx2\t\t\tf(x2) \n");
  printf("_________________________________________________________________\n");

  do
  {
    f0 = f(x0);
    f1 = f(x1);

    // Check for division by zero
    if (f0 == f1)
    {
      printf("Secant Method cannot be applied (division by zero).\n");
      exit(0);
    }

    // Apply the Secant Method formula
    x2 = ((f1 * x0) - (f0 * x1)) / (f1 - f0);
    f2 = f(x2);

    // Print the current iteration
    printf("%d \t\t %f \t %f \t\t %f \t\t %f\n", Iteration, x0, x1, x2, f2);

    // Update values for the next iteration
    x0 = x1;
    x1 = x2;
    Iteration++;

    // Check if maximum iterations are reached
    if (Iteration > N)
    {
      printf("\nThe solution does not converge within the maximum number of iterations.\n");
      exit(0);
    }
  } while (fabs(f2) > e); // Check if the tolerance is achieved

  // Print the final result
  printf("\n___________________________________________\n");
  printf("The appropriate real root of the equation is %0.8f\n\n\n", x2);
}

/*



*/

/*
Pseudo Code

1: Start
2: Input initial guesses (x0, x1), maximum iterations (N), and tolerance (e)
3: Initialize iteration = 1
4: Calculate f0 = f(x0) and f1 = f(x1)
5: If f0 == f1, print "Secant Method cannot be applied (division by zero)" and exit
6: While iteration <= N:
    6.1: Calculate x2 = ((f1 * x0) - (f0 * x1)) / (f1 - f0)
    6.2: Calculate f2 = f(x2)
    6.3: Print "Iteration", iteration, "x0:", x0, "x1:", x1, "x2:", x2, "f(x2):", f2
    6.4: If |f2| <= e, print "The root is approximately:", x2 and exit
    6.5: Set x0 = x1, x1 = x2
    6.6: Increment iteration by 1
7: If iteration > N, print "The solution did not converge within N iterations" and exit
8: End

*/
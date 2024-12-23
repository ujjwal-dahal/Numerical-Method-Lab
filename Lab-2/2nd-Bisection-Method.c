/*
Use Bisection Method To Solve This Equation :

Formula : x2 = (x1 + x0) / 2
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) ((3 * (x)) - 1 - cos(x))

int main()
{
    float x0, x1, e, f0, f1, x2, f2;
    int Iteration = 1; // Initialize iteration count

    // Title of the program
    printf("\nC Program using Bisection Method By Ujjwal Dahal on 2081-09-08\n");

    // Input values
    printf("\nEnter Lower Initial Guess (x0): ");
    scanf("%f", &x0);

    printf("\nEnter Upper Initial Guess (x1): ");
    scanf("%f", &x1);

    printf("\nEnter Value of Predefined Absolute Error (e): ");
    scanf("%f", &e);

    // Table header
    printf("\n--------------------------------------------------------------------------------\n");
    printf("Iteration \t x0 \t\t x1 \t\t x2 \t\t f(x2)\n");
    printf("--------------------------------------------------------------------------------\n");

    // Bisection Method
    do
    {
        f0 = f(x0);
        f1 = f(x1);

        // Check for invalid initial guesses
        if (f0 * f1 > 0.0)
        {
            printf("\nWrong Initial Guesses! The function must have opposite signs at x0 and x1.\n");
            exit(0); // Exit with error code
        }

        // Calculate midpoint
        x2 = (x0 + x1) / 2;
        f2 = f(x2);

        // Print the current iteration
        printf("%d \t\t %10.6f \t %10.6f \t %10.6f \t %10.6f\n", Iteration, x0, x1, x2, f2);

        // Update the bounds
        if (f0 * f2 < 0.0)
        {
            x1 = x2;
        }
        else
        {
            x0 = x2;
        }

        Iteration++;
    } while (fabs(f2) > e); // Check for convergence

    // Result
    printf("\n----------------------------------------------------------");
    printf("\nRequired Root is: %.6f\n\n", x2);

    return 0;
}

/*
Pseudo Code

1. Start
2. Initialize x0, x1, tolerance (e), and iteration count
3. Calculate f(x0) and f(x1)
4. If f(x0) * f(x1) > 0, exit (Invalid initial guesses)
5. Repeat until convergence:
    a. Calculate x2 = (x0 + x1) / 2
    b. Calculate f(x2)
    c. Print the current iteration: x0, x1, x2, f(x2)
    d. If |f(x2)| < tolerance, exit
    e. If f(x0) * f(x2) < 0, set x1 = x2
    f. Otherwise, set x0 = x2
    g. Increment iteration count
6. Output the root approximation x2
7. End


 */

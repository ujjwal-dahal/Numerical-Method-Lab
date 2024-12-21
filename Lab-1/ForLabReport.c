#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define the function f(x) and its derivative
#define fx(x) ((x) * log10(x) - 1.2)       // Use log10 for base-10 logarithm
#define d_fx(x) (log10(x) + 1 / log(10))   // Correct derivative of x * log10(x)

int main()
{
    // Declare variables
    float x0, f0, d_f0, x1, f1, e;
    int Iteration = 1, N;
    char myName[10] = "Ujjwal";
    char createdDate[50] = "24 Mangsir 2081, Monday";

    // Display program title
    printf("\nC Program For Newton-Raphson Method Created By: %s On: %s\n", myName, createdDate);

    // Input: Initial guess, maximum iterations, and allowable error
    printf("\nEnter the value of initial guess (x0): ");
    scanf("%f", &x0);

    printf("Enter the maximum number of iterations (N): ");
    scanf("%d", &N);

    printf("Enter the allowable error (e): ");
    scanf("%f", &e);

    // Display table header
    printf("\n----------------------------------------------------------------------------\n");
    printf("| Iteration\t| x0\t\t| f(x0)\t\t| x1\t\t| f(x1)\t\t|\n");
    printf("----------------------------------------------------------------------------\n");

    // Newton-Raphson Method
    do
    {
        // Evaluate f(x0) and f'(x0)
        f0 = fx(x0);
        d_f0 = d_fx(x0);

        // Check if derivative is zero (to avoid division by zero)
        if (d_f0 == 0.0)
        {
            printf("\nMathematical error: Derivative is zero.\n");
            exit(0);
        }

        // Calculate the next approximation x1
        x1 = x0 - (f0 / d_f0);
        f1 = fx(x1);

        // Display current iteration
        printf("| %d\t\t| %.6f\t| %.6f\t| %.6f\t| %.6f\t|\n", Iteration, x0, f0, x1, f1);

        // Update x0 for the next iteration
        x0 = x1;
        Iteration++;

        // Exit if maximum iterations reached
        if (Iteration > N)
        {
            printf("The solution does not converge within the given iterations.\n");
            exit(0);
        }

    } while (fabs(f1) > e); // Stop when |f(x1)| <= e

    printf("----------------------------------------------------------------------------\n");
    printf("\nThe required approximate root is: %.6f\n", x1);

    return 0;
}

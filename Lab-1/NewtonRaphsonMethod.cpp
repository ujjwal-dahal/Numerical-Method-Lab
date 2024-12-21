#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

#define fx(x) (x * log10(x) - 1.2)             // Use log10 for base-10 logarithm
#define d_fx(x) (log10(x) + 1 / (x * log(10))) // Derivative of x * log10(x)

using namespace std;

int main()
{
  float x0, f0, d_f0, x1, f1, e;
  int Iteration = 1, N;
  char myName[10] = "Ujjwal";
  char createdDate[50] = "24 Mangsir 2081, Monday";

  // Title
  cout << "\nC++ Program For Newton-Raphson Method Created By: "
       << myName << " On: " << createdDate << endl;

  // Input
  cout << "\nEnter the value of initial guess (x0): ";
  cin >> x0;

  cout << "Enter the maximum number of iterations (N): ";
  cin >> N;

  cout << "Enter the allowable error (e): ";
  cin >> e;

  // Display table header
  cout << "\n----------------------------------------------------------------------------" << endl;
  cout << "| Iteration \t|x0\t\t|f(x0)\t\t|x1\t\t|f(x1)\t\t|" << endl;
  cout << "----------------------------------------------------------------------------" << endl;

  // Newton-Raphson Method
  cout << fixed << setprecision(6);
  do
  {
    f0 = fx(x0);
    d_f0 = d_fx(x0);

    if (d_f0 == 0.0)
    {
      cout << "\nMathematical error: Derivative is zero." << endl;
      exit(0);
    }

    x1 = x0 - (f0 / d_f0);
    f1 = fx(x1);

    // Display current iteration
    cout << "| " << Iteration << "\t\t"
         << x0 << "\t"
         << f0 << "\t"
         << x1 << "\t"
         << f1 << endl;

    // Update x0 for next iteration
    x0 = x1;
    Iteration++;

    // Exit if maximum iterations reached
    if (Iteration > N)
    {
      cout << "The solution does not converge within the given iterations." << endl;
      exit(0);
    }

  } while (fabs(f1) > e); // Use difference between successive approximations

  cout << "----------------------------------------------------------------------------" << endl;
  cout << "\nThe required approximate root is: " << x1 << endl;

  return 0;
}

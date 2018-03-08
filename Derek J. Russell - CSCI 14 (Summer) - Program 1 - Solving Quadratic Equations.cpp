/// Derek J. Russell
/// Ms. Wanda Wong
/// CSCI 14 - Summer 2015
/// Program 1 due Friday, 7/3/2015 @ 11:00pm
/// June 26, 2015
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

 main (int argc, char *argv[], char again, int SUCCESSFUL_ACCESS_ACE_FLAG)
 {
   double a, b, c;
   double x[2];
   double square_discriminant;
   double Solution_1, Solution_2;
   char symbol;

    if (argc == 4)
    {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        c = atoi(argv[3]);

        return argc == 4;
    }
     do
        {
             cout << "Name - Derek J. Russell\n\n";
             cout << "Date - June 29, 2015\n\n\n\n\n";
             cout << "\t\t\tSolving Quadratic Equations" << endl;
             cout << endl << endl << endl;
             cout << "\t * This program solves Quadratic Equations." << endl;
             cout << endl;
             cout << "\t * It will test to see if the equation has a solution or not. " << endl;
             cout << endl;
             cout << "\t * It will also test to see if the solution is unique." << '\n';
             cout << endl << endl;
             cout << "Please type in the three coefficients a, b, c for a quadratic equation: " << endl;
             cout << endl << endl;
             cout << "ax^2 + bx + c    ";
             cin >> a >> b >> c;

             /// Calculations  Computations
             square_discriminant  = ((b * b) -4 * a * c);
             Solution_1 = (-b + sqrt(square_discriminant)) / (2 * a);
             Solution_2 = (-b - sqrt(square_discriminant)) / (2 * a);

             /// Formating #include <iomanip> = 1.000
             cout << fixed << showpoint << setprecision(3) << endl;

             cout << endl;

             if (a == 0)
             {
               cout << "This is a line; not a Quadratic Equation." << endl;
               cout << endl;
               cout << static_cast<int>(a) << "x^2 + " << static_cast<int>(b) << "x + "
                    << static_cast<int>(c) << " has unique solution " << (-c / b) << "." << endl;

                    //return Solution_1 = -c / b;
             }
             else if(square_discriminant < 0 )
             {
                 cout << static_cast<int>(a) << "x^2 + " << static_cast<int>(b) << "x + "
                      << static_cast<int>(c) << " has no solution" << "." << endl;
             }
             else if(Solution_1 == Solution_2)
             {
                cout << static_cast<int>(a) << "x^2 + " << static_cast<int>(b) << "x + "
                     << static_cast<int>(c) << " has unique solution " << Solution_2 << "." << endl;

             }
             else
             {
                 cout << static_cast<int>(a) << "x^2 + " << static_cast<int>(b) << "x + "
                      << static_cast<int>(c) << " has unique solutions " << Solution_1 << " and "
                      << Solution_2 << "." << endl;
            }

             cout << endl << endl << endl << endl << endl;
             system("PAUSE");
             system("CLS");
             cout << "Would you like to calculate again (Y or N): "; ///Option!
             cin >> again;
             cout << endl << endl << endl;
        } while (again == 'Y' || again == 'y');

        return SUCCESSFUL_ACCESS_ACE_FLAG;
        exit(23);
 }



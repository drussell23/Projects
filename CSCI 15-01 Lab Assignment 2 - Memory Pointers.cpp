/**
    Derek J. Russell
    Professor Desmond Chun
    CSCI 15-01 Lab Assignment 2
    Due - February 22nd, 2016
    Memory Pointers
    February 14th, 2016
**/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <cctype>
using namespace std;

/// Function Prototype
void Calculate_Pointer(double *pnum1, double *pnum2, double *Add, double *Subtract, double *Multiply);

/// Performing Calculation by using pointers to return multiple values in a single function.
    /**
         a. - Add the two values, pnum1, is "pointing to" and pnum2 is "pointing to"
         b. - Subtract the value pnum2 is "pointing to" from the value pnum1 is "pointing to" (i.e. *pnum1 - *pnum2)
         c. - Multiply the two values, pnum1 is "pointing to" and pnum2 is "pointing to"
         d. - Do not display the output in the function.
    **/
void Calculate_Pointer(double *pnum1, double *pnum2, double *Add, double *Subtract, double *Multiply)
{
     *Add = *pnum1 + *pnum2;
     *Subtract = *pnum1 - *pnum2;
     *Multiply = *pnum1 * *pnum2;
}
int main()
{
   double *pnum1, *pnum2; /// These pointers holds the address of number1, number2.
   double *Add, *Subtract, *Multiply; /// These pointers holds the address of A, S, & M.

   double number1, number2; /// These variables will hold doubles.
   double A, S, M; /// These variables will hold doubles.

    Add = &A; /// Add points to the address of A.
    Subtract = &S; /// Subtract points to the address of S.
    Multiply = &M; /// Multiply points to the address of M.

        time_t CurrentTime;
        struct tm *localTime;

        time(&CurrentTime); /// This gets the current time.
        localTime = localtime(&CurrentTime); /// This converts the time to local time.

        int Day   = localTime -> tm_mday;
        int Month = localTime -> tm_mon + 1;
        int Year  = localTime -> tm_year + 1900;
        int Hour  = localTime -> tm_hour;
        int Min   = localTime -> tm_min;
        int Sec   = localTime -> tm_sec;

  char again = 'y';

   while (again == 'y')
   {
       cout << "Name: Derek J. Russell\t\t\t\t" << "\t\t" << "Date: " << Month << "-" << Day << "-" << Year << endl;
       cout << "\n\n";
       cout << "\t\t\2 CSCI 15-01 Lab Assignment 2 - Memory Pointers \1" << endl;
       cout << "\n\n";
       cout << "1 of 2: Enter a Decimal Number for Variable 'number 1:' ";
       cin >> number1;
       pnum1 = &number1;

       cout << endl;
       cout << "2 of 2: Enter a Decimal Number for Variable 'number 2': ";
       cin >> number2;
       pnum2 = &number2;
       cout << "\n\n";

       /// Performing Calculations
       Calculate_Pointer(pnum1, pnum2, Add, Subtract, Multiply); /// Function Call!
       cout << setw(25) << "\4 HERE IS THE RESULT \1" << endl;
       cout << "\n\n";
       cout << "\t" << *pnum1 << " + " << *pnum2 << " = " << *Add << endl;
       cout << endl;
       cout << "\t" << *pnum1 << " - " << *pnum2 << " = " << *Subtract << endl;
       cout << endl;
       cout << "\t" << *pnum1 << " X " << *pnum2 << " = " << *Multiply << endl;

       cout << "\n\n\n";
       cout << "Run this Again (Y or N): ";
       cin >> again;
       again = tolower(again); /// If the user puts in a lowercase letter.
       system("CLS");
   }
    return 0;
}

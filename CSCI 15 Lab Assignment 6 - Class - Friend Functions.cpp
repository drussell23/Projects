/**
    Derek J. Russell
    Professor Desmond Chun
    CSCI 15 - Lab Assignment 6
    Due: April 11th, 2016
    Classes - Friend Functions
    April 5th, 2016
**/
#include <iostream>
#include <iomanip> /// setw();
#include <cctype> /// tolower();
#include <cstdlib>
#include <ctime>
using namespace std;

class Arithmetic_Functions
{
    protected:
            double n1, n2;

    public:

            double Addition() const // Add two numbers and return the sum (n1 + n2).
            { return n1 + n2; }

            double Subtraction() const // Subtract two numbers and return the difference (n1 - n2).
            { return n1 - n2; }

            double Multiply() const // Multiply two numbers and return the product (n1 * n2).
            { return n1 * n2; }

            double Dividing() // Divide two numbers and return the dividend (n1 / n2). If n2 is zero, set n2 to 1.
            {
                if(n2 == 0)
                {
                    cout  << setw(25) << "\1 SORRY! Cannot Divide By Zero!!!" << endl;
                    cout << endl;
                    n2 = 1; // Set n2 to 1 as a default.

                    return n1;
                }
                return n1 / n2; // Returns the quotient.
            }
            double Get_Number1() // Gets the variable of n1 and returns it in the Get_Number1() function.
                { return n1; }

            double Get_Number2() // Gets the variable of n2 and returns it in the Get_Number2() function.
                { return n2; }
            // Average - pass the class object and return the average of n1 and n2.
            friend double Average(Arithmetic_Functions num_Object)
            {
                return (num_Object.Get_Number1() + num_Object.Get_Number2()) / 2; /// Returns the AVERAGE.
            }
            /**
             Compare1 - pass the class object and return the Larger of n1 and n2.
            **/
            friend double Compare1(Arithmetic_Functions Comparsion_Object1)
            {
                if(Comparsion_Object1.Get_Number1() == 0 && Comparsion_Object1.Get_Number2() == 0)
                {
                   /// If n1 and n2 are equal zero to signal that n1 and n2 are equal.
                    cout << "Both numbers are equal to 0." << endl;
                }

                if(Comparsion_Object1.Get_Number1() < Comparsion_Object1.Get_Number2())
                {
                    return Comparsion_Object1.Get_Number2(); /// Returns the LARGER Number (n2).
                }
                else
                {
                    return Comparsion_Object1.Get_Number1(); /// Returns the LARGER Number (n1).
                }
            }
            friend double Compare2(Arithmetic_Functions Comparsion_Object2)
            {
                if(Comparsion_Object2.Get_Number1() == 0 && Comparsion_Object2.Get_Number2() == 0)
                    {
                        /// If n1 and n2 are equal zero to signal that n1 and n2 are equal.
                        cout << "Both numbers are equal to 0." << endl;
                    }

                if(Comparsion_Object2.Get_Number1() > Comparsion_Object2.Get_Number2())
                {
                    return Comparsion_Object2.Get_Number2(); /// Returns the SMALLER Number (n2).
                }
                else
                {
                    return Comparsion_Object2.Get_Number1(); /// Returns the SMALLER Number (n1).
                }
            }
            void Input_FUNCTION() /// User Input from the keyboard.
            {
                cout << "1 of 2 - Enter First numeric Value: ";
                cin >> n1;
                cout << endl;

                cout << "2 of 2 - Enter Second numeric Value: ";
                cin >> n2;
                cout << "\n\n";
            }
            void Output_FUNCTION() /// Outputs the Results.
            {
                cout << "==============================================================" << endl;
                cout << endl;
                cout << "\1 Results:" << endl;
                cout << "\n\n";
                cout << n1 << " + " << n2 << " = " << Addition() << endl;
                cout << endl;
                cout << n1 << " - " << n2 << " = " << Subtraction() << endl;
                cout << endl;
                cout << n1 << " X " << n2 << " = " << Multiply() << endl;
                cout << endl;
                cout << n1 << " / " << n2 <<  " = " << Dividing() << endl;
                cout << "\n\n";
                cout << "==============================================================" << endl;
                cout << endl;
                cout << "Average of " << Addition() << " is " << Average(*this) << endl;
                cout << endl;
                cout << "The Larger of " << n1 << " and " << n2 << " is " << Compare1(*this) << endl;
                cout << endl;
                cout << "The Smaller of " << n1 << " and " << n2 << " is " << Compare2(*this) << endl;
            }
};
/// Function Prototypes.
void DisplayTitle();

void DisplayTitle()
{
    time_t CurrentTime;
    struct tm *localTime;

    time(&CurrentTime); /// This gets the current time.
    localTime = localtime(&CurrentTime); /// This converts the time to local time.

      intmax_t Day   = localTime -> tm_mday;
      intmax_t Month = localTime -> tm_mon + 1;
      int Year  = localTime -> tm_year + 1900;
      int Hour  = localTime -> tm_hour;
      int Min   = localTime -> tm_min;
      int Sec   = localTime -> tm_sec;

       cout << "Name: Derek J. Russell\t\t\t\t" << "\t\t" << "Date: " << Month << "/" << Day << "/" << Year << endl;
       cout << "\n\n";
       cout << setw(55) << "\t\1 CSCI 15 Assignment 6: Class - Friend Functions \2" << endl;
       cout << "\n\n";
       cout << "Clock: " << Hour << ":" << Min << ":" << Sec << endl;
       cout << "\n\n";
}
int32_t main()
{
    Arithmetic_Functions Number;
    char again = 'y';

    while (again == 'y')
    {
        DisplayTitle();
        Number.Input_FUNCTION();
        Number.Output_FUNCTION();
        cout << "\n\n\n";
        cout << "Run this Again (Y or N): ";
        cin >> again;
        again = tolower(again); /// To lower the letter.
        system("CLS");
    }
    return 0;
}

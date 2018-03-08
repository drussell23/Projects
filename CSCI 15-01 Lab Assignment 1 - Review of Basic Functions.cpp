/**
    Derek J. Russell
    Professor Desmond Chun
    CSCI 15-01 Lab Assignment 1
    Due - February 8th, 2016
    Review of Basic Functions
    January 29th, 2016
**/
#include <iostream> /// Console Input & Output
#include <stdlib.h> /// System("CLS"); System("PAUSE");
#include <iomanip>  /// cout.precision(2); cout.setf(ios::fixed);
#include <ctime> /// time_t - time(&CurrentTime); /// This gets the current time.

using namespace std;

/// Function Prototypes.
double Addition(double number1, double number2); /// Addition Function.
double Subtract(double number1, double number2); /// Subtraction Function.
double Multiplication(double number1, double number2); /// Multiplication Function.
double Divide(double number1, double number2); /// Divide Function.
void Calling_All_Arithmetic_Functions(double number1, double number2); /// Special Function Calling Other Function.
void Definitions_of_Arithmetic_Operations_1(); /// Overview Of The Program.

double Addition(double number1, double number2)
{
    return number1 + number2;
}
double Subtract(double number1, double number2)
{
    return number1 - number2;
}
double Multiplication(double number1, double number2)
{
    return number1 * number2;
}
double Divide(double number1, double number2)
{
    /** (1) - This condition test if the denominator is 0.
        (2) - If the condition is equal to zero, it will display a message
              to the user, "Cannot Divide By Zero.

        (3) - The dividend is the numerator (number 1).
        (4) - The divisor is the denominator (number 2).
    **/
    if(number2 == 0) /// This condition test if the denominator is 0.
    {
       /// Display the message to the user.
        cout << "\t \1 Cannot Divide By Zero!" << endl; /// Display the massage to user that the denominator is undefined.
        cout << endl;
        number2 = 1; /// Sets default number 2 (denominator) to 1.

        return number1; /// This is returning the dividend of the numerator.  (dividend / divisor).
    }

    return number1 / number2; /// Returns the quotient of the function.
}
void Calling_All_Arithmetic_Functions(double number1, double number2)
{
    cout << "\t" << number1 << " + " << number2 << " = " <<  Addition(number1, number2) << endl;
    cout << endl;
    cout << "\t" << number1 << " - " << number2 << " = " << Subtract(number1, number2) << endl;
    cout << endl;
    cout << "\t" << number1 << " * " << number2 << " = " << Multiplication(number1, number2) << endl;
    cout << endl;
    cout << "\t" << number1 << " / " << number2 << " = " <<  Divide(number1, number2) << endl;
    cout << "\n\n\n";
}
void Definitions_of_Arithmetic_Operations_1() /// Overview of the program.
{
    cout << setw(40) << "\t\t\2 Definitions of Arithmetic Operations \1" << endl;
    cout << "\n\n";
    cout << "1. Addition - Addition is finding the total, or sum, by combining two" << '\n';
    cout << endl;
    cout << "              or more numbers." << '\n';
    cout << endl << endl;
    cout << " Example: 5 + 11 + 3 = 19" << '\n';
    cout << "\n\n\n\n\n";
    system("PAUSE");
    system("CLS");
    cout << endl;
    cout << setw(40) << "\t\t\2 Definitions of Arithmetic Operations \1" << endl;
    cout << "\n\n";
    cout << "2. Subtraction - Taking one number away from another. If you have 5 apples" << '\n';
    cout << endl;
    cout << "                 and you subtract 2, you are left with 3." << '\n';
    cout << endl << endl;
    cout << " Example: 5 - 2 = 3" << '\n';
    cout << "\n\n\n\n\n";
    system("PAUSE");
    system("CLS");
    cout << setw(40) <<"\t\t\2 Definitions of Arithmetic Operations \1" << endl;
    cout << "\n\n";
    cout << "3. Multiplication - The basic idea of multiplication is repeated addition." << '\n';
    cout << endl;
    cout << "                    But as well as multiplying by whole numbers, we can also" << '\n';
    cout << endl;
    cout << "                    multiply by fractions, decimals and more." << endl;
    cout << endl << endl;
    cout << "\tExample: 5 x 3 = 5 + 5 + 5 = 15" << endl;
    cout << "\n\n\n\n\n";
    system("PAUSE");
    system("CLS");
    cout << setw(40) << "\t\t\2 Definitions of Arithmetic Operations \1" << endl;
    cout << "\n\n";
    cout << "4. Divide - To divide is to split into equal parts or group." << endl;
    cout << endl;
    cout << "            It is 'fair sharing'." << '\n';
    cout << endl << endl;
    cout << "\tExample 1: there are 12 chocolates, and 3 friends want to share" << endl;
    cout << endl;
    cout << "\t           them, how do they divide the chocolates?" << endl;
    cout << endl << endl;
    cout << "                 * Answer: They should get 4 each." << endl;
    cout << "\n\n";
    cout << "\t\t* We use the / symbol to divide numbers." << '\n';
    cout << endl << '\n';
    cout << "\t\tExample 2: 12 / 3 = 4" << endl;
    cout << endl << endl;
}
int main(double number1, double number2)
{
    int choice, again;

    const int Addition_Selection = 1,
              Subtraction_Selection = 2,
              Multiplication_Selection = 3,
              Division_Selection = 4,
              All_Arithemetic_Calculation_Combined = 5,
              Definition_Of_Arithmetic_Operations = 6,
              Quit_The_Program = 7;

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

    do
    {
        do
        {
            cout << "Name: Derek J. Russell\t\t\t\t" << "\t\t"
                 << "Date: " << Month << "-" << Day << "-" << Year << endl;
            cout << "\n\n";
            cout << setw(49) << "\t\t\2 Welcome to the Arithmetic Calculator \1" << endl;
            cout << "\n\n";
            cout << "[1 of 2] - Enter First Number: ";
            cin >> number1;
            cout << endl;
            cout << "[2 of 2] - Enter Second Number: ";
            cin >> number2;
            cout << "\n\n\n";
            cout << "\t1 - Add (" << number1 << " + " << number2 << ")" << endl;
            cout << '\n';
            cout << "\t2 - Subtract (" << number1 << " - " << number2 << ")" << endl;;
            cout << '\n';
            cout << "\t3 - Multiplication (" << number1 << " X " << number2 << ")" << endl;
            cout << '\n';
            cout << "\t4 - Divide (" << number1 << " / " << number2 << ")" << endl;;
            cout << '\n';
            cout << "\t5 - ALL" << endl;
            cout << '\n';
            cout << "\t6 - Definition of Arithmetic Operations (+, -, x, /) " << endl;
            cout << '\n';
            cout << "\t7 - Quit" << endl;
            cout << "\n\n";
            cout << "Enter Your Choice (1 - 7): ";
            cin >> choice;
            /// This is a test condition that test if the user enters less than 1 or greater than 7.
            if(choice < 1 || choice > 7)
            {
                cout << "\n\n\n";
                cout << "Please Enter a Number From 1 - 7. " << endl;
            }

            cout << "\n\n\n";
            system("PAUSE");
            system("CLS");
        }while(choice < 1 || choice > 7);

        switch(choice)
        {
            case Addition_Selection:

                cout << "1. - Addition" << endl;
                cout << endl;
                cout << " \2 Here is the result \1" << endl;
                cout << endl << endl;
                cout << number1 << " + " << number2 << " = " <<  Addition(number1, number2) << endl;
                cout << "\n\n\n";
                system("PAUSE");
                system("CLS");
                break;

            case Subtraction_Selection:

                cout << "2. - Subtraction" << endl;
                cout << endl;
                cout << " \2 Here is the result \1" << endl;
                cout << endl << endl;
                cout << number1 << " - " << number2 << " = " << Subtract(number1, number2) << endl;
                cout << "\n\n\n";
                system("PAUSE");
                system("CLS");
                break;

            case Multiplication_Selection:

                cout << "3. - Multiplication" << endl;
                cout << endl;
                cout << " \2 Here is the result \1" << endl;
                cout << endl << endl;
                cout << number1 << " * " << number2 << " = " << Multiplication(number1, number2) << endl;
                cout << "\n\n\n";
                system("PAUSE");
                system("CLS");
                break;

            case Division_Selection:

                cout << "4. - Division" << endl;
                cout << endl;
                cout << " \2 Here is the result \1" << endl;
                cout << endl << endl;
                cout << "\t" << number1 << " / " << number2 << " = " << Divide(number1, number2) << endl;
                cout << "\n\n\n";
                system("PAUSE");
                system("CLS");
                break;

            case All_Arithemetic_Calculation_Combined:

                cout << "\2 Result for all Arithmetic Calculation Operations \1" << endl;
                cout << endl << endl;
                Calling_All_Arithmetic_Functions(number1, number2); /// Function Calling Other Functions.
                cout << "\n\n\n";
                system("PAUSE");
                system("CLS");
                break;

            case Definition_Of_Arithmetic_Operations:

                Definitions_of_Arithmetic_Operations_1(); /// Overview of the program.
                cout << endl;
                system("PAUSE");
                system("CLS");
                 break;

            case Quit_The_Program:

                cout << "This program was executed at: " << Hour << ":" << Min << ":" << Sec << endl;
                exit(-1); /// Exits the program.
                break;
        }
    }while(again >= 1 || again <= 7);
    return 0;
}

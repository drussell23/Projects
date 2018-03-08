/**
    Derek J. Russell
    Professor Desmond Chun
    CSCI 15-01 Lab Assignment 3
    Due - February 29th, 2016
    String Processing
    February 24th, 2016
**/
#include <conio.h> /// for getch();
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string.h>
#include <ctime>  /// time_t - time(&CurrentTime); /// This gets the current time.
#include <cctype> /// To convert characters to either uppercase or lowercase
using namespace std;

void CalculateVowels(string &StringInput, int &A, int &E, int &I, int &O, int &U, int &NonVowels)
{
    for(int j = 0; j < StringInput.length(); j++)
    {
        if(tolower(StringInput[j]) == 'a')
        {
            A += 1;
        }
        else if(tolower(StringInput[j]) == 'e')
        {
            E += 1;
        }
        else if(tolower(StringInput[j]) == 'i')
        {
            I += 1;
        }
        else if(tolower(StringInput[j]) == 'o')
        {
            O += 1;
        }
        else if(tolower(StringInput[j]) == 'u')
        {
            U += 1;
        }
        else if(tolower(StringInput[j]) == '\n')
        {
            continue;
        }
        else
        {
            NonVowels += 1;

        }
    }
}
int main()
{
    string StringInput;
    int StringLength, count = 0;
    string str;
    char again = 'y';

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
    while(again == 'y')
    {
        cout << "Name: Derek J. Russell\t\t\t\t" << "\t\t" << "Date: " << Month << "-" << Day << "-" << Year << endl;
        cout << "\n\n";
        cout << setw(66) << "\2 CSCI 15-01 Lab Assignment 3 - String Processing \1" << endl;
        cout << "\n\n";
        cout << "Enter a string of text: ";
        getline(cin, StringInput, '\n');
        cout << endl;

        StringLength = StringInput.length();

        cout << endl;
        cout << "There are " << StringLength << " characters in " << StringInput << endl;
        cout << endl;
        cout << "'" << StringInput << "' has: " << endl;
        cout << "\n\n";

        int A = 0, E = 0, I = 0, O = 0, U = 0, NonVowels = 0;

        CalculateVowels(StringInput, A, E, I, O, U, NonVowels); /// Function Call for calculating vowels.

        cout << A << " -> A's" << endl;
        cout << endl;
        cout << E << " -> E's" << endl;
        cout << endl;
        cout << I << " -> I's" << endl;
        cout << endl;
        cout << O << " -> O's" << endl;
        cout << endl;
        cout << U << " -> U's" << endl;
        cout << endl;
        cout << NonVowels << " Non Vowels" << endl;
        cout << "\n\n";
        cout << "Run this Again (Y or N): ";
        cin >> again;
        cin.ignore(); /// Ignores the buffer
        again = tolower(again);
        system("CLS");
    }

    return 0;
}

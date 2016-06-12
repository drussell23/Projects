/**
    Derek J. Russell
    Professor Desmond Chun
    CSCI 15 Assignment 3
    Due - March 2nd, 2016
    String Processing
    February 28th, 2016
**/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include <conio.h>
#include <cctype>

using namespace std;

void Valid_Customer_ID_Rules();
char * UserInput_CustomerID();
bool Determine_CustomerID_Valid(char Customer_Number_Letters_Numbers[], int size);
bool Testing_Alphabetic_Letters(char Customer_Number_Letters_Numbers[], int size);
bool Testing_Numeric_Digits(char Customer_Number_Letters_Numbers[], int size);
bool SwitchFunctionCall_Position1(char SwitchPosition1, char SwitchPosition2, int SwitchPosition3);
bool SwitchFunctionCall_Position2(char SwitchPosition1, char SwitchPosition2, int SwitchPosition3);
bool SwitchFunctionCall_Position3(char SwitchPosition1, char SwitchPosition2, int SwitchPosition3);
bool SwitchFunctionCall_Position4(char SwitchPosition1, char SwitchPosition2, int SwitchPosition3);

void Valid_Customer_ID_Rules()
{
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

    cout << "Name: Derek J. Russell\t\t\t\t" << "\t\t" << "Date: " << Month << "/" << Day << "/" << Year << endl;
    cout << "\n\n";
    cout << setw(48) << "\t\t\1 CSCI 15 Assignment 3 - String Processing \2" << endl;
    cout << "\n\n";
    cout << setw(23) << "Valid Customer ID Rules:" << endl;
    cout << "\n\n";
    cout << "1. A, K, S - Followed by B, C, D, Followed by 101 to 110." << endl;
    cout << "\n\n";
    cout << "2. B, H, N - Followed by A, F, G, H, Followed by 113 - to 118 or 213." << endl;
    cout << "\n\n";
    cout << "             or 220 or 560 or 890." << endl;
    cout << "\n\n";
    cout << "3. C or T - Followed by K, L, Z, Followed by 134, 138, 145, or 246." << endl;
    cout << "\n\n";
    cout << "4. M, O, Z - Followed by A, D, F, Followed by 177 to 181 or 333 to 335." << endl;
    cout << "\n";
}
char * UserInput_CustomerID()
{
    Valid_Customer_ID_Rules();
    cout << "\n\n";
    const int CustomerID_SIZE = 6; /// Array Size.
    char CustomerID[CustomerID_SIZE]; /// To hold a customer number.
    int Position3;

    /// Get the customer number.
    cout << "Enter a Customer ID: ";
    cin.getline(CustomerID, CustomerID_SIZE);
    cout << endl;
    cout << "Customer ID is " << CustomerID << endl;

    return CustomerID; /// Returns the Customer ID and the Array Size from the UserInput.

}
/// Determine whether its is valid.
bool Determine_CustomerID_Valid(char Customer_Number_Letters_Numbers[], int size)
{
    const int CustomerID_SIZE = 6; /// Array Size.
    char CustomerID[CustomerID_SIZE]; /// To hold a customer number.

    bool TestingAlphabetic = Testing_Alphabetic_Letters(CustomerID, size);
    bool TestingNumeric = Testing_Numeric_Digits(CustomerID, size);

    if(TestingAlphabetic && TestingNumeric)
    {
        return true;
    }
    else
        return false;
}
bool Testing_Alphabetic_Letters(char Customer_Number_Letters_Numbers[], int size)
{
    /// Test the first 2 characters for alphabetic letters.
    for(int count = 0; count < 2; count++)
    {
        if(!isalpha(toupper(Customer_Number_Letters_Numbers[count])))
        {
            return false;
        }
    }
    return true;
}
bool Testing_Numeric_Digits(char Customer_Number_Letters_Numbers[], int size)
{
    /// Test the remaining characters for numeric digits.
    for(int count = 2; count <= size - 1; count++)
    {
        if(!isdigit(Customer_Number_Letters_Numbers[count]))
        {
            return false;
        }
    }
    return true;
}
bool SwitchFunctionCall_Position1(char SwitchPosition1, char SwitchPosition2, int SwitchPosition3)
{
    switch(SwitchPosition1)
    {
        case 'A':
        case 'K':
        case 'S':

            switch(SwitchPosition2)
            {
                case 'B':
                case 'C':
                case 'D':

                    switch (SwitchPosition3)
                    {
                        case 101:
                            break;
                        case 102:
                            break;
                        case 103:
                            break;
                        case 104:
                            break;
                        case 105:
                            break;
                        case 106:
                            break;
                        case 107:
                            break;
                        case 108:
                            break;
                        case 109:
                            break;
                        case 110:
                            break;
                                default:
                                    return false;
                    }
                        break;
                            default:
                                return false;
            }
                    break;
                        default:
                            return false;
    }
}
bool SwitchFunctionCall_Position2(char SwitchPosition1, char SwitchPosition2, int SwitchPosition3)
{
     switch(SwitchPosition1)
    {
        case 'B':
        case 'H':
        case 'N':

            switch(SwitchPosition2)
            {
                case 'A':
                case 'F':
                case 'G':
                case 'H':

                    switch (SwitchPosition3)
                    {
                        case 113:
                            break;
                        case 114:
                            break;
                        case 115:
                            break;
                        case 116:
                            break;
                        case 117:
                            break;
                        case 118:
                            break;
                        case 213:
                            break;
                        case 220:
                            break;
                        case 560:
                            break;
                        case 890:
                            break;
                                default:
                                    return false;
                    }
                        break;
                            default:
                                return false;
            }
                break;
                    default:
                        return false;
    }
}
bool SwitchFunctionCall_Position3(char SwitchPosition1, char SwitchPosition2, int SwitchPosition3)
{
     switch(SwitchPosition1)
    {
        case 'C':
        case 'T':

            switch(SwitchPosition2)
            {
                case 'K':
                case 'L':
                case 'Z':

                    switch (SwitchPosition3)
                    {
                        case 134:
                            break;
                        case 138:
                            break;
                        case 145:
                            break;
                        case 246:
                            break;
                                default:
                                    return false;
                    }
                        break;
                            default:
                                return false;
            }
                break;
                    default:
                        return false;
    }
}
bool SwitchFunctionCall_Position4(char SwitchPosition1, char SwitchPosition2, int SwitchPosition3)
{
     switch(SwitchPosition1)
    {
        case 'M':
        case 'O':
        case 'Z':

            switch(SwitchPosition2)
            {
                case 'A':
                case 'D':
                case 'F':

                    switch (SwitchPosition3)
                    {
                        case 177:
                            break;
                        case 178:
                            break;
                        case 179:
                            break;
                        case 180:
                            break;
                        case 181:
                            break;
                        case 333:
                            break;
                        case 334:
                            break;
                        case 335:
                            break;
                                default:
                                    return false;
                    }
                        break;
                            default:
                                return false;
            }
                break;
                    default:
                         return false;
    }
}

int main()
{
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

    const int CustomerID_SIZE = 6; /// Array Size.

    char CustomerID[CustomerID_SIZE]; /// To hold a customer number.

    char SwitchPosition1;
    char SwitchPosition2;
    char Customer_Number_Letters_Numbers[CustomerID_SIZE];
    char again = 'y';

    int FunctionSwitchCall1;

    int choice;
    int size;

    intmax_t SwitchPosition3;

    while (again == 'y')
    {
            strcpy(CustomerID, UserInput_CustomerID());
            Determine_CustomerID_Valid(Customer_Number_Letters_Numbers, size);

            SwitchPosition1 = toupper(CustomerID[0]);
            SwitchPosition2 = toupper(CustomerID[1]);

            char Numbers[3];

            for(int j = 0; j <= 2; j++)
            {
                Numbers[j] = CustomerID[j + 2];
            }

            SwitchPosition3 = atoi(Numbers);

            if(SwitchPosition1 == 'A' || SwitchPosition1 == 'K' || SwitchPosition1 == 'S')
            {
                choice = 1;
            }
            else if (SwitchPosition1 == 'B' || SwitchPosition1 == 'H' || SwitchPosition1 == 'N')
            {
                choice = 2;
            }
            else if (SwitchPosition1 == 'C' || SwitchPosition1 == 'T')
            {
                choice = 3;
            }
            else if (SwitchPosition1 == 'M' || SwitchPosition1 == 'O' || SwitchPosition1 == 'Z')
            {
                choice = 4;
            }
            else
            {
                choice = 5;
            }

        switch(choice)
        {
            case 1:
                {
                       if (SwitchFunctionCall_Position1(SwitchPosition1, SwitchPosition2, SwitchPosition3) == true)
                       {
                           cout << endl;
                           cout << "Customer ID is Valid :-)" << endl;
                           cout << "\n\n";
                           system("PAUSE");
                           system("CLS");
                       }
                       else
                       {
                           cout << endl;
                           cout << "Customer ID is Invalid :-(" << endl;
                           cout << "\n\n";
                           cout << "(1.) - A, K, S - Followed by B, C, D, Followed by 101 to 110." << endl;
                           cout << "\n\n";
                           system("PAUSE");
                           system("CLS");
                       }

                   break;
                }
            case 2:
                {
                        if (SwitchFunctionCall_Position2(SwitchPosition1, SwitchPosition2, SwitchPosition3) == true)
                        {
                            cout << endl;
                            cout << "Customer ID is Valid :-)" << endl;
                            cout << "\n\n";
                            system("PAUSE");
                            system("CLS");
                        }
                        else
                        {
                            cout << endl;
                            cout << "Customer ID is Invalid :-(" << endl;
                            cout << "\n\n";
                            cout << "(2.) - B, H, N - Followed by A, F, G, H, Followed by 113 - to 118 or 213." << endl;
                            cout << "\n";
                            cout << "       or 220 or 560 or 890." << endl;
                            cout << "\n\n";
                            system("PAUSE");
                            system("CLS");
                        }

                    break;
                }
            case 3:
                {
                    if (SwitchFunctionCall_Position3(SwitchPosition1, SwitchPosition2, SwitchPosition3) == true)
                     {
                         cout << endl;
                         cout << "Customer ID is Valid :-)" << endl;
                         cout << "\n\n";
                         system("PAUSE");
                         system("CLS");
                     }
                     else
                     {
                         cout << endl;
                         cout << "Customer ID is Invalid :-(" << endl;
                         cout << "\n\n";
                         cout << "(3.) - C or T - Followed by K, L, Z, Followed by 134, 138, 145, or 246." << endl;
                         cout << "\n\n";
                         system("PAUSE");
                         system("CLS");
                     }


                     break;
                }
            case 4:
                {
                    if(SwitchFunctionCall_Position4(SwitchPosition1, SwitchPosition2, SwitchPosition3) == true)
                    {
                        cout << endl;
                        cout << "Customer ID is Valid :-)" << endl;
                        cout << "\n\n";
                        system("PAUSE");
                        system("CLS");
                    }
                    else
                    {
                        cout << endl;
                        cout << "Customer ID is Invalid :-(" << endl;
                        cout << "\n\n";
                        cout << "(4.) - M, O, Z - Followed by A, D, F, Followed by 177 to 181 or 333 to 335." << endl;
                        cout << "\n\n";
                        system("PAUSE");
                        system("CLS");
                    }
                    break;

                }
            default:
                    cout << endl;
                    cout << "Customer ID is Invalid :-(" << endl;
                    cout << "\n\n";
                    system("PAUSE");
                    system("CLS");
        }
        cout << endl;
        cout << "Validate Another ID (Y or N): ";
        cin >> again;
        cin.ignore(); /// Ignores the buffer.
        again = tolower(again);
        system("CLS");
    }
    return 0;
}

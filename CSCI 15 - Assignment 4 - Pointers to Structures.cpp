/**
    Derek J. Russell
    Professor Desmond Chun
    CSCI 15 Assignment 4
    Due - March 14th, 2016
    Pointers to Structures
    March 11th, 2016
**/
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

struct Employee_Record
{
    string Employee_LastName;
    string Employee_FirstName;
    float Pay_Rate;
    float Hours_Worked;
    float Tax_Rate;
};
void QUIT()
{
    cout << "Good Bye!" << endl;
    cout << "\n\n";
    system("Pause");
    system("CLS");
    exit(0);
}
int main()
{
    const int Array_Elements = 10;
    int NumberEmployees = 6;
    int input;
    /// For an infinite loop.
    bool again = true;
    int choice;

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

    /// Array of "arrays" - Load that struct array.
    Employee_Record Employee[Array_Elements] = {"De Bosse", "Ian", 45.75, 34.5, 0.05,
                                                "Smithers", "Weylan K.S.", 28.75, 40.1, 0.04,
                                                "Simpson", "Homer J.", 23.44, 40, 0.023,
                                                "Smith", "Janet K.B.", 35.75, 33.9, 0.05,
                                                "Griffin", "Peter R.", 17.88, 25.6, 0.02,
                                                "Jones", "Alias N.", 37.88, 28.9, 0.045};

    /// Set the initial location to the first array element.
    Employee_Record *PointerToArray = &Employee[0];

    /// Setting the correct format. 2 zeros after the decimal point.
    cout.precision(2);
    cout.setf (ios::fixed | ios::showpoint);

    while (again)
    {
        cout << "Name: Derek J. Russell\t\t\t\t" << "\t\t" << "Date: " << Month << "/" << Day << "/" << Year << endl;
        cout << "\n\n";
        cout << setw(49) << "\t\t\1 CSCI 15 Assignment 4 - Pointers to Structures \2" << endl;
        cout << "\n\n";
        cout << "\t(1.) - Display All Employees \1" << endl;
        cout << endl;
        cout << "\t(2.) - Find One Particular Employee \2" << endl;
        cout << endl;
        cout << "\t(3.) - Add a New Employee \1" << endl;
        cout << endl;
        cout << "\t(4.) - Quit \2" << endl;
        cout << endl;
        cout << "Enter your choice from (1 - 4): ";
        cin >> choice;

        choice = abs(choice);

        cout << "\n\n";
        system("PAUSE");
        system("CLS");

            switch (choice)
                {
                    /// Using pointers against the array.
                        case 1:

                             PointerToArray = &Employee[0];
                             cout << endl;
                             cout << "Move through the Array using pointers...." << endl;

                             for(int i = 0; i <= NumberEmployees - 1; i++)
                             {
                                 cout << endl;
                                 cout << "Employee #" << (i + 1) << endl;
                                 cout << endl;
                                 cout << (*PointerToArray).Employee_LastName << ", " << (*PointerToArray).Employee_FirstName << endl;
                                 cout << endl;
                                 cout << "Hours Worked: " << (*PointerToArray).Hours_Worked << endl;
                                 cout << endl;
                                 cout << "Employee Pay Rate: $" << (*PointerToArray).Pay_Rate << endl;
                                 cout << endl;
                                 cout << "Employee Tax Rate: " << (*PointerToArray).Tax_Rate * 100 << "%" << endl;
                                 cout << "\n\n";

                                 *PointerToArray++; /// Increment the pointer variable to the next location.
                             }
                             cout << "\n\n";
                             system("PAUSE");
                             system("CLS");

                        break;

                        case 2:

                                PointerToArray = &Employee[0];
                                input = -1;
                                while (input < 0 || input > NumberEmployees)
                                {
                                    cout << "Enter an Index (0 to " << NumberEmployees - 1 << "): ";
                                    cin >> input;
                                    cout << "\n\n";

                                }

                                for(int count = 0; count < input; count++)
                                {
                                   *PointerToArray++;
                                }

                                cout << "Index Location " << input << " of " << NumberEmployees - 1 << endl;
                                cout << endl;
                                cout << "Employee LAST NAME: " << (*PointerToArray).Employee_LastName << endl;
                                cout << endl;
                                cout << "Employee FIRST NAME: " << (*PointerToArray).Employee_FirstName << endl;
                                cout << endl;
                                cout << "Hours Worked: " << (*PointerToArray).Hours_Worked << endl;
                                cout << endl;
                                cout << "Employee Pay Rate: $" << (*PointerToArray).Pay_Rate << endl;
                                cout << endl;
                                cout << "Employee Tax Rate: " << (*PointerToArray).Tax_Rate * 100 << "%" << endl;
                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                            break;

                        case 3:

                           if(NumberEmployees >= Array_Elements)
                           {
                               cout << "Sorry! The Maximum number of Employees you can enter is up to 10." << endl;
                               cout << endl;
                               system("PAUSE");
                               system("CLS");
                               break;
                           }
                           NumberEmployees++;
                           cout << "Record #" << NumberEmployees << " of " << Array_Elements << endl;
                           cout << endl;

                           cin.ignore();
                           cout << "(1 of 5) - Enter Employee's Last Name: ";
                           getline(cin, Employee[NumberEmployees - 1].Employee_LastName);
                           cout << endl;

                           cout << "(2 of 5) - Enter Employee's First Name: ";
                           getline(cin, Employee[NumberEmployees - 1].Employee_FirstName);
                           cout << endl;

                           cout << "(3 of 5) - Enter the Number of Hours Worked (0 to 40): ";
                           cin >> Employee[NumberEmployees - 1].Hours_Worked;
                           cout << endl;

                           while(Employee[NumberEmployees - 1].Hours_Worked < 0 || Employee[NumberEmployees - 1].Hours_Worked > 40)
                           {
                               cout << "(3 of 5) - Please Enter the Number of Hours Worked (0 to 40): ";
                               cin >> Employee[NumberEmployees - 1].Hours_Worked;
                               cout << endl;
                           }

                           cout << "(4 of 5) - Enter Employee's Pay Per Hour: ";
                           cin >> Employee[NumberEmployees - 1].Pay_Rate;

                           cout << endl;
                           cout << "(5 of 5) - Enter Employee's Income Tax Rate: ";
                           cin >> Employee[NumberEmployees - 1].Tax_Rate;
                           cout << endl;
                           cout << "\n\n";
                           system("PAUSE");
                           system("CLS");

                        break;

                        case 4:

                                QUIT();

                          break;

                        default:

                            cout << "Sorry! Please select an option on the MENU from 1 to 4." << endl;
                            cout << "\n\n";
                            system("PAUSE");
                            system("CLS");
                }
    }
    return 0;
}

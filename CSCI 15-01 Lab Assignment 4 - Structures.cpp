/**
    Derek J. Russell
    Professor Desmond Chun
    CSCI 15-01 Lab Assignment 4
    Due - March 9th, 2016
    Structures
    March 2nd, 2016
**/
#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <conio.h>

using namespace std;

struct Employee_Records
{
   string EmployeeID;
   string Last_Name;
   string Frist_Name;
   float Hours;
   float Pay_Rate_Per_Hour;
   float Gross_Pay;
};
void DescriptionOfTheProgram()
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
    cout << setw(49) << "\t\t\1 CSCI 15-01 Lab Assignment 4 - Structures \2" << endl;
    cout << "\n\n";
    cout << "\4 -  A structure (struct) allows us to store a record that comprises multiple" << endl;
    cout << endl;
    cout << "     that may be a different data type (i.e. several strings, some integers" << endl;
    cout << endl;
    cout << "     and floats). A structure can be stored in an array to allow easier" << endl;
    cout << endl;
    cout << "     access to any of the records's fields." << endl;
    cout << "\n\n";
    cout << "1. The struct consists of an employee record's fields:" << endl;
    cout << endl;
    cout << "\ta. Employee ID (string)" << endl;
    cout << "\tb. Last Name (string)" << endl;
    cout << "\tc. First Name (string)" << endl;
    cout << "\td. Hours (float)" << endl;
    cout << "\te. Pay Rate Per Hour (float)" << endl;
    cout << "\tf. Gross Pay (float)" << endl;
    cout << endl;
    cout << "2. Allow the user to manually enter the number of records to be entered." << endl;
    cout << endl;
    cout << "   Store the structure into an array with a maximum of 20 employees." << endl;
    cout << "\n\n";
    cout << "3. User manually enters:" << endl;
    cout << endl;
    cout << "\ta. Employee ID" << endl;
    cout << "\tb. Last Name" << endl;
    cout << "\tc. First Name" << endl;
    cout << "\td. Hours" << endl;
    cout << "\te. Pay Rate Per Hour" << endl;
    cout << "\n\n";
    cout << "4. Gross Pay will be calculated from the Hours and Pay Rate" << endl;
    cout << endl;
    cout << "   (i.e. Hours * Pay Rate)." << endl;
    cout << "\n\n";
    cout << "5. Display the (structure) struct records fields and the Gross pay calculation." << endl;
    cout << "\n\n\n";
    system("PAUSE");
    system("CLS");
}
void Display_Title()
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
    cout << setw(49) << "\t\t\1 CSCI 15-01 Lab Assignment 4 - Structures \2" << endl;
    cout << "\n\n";
}
int main()
{
   DescriptionOfTheProgram();
   Display_Title();

   const int max = 20;
   Employee_Records Employee[max];

   int Number;

   char again = 'y';

   cout.precision(2);
   cout.setf(ios::fixed | ios::showpoint);

   while (again == 'y')
   {
       cout << "\nEnter the Number of Employees to Enter: ";
       cin >> Number;

       Number = abs(Number);

       if(Number > max)
       {
           Number = max;
       }
               for(int j = 0; j <= Number - 1; j++)
               {
                   cout << "\n\n";
                   cin.ignore(80, '\n');
                   cout << "Employee # " << (j + 1) << " of " << Number << endl;
                   cout << endl;
                   cout << "1 of 5 - Enter Employee ID: ";
                   getline(cin, Employee[j].EmployeeID);
                   cout << endl;
                   cout << "2 of 5 - Enter Employee LAST NAME: ";
                   getline(cin, Employee[j].Last_Name);
                   cout << endl;
                   cout << "3 of 5 - Enter Employee FIRST NAME: ";
                   getline(cin, Employee[j].Frist_Name);
                   cout << endl;

                   cout << "4 of 5 - Enter Hours Worked: ";
                   cin >> Employee[j].Hours;

                        if(Employee[j].Hours < 0)
                        {
                            Employee[j].Hours = Employee[j].Hours * -1;
                        }

                   cout << endl;
                   cout << "5 of 5 - Enter Pay Rate: ";
                   cin >> Employee[j].Pay_Rate_Per_Hour;

                       if(Employee[j].Pay_Rate_Per_Hour < 0)
                       {
                           Employee[j].Pay_Rate_Per_Hour = Employee[j].Pay_Rate_Per_Hour * -1;
                       }
                       Employee[j].Gross_Pay = Employee[j].Pay_Rate_Per_Hour * Employee[j].Hours;
               }
               cout << "\n\n";
               /// Display Contents of the Array.
               cout << "\4 Displaying Records Fields & Gross Pay Calculation" << endl;
               cout << endl;
               for(int i = 0; i <= Number - 1; i++)
               {
                   cout << "Employee #" << (i + 1) << " of " << Number;
                   cout << "\n\n";
                   cout << "Employee LAST NAME: " << Employee[i].Last_Name << endl;
                   cout << endl;
                   cout << "Employee FIRST NAME: " << Employee[i].Frist_Name << endl;
                   cout << endl;
                   cout << "Hours Worked: " << Employee[i].Hours << endl;
                   cout << endl;
                   cout << "Employee Pay Rate: $" << Employee[i].Pay_Rate_Per_Hour << endl;
                   cout << endl;
                   cout << "Employee Gross Pay: $" << Employee[i].Gross_Pay << endl;
                   cout << "\n\n";
               }
        cout << endl;
        cout << "Do You Want Run This Again? (Y or N): ";
        cin >> again;
        cin.ignore(); /// Ignores the buffer.
        again = tolower(again);
        system("CLS");
   }
    return 0;
}

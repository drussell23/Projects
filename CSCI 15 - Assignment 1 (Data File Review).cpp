/**
    Derek J. Russell
    Professor Desmond Chun
    CSCI 15 Assignment 1
    Due - February 10th, 2016
    Data File Review
    February 6th, 2016
**/
#include <iostream> /// Console Input & Output
#include <cstdlib> /// System("CLS"); System("PAUSE");
#include <iomanip>  /// cout.precision(2); cout.setf(ios::fixed);
#include <fstream>  /// Data Files.
#include <ctime> /// time_t - time(&CurrentTime); /// This gets the current time.
#include <conio.h> /// getch();

using namespace std;

/// (Calculation) Function Prototypes
float GrossPay_Calculation(float Hours_Worked, float Hourly_Pay_Rate, float Overtime_Hours, float Overtime_Pay);
float StateTotal_Calculation(float Gross_Pay, float State_Tax_Rate);
float FederalTotal_Calculation(float Gross_Pay, float Federal_Tax_Rate);

/// (Void) Function Prototypes
void ADD_NEW_RECORDS();
void DISPLAY_RECORDS();
void QUIT();

void ADD_NEW_RECORDS()
{
     char Employee_ID[10],
          Employee_Last_Name[30],
          Employee_First_Name[30];

    float Hours_Worked,
          Hourly_Pay_Rate,
          Federal_Tax_Rate,
          State_Tax_Rate,
          Gross_Pay,
          Net_Pay;

    float Federal_Tax_Rate_MAX = 0.40;
    float State_Tax_Rate_MAX = 0.10;

    int choice, count = 1;

        /// Writing to the file
        ofstream outFile("DataFileReview.dat", ios::out | ios::app);
       /// fstream outFile("DataFileReview.dat", ios::out | ios::app);
        system("CLS");
        cout << "\t\t(1.) \5 Write new Records to the Data File" << endl;
        cout << endl;
        cout << "1 of 7 - Enter Employee Worker ID Code (i.e. AF123): ";
        cin >> Employee_ID;
        cout << endl;

        cout << "2 of 7 - Enter Employee LAST Name: ";
        cin >> Employee_Last_Name;
        cout << endl;

        cout << "3 of 7 - Enter Employee FIRST Name: ";
        cin >> Employee_First_Name;
        cout << endl;

        cout << "4 of 7 - Enter the Hours Worked: ";
        cin >> Hours_Worked;
        cout << endl;

        /// Ranging from 0 to a maximum of 40 hours.
        while(Hours_Worked < 0 || Hours_Worked > 40)
        {
            cout << "Enter the Hours Worked that's ranging from 0 to a maximum of 40 hours." << endl;
            cout << endl;
            cout << "4 of 7 - Enter the Hours Worked: ";
            cin >> Hours_Worked;
            cout << endl;
        }

            cout << "5 of 7 - Enter the Hourly Pay Rate: ";
            cin >> Hourly_Pay_Rate;
            cout << endl;

            /// Ranging from a minimum rate of $10/Hour to a maximum of $100/Hour.
            while(Hourly_Pay_Rate < 10 || Hourly_Pay_Rate > 100)
            {
                cout << "Enter the Hourly Pay Rate that's ranging from 10 to a maximum of 100 hours." << endl;
                cout << endl;
                cout << "5 of 7 - Enter the Hourly Pay Rate: ";
                cin >> Hourly_Pay_Rate;
                cout << endl;
            }

            cout << "6 of 7 - Enter the Federal Tax Rate: ";
            cin >> Federal_Tax_Rate;
            cout << endl;

            /// Ranging from zero to a maximum of 40%.
            while(Federal_Tax_Rate < 0 || Federal_Tax_Rate > Federal_Tax_Rate_MAX)
            {
                cout << "Enter the Federal Tax Rate that's ranging from 0 to a maximum of 40%." << endl;
                cout << endl;
                cout << "6 of 7 - Enter the Federal Tax Rate: ";
                cin >> Federal_Tax_Rate;
                cout << endl;
            }

            cout << "7 of 7 - Enter State Tax Rate: ";
            cin >> State_Tax_Rate;
            cout << endl;

            /// Ranging from zero to a maximum of 10%.
            while(State_Tax_Rate < 0 || State_Tax_Rate > State_Tax_Rate_MAX)
            {
                cout << "Enter the State Tax Rate that's ranging from 0 to a maximum of 10%." << endl;
                cout << endl;
                cout << "7 of 7 - Enter State Tax Rate: ";
                cin >> State_Tax_Rate;
                cout << endl;
            }
            cout << "\n\n\n";
            system("PAUSE");
            system("CLS");
            /// Writing the variables' values to the data file.
                outFile << Employee_ID << " " << Employee_Last_Name << " " << Employee_First_Name
                        << " " << Hours_Worked << " " << Hourly_Pay_Rate << " " << Federal_Tax_Rate
                        << " " << State_Tax_Rate << endl;

            /// Close the file stream.
            outFile.close();
    return;
}
void DISPLAY_RECORDS()
{
    char Employee_ID[10],
         Employee_Last_Name[30],
         Employee_First_Name[30];

    float Hours_Worked,
          Hourly_Pay_Rate,
          Federal_Tax_Rate,
          State_Tax_Rate,
          Gross_Pay,
          Net_Pay;

    float Overtime_Hours = 0;
    float Overtime_Pay = 0;

    double StateTotal, FederalTotal;

    int choice, count = 1;

     /// Read from the file
    /// C++ wants you to declare the read stream as a "local" (quirk in the compiler)
    ifstream inFile("DataFileReview.dat", ios::in);

        system("CLS");
        cout << "\t\t(2.) \5 Display Records From the Data file to the Screen" << endl;
        /// cout << endl;
        /// cout << "Reading from the data file\n";

        if(!inFile)
        {
            cout << "\nSorry, the data file \"DataFileReview.dat\" was not found on this drive";
            cout << "\n\n\n";
            system("PAUSE");
            getch();
            system("CLS");
            return;
        }
            /// Read the first record(we can reuse the variables).
            inFile >> Employee_ID >> Employee_Last_Name >> Employee_First_Name
                   >> Hours_Worked >> Hourly_Pay_Rate >> Federal_Tax_Rate >> State_Tax_Rate;

        /// Loop through the data file and display the fields of each record to the CRT.
        /// Read a file until you've reached the end.
        while(!inFile.eof())
        {
           /// Compute Calculations
           Gross_Pay = GrossPay_Calculation(Hours_Worked, Hourly_Pay_Rate, Overtime_Hours, Overtime_Pay);
           /// Calculates the Gross Pay.
           StateTotal = StateTotal_Calculation(Gross_Pay, State_Tax_Rate);
           /// Calculates the State Total.
           FederalTotal = FederalTotal_Calculation(Gross_Pay, Federal_Tax_Rate);
           /// Calculates the Federal Total.
           Net_Pay = Gross_Pay - (StateTotal + FederalTotal);
           /// NetPay = Gross_Pay - (StateTotal + FederalTotal);

            cout << "\nRecord #" << count << endl;
            cout << endl;
            cout << "Employee ID: " << Employee_ID << endl;
            cout << endl;
            cout << "Last Name: " << Employee_Last_Name << "\t" << "First Name: " << Employee_First_Name << endl;
            cout << "================================================================================" << endl;
            cout << endl;
            cout << "Hours Worked: " << Hours_Worked << "\t" << "Pay Per Hour: $"
                 << Hourly_Pay_Rate << "\t" << "Gross Pay: $" << Gross_Pay << endl;
            cout << "================================================================================" << endl;
            cout << endl;
            cout << "Federal Taxes: $" << FederalTotal << "\t" << "State Taxes $"
                 << StateTotal << "\t" << "Net Pay: $" << Net_Pay << endl;
            cout << "================================================================================" << endl;
            cout << endl;
            cout << "Employee Federal Tax Rate: " << Federal_Tax_Rate * 100 << "%" << "\t";
            cout << "Employee State Tax Rate: " << State_Tax_Rate * 100 << "%" << endl;
            cout << "================================================================================" << endl;

            count++;

            cout << "\n\n";
              inFile >> Employee_ID >> Employee_Last_Name >> Employee_First_Name
                   >> Hours_Worked >> Hourly_Pay_Rate >> Federal_Tax_Rate >> State_Tax_Rate;

            system("PAUSE");
            system("CLS");
        }
            cout << endl;
            cout << "MAXIMUM RECORDS STORED IN THE DATA FILE STORAGE: " << endl;
            cout << endl;
            cout << "\t\5 There are " << count - 1 << " RECORD(s) stored in the Data File." << endl;
            cout << "\n\n\n";
            system("PAUSE");
            system("CLS");
            getch();

        /// Close the file stream.
        inFile.close();
        /// Reset the counter to for the Record FILES.
        count = 1;
    return;
}
void QUIT()
{
    system("CLS");
    cout << "Program Shutting Down..." << endl;
    cout << "\n\n";
    cout << "\t\t\t\t\1 GOODBYE!!! \2" << endl;
    cout << "\n\n\n";
    exit(0); /// Exits the Program.
}
float GrossPay_Calculation(float Hours_Worked, float Hourly_Pay_Rate, float Overtime_Hours, float Overtime_Pay)
{
    return (Hours_Worked * Hourly_Pay_Rate) + (Overtime_Hours * Overtime_Pay); /// Hourly_Pay_Rate is Pay Per Hour.
}
float StateTotal_Calculation(float Gross_Pay, float State_Tax_Rate)
{
    return Gross_Pay * State_Tax_Rate;
}
float FederalTotal_Calculation(float Gross_Pay, float Federal_Tax_Rate)
{
    return Gross_Pay * Federal_Tax_Rate;
}
int main()
{
    char Employee_ID[10],
         Employee_Last_Name[30],
         Employee_First_Name[30];

    float Hours_Worked,
          Hourly_Pay_Rate,
          Federal_Tax_Rate,
          State_Tax_Rate,
          Gross_Pay,
          Net_Pay;

    int choice, count = 1;

    bool again = true;

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

    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);

    while(again)
    {
        cout << "Name: Derek J. Russell\t\t\t\t" << "\t\t" << "Date: " << Month << "-" << Day << "-" << Year << endl;
        cout << "\n\n";
        cout << setw(51) << "\t\t\2 CSCI 15 Assignment 1 - Data File Review \1" << endl;
        cout << endl << endl;
        /// Use an "endless loop" for the application, the only way out is the "Quit Case
        cout << "\t(1.) \5 Write new Records to Data File" << endl;
        cout << endl;
        cout << "\t(2.) \5 Display Records From the Data file to the Screen" << endl;
        cout << endl;
        cout << "\t(3.) \5 QUIT" << endl;
        cout << "\n\n";
        cout << "Enter 1, 2 or 3: ";
        cin >> choice;

        while((choice <= 0) || (choice > 3))
        {
            system("CLS");
                    cout << "You entered an invalid number: " << choice << endl;
                    cout << endl;
                    cout << "Please Enter a choice from 1 - 3: ";
                    cin >> choice;
        }

        switch(choice)
        {
            case 1:
                {
                   ADD_NEW_RECORDS(); /// Write new Records to the Data File.
                        break;
                }
            case 2:
                {
                   DISPLAY_RECORDS(); /// Display Records From the Data file to the Screen.
                        break;
                }
            case 3:
                {
                  QUIT(); /// This Function Exits out of the Program.
                  break;
                }
        }
    }
    system("CLS");
    return 0;
}

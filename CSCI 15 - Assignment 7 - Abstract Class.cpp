/**
    Derek J. Russell
    Professor Desmond Chun
    CSCI 15 - Assignment 7
    Due: April 27th, 2016
    Abstract Classes
    April 15th, 2016
**/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <time.h>
#include <cstring>
#include <string>
#include <memory>
#include <cmath>
#include <math.h>
using namespace std;

class Employee
{
    protected:
               string Employee_ID;
               float Hours;
               float PayPer_Hour;
               float Income_Tax_Rate;
               float Over_Time_Hours;
               string Employee_Status;

    public:
            void SetID(string ID)
            {
                Employee_ID = ID;
            }
            void SetHours(float H)
            {
                Hours = H;
            }
            void SetPay(float PayRate)
            {
                PayPer_Hour = PayRate;
            }
            void SetTaxRate(float Tax_Rate)
            {
                Income_Tax_Rate = Tax_Rate;
            }
            void SetStatus(string Emp_Status)
            {
                Employee_Status = Emp_Status;
            }
            // Inline Functions.
            string getID() const
            {
                return Employee_ID; // RETTURN EMPLOYEE ID.
            }
            float getHours() const
            {
                return Hours; // RETURN HOURS.
            }
            float getPay() const
            {
                return PayPer_Hour; // RETURN PAY PER HOUR.
            }
            string getStatus() const
            {
                return Employee_Status; // RETURN STATUS.
            }
            Employee() // Set the numeric member values to zero and the string values to "N/A".
            {
                Employee_ID = "N/A";
                Hours = 0.0;
                PayPer_Hour = 0.0;
                Income_Tax_Rate = 0.0;
                Over_Time_Hours = 0.0;
                Employee_Status = "N/A";
            }
            virtual double CalculatePay() = 0; // Virtual abstract function calculate pay.

};
class Hourly : public Employee // Hourly Class which its version of calculate pay.
{
  public:

    double CalculatePay()
    {
        double RegularPay;
        double OvertimePay;
        double GrossPay;
        double Taxes;
        double NetPay;

        Overtime(); // Function Call.

        RegularPay = Hours * PayPer_Hour;
        OvertimePay = Hours * PayPer_Hour * 1.5;
        GrossPay = RegularPay + OvertimePay;
        Taxes = GrossPay * Income_Tax_Rate;
        NetPay = GrossPay - Taxes;

        cout << "Regular Hours " << Hours << endl;
        cout << endl;

        if (Over_Time_Hours != 0)
        {
            cout << "Overtime Hours: " << Over_Time_Hours << endl;
            cout << endl;
        }

        cout << "Display Regular Pay: $" << RegularPay << endl;
        cout << endl;

        if (OvertimePay != 0)
        {
            cout << "Overtime Pay: $" << OvertimePay << endl;
            cout << endl;
        }

        cout << "Gross Pay: $" << GrossPay << endl;
        cout << endl;
        cout << "Taxes Withheld: $" << Taxes << endl;
        cout << endl;
        cout << "Net Pay: $" << NetPay << endl;
        cout << endl;
        cout << "Employee Status: " << Employee_Status << endl;
    }
    void Overtime() // Determines Regular Hours, and any Overtime Hours based on what the Hours were.
    {
        if(Hours <= 40)
        {
            Over_Time_Hours = 0.0;
        }
        else
        {
            Over_Time_Hours = Hours - 40;
            Hours = 40;
        }
        return;
    }
};
class Salaried : public Employee
{
  public:
    double CalculatePay()
    {
        double GrossPay;
        double Taxes_Withheld;
        double NetPay;

        GrossPay = PayPer_Hour;
        Taxes_Withheld = GrossPay * Income_Tax_Rate;
        NetPay = GrossPay - Taxes_Withheld;

        cout << "Gross Pay: $" << GrossPay << endl;
        cout << endl;
        cout << "Taxes: " << Income_Tax_Rate * 100 << "%" <<  endl;
        cout << endl;
        cout << "Net Pay: $" << NetPay << endl;
    }
};
class Contractor : public Employee
{
  public:
    double CalculatePay()
    {
        double GrossPay;

        GrossPay = PayPer_Hour;

        cout << "Contractor Fee for the Contractor: " << PayPer_Hour << endl;
    }
};
// Function Prototypes.
void DisplayTitle();

void DisplayTitle()
{
    time_t CurrentTime;
    struct tm *localTime;

    time(&CurrentTime); // This gets the current time.
    localTime = localtime(&CurrentTime); // This converts the time to local time.

    intmax_t Day   = localTime -> tm_mday;
    intmax_t Month = localTime -> tm_mon + 1;
    intmax_t Year  = localTime -> tm_year + 1900;
    intmax_t Hour  = localTime -> tm_hour;
    intmax_t Min   = localTime -> tm_min;
    intmax_t Sec   = localTime -> tm_sec;

    cout << "Name: Derek J. Russell\t\t\t\t\t\t" << "Date: " << Month << "/" << Day << "/" << Year << endl;
    cout << "\n\n";
    cout << setw(55) << "\t\1 CSCI 15 Assignment 7 - Abstract Class \2" << endl;
    cout << "\n\n";
    cout << "Clock -> " << Hour << ":" << Min << ":" << Sec << endl;
}
int main()
{
    bool again = true;
    intmax_t choice;
    const intmax_t max = 3;

    Hourly hour1, hour2, hour3;
    Salaried salary1, salary2, salary3;
    Contractor contract1, contract2, contract3;

    Hourly hours[max] = {hour1, hour2, hour3};
    Salaried salary[max] = {salary1, salary2, salary3};
    Contractor contract[max] = {contract1, contract2, contract3};

    string EMP_id;
    double total_hours_worked;
    double pay_rate;
    double income_tax_rate;
    string EMP_status;

    int count = 0;
    int SalaryCount = 0;
    int ContractorCount = 0;

    int Input_INDEX = -1;

   cout.precision(2);
   cout.setf(ios::fixed | ios::showpoint);

    while (again)
    {
        DisplayTitle();
        cout << "\n\n";
        cout << "(1.) - Enter Data for the Hourly" << endl;
        cout << endl;
        cout << "(2.) - Enter Data for the Salaried" << endl;
        cout << endl;
        cout << "(3.) - Enter data for Contractor" << endl;
        cout << endl;
        cout << "(4.) - Display the ID, Pay, Horus Tax, Net if any for Hourly" << endl;
        cout << endl;
        cout << "(5.) - Display the ID, Annual Salary, Tax, Net for the Salaried" << endl;
        cout << endl;
        cout << "(6.) - Display the ID, Contractor Fee for the Contractor" << endl;
        cout << endl;
        cout << "(7.) - Quit" << endl;
        cout << "\n\n";
        cout << "Enter your choice from (1 to 7): ";
        cin >> choice;

        choice = abs(choice);

        cout << "\n\n";
        system("PAUSE");
        system("CLS");

                    switch(choice)
                    {
                        case 1:
                                cout << "(1.) - Enter Data for the Hourly" << endl;
                                cout << "\n\n";
                                if(count >= 3)
                                {
                                    cout << "Sorry! The Maximum number of Hourly you can enter is up to 3." << endl;
                                    cout << "\n\n";
                                    system("PAUSE");
                                    system("CLS");
                                    break;
                                }

                                cin.ignore();

                                cout << "(1 of 5) - Enter Employee ID: ";
                                getline(cin, EMP_id);
                                cout << endl;

                                cout << "(2 of 5) - Enter the Total Hours Worked: ";
                                cin >> total_hours_worked;
                                cout << endl;

                                while (total_hours_worked < 0.0)
                                {
                                    cout << "(2 of 5) - Enter the Total Hours Worked: ";
                                    cin >> total_hours_worked;
                                    cout << endl;
                                }

                                cout << "(3 of 5) - Enter the Pay Rate: ";
                                cin >> pay_rate;
                                cout << endl;

                                while (pay_rate < 0.0)
                                {
                                    cout << "(3 of 5) - Enter the Pay Rate: ";
                                    cin >> pay_rate;
                                    cout << endl;
                                }

                                cout << "(4 of 5) - Enter Income Tax Rate: ";
                                cin >> income_tax_rate;
                                cout << endl;

                                while (income_tax_rate < 0.0)
                                {
                                    cout << "(4 of 5) - Enter Income Tax Rate: ";
                                    cin >> income_tax_rate;
                                    cout << endl;
                                }

                                cin.ignore();

                                cout << "(5 of 5) - Enter Employee Status: ";
                                getline(cin, EMP_status);
                                cout << endl;

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                hours[count].SetID(EMP_id);
                                hours[count].SetHours(total_hours_worked);
                                hours[count].SetPay(pay_rate);
                                hours[count].SetTaxRate(income_tax_rate);
                                hours[count].SetStatus(EMP_status);

                                // Move to next point in array, make an if statement to make sure Salary count does not exceed array.
                                count++;

                                break;

                        case 2:
                                cout << "(2.) - Enter Data for the Salaried" << endl;
                                cout << "\n\n";
                                if(SalaryCount >= 3)
                                {
                                    cout << "Sorry! The Maximum number of Salaried you can enter is up to 3." << endl;
                                    cout << "\n\n";
                                    system("PAUSE");
                                    system("CLS");
                                    break;
                                }

                                cin.ignore();

                                cout << "(1 of 3) - Enter the Employee ID: ";
                                getline(cin, EMP_id);
                                cout << endl;

                                cout << "(2 of 3) - Enter the Annual Salary: ";
                                cin >> pay_rate;
                                cout << endl;

                                while (pay_rate < 0.0)
                                {
                                    cout << "(2 of 3) - Enter the Annual Salary: ";
                                    cin >> pay_rate;
                                    cout << endl;
                                }

                                cout << "(3 of 3) - Enter the Income Tax Rate: ";
                                cin >> income_tax_rate;
                                cout << endl;

                                while (income_tax_rate < 0.0)
                                {
                                    cout << "(3 of 3) - Enter the Income Tax Rate: ";
                                    cin >> income_tax_rate;
                                    cout << endl;
                                }

                                /**
                                    Setting Class Member Values into Array.
                                    If statement under here if Salary count is > 2(3 items in array), do not set into array.
                                 **/

                                salary[SalaryCount].SetID(EMP_id);
                                salary[SalaryCount].SetPay(pay_rate);
                                salary[SalaryCount].SetTaxRate(income_tax_rate);

                                // Move to next point in array, make an if statement to make sure Salary count does not exceed array.
                                SalaryCount++;

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                break;

                        case 3:
                                cout << "(3.) - Enter data for Contractor" << endl;
                                cout << "\n\n";
                                if(ContractorCount >= 3)
                                {
                                    cout << "Sorry! The Maximum number of Contractor(s) you can enter is up to 3." << endl;
                                    cout << "\n\n";
                                    system("PAUSE");
                                    system("CLS");
                                    break;
                                }

                                cin.ignore();

                                cout << "(1 of 2) - Enter the Employee ID: ";
                                getline(cin, EMP_id);
                                cout << endl;

                                cout << "(2 of 2) - Enter the Contractor Fee: ";
                                cin >> pay_rate;
                                cout << endl;

                                while (pay_rate < 0.0)
                                {
                                    cout << "(2 of 2) - Enter the Contractor Fee: ";
                                    cin >> pay_rate;
                                    cout << endl;
                                }

                                contract[ContractorCount].SetID(EMP_id);
                                contract[ContractorCount].SetPay(pay_rate);

                                // Move to next point in array, make an if statement to make sure Salary count does not exceed array.
                                ContractorCount++;

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                break;

                        case 4:
                                cout << "(4.) - Display the ID, Pay, Horus Tax, Net if any for Hourly" << endl;
                                cout << "\n\n";
                                cout << "Enter an Index (0 to " << count - 1 << "): ";
                                cin >> Input_INDEX;
                                cout << endl;

                                while (Input_INDEX < 0 || Input_INDEX > count - 1)
                                {
                                    cout << "Enter an Index (0 to " << count - 1 << "): ";
                                    cin >> Input_INDEX;
                                    cout << "\n\n";
                                }

                                cout << "Employee ID: " << hours[Input_INDEX].getID() << endl;
                                cout << endl;
                                hours[Input_INDEX].CalculatePay();

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                break;

                        case 5:
                                cout << "(5.) - Display the ID, Annual Salary, Tax, Net for the Salaried" << endl;
                                cout << "\n\n";
                                cout << "Enter an Index (0 to " << SalaryCount - 1 << "): ";
                                cin >> Input_INDEX;
                                cout << endl;

                                while (Input_INDEX < 0 || Input_INDEX > SalaryCount - 1)
                                {
                                    cout << "Enter an Index (0 to " << SalaryCount - 1 << "): ";
                                    cin >> Input_INDEX;
                                    cout << "\n\n";
                                }

                                cout << "Employee ID: " << salary[Input_INDEX].getID() << endl;
                                cout << endl;
                                salary[Input_INDEX].CalculatePay();

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                break;

                        case 6:
                                cout << "(6.) - Display the ID, Contractor Fee for the Contractor" << endl;
                                cout << "\n\n";
                                cout << "Enter an Index (0 to " << ContractorCount - 1 << "): ";
                                cin >> Input_INDEX;
                                cout << endl;

                                while (Input_INDEX < 0 || Input_INDEX > ContractorCount - 1)
                                {
                                    cout << "Enter an Index (0 to " << ContractorCount - 1 << "): ";
                                    cin >> Input_INDEX;
                                    cout << "\n\n";
                                }

                                cout << "Employee ID: " << contract[Input_INDEX].getID() << endl;
                                cout << endl;
                                contract[Input_INDEX].CalculatePay();

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                break;

                        case 7:
                                cout << "(7.) - Quit" << endl;
                                cout << "\n\n";
                                cout << "\1 Good Bye!!! \2" << endl;
                                again = false;

                                break;

                        default:
                                 cout << "Sorry! Please select an option on the MENU from (1 to 7)." << endl;
                                 cout << "\n\n";
                                 system("PAUSE");
                                 system("CLS");

                    }
    }

    return 0;
}

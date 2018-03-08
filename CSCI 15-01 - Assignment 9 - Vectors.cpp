#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Employee_Record
{
    string EmployeeID;
    string Last_Name;
    string First_Name;
    float Hours;
    float PayRate;
    float Income_Tax_Rate;
    intmax_t NumberDependents;
};

int main()
{
    bool again = true;
    intmax_t option, location = 0, index;
    const intmax_t Array_Elements = 10;
    intmax_t store, CHANGE_FIELD_RECORDS;

    string change_EmployeeID, change_LastName, change_FirstName;
    float change_Hours, change_PayRate, change_IncomeTaxRate;
    intmax_t change_NumberDependents;

    int empid_vector ;

    // We can use a vector to store a Struct.
    vector<Employee_Record> employee_vector;

    Employee_Record temp, temp3;

    fstream File;

    File.open("personnel.dat", ios::in | ios::out | ios::binary);

    if(!File)
    {

        cout << "\nSorry, the data file \"personnel.dat\" was not found on this drive";
        cout << "\n\n\n";
        system("PAUSE");
        system("CLS");

        return -1;
    }

    int count = 0;

    while(!File.eof())
    {
          File >> temp.EmployeeID
               >> temp.Last_Name
               >> temp.First_Name
               >> temp.Hours
               >> temp.PayRate
               >> temp.Income_Tax_Rate
               >> temp.NumberDependents;

        employee_vector.push_back(temp);

    }

    File.close();

    cout.precision(2);
    cout.setf (ios::fixed | ios::showpoint);

    while(again)
    {
        cout << "(1.) - Find a Record based in Employee ID" << endl;
        cout << endl;
        cout << "(2.) - Sort the Records based on Last Name" << endl;
        cout << endl;
        cout << "(3.) - Delete a record based on Employee ID" << endl;
        cout << endl;
        cout << "(4.) - Change one or more fields in a Record" << endl;
        cout << endl;
        cout << "(5.) - Add a new Record to the vector" << endl;
        cout << endl;
        cout << "(6.) - Quit" << endl;
        cout << "\n\n";
        cout << "Enter an option (1 - 6): ";
        cin >> option;

        option = abs(option);

        cout << "\n\n\n";
        system("PAUSE");
        system("CLS");

        int finding;
        bool find = 0;
                switch(option)
                {
                    case 1:
                            finding = 0;

                            cout << "Enter the Employee ID you want to find: ";
                            cin.ignore(80,'\n');
                            getline(cin, temp.EmployeeID);
                            cout << endl;

                            while(finding < employee_vector.size())
                            {
                                if(temp.EmployeeID == employee_vector[finding].EmployeeID)
                                {
                                    find = 1;
                                    cout << "Employee ID: " << employee_vector[finding].EmployeeID << " is Found in the Vector!" << endl;
                                    cout << "\n\n";
                                    cout << "Employee ID: " <<employee_vector[finding].EmployeeID << endl;
                                    cout << endl;
                                    cout << "Last Name: " <<employee_vector[finding].Last_Name << endl;
                                    cout << endl;
                                    cout << "First Name: " << employee_vector[finding].First_Name << endl;
                                    cout << endl;
                                    cout << "Hours: " << employee_vector[finding].Hours << endl;
                                    cout << endl;
                                    cout << "Pay Rate: " << employee_vector[finding].PayRate << endl;
                                    cout << endl;
                                    cout << "Income Tax Rate: " << employee_vector[finding].Income_Tax_Rate << endl;
                                    cout << endl;
                                    cout << "Number Dependents: " << employee_vector[finding].NumberDependents << endl;

                                    cout << "\n\n\n";
                                    system("PAUSE");
                                    system("CLS");

                                    break;
                                }
                                finding++;
                            }
                            if(find == false)
                            {
                                cout << temp.EmployeeID << " is not Found in the Vector!" << endl;
                                cout << "\n\n\n";
                                system("PAUSE");
                                system("CLS");

                                break;
                            }

                            break;

                    case 2:
                            cout << "The Records has officially been sorted by Last Name." << endl;
                            empid_vector = employee_vector.size();

                            for(intmax_t count = 1; count <= empid_vector - 1; count++)
                            {
                                for(intmax_t j = 0; j <= empid_vector - 2; j++)
                                {
                                    if(employee_vector[j].Last_Name > employee_vector[j + 1].Last_Name)
                                    {
                                        temp3 = employee_vector[j];
                                        employee_vector[j] = employee_vector[j + 1];
                                        employee_vector[j + 1] = temp3;
                                    }
                                }
                            }

                            cout << "\n\n\n";
                            system("PAUSE");
                            system("CLS");

                            break;

                    case 3: // Delete a Record Based on Employee ID.
                            finding = 0;

                            cout << "Enter the Employee ID you want to find: ";
                            cin.ignore(80,'\n');
                            getline(cin, temp.EmployeeID);
                            cout << endl;

                            while(finding < employee_vector.size())
                            {
                                if(temp.EmployeeID == employee_vector[finding].EmployeeID)
                                {
                                    cout << employee_vector[finding].EmployeeID << " is Found in the Vector!" << endl;
                                    cout << "\n\n\n";
                                    system("PAUSE");
                                    system("CLS");

                                    employee_vector.erase(employee_vector.begin() + finding);
                                    employee_vector.erase(employee_vector.end() + finding);

                                    cout << "Employee ID: " << temp.EmployeeID << " has been deleted!" << endl;
                                    cout << endl;

                                    break;
                                }
                                finding++;
                            }
                            if(find == false)
                            {
                                cout << temp.EmployeeID << " is not Found in the Vector!" << endl;
                                cout << "\n\n\n";
                                system("PAUSE");
                                system("CLS");

                                break;
                            }

                            break;

                    case 4:
                            finding = 0;

                            cout << "Enter the Employee ID you want to find: ";
                            cin.ignore(20,'\n');
                            getline(cin, temp.EmployeeID);
                            cout << endl;

                            while(finding < employee_vector.size())
                            {
                                if(temp.EmployeeID == employee_vector[finding].EmployeeID)
                                {
                                    find = 1;
                                    cout << "Employee ID: " << employee_vector[finding].EmployeeID << " is Found in the Vector!" << endl;
                                    cout << "\n\n";
                                    cout << "Employee ID: " <<employee_vector[finding].EmployeeID << endl;
                                    cout << endl;
                                    cout << "Last Name: " <<employee_vector[finding].Last_Name << endl;
                                    cout << endl;
                                    cout << "First Name: " << employee_vector[finding].First_Name << endl;
                                    cout << endl;
                                    cout << "Hours: " << employee_vector[finding].Hours << endl;
                                    cout << endl;
                                    cout << "Pay Rate: " << employee_vector[finding].PayRate << endl;
                                    cout << endl;
                                    cout << "Income Tax Rate: " << employee_vector[finding].Income_Tax_Rate << endl;
                                    cout << endl;
                                    cout << "Number Depdents: " << employee_vector[finding].NumberDependents << endl;
                                    cout << "\n\n";

                                    //put switch and menu here so you can directly edit the vector element
                                    //example below

                                    cout << "=========================================" << endl;
                                    cout << "\n\n";
                                    cout << "(1.) - Change Employee ID " << endl;
                                    cout << endl;
                                    cout << "(2.) - Change Last Name " << endl;
                                    cout << endl;
                                    cout << "(3.) - Change First Name " << endl;
                                    cout << endl;
                                    cout << "(4.) - Change Hours Worked " << endl;
                                    cout << endl;
                                    cout << "(5.) - Change Pay Rate " << endl;
                                    cout << endl;
                                    cout << "(6.) - Change Income Tax Rate " << endl;
                                    cout << endl;
                                    cout << "(7.) - Change Number Dependents " << endl;
                                    cout << endl;
                                    cout << "(8.) - Cancel" << endl;
                                    cout << "\n\n";
                                    cout << "Enter your choice (1 - 8): ";
                                    cin >> CHANGE_FIELD_RECORDS;

                                    CHANGE_FIELD_RECORDS = abs(CHANGE_FIELD_RECORDS);

                                    cout << "\n\n";
                                    system("PAUSE");
                                    system("CLS");

                                         //Switch should be inside if statement
                                            switch(CHANGE_FIELD_RECORDS)
                                            {
                                                case 1:
                                                        cout << "Enter the Employee ID: ";
                                                        cin.ignore();
                                                        getline(cin, employee_vector[finding].EmployeeID);
                                                        cout << "\n\n\n";
                                                        system("PAUSE");
                                                        system("CLS");


                                                         //push back is not needed here, it will add a new vector instead of changing one
                                                         //employee_vector.push_back(temp);

                                                        break;

                                                case 2:
                                                        cout << "Enter the Last Name: ";
                                                        cin.ignore();
                                                        getline(cin, employee_vector[finding].Last_Name);
                                                        cout << "\n\n\n";
                                                        system("PAUSE");
                                                        system("CLS");

                                                        break;

                                                case 3:
                                                        cout << "Enter the First Name: ";
                                                        cin.ignore();
                                                        getline(cin, employee_vector[finding].First_Name);
                                                        cout << "\n\n\n";
                                                        system("PAUSE");
                                                        system("CLS");

                                                        break;

                                                case 4:
                                                        cout << "Enter the Hours Worked: ";
                                                        cin >> employee_vector[finding].Hours;
                                                        cout << endl;

                                                        while (employee_vector[finding].Hours < 0.0)
                                                        {
                                                            cout << "Enter the Hours Worked: ";
                                                            cin >> employee_vector[finding].Hours;
                                                            cout << endl;
                                                        }

                                                        cout << "\n\n\n";
                                                        system("PAUSE");
                                                        system("CLS");

                                                        break;

                                                case 5:
                                                        cout << "Enter the Pay Rate: ";
                                                        cin >> employee_vector[finding].PayRate;
                                                        cout << endl;

                                                        while (employee_vector[finding].PayRate < 0.0)
                                                        {
                                                            cout << "Enter the Pay Rate: ";
                                                            cin >> employee_vector[finding].PayRate;
                                                            cout << endl;
                                                        }

                                                        cout << "\n\n\n";
                                                        system("PAUSE");
                                                        system("CLS");

                                                        break;

                                                case 6:
                                                        cout << "Enter the Income Tax Rate: ";
                                                        cin >> employee_vector[finding].Income_Tax_Rate;
                                                        cout << endl;

                                                        while (employee_vector[finding].Income_Tax_Rate < 0.0)
                                                        {
                                                            cout << "Enter the Income Tax Rate: ";
                                                            cin >> employee_vector[finding].Income_Tax_Rate;
                                                            cout << endl;
                                                        }

                                                        cout << "\n\n\n";
                                                        system("PAUSE");
                                                        system("CLS");

                                                        break;

                                                case 7:
                                                        cout << "Enter the Number Dependents: ";
                                                        cin >> employee_vector[finding].NumberDependents;
                                                        cout << endl;

                                                        while (employee_vector[finding].NumberDependents < 0)
                                                        {
                                                            cout << "Enter the Number Dependents: ";
                                                            cin >> employee_vector[finding].NumberDependents;
                                                            cout << endl;
                                                        }

                                                        cout << "\n\n\n";
                                                        system("PAUSE");
                                                        system("CLS");

                                                        break;

                                                case 8:
                                                        // Cancel and goes back to the main menu of the program.
                                                        break;

                                                default:
                                                        cout << "Sorry! " << CHANGE_FIELD_RECORDS << " was an Invalid Choice!" << endl;
                                                        cout << "\n\n\n";
                                                        system("PAUSE");
                                                        system("CLS");
                                    }
                                    break;
                                }
                                finding++;
                            }
                            if(find == false)
                            {
                                cout << temp.EmployeeID << " is not Found in the Vector!" << endl;
                                cout << "\n\n\n";
                                system("PAUSE");
                                system("CLS");

                                break;
                            }
                            break;

                    case 5: // Add a new Record to the vector

                                cout << "(1 of 7) - Enter the Employee ID: ";
                                cin.ignore();
                                getline(cin, temp.EmployeeID);
                                cin.ignore();
                                cout << endl;

                                cout << "(2 of 7) - Enter the Last Name: ";
                                getline(cin, temp.Last_Name);
                                cin.ignore();
                                cout << endl;

                                cout << "(3 of 7) - Enter the First Name: ";
                                getline(cin, temp.First_Name);
                                cin.ignore();
                                cout << endl;

                                cout << "(4 of 7) - Enter the Hours Worked: ";
                                cin >> temp.Hours;
                                cout << endl;

                                    while(temp.Hours < 0.0)
                                    {
                                        cout << "Enter the Hours Worked: ";
                                        cin >> temp.Hours;
                                        cout << endl;
                                    }

                                cout << "(5 of 7) - Enter the Pay Rate: ";
                                cin >> temp.PayRate;
                                cout << endl;

                                    while(temp.PayRate < 0.0)
                                    {
                                        cout << "Enter the Pay Rate: ";
                                        cin >> temp.PayRate;
                                        cout << endl;
                                    }

                                cout << "(6 of 7) - Enter the Income Tax Rate: ";
                                cin >> temp.Income_Tax_Rate;
                                cout << endl;

                                    while(temp.Income_Tax_Rate < 0.0)
                                    {
                                        cout << "Enter the Income Tax Rate: ";
                                        cin >> temp.Income_Tax_Rate;
                                        cout << endl;
                                    }

                                cout << "(7 of 7) - Enter the Number Dependents: ";
                                cin >> temp.NumberDependents;
                                cout << endl;

                                    while(temp.NumberDependents < 0)
                                    {
                                        cout << "Enter the Number Dependents: ";
                                        cin >> temp.NumberDependents;
                                        cout << endl;
                                    }

                                    employee_vector.push_back(temp);

                                cout << "\n\n\n";
                                system("PAUSE");
                                system("CLS");

                            break;

                    case 6:
                            exit(0);

                            break;

                    default:
                            cout << "Sorry! " << option << " was an Invalid Choice." << endl;
                            cout << "\n\n\n";
                            system("PAUSE");
                            system("CLS");
                    }

                 ofstream outFile("personnel.dat",ios::out);

                for(int count = 0; count < employee_vector.size(); count++)
                {
                    outFile << employee_vector[count].EmployeeID << " "
                            << employee_vector[count].Last_Name << " "
                            << employee_vector[count].First_Name << " "
                            << employee_vector[count].Hours << " "
                            << employee_vector[count].PayRate << " "
                            << employee_vector[count].Income_Tax_Rate << " "
                            << employee_vector[count].NumberDependents << endl;
                }
                outFile.close();
            }
    return 0;
}

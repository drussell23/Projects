 /**
    Derek J. Russell
    Professor Desmond Chun
    CSCI 15-01 - Assignment 8
    Due: May 4th, 2016
    Linked List
    May 1st, 2016
**/
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include <memory>
#include <list>
#include <cstring>

using namespace std;

struct Node
{
    string Employee_ID;
    double Hours;
    double Pay_Rate;
    Node *Next;
    Node *Previous;
};
/// Function Prototypes
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
    cout << setw(58) << "\t\1 CSCI 15-01 Assignment 8 - Linked List \2" << endl;
    cout << endl;
    cout << "Clock -> " << Hour << ":" << Min << ":" << Sec << endl;
    cout << "\n\n";
}
int main()
{
    Node *First = nullptr;
    Node *Middle = nullptr;
    Node *Last = nullptr;
    Node *TempPrevious;
    Node *TempNext;
    Node *P;
    Node *N;

    string employee_ID;
    double hrs, pay_rate;

    int choice2;
    bool found = true;

    intmax_t CHOICE, count = 0;
    char Answer = 'Y';

                while (Answer = 'Y')
                {
                    DisplayTitle();
                    cout << "(1.) - Add a Node to the FRONT of the LIST." << endl;
                    cout << endl;
                    cout << "(2.) - Add a Node to the REAR of the LIST." << endl;
                    cout << endl;
                    cout << "(3.) - Add a Node in the MIDDLE of the LIST." << endl;
                    cout << endl;
                    cout << "(4.) - Display all Nodes from FRONT to the LAST Node." << endl;
                    cout << endl;
                    cout << "(5.) - Display all Nodes from LAST to the FIRST Node (Reverse Display)." << endl;
                    cout << endl;
                    cout << "(6.) - Search for one Node based on Employee ID." << endl;
                    cout << endl;
                    cout << "(7.) - Search for one Node based on Employee ID and CHANGE Any of the Fields." << endl;
                    cout << endl;
                    cout << "(8.) - DELETE a node based on Employee ID." << endl;
                    cout << endl;
                    cout << "(9.) - QUIT The Program." << endl;
                    cout << "\n\n";
                    cout << "Enter a CHOICE from (1 - 9): ";
                    cin >> CHOICE;

                    CHOICE = abs(CHOICE);
                    cout << "\n\n";
                    system("PAUSE");
                    system("CLS");

                    switch(CHOICE)
                    {
                            case 1:
                                    P = new Node(); // Create a New Node.
                                    count += 1;

                                    cin.ignore();
                                    cout << "(1 of 3) - Enter Employee ID: ";
                                    getline(cin, employee_ID);
                                    cout << endl;

                                    P -> Previous = nullptr;
                                    P -> Employee_ID = employee_ID;

                                    cout << "(2 of 3) - Enter the Hours: ";
                                    cin >> hrs;
                                    cout << endl;

                                    P -> Previous = nullptr;
                                    P -> Hours = hrs;

                                    cout << "(3 of 3) - Enter the Pay Rate: ";
                                    cin >> pay_rate;
                                    cout << endl;

                                    P ->Previous = nullptr;
                                    P ->Pay_Rate = pay_rate;

                                    P -> Next = First;

                                    First = P;

                                    if(count == 1)
                                    {
                                        Last = P;
                                    }
                                    if(count > 1)
                                    {
                                        P = P -> Next;
                                        P -> Previous = First;
                                    }

                                    cout << "\n\n\n";
                                    system("PAUSE");
                                    system("CLS");
                                    break;

                            case 2:
                                    P = new Node;
                                    count += 1;

                                    if(count == 1)
                                    {
                                        First = nullptr;
                                    }

                                    cin.ignore();
                                    cout << "(1 of 3) - Enter Employee ID: ";
                                    getline(cin, employee_ID);
                                    cout << endl;

                                    P ->Previous = Last;
                                    P ->Employee_ID = employee_ID;

                                    cout << "(2 of 3) - Enter the Hours: ";
                                    cin >> hrs;
                                    cout << endl;

                                    P ->Previous = Last;
                                    P ->Hours = hrs;

                                    while (hrs < 0)
                                    {
                                        cout << "(2 of 3) - Enter the Hours: ";
                                        cin >> hrs;
                                        cout << endl;
                                    }

                                    P ->Previous = nullptr;
                                    P ->Hours = hrs;

                                    cout << "(3 of 3) - Enter the Pay Rate: ";
                                    cin >> pay_rate;
                                    cout << endl;

                                    P ->Previous = nullptr;
                                    P ->Pay_Rate = pay_rate;

                                    while (pay_rate < 0)
                                    {
                                        cout << "(3 of 3) - Enter the Pay Rate: ";
                                        cin >> pay_rate;
                                        cout << endl;
                                    }

                                    P ->Previous = Last;
                                    P ->Pay_Rate = pay_rate;
                                    P -> Next = NULL;
                                    Last = P;

                                    if(First == NULL)
                                    {
                                        First = P;
                                        P -> Previous = NULL;
                                    }
                                    else
                                    {
                                        P = P -> Previous;
                                        P -> Next = Last;
                                    }
                                    cout << "\n\n\n";
                                    system("PAUSE");
                                    system("CLS");

                                    break;


                        case 3:
                                P = new Node; // Create a New Node.
                                count += 1;

                                cin.ignore();
                                cout << "(1 of 3) - Enter Employee ID: ";
                                getline(cin, employee_ID);
                                cout << endl;

                                P -> Previous = NULL;
                                P -> Employee_ID = employee_ID;

                                cout << "(2 of 3) - Enter the Hours: ";
                                cin >> hrs;
                                cout << endl;

                                P -> Previous = NULL;
                                P -> Hours = hrs;

                                while (hrs < 0)
                                {
                                    cout << "(2 of 3) - Enter the Hours: ";
                                    cin >> hrs;
                                    cout << endl;

                                }

                                P -> Previous = NULL;
                                P -> Hours = hrs;

                                cout << "(3 of 3) - Enter the Pay Rate: ";
                                cin >> pay_rate;
                                cout << endl;

                                P ->Previous = NULL;
                                P ->Pay_Rate = pay_rate;

                                while (pay_rate < 0)
                                {
                                    cout << "(3 of 3) - Enter the Pay Rate: ";
                                    cin >> pay_rate;
                                    cout << endl;
                                }

                                P ->Previous = NULL;
                                P ->Pay_Rate = pay_rate;

                                P -> Next = First;

                                First = P;

                                if(count == 1)
                                {
                                    Last = P;
                                }
                                if(count > 1)
                                {
                                    P = P ->Next;
                                    P -> Previous = First;
                                }
                                while(P != NULL && P->Employee_ID < employee_ID)
                                {
                                    P = P ->Previous;
                                    P = P-> Next;
                                }
                                cout << "\n\n\n";
                                system("PAUSE");
                                system("CLS");
                                break;

                        case 4: // Display all Nodes from front to the last Node.
                                if(count > 0)
                                {
                                  cout << "List has " << count << " Employee Record(s)" << endl;
                                  cout << endl;
                                        P = First;
                                        while(P -> Next != NULL)
                                        {
                                            cout << "Employee ID: " << P->Employee_ID << endl;
                                            cout << endl;
                                            cout << "Hours: " << P->Hours << endl;
                                            cout << endl;
                                            cout << "Pay Rate: "<< P->Pay_Rate << endl;
                                            cout << endl;
                                            cout << "===========================================" << endl;
                                            cout << endl;
                                            P = P -> Next;
                                        }
                                        cout << "Employee ID: " << P->Employee_ID << endl;
                                        cout << endl;
                                        cout << "Hours: " << P->Hours << endl;
                                        cout << endl;
                                        cout << "Pay Rate: "<< P->Pay_Rate << endl;
                                        cout << endl;
                                        cout << "\tEnd of the List" << endl;
                                        cout << "\n\n\n";
                                        system("PAUSE");
                                        system("CLS");
                                }
                                else
                                {
                                    cout << "LIST is EMPTY!" << endl;
                                    cout << "\n\n\n";
                                    system("PAUSE");
                                    system("CLS");
                                    break;
                                }
                                break;

                        case 5: // Display all Nodes from last to the first node (Reverse Display).
                                if(count > 0)
                                {
                                    cout << "List has " << count << "of Employee Record(s)" << endl;
                                    cout << endl;
                                    P = Last;

                                    while(P->Previous != nullptr)
                                    {
                                            cout << "Employee ID: " << P->Employee_ID << endl;
                                            cout << endl;
                                            cout << "Hours: " << P->Hours << endl;
                                            cout << endl;
                                            cout << "Pay Rate: "<< P->Pay_Rate << endl;
                                            cout << endl;
                                            cout << "===========================================" << endl;
                                            cout << endl;

                                        P = P -> Previous;
                                    }
                                    cout << "Employee ID: " << P->Employee_ID << endl;
                                    cout << endl;
                                    cout << "Hours: " << P->Hours << endl;
                                    cout << endl;
                                    cout << "Pay Rate: " << P->Pay_Rate << endl;
                                    cout << "\n\n\n";
                                    system("PAUSE");
                                    system("CLS");
                                }
                                else
                                {
                                    cout << "LIST is EMPTY!!!" << endl;
                                    cout << "\n\n\n";
                                    system("PAUSE");
                                    system("CLS");
                                    break;
                                }
                                break;

                        case 6: // Search for one Node based on Employee ID.
                                if(count > 0)
                                    {
                                        cout << "(6.) - Search for one Node based on Employee ID." << endl;
                                        cout << "\n\n";
                                        bool found = false;
                                        cin.ignore();
                                        cout << "Enter the Employee ID: ";
                                        cin >> employee_ID;

                                        P = First; // "P" is equal to first Node in the list.
                                        while(P ->Next != nullptr) // Keep going until we reached the end of the LIST.
                                        {
                                                if(P->Employee_ID == employee_ID) // Checking to see if the number is in the LIST.
                                                {
                                                    cout << endl;
                                                    cout << "\2 Congratulations! \1 " << endl;
                                                    cout << "\n\n";
                                                    cout << "Employee ID: " << employee_ID << " has been Found in the LIST! =) " << endl;
                                                    cout << "\n\n";
                                                    cout << "Employee ID: " << employee_ID << endl;
                                                    cout << endl;
                                                    cout << "Hours: " << hrs << endl;
                                                    cout << endl;
                                                    cout << "Pay Rate: " << pay_rate << endl;
                                                    found = true;
                                                    cout << "\n\n\n";
                                                    system("PAUSE");
                                                    system("CLS");
                                                    break;
                                                }
                                                else
                                                {
                                                  P = P -> Next; // Set the pointer "P" to the next Node in the LIST.
                                                }

                                        }
                                        if(P->Next == nullptr)
                                        {
                                           if(P ->Employee_ID == employee_ID)

                                           {
                                                cout << endl;
                                                cout << employee_ID << " is Found in the LIST! =) " << endl;
                                                cout << "\n\n";
                                                cout << "\2 Congratulations! \1 " << endl;
                                                cout << "\n\n";
                                                cout << "Employee ID: " << employee_ID << endl;
                                                cout << endl;
                                                cout << "Hours: " << hrs << endl;
                                                cout << endl;
                                                cout << "Pay Rate: " << pay_rate << endl;
                                                found = true;
                                                cout << "\n\n\n";
                                                system("PAUSE");
                                                system("CLS");
                                                break;
                                           }

                                        }
                                        if(found == false)
                                        {
                                            cout << endl;
                                            cout << employee_ID << " is not FOUND in the LIST! =(" << endl;
                                            cout << "\n\n\n";
                                            system("PAUSE");
                                            system("CLS");
                                        }
                                        break;
                                    }
                                    else
                                    {
                                        cout << "EMPTY LIST!!!" << endl;
                                        cout << "\n\n\n";
                                        system("PAUSE");
                                        system("CLS");
                                    }
                                        break;

                        case 7:
                                        if(count > 0)
                                        {
                                            cin.ignore();
                                            cout << "Enter the Employee ID: ";
                                            getline(cin, employee_ID);
                                            cout << endl;
                                            P = First;

                                            while(found)
                                            {
                                                if(P -> Employee_ID == employee_ID)
                                                {
                                                    cout << "Change a Field Value" << endl;
                                                    cout << endl;
                                                    cout << "(1.) - Employee ID" << endl;
                                                    cout << endl;
                                                    cout << "(2.) - Total hours worked" << endl;
                                                    cout << endl;
                                                    cout << "(3.) - Pay Rate" << endl;
                                                    cout << endl;
                                                    cout << "Enter an Option(1 to 3): ";
                                                    cin  >> choice2;

                                                    choice2 = abs(choice2);
                                                    cout << "\n\n";
                                                    system("PAUSE");
                                                    system("CLS");

                                                    switch(choice2)
                                                    {
                                                        case 1:
                                                        {
                                                            cin.ignore();
                                                            cout << "Enter Employee ID: ";
                                                            getline(cin, employee_ID);
                                                            P ->Employee_ID = employee_ID;
                                                            cout << "\n\n\n";
                                                            system("PAUSE");
                                                            system("CLS");
                                                            break;
                                                        }

                                                        case 2:
                                                        {
                                                                cout << "Enter the Total Hours Worked: ";
                                                                cin >> hrs;
                                                                P ->Hours = hrs;
                                                                cout << "\n\n\n";
                                                                system("PAUSE");
                                                                system("CLS");

                                                                break;
                                                        }

                                                        case 3:
                                                        {
                                                                cout << "Enter the Pay Rate: ";
                                                                cin >> pay_rate;
                                                                P ->Pay_Rate = pay_rate;
                                                                cout << "\n\n\n";
                                                                system("PAUSE");
                                                                system("CLS");

                                                                break;
                                                        }

                                                        default:
                                                                cout << "Sorry!" << choice2 << "is an Invalid Menu Option!" << endl;
                                                                cout << endl;
                                                                cout << "Please enter a valid menu option(1 - 3)" << endl;
                                                                cout << "\n\n\n";
                                                                system("PAUSE");
                                                                system("CLS");
                                                    }

                                                    break;

                                                    found = false;

                                                }
                                                else
                                                {
                                                    P = P ->Next;
                                                    if((P ->Next == nullptr) && (P ->Employee_ID != employee_ID) )
                                                    {
                                                        cout << "Employee " << employee_ID << " Does Not Exist!" << endl;
                                                        cout << "\n\n\n";
                                                        system("PAUSE");
                                                        system("CLS");

                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            cout << "Sorry! No Employee Records Exist!" << endl;
                                            cout << "\n\n\n";
                                            system("PAUSE");
                                            system("CLS");
                                        }
                                        break;

                        case 8:
                                if(count > 0)
                                {
                                    cout << "(3.) - REMOVE a Specific Numeric Value From the LIST." << endl;
                                    cout << "\n\n";
                                    cout << "Enter the Employee ID: ";
                                    cin >> employee_ID;
                                    P = First;
                                    cout << endl;

                                    while (Answer == 'Y')
                                    {
                                        if(P ->Employee_ID == employee_ID) // Checking to see if P-> NUMBER is equal to the temp (number).
                                        {
                                            cout << "Employee ID: " << P ->Employee_ID << " has been deleted from List." << endl;
                                            count -= 1; // elements = elements - 1
                                            if(count == 0)
                                            {
                                                delete P;
                                                First = NULL;
                                                Last = NULL;
                                                cout << "\n\n";
                                                system("PAUSE");
                                                system("CLS");
                                                break;
                                            }
                                            TempPrevious = P -> Previous;
                                            TempNext = P -> Next;
                                            delete P;

                                            /**
                                                Reset Previous Node's "Next" Pointer and
                                                Next Node's "Previous" Pointer.

                                                ==========================================

                                                Determine if Previous was NULL (i.e. we deleted)
                                                the FIRST node in the LIST.

                                            **/
                                            if(TempPrevious == NULL)
                                            {
                                                // Move to adjust NEXT node's pointer.
                                                P = TempNext;
                                                P -> Previous = NULL;
                                                First = P;
                                                cout << " First Element Deleted From List";
                                                cout << "\n\n";
                                                system("PAUSE");
                                                system("CLS");
                                                break;
                                            }
                                            /**
                                                Determine if Next was NULL (i.e. we deleted)
                                                the LAST node in the LIST.
                                            **/
                                            if(TempNext == NULL)
                                            {
                                                // Move to adjust PREVIOUS node's pointer.
                                                P = TempPrevious;
                                                P ->Next = NULL;
                                                Last = P;
                                                cout << "\n\n";
                                                system("PAUSE");
                                                system("CLS");
                                                break;
                                            }
                                            /**
                                                Deleted Node was in the "middle" of the LIST.
                                                Adjust pointers for the PREVIOUS and NEXT
                                                pointers.
                                            **/
                                            if((TempPrevious != NULL) && (TempNext != NULL))
                                            {
                                                P = TempPrevious;
                                                P -> Next = TempNext;
                                                P = TempNext;
                                                P -> Previous = TempPrevious;
                                                cout << "\n\n";
                                                system("PAUSE");
                                                system("CLS");
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            // NOT Found, move to the NEXT Node.
                                            P = P ->Next;
                                            if((P -> Next == NULL) && (P ->Employee_ID != employee_ID))
                                            {
                                                cout << "\n" << employee_ID << " is NOT in the LIST!" << endl;
                                                cout << "\n\n";
                                                system("PAUSE");
                                                system("CLS");
                                                break;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    cout << "LIST is EMPTY!!!";
                                    cout << "\n\n";
                                    system("PAUSE");
                                    system("CLS");
                                }
                                break;

                        case 9:
                                cout << "Exiting LINKED LIST Program!" << endl;
                                exit(-1);
                                cout << "\n\n\n";
                                system("PAUSE");
                                system("CLS");

                                break;



                        default:
                                cout << CHOICE << " is NOT a Valid value!" << endl;
                                cout << "\n\n\n";
                                system("PAUSE");
                                system("CLS");

                    }
            }

    return 0;

}

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

int main()
{
    vector<intmax_t> numbers;
    int index, count = 0, value, option, number_of_elements = 10;
    bool again = true;
    cout.setf(ios::right, ios::adjustfield);

    // Load initial vector
    for(int n = 0; n < number_of_elements; n++)
    {
        numbers.push_back((rand() + time(0) % 100 + 1));
    }
    while(again)
    {
        cout << "\n" << numbers.size() << " Elements in this Vector " << endl;
        cout << "\n\n";
        cout << "(1.) - Display Vector Contents" << endl;
        cout << endl;
        cout << "(2.) - Add a new value to the Vector" << endl;
        cout << endl;
        cout << "(3.) - Delete an existing value in the Vector" << endl;
        cout << endl;
        cout << "(4.) - Find a Value in the Vector" << endl;
        cout << endl;
        cout << "(5.) - Sort the Vector - Ascending Order" << endl;
        cout << endl;
        cout << "(6.) - Sort the Vector - Descending Order" << endl;
        cout << endl;
        cout << "(7.) - Quit" << endl;
        cout << "\n\n";
        cout << "Enter an option (1 - 7): ";
        cin >> option;

        option = abs(option);

        cout << "\n\n\n";
        system("PAUSE");
        system("CLS");

        switch(option)
        {
            case 1: // Display Vector Contents.
                    for(int count = 0; count < numbers.size(); << count++)
                    {
                        cout << "\nIndex #" << setw(3) << count << setw(6) << numbers[count];
                    }
                    cout << "\n\n\n";
                    system("PAUSE");
                    system("CLS");
                    break;

            case 2: // Add a new value to the Vector.
                    cout << "\n" << numbers.size() << " Elements in the Vector:\n";

                        if(numbers.size() > 0)
                        {
                            cout << "\nEnter an Index Location to Add a new value (0 to " << numbers.size() - 1 << "): ";
                            cin >> index;
                            index = abs(index);

                            cout << "\n\n\n";
                            system("PAUSE");
                            system("CLS");

                            while(index >= numbers.size())
                            {
                                cout << "You entered an Invalid Index Number, " << index << endl;
                                cout << endl;
                                cout << "Enter an Index Location to Add a new value (0 to " << numbers.size() - 1 << "): ";
                                cin >> index;
                                index = abs(index);
                                cout << "\n\n\n";
                                system("PAUSE");
                                system("CLS");
                            }
                            cout << "Enter an Integer Value: ";
                            cin >> value;
                            numbers.insert(numbers.begin() + index, value);
                            cout << "\n\n\n";
                            system("PAUSE");
                            system("CLS");
                            }


                        }


        }

    }
    return EXIT_SUCCESS;
}


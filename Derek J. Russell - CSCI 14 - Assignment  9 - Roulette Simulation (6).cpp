//Derek J. Russell
//Desmond Chun
//CSCI 14 - Spring 2014 - Assignment 9 - Roulette Simulation  || Due - May 19th, 2015
//May 11th, 2015
#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
#include <cstdlib>
using namespace std;

const int Green = 0, Red = 1, Black = 2;

int Rand()
{
    return ((rand() % 37));
}
int Color(int Number)
{
    if(Number == 0)
    {
        return Green;
    }
    if(Number == 1 || Number == 3 || Number == 5 || Number == 7 || Number == 9 || Number == 12 || Number == 14 ||
       Number == 16 || Number == 18 || Number == 19 || Number == 21 || Number == 23 || Number == 25 || Number == 27 ||
       Number == 30 || Number == 32 || Number == 34|| Number == 36)
    {
        return Red;
    }


    return Black;


}
int main()
{
     srand(time(NULL));
     int option;
     int Roulette_Simulation_Spin_Random_Number,
         Roulette_Simulation_Spin_Random_Color;
     int Input_Number;
     char choice;
    // Decide The Bet.
    do
    {
        do
        {
            cout << "Name: Derek J. Russell" << endl;
            cout << "Date: May 11th, 2015" << endl;
            cout << endl;
            cout << endl;
            cout << "\t\tCSCI 14 - Assignment 9 - Roulette Simulation" << endl;
            cout << endl;
            cout << "Please Select An Option:" << endl;
                cout << endl;
                cout << "\t(1.) - Bet Red?" << endl;
                cout << endl;
                cout << "\t(2.) - Bet Black?" << endl;
                cout << endl;
                cout << "\t(3.) - Bet ODD Number." << endl;
                cout << endl;
                cout << "\t(4.) - Bet EVEN Number." << endl;
                cout << endl;
                cout << "\t(5.) - Bet that 1 to 18 Will Come Up." << endl;
                cout << endl;
                cout << "\t(6.) - Bet that 19 to 36 Will Come Up." << endl;
                cout << endl;
                cout << "\t(7.) - Bet that 0, 2, or 3 Will Come Up (Trio)." << endl;
                cout << endl;
                cout << "\t(8.) - Bet that 0, 1, 2 or 3 Will Come Up (Basket)." << endl;
                cout << endl;
                cout << "\t(9.) - Bet that one particular Number (0 to 36) will Come Up." << endl;
                cout << endl;
                cout << "\t(10.) - Quit the Program." << endl;
                cout << endl;
                cin >> option;
                cout << endl;
                system("pause");
                system("cls");

        }while(option < 1 || option > 10);
        if(option == 10)
        {
            break;
        }

        // Spin The Wheel.
        Roulette_Simulation_Spin_Random_Number = rand() % 37; //Generating A Random Number.
        Roulette_Simulation_Spin_Random_Color = Color(Roulette_Simulation_Spin_Random_Number);

        // get results
        switch(option)
        {
            case 1:
                   if (Roulette_Simulation_Spin_Random_Color == Red) //Bet Red
                       {
                           cout << endl;
                           cout << "You WIN!!! =D " << endl;
                           cout << endl;
                       }
                    else
                        {
                            cout << endl;
                            cout << "You LOST!!! =( " << endl;
                            cout << endl;
                        }
                    break;
            case 2:
                   if (Roulette_Simulation_Spin_Random_Color == Black) // Bet Black
                       {
                            cout << endl;
                            cout << "You WIN!!! =D " << endl;
                            cout << endl;
                       }
                    else
                        {
                            cout << endl;
                            cout << "You LOST!!! =( " << endl;
                            cout << endl;
                        }
                    break;
            case 3:
                   if (Roulette_Simulation_Spin_Random_Number % 2 != 0) // Bet Odd Numbers.
                   {
                       cout << endl;
                       cout << "You WIN!!! =D " << endl;
                       cout << endl;
                   }
                   else
                   {
                       cout << endl;
                       cout << "You LOST!!! =( " << endl;
                       cout << endl;
                   }

                    break;
            case 4:
                    if (Roulette_Simulation_Spin_Random_Number % 2 == 0) // Bet Even Numbers.
                    {
                        cout << endl;
                        cout << "You WIN!!! =D " << endl;
                        cout << endl;
                    }
                    else
                    {
                        cout << endl;
                        cout << "You LOST!!! =( " << endl;
                        cout << endl;
                    }
                    break;
            case 5:
                    if (Roulette_Simulation_Spin_Random_Number >= 1 && Roulette_Simulation_Spin_Random_Number <= 18) // Bet That 1 to 18 Will Come Up.
                    {
                        cout << endl;
                        cout << "You WIN!!! =D " << endl;
                        cout << endl;
                    }
                    else
                    {
                        cout << endl;
                        cout << "You LOST!!! =( " << endl;
                        cout << endl;
                    }
                    break;

            case 6:
                    if (Roulette_Simulation_Spin_Random_Number >= 19 && Roulette_Simulation_Spin_Random_Number <= 36) // Bet That 19 to 36 Will Come Up.
                    {
                        cout << endl;
                        cout << "You WIN!!! =D " << endl;
                        cout << endl;
                    }
                    else
                    {
                        cout << endl;
                        cout << "You LOST!!! =( " << endl;
                        cout << endl;
                    }
                    break;
            case 7:
                    if (Roulette_Simulation_Spin_Random_Number == 0 || Roulette_Simulation_Spin_Random_Number == 2
                        || Roulette_Simulation_Spin_Random_Number == 3) // Bet that 0, 2, or 3 Will Come Up (Trio).
                    {
                        cout << endl;
                        cout << "You WIN!!! =D " << endl;
                        cout << endl;
                    }
                    else
                    {
                        cout << endl;
                        cout << "You LOST!!! =( " << endl;
                        cout << endl;
                    }
                    break;
            case 8:
                    if(Roulette_Simulation_Spin_Random_Number == 0 || Roulette_Simulation_Spin_Random_Number == 1
                       || Roulette_Simulation_Spin_Random_Number == 2 || Roulette_Simulation_Spin_Random_Number == 3) // Bet that 0, 1, 2 or 3 Will Come Up (Basket).
                       {
                           cout << endl;
                           cout << "You WIN!!! =D " << endl;
                           cout << endl;
                       }
                       else
                       {
                           cout << endl;
                           cout << "You LOST!!! =( " << endl;
                           cout << endl;
                       }
                       break;

            case 9:
                   cout << "Please Input A Number: ";
                   cin >> Input_Number;
                   cout << endl;
                   system("pause");
                   system("cls");
                   if(Roulette_Simulation_Spin_Random_Number == Input_Number) // Bet that one particular Number (0 to 36) will Come Up.
                   {
                       cout << endl;
                       cout << "You WIN!!! =D " << endl;
                       cout << endl;
                   }
                   else
                   {

                       cout << endl;
                       cout << "You Bet " << Input_Number << "???!!!" << endl;
                       cout << endl;
                       system("pause");
                       system("cls");
                       cout << "You LOST!!! =( " << endl;
                       cout << endl;

                   }

                    break;

            case 10: // Quit The Program.

                    break;

        }
        if(Roulette_Simulation_Spin_Random_Color == Green)
        {
            cout << "Green " << Roulette_Simulation_Spin_Random_Number << ":" << endl;
        }
        if(Roulette_Simulation_Spin_Random_Color == Red)
        {
            cout << "Red " << Roulette_Simulation_Spin_Random_Number << ":" << endl;
        }
        if(Roulette_Simulation_Spin_Random_Color == Black)
        {
            cout << "Black " << Roulette_Simulation_Spin_Random_Number << ":" << endl;
        }
        cout << endl;
        system("pause");
        system("cls");
        cout << endl;

} while (option >= 1 || option <= 10);
   system("cls");
    return 0;
}

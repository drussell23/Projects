/**
    Derek J. Russell
    Professor Desmond Chun
    CSCI 15 - Assignment 7
    Due: May 25th, 2016
    Abstract Classes
    April 15, 2016
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

class Shapes
{
    protected:
                double WIDTH;
                double HEIGHT;

    public:
            virtual double Get_Area() = 0;

            void SetWidth_AND_SetHeight(double W, double H)
            {
                WIDTH = W;
                HEIGHT = H;
            }
};
class Rectangle : public Shapes
{
    public:
            double Get_Area()
            {
                return (WIDTH * HEIGHT);
            }
};
class Triangle : public Shapes
{
    public:
            double Get_Area()
            {
                return ((WIDTH * HEIGHT) / 2.0);
            }
};
class Cylinder : public Shapes
{
    public:
            double Get_Area()
            {
                 double PI = 3.14159;
                 return ((2 * PI * HEIGHT * WIDTH) + (2 * PI * (HEIGHT * HEIGHT)));
            }
};
class Trapezoid : public Shapes
{
    public:
            double Get_Area()
            {
                return (((WIDTH + WIDTH) / 2.0) * HEIGHT);
            }
};
class Circle : public Shapes
{
    public:
            double Get_Area()
            {
                double PI = 3.14159;
                return (PI * WIDTH * WIDTH);
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
    cout << setw(55) << "\t\1 CSCI 15 Assignment 6 - Inherited Class \2" << endl;
}
int main()
{
    int choice;
    bool again = true;
    double width, length;

    Rectangle rectangle_main;
    Triangle triangle_main;
    Cylinder cylinder_main;
    Trapezoid trapezoid_main;
    Circle circle_main;

    Shapes *shapes1 = &rectangle_main;
    Shapes *shapes2 = &triangle_main;
    Shapes *shapes3 = &cylinder_main;
    Shapes *shapes4 = &trapezoid_main;
    Shapes *shapes5 = &circle_main;

                while (again)
                {
                    DisplayTitle();
                    cout << "\n\n";
                    cout << "Determining the Area of the Objects: " << endl;
                    cout << endl;
                    cout << "(1.) - Rectangle" << endl;
                    cout << endl;
                    cout << "(2.) - Triangle" << endl;
                    cout << endl;
                    cout << "(3.) - Cylinder" << endl;
                    cout << endl;
                    cout << "(4.) - Trapezoid" << endl;
                    cout << endl;
                    cout << "(5.) - Circle" << endl;
                    cout << endl;
                    cout << "(6.) - Quit" << endl;
                    cout << "\n\n";
                    cout << "Enter an Option (1 - 6): ";
                    cin >> choice;

                    choice = abs(choice);

                    cout << "\n\n";
                    system("PAUSE");
                    system("CLS");

                        switch(choice)
                        {
                            case 1:
                                    cout << "1 - Rectangle" << endl;
                                    cout << "\n\n";
                                    cout << "Rectangle Object:" << endl;
                                    cout << endl;
                                    cout << "(1 of 2) - Enter the Height for the Rectangle: ";
                                    cin >> length;
                                    length = fabs(length);
                                    cout << endl;

                                    cout << "(2 of 2) - Enter the Width for the Rectangle: ";
                                    cin >> width;
                                    width = fabs(width);
                                    cout << "\n\n";

                                    shapes1->SetWidth_AND_SetHeight(length, width);

                                    cout << "Total Rectangle area for " << length << " Height by " << width
                                         << " Width is : " << shapes1->Get_Area() << endl;

                                    cout << "\n\n\n";
                                    system("PAUSE");
                                    system("CLS");

                                    break;

                            case 2:
                                    cout << "2 - Triangle" << endl;
                                    cout << "\n\n";
                                    cout << "Triangle Object:" << endl;
                                    cout << endl;
                                    cout << "(1 of 2) - Enter the Height for the Triangle: ";
                                    cin >> length;
                                    length = fabs(length);
                                    cout << endl;
                                    cout << "(2 of 2) - Enter the Width for the Triangle: ";
                                    cin >> width;
                                    width = fabs(width);
                                    cout << "\n\n";

                                    shapes2->SetWidth_AND_SetHeight(length, width);

                                    cout << "Total Triangle area for (" << length << " X "
                                         << width << ")/2 is: " << shapes2->Get_Area() << endl;
                                    cout << endl;
                                    cout << "Total Triangle area for " << length << " Height by " << width
                                         << " Width is : " << shapes2->Get_Area() << endl;

                                    cout << "\n\n\n";
                                    system("PAUSE");
                                    system("CLS");

                                    break;

                            case 3:
                                    cout << "3 - Cylinder " << endl;
                                    cout << "\n\n";
                                    cout << "Cylinder Object:" << endl;
                                    cout << endl;
                                    cout << "(1 of 2) - Enter the Height for the Cylinder: ";
                                    cin >> length;
                                    length = fabs(length);
                                    cout << endl;
                                    cout << "(2 of 2) - Enter the Radius for the Cylinder: ";
                                    cin >> width;
                                    width = fabs(width);
                                    cout << "\n\n";

                                    shapes3->SetWidth_AND_SetHeight(length, width);

                                    cout << "Total Cylinder area for " << length << " Height by " << width
                                         << " Width is : " << shapes3->Get_Area() << endl;

                                    cout << "\n\n\n";
                                    system("PAUSE");
                                    system("CLS");

                                    break;

                            case 4:
                                    cout << "4 - Trapezoid " << endl;
                                    cout << "\n\n";
                                    cout << "Trapezoid Object:" << endl;
                                    cout << endl;
                                    cout << "(1 of 2) - Enter the Height for the Trapezoid: ";
                                    cin >> length;
                                    length = fabs(length);
                                    cout << endl;
                                    cout << "(2 of 2) - Enter the Width for the Trapezoid: ";
                                    cin >> width;
                                    width = fabs(width);
                                    cout << "\n\n";

                                    shapes4->SetWidth_AND_SetHeight(length, width);

                                    cout << "Total Trapezoid area for " << length << " Height by " << width
                                         << " Width is : " << shapes4->Get_Area() << endl;

                                    cout << "\n\n\n";
                                    system("PAUSE");
                                    system("CLS");

                                    break;

                            case 5:
                                    cout << "5 - Circle " << endl;
                                    cout << "\n\n";
                                    cout << "Circle Object:" << endl;
                                    cout << endl;
                                    cout << "(1 of 1) - Enter the Radius for the Circle: ";
                                    cin >> width;
                                    width = fabs(width);
                                    cout << "\n\n";

                                    shapes5->SetWidth_AND_SetHeight(width, width);

                                    cout << "Total Circle area for " << width << " Height by " << width
                                         << " Width is : " << shapes5->Get_Area() << endl;

                                    cout << "\n\n\n";
                                    system("PAUSE");
                                    system("CLS");

                                    break;

                            case 6:
                                    cout << "6 - Quit:" << endl;
                                    cout << "\n\n";

                                    again = false;
                                    cout << "\1 Good Bye!!! \2" << endl;

                                    break;

                            default:
                                      cout << "Sorry! Please select an option on the MENU from (1 to 6)." << endl;
                                      cout << "\n\n";
                                      system("PAUSE");
                                      system("CLS");
                            }
                }
    return 0;
}

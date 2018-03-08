/**
    Derek J. Russell
    Professor Desmond Chun
    CSCI 15-01 Lab Assignment 5
    Due - March 21st, 2016
    Classes
    March 16th, 2016
**/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <memory>
#include <cctype>
#include <cstring>
using namespace std;

class Student
{
    private:
        /// Characteristic values of member.
        string Student_ID;
        string Last_NAME;
        string First_NAME;
        float GPA;
        int NumberOfEnrolled_Classes;

    public:
        void setID(string);
        void setLastName(string);
        void setFirstName(string);
        void setGPA(float);
        void setClasses(int);
        void DisplayStudent();
        void SetALL(string, string, string, float, int);
};
void Student::setID(string Student_ID_New)
{
    Student_ID = Student_ID_New;
}
void Student::setLastName(string LastName)
{
    Last_NAME = LastName;
}
void Student::setFirstName(string FirstName)
{
    First_NAME = FirstName;
}
void Student::setGPA(float StudentGPA)
{
    GPA = StudentGPA;
}
void Student::setClasses(int classes)
{
    NumberOfEnrolled_Classes = classes;
}
void Student::SetALL(string ID, string first, string last, float gpa, int classes)
{
    Student_ID = ID;
    Last_NAME = last;
    First_NAME = first;
    GPA = gpa;
    NumberOfEnrolled_Classes = classes;
}
void Student::DisplayStudent()
{
    cout.precision(1); /// 1 number after the decimal point.
    cout.setf (ios::fixed | ios::showpoint);

    cout << "Student ID: " << Student_ID << endl;
    cout << endl;
    cout << Last_NAME << ", " << First_NAME << endl;
    cout << endl;
    cout << NumberOfEnrolled_Classes << " Classes Taken This Semester" << endl;
    cout << endl;
    cout << "Current GPA is " << GPA << endl;
    cout << endl;
}
void DisplayTitle()
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
       cout << setw(60) << "\t\1 CSCI 15-01 Lab Assignment 5 - Classes \2" << endl;
}
int main()
{
    /// Using a series of standalone variables.
    string StudentID, FirstName, LastName;
    int NumberOFClasses, choice, input;
    float CurrentGPA;
    bool again = true;

    int CurrentNumberOFStudents = 0; /// Keeps track of the current students.

    Student * objectPointer;
    Student *ListOfStudents[6]; /// Create an array of 6 pointers to the object Student.


    for(int i = 0; i < 6; i++)
    {
        ListOfStudents[i] = new Student; /// Creates a new Student.
    }

    while (again)
    {
        DisplayTitle();
        cout << "\n\n";
        cout << "(1.) - Display each member's individual characteristics. \1" << endl;
        cout << endl;
        cout << "(2.) - Enter a NEW class member. \2" << endl;
        cout << endl;
        cout << "(3.) - QUIT. \1" <<  endl;
        cout << endl;
        cout << "Enter your choice from (1 - 3): ";
        cin >> choice;

        choice = abs(choice);

        cout << "\n\n";
        system("PAUSE");
        system("CLS");

            switch (choice)
            {
                case 1:
                        cout << "Displaying the students' data:" << endl;
                        cout << "\n\n";
                        for(int count = 0; count < CurrentNumberOFStudents; count++)
                        {
                            ListOfStudents[count]->DisplayStudent();
                            cout << "\n\n";
                            cout << "===============================================================================" << endl;
                            cout << "\n\n";
                        }
                        cout << "\n\n";
                        system("PAUSE");
                        system("CLS");
                       break;
                case 2:
                        cin.ignore();
                        cout << "(1 of 5) - Enter Student ID: ";
                        getline(cin, StudentID);
                        cout << endl;

                        cout << "(2 of 5) - Enter the your Last Name: ";
                        getline(cin, LastName);
                        cout << endl;

                        cout << "(3 of 5) - Enter the your First Name: ";
                        getline(cin, FirstName);
                        cout << endl;

                        cout << "(4 of 5) - Enter the classes you're enrolled in this Semester: ";
                        cin >> NumberOFClasses;
                        cout << endl;

                        cout << "(5 of 5) - Enter your current GPA: ";
                        cin >> CurrentGPA;
                        cout << "\n\n\n";

                        system("PAUSE");
                        system("CLS");

                        ListOfStudents[CurrentNumberOFStudents]->SetALL(StudentID, FirstName, LastName, CurrentGPA, NumberOFClasses);
                        CurrentNumberOFStudents++;
                        break;
                case 3:
                        again = false;
                        cout << "Good Bye!" << endl;
                        break;

                default:
                         cout << "Sorry! Please select an option on the MENU from 1 to 3." << endl;
                         cout << "\n\n";
                         system("PAUSE");
                         system("CLS");
            }
       }
    return 0;
}

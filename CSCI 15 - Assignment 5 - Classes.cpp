/**
    Derek J. Russell
    Professor Desmond Chun
    CSCI 15 - Assignment 5
    Due April 4th, 2016
    Classes
    March 25th, 2016
**/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <string>
#include <memory>
using namespace std;

class Student
{
    private:
            string Student_ID;
            string Last_NAME;
            string First_NAME;
            float GPA;
            int NumberOfEnrolled_Classes;

    public:
            /// Member functions
            void DisplayStudent();
            void SetALL(string, string, string, float, int);
            void SetID(string);
            void SetLastName(string);
            void SetFirstName(string);
            void SetGPA(float);
            void SetClasss(int);
            Student(); /// Default Constructor.
            Student(string Student_ID, string Last_NAME, string First_NAME, float GPA, int NumberOfEnrolled_Classes);

            /// Inline Functions
            string GetID() const
            { return Student_ID; }

            string GetLastName() const
            { return Last_NAME; }

            string GetFirstName() const
            { return First_NAME; }

            float GetGPA() const
            { return GPA; }

            int GetClasses() const
            { return NumberOfEnrolled_Classes; }
};
/// Default Constructor.
Student::Student()
{
    SetALL("N/A", "N/A", "N/A", 0.0, 0);
}
/// Normal Constructor.
Student::Student(string Student_ID, string Last_NAME, string First_NAME, float GPA, int NumberOfEnrolled_Classes)
{
    SetALL(Student_ID, Last_NAME, First_NAME, GPA, NumberOfEnrolled_Classes);
}
void Student::DisplayStudent()
{
    cout << "Student ID: " << Student_ID << endl;
    cout << endl;
    cout << First_NAME << ", " << Last_NAME << endl;
    cout << endl;
    cout << NumberOfEnrolled_Classes << " Classes Taken This Semester" << endl;
    cout << endl;
    cout << "Current GPA is " << GPA << endl;
}
void Student::SetALL(string ID, string first, string last, float gpa, int classes)
{
    Student_ID = ID;
    Last_NAME = last;
    First_NAME = first;
    GPA = gpa;
    NumberOfEnrolled_Classes = classes;
}
void Student::SetID(string Student_ID_NEW)
{
    Student_ID = Student_ID_NEW;
}
void Student::SetLastName(string LastName)
{
    Last_NAME = LastName;
}
void Student::SetFirstName(string FirstName)
{
    First_NAME = FirstName;
}
void Student::SetGPA(float StudentGPA)
{
    GPA = StudentGPA;
}
void Student::SetClasss(int classes)
{
    NumberOfEnrolled_Classes = classes;
}
/// Function Prototypes.
void DisplayTitle();

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
       cout << setw(55) << "\t\1 CSCI 15 Assignment 5 - Classes \2" << endl;
}
int main()
{
    bool again = true;
    int choice;
    intmax_t ClassEnrolled_StudentID;
    float GradePoint_Average;
    string studentID_main, firstname_main, lastname_main;
    const int max = 10;
    int Current_NumberOfStudents = 6;

    Student student1, student2, student3, student4, student5, student6;

    /// Create six class members.
    student1.SetALL("AF101", "Smith", "Zachery H.", 3.2, 4);
    student2.SetALL("HJ389", "Jones", "Alias T.", 3.3, 2);
    student3.SetALL("KL209", "Luzer", "Emma P.", 4.0, 4);
    student4.SetALL("LL309", "De Mann", "Stan D.", 3.5, 3);
    student5.SetALL("ZZ009", "Wilkins II", "Jonathan B.", 2.5, 2);
    student6.SetALL("NM210", "Williams", "Judith G", 3.0, 4);

    Student student_Array[max] = {student1,
                                  student2,
                                  student3,
                                  student4,
                                  student5,
                                  student6};

    string change_inputID;
    string change_lastname;
    string change_firstname;
    float change_GPA;
    int change_NumberOfEnrolledClasses;
    int change_choice_Option;

    while(again)
    {
        DisplayTitle();
        cout << "\n\n";
        cout << "(1.) - Display ALL Records " << endl;
        cout << endl;
        cout << "(2.) - Add a New Record to the Maximum of " << Current_NumberOfStudents << " Records" << endl;
        cout << endl;
        cout << "(3.) - Change an Existing Record's Fields" << endl;
        cout << endl;
        cout << "(4.) - Find One Record" << endl;
        cout << endl;
        cout << "(5.) - Quit" << endl;
        cout << endl;
        cout << "Enter your choice from (1 - 5): ";
        cin >> choice;

        choice = abs(choice);

        cout << "\n\n";
        system("PAUSE");
        system("CLS");

        switch (choice)
        {
            case 1:
                    cout << endl;
                    cout << "Displaying the students' data:" << endl;
                    cout << endl;

                    for(int count = 0; count <= Current_NumberOfStudents - 1; count++)
                    {
                        cout << endl;
                        student_Array[count].DisplayStudent();
                        cout << "\n\n";
                        cout << "==============================================================================" << endl;
                        cout << endl;
                    }
                    system("PAUSE");
                    system("CLS");
                break;

            case 2:

                  if(Current_NumberOfStudents >= max)
                  {
                      cout << "Sorry! The Maximum number of Employees you can enter is up to 10." << endl;
                      cout << endl;
                      system("PAUSE");
                      system("CLS");
                      break;
                  }
                  Current_NumberOfStudents++;
                  cout << "Adding a New Record to the File: " << endl;
                  cout << "\n\n";
                  cout << "Record #" << Current_NumberOfStudents << " of " << max << endl;
                  cout << endl;

                  cin.ignore();

                  cout << "(1 of 5) - Enter Student ID: ";
                  getline(cin, studentID_main);
                  cout << endl;

                  cout << "(2 of 5) - Enter Student Last Name: ";
                  getline(cin, lastname_main);
                  cout << endl;

                  cout << "(3 of 5) - Enter Student First Name: ";
                  getline(cin, firstname_main);
                  cout << endl;

                  cout << "(4 of 5) - Enter Student Grade Point Average: ";
                  cin >> GradePoint_Average;
                  cout << endl;

                  cout << "(5 of 5) - Enter Number of Class Enrolled for Student ID " << studentID_main << ": ";
                  cin >> ClassEnrolled_StudentID;
                  cout << "\n\n";

                  system("PAUSE");
                  system("CLS");

                  student_Array[Current_NumberOfStudents - 1].SetALL(studentID_main, firstname_main,
                                                                     lastname_main, GradePoint_Average,
                                                                     ClassEnrolled_StudentID);
                break;

            case 3:

                int Input_INDEX;
                Input_INDEX = -1;

                int changing_field_record;

                cout << "\t\tChange an Existing Record's Fields" << endl;
                cout << "\n\n";

                while (Input_INDEX < 0 || Input_INDEX > Current_NumberOfStudents - 1)
                {
                    cout << "Enter an Index (0 to " << Current_NumberOfStudents - 1 << "): ";
                    cin >> Input_INDEX;
                    cout << "\n\n";
                }
                cout << "\n\n";
                student_Array[Input_INDEX].DisplayStudent();
                cout << "\n\n";
                cout << "===================================================================" << endl;
                cout << "\n\n";
                cout << "Change A Field Value:" << endl;
                cout << "\n\n";
                cout << "1 - Student ID" << endl;
                cout << endl;
                cout << "2 - Student Last Name" << endl;
                cout << endl;
                cout << "3 - Student First Name" << endl;
                cout << endl;
                cout << "4 - Student GPA" << endl;
                cout << endl;
                cout << "5 - Number of Enrolled Classes" << endl;
                cout << "\n\n";
                cout << "Enter your choice (1 to 5): ";
                cin >> change_choice_Option;
                cout << "\n\n\n";

                change_choice_Option = abs(change_choice_Option);

                cout << "\n\n";
                system("PAUSE");
                system("CLS");

                        switch (change_choice_Option)
                        {
                            case 1:
                                    cin.ignore();

                                    cout << "Enter Student ID: ";
                                    getline(cin, change_inputID);
                                    student_Array[Input_INDEX].SetID(change_inputID);
                                    cout << "\n\n";
                                    system("PAUSE");
                                    system("CLS");

                                    break;

                            case 2:
                                    cin.ignore();

                                    cout << "Enter Last Name: ";
                                    getline(cin, change_lastname);
                                    student_Array[Input_INDEX].SetLastName(change_lastname);
                                    cout << "\n\n";
                                    system("PAUSE");
                                    system("CLS");

                                    break;

                            case 3:
                                    cin.ignore();

                                    cout << "Enter First Name: ";
                                    getline(cin, change_firstname);
                                    student_Array[Input_INDEX].SetFirstName(change_firstname);
                                    cout << "\n\n";
                                    system("PAUSE");
                                    system("CLS");

                                    break;

                            case 4:
                                    cout << "Enter GPA: ";
                                    cin >> change_GPA;
                                    student_Array[Input_INDEX].SetGPA(change_GPA);
                                    cout << "\n\n";
                                    system("PAUSE");
                                    system("CLS");

                                    break;

                            case 5:
                                    cout << "Enter Number of Class Enrolled: ";
                                    cin >> change_NumberOfEnrolledClasses;
                                    student_Array[Input_INDEX].SetClasss(change_NumberOfEnrolledClasses);
                                    cout << "\n\n";
                                    system("PAUSE");
                                    system("CLS");

                                    break;

                            default:
                                    cout << "Sorry! Please select a menu from 1 to 5. " << endl;
                                    cout << "\n\n";
                                    system("PAUSE");
                                    system("CLS");
                        }
                break;

            case 4:
                    cout << "\2 Find One Record: ";
                    cout << "\n\n";

                    cout << "Enter an Index (0 to " << Current_NumberOfStudents - 1 << "): ";
                    cin >> Input_INDEX;
                    cout << "\n\n";

                    while (Input_INDEX < 0 || Input_INDEX > Current_NumberOfStudents - 1)
                    {
                        cout << "Enter an Index (0 to " << Current_NumberOfStudents - 1 << "): ";
                        cin >> Input_INDEX;
                        cout << "\n\n";
                    }

                    student_Array[Input_INDEX].DisplayStudent();
                    cout << "\n\n";
                    system("PAUSE");
                    system("CLS");

                    break;

            case 5:
                    again = false;
                    cout << "Good Bye!" << endl;
                    break;

            default:
                     cout << "Sorry! Please select an option on the MENU from 1 to 5." << endl;
                     cout << "\n\n";
                     system("PAUSE");
                     system("CLS");
        }
    }
    return 0;
}

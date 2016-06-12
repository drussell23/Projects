/**
    Derek J. Russell
    Professor Desmond Chun
    CSCI 15 Assignment 2
    Due - February 24th, 2016
    Accessing Arrays via Pointers ("Shadow Array")
    February 12th, 2016
**/
/// Sort Array via Pointers
#include <iostream> /// cout << "Hello World!" << endl;
#include <stdlib.h> /// system("CLS");
#include <iomanip> /// cout.precision(2); cout.setf(ios::fixed);
#include <conio.h> /// getch();
#include <time.h> /// time_t - time(&CurrentTime); /// This gets the current time.
#include <algorithm> /// swap
using namespace std;

/// Function Prototypes
void Description_Of_The_Program(time_t CurrentTime,  struct tm *localTime);
void swap(int * x, int * y);
void SelectionSort_AscendingOrder(int * array[], int size); /// Ascending Order Function Sort.
void SelectionSort_DescendingOrder(int * array[], int size); /// Descending Order Function Sort.
  /// Created two additional arrays of pointers, aim the array index pointers to the integer array.
    /**
      * int *FirstArray_Pointer[ArraySize];
      * Pass the array of pointers to a sort function to "sort ascending order" the pointer
      * values based on the value that these pointers are "pointing" to in the "numbers" array.
      * The pointer values will be swapped within the pointer array.
      ==========================================================================================
      * int *SecondArray_Pointer[ArraySize];
      * Pass the second array of pointers to a function to "sort descending order" the pointer
      * values based on the value that these pointers are "pointing" to the "numbers" array.
      * The pointer values will be swapped within the pointer array.
      ==========================================================================================
    **/
void Description_Of_The_Program()
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

    cout << "Name: Derek J. Russell\t\t\t\t" << "\t\t" << "Date: " << Month << "-" << Day << "-" << Year << endl;
    cout << "\n\n";
    cout << setw(76) << "\2 CSCI 15 Assignment 2 - Accessing Arrays via Pointers ('shadow array') \1" << endl;
    cout << "\n\n";
    cout << "\5 Created 2 additional arrays of pointers, aim the array index pointers" << endl;
    cout << endl;
    cout << "   to the integer array." << endl;
    cout << "\n\n";
    cout << "\t\5 int * FirstArray_Pointer[ArraySize];" << endl;
    cout << endl << endl;
    cout << "\5 Pass the array of pointers to a sort function to 'sort ascending order' " << endl;
    cout << endl;
    cout << "   the pointer." << endl;
    cout << endl << endl;
    cout << "\5 Values based on the value that these pointers are 'pointing' to in the" << endl;
    cout << endl;
    cout << "  'numbers' array." << endl;
    cout << endl << endl;
    cout << "\5 The pointer values will be swapped within the pointer array." << endl;
    cout << "\n\n";
    cout << "\t\5 int * SecondArray_Pointer[ArraySize];" << endl;
    cout << endl << endl;
    cout << "\5 Pass the second array of pointers to a function to 'sort descending order'" << endl;
    cout << endl;
    cout << "  the pointer. Values based on the value that these pointers are" << endl;
    cout << endl;
    cout << " 'pointing' to the 'numbers' array." << endl;
    cout << endl << endl;
    cout << "\5 The pointer values will be swapped within the pointer array." << endl;
    cout << "\n\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
/// Swap values at memory locations to which x and y "point".
/**

**/
void swap(int * x, int * y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
///Function to sort the Array (Ascending Order)
void SelectionSort_AscendingOrder(int * array[], int size)
{
    int smallest; /// Index of smallest element
    for(int a = 0; a < size - 1; a++)
    {
        smallest = a; /// First index of remaining array.
        /// loop to find index of largest element
        for(int index = a + 1; index < size; index++)
            if( *array[index] < *array[a] )
        {
            int *temp = array[a];
            array[a] = array[index];
            array[index] = temp;
        }
    }
}
/// Function to sort the Array (Descending Order)
void SelectionSort_DescendingOrder(int * array[], int size)
{
    int largest; /// index of smallest element
    for(int count = 0; count < size - 1; count++)
    {
         /// First index of remaining array
        /// Loop to find index of largest element
        for(int index = count + 1; index < size; index++)
        {
            if(*array[index] > *array[count])
            {

                int  *temp = array[count];
                array[count] = array[index];
                array[index] = temp;
            }
        }
    }
}
/// Heart of the Program -> int main()
int main()
{
    const int ArraySize = 15;
    int numbers[ArraySize];
    char again = 'y';

    /// Created two additional arrays of pointers, aim the array index pointers to the integer array.
    /**
      * int *FirstArray_Pointer[ArraySize];
      * Pass the array of pointers to a sort function to "sort ascending order" the pointer
      * values based on the value that these pointers are "pointing" to in the "numbers" array.
      * The pointer values will be swapped within the pointer array.
      ==========================================================================================
      * int *SecondArray_Pointer[ArraySize];
      * Pass the second array of pointers to a function to "sort descending order" the pointer
      * values based on the value that these pointers are "pointing" to the "numbers" array.
      * The pointer values will be swapped within the pointer array.
      ==========================================================================================
    **/
    int *FirstArray_Pointer[ArraySize];
    int *SecondArray_Pointer[ArraySize];

        /// Scramble the pseudo random number seed.

                srand( (unsigned) time (NULL) ); /// Generating Random Numbers.

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

        while(again == 'y')
        {
            Description_Of_The_Program(); /// Overview of the program.
            cout << "Name: Derek J. Russell\t\t\t\t" << "\t\t" << "Date: " << Month << "-" << Day << "-" << Year << endl;
            cout << "\n\n";
            cout << setw(76) << "\2 CSCI 15 Assignment 2 - Accessing Arrays via Pointers ('shadow array') \1" << endl;
            cout << "\n\n";
            /// Initialize the Array with random numbers 1 to 100.
            /// Displaying the contents of the Array.
            cout << "Display the contents of the Array:" << endl;

                for(int j = 0; j < 10; j++)
                {
                    numbers[j] = rand() % 100 + 1; /// The Array has been initialize for random numbers from 1 to 100.
                    cout << "\n\tIndex # " << j + 1 << "\t" << numbers[j] << endl;
                }

            cout << "\n\n";

            /// Loading Memory Addresses for each array index.
                for(int j = 0; j < ArraySize; j++)
                {
                    FirstArray_Pointer[j] = &numbers[j];
                    SecondArray_Pointer[j] = &numbers[j];
                }
            cout << "Display the contents of the Array via the 'shadow' pointer Array I:" << endl;

                for(int k = 0; k < 10; k++)
                {
                    cout << "\nString # " << k << "\t" << *FirstArray_Pointer[k] << "\t\t@ Memory Location " << FirstArray_Pointer[k] << endl;
                }

            cout << "\n\n\n";
            cout << "Sorting the shadow pointer array in the function (Ascending Order)." << endl;
            cout << "\n\n";
            cout << "Display the Sorted Ascending contents of the Array" << endl;
            cout << endl;
            cout << "via the 'shadow' pointer Array I:" << endl;
            cout << endl;

            /// Calling the SelectionSort_AscendingOrder(numbers, ArraySize); -> Function.
           SelectionSort_AscendingOrder(FirstArray_Pointer, 10); /// Sorting the array Ascending.
            ///SelectionSort_AscendingOrder(numbers, ArraySize);
            for(int A = 0; A < 10; A++)
            {
                cout << "\nIndex #" << A << "\t" << *FirstArray_Pointer[A] << "\t\t@ Memory Location " << FirstArray_Pointer[A] << endl;
            }

            cout << "\n\n\n";
            cout << "Sorting the shadow pointer array in the function (Descending)." << endl;
            cout << "\n\n";
            cout << "Display the Sorted Descending contents of the Array" << endl;
            cout << endl;
            cout << "via the 'shadow' pointer Array II:" << endl;
            cout << endl;

                        ///    SecondArray_Pointer = numbers;

            /// Calling the  SelectionSort_DescendingOrder(numbers, ArraySize); -> Function.
            SelectionSort_DescendingOrder(SecondArray_Pointer, 10); /// Sorting the array Descending.

                for (int D = 0; D < 10; D++)
                {
                    cout << "\nIndex #" << D << "\t" << *SecondArray_Pointer[D] << "\t\t@ Memory Location " << SecondArray_Pointer[D] << endl;
                }

            cout << "\n\n";
            cout << "Display the contents of the Array:" << endl;

                for(int j = 0; j < 10; j++)
                {
                    cout << "\n\tIndex # " << j + 1 << "\t" << numbers[j] << endl;
                }

            cout << "\n\n";
            cout << "Run this Again (Y or N): ";
            cin >> again;
            again = tolower(again); /// If the user puts in a lowercase letter.
            system("CLS");
        }
        return EXIT_SUCCESS;
}

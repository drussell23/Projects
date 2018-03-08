/**
    Derek J. Russell
    Professor Jonathan Traugott
    LetterBag - (Assignment 1)
    CSCI 20 - Data Structures C++ - Spring 2018
    Chabot Community College
    Date: February 1st, 2018
    ===========================================
**/
/**
                                LETTERBAG ASSGINMENT 1 - OUTLINE INSTRUCTIONS
                                =============================================
                      ----------------------------------------------------------------
                    * Implement a LetterBag.cpp for the attached LetterBag.h.
                      Also write a driver that creates LetterBag objects using each of
                      the constructors and and calls each of the member functions at
                      least once.
                      ----------------------------------------------------------------
                      ----------------------------------------------------------------

#ifndef LETTERBAG_H
#define LETTERBAG_H

#include <vector>
#include <iostream>
using namespace std;

class LetterBag {
public:
LetterBag() ;  // no-parameter constructor for an empty LetterBag.

// initialize counts using letters in v, omitting non letters.
// e.g.  v = {'6','A','b','C','a','G','g','G','g','B','b','%','g'}
// means counts = {2,3,1,0,0,0,5,...} and size = 10.
LetterBag(const vector<char> & v);

// similar to the vector constructor but using a string to initialize.
LetterBag(const string & s);

// return this->size
int getCurrentSize() const;  // return the current size of the LetterBag

// return true iff this->size is zero
bool isEmpty() const;

// insert ch into a copy of the current object and return the copy.
// if ch is out of range, do nothing.
LetterBag operator+(char ch) const;

// insert ch into the current object and return the current object
// if ch is out of range, do nothing.
LetterBag & operator+=(char ch);

// add the contents of other to a copy of the current object and return the copy.
LetterBag operator+(const LetterBag & other) const;

// add the contents of other  the current object and return the current object.
LetterBag & operator+=(const LetterBag & other);

// remove one occurrence of ch from a copy of the current object and return the copy.
// if ch is out of range or has count equal to zero do nothing.
LetterBag operator-(char ch) const;

// remove one occurrence of ch from the current object and return the current object.
// if ch is out of range or has count equal to zero do nothing.
LetterBag & operator-=(char ch);

// remove the contents of other from a copy of the current object and return the copy.
// note: anytime the count of a letter in other exceeds the count in this, set count to zero.
// size should be changed appropriately.
LetterBag operator-(const LetterBag & other) const;

// remove the contents of other from  the current object and return the current object.
// You can do this cone by calling operator-.
LetterBag & operator-=(const LetterBag & other);

// remove all occurence occurrence of ch from the current object.
// if ch is out of range or has count equal to zero do nothing.
void removeAll(char ch);

// remove all occurrences of all letters from the current object and set size to zero.
void clear();

// return the number of occurence of ch in the current object.
int getFrequency(char c) const;

// return a vector with the letters in this object, in sorted order and lowercase.
vector<char> toVector() const;

// return a string with the letters in this object, in sorted order and lowercase.
string toString() const;

// return true if the current object is a proper subbag of other.
bool operator<(const LetterBag & other) const;

// return true if the current object is a subbag of other and false otherwise.
bool operator<=(const LetterBag & other) const;

// return true if the other is a proper subbag of the current object and false otherwise.
// note proper subbag means it's a subbag but not equal to the other bag.
bool operator>(const LetterBag & other) const;

// return true if the other is a subbag of the current object.
bool operator>=(const LetterBag & other) const;

// return true iff the current object and other are equal.
bool operator==(const LetterBag & other) const;

// return false iff the current object and other are equal.
bool operator!=(const LetterBag & other) const;

private:

int counts[26];  // counts[0] represents the number of 'a's etc.

// return true iff ch is in range 'a'...'z' or 'A'...'Z'
static bool inRange(char ch);

int size; // total number of letters in the current object (equals the sum of the counts array)
};

#endif

**/

#include "LetterBag.h"
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

    /**
        - Declared Global Functions Outside Of The Functions Including Main.
    **/

    char ch = 'a';
    LetterBag bag_1, bag_2;

	vector<char> vec_1 = bag_1.toVector();
	vector<char> vec_2 = bag_2.toVector();

void Print_LetterBag(const LetterBag &bag_1)
{
	int Frequency;

    //cout << "The quantity of letters that contain in each alphabet." << endl;
    //cout << "------------------------------------------------------" << endl;
	for (char ch = 'a'; ch <= 'z'; ch++)
	{
		Frequency = bag_1.getFrequency(ch);
		if (Frequency > 0)
		{
			cout << ch << " : " << Frequency << endl;
		}
	}
	cout << endl;

	return;
}
void Printing_Vector()
{
	//cout << "Adding characters now...\n";

	bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

	cout << "Printing Vector" << endl;
	cout << "-----------------------------  ----------------" << endl;
	cout << "Current size: " << bag_1.getCurrentSize() << endl;

	for (unsigned int i = 0; i < vec_1.size(); i++)
	{
		cout << vec_1[i] << " ";
	}
    cout << endl;
	Print_LetterBag(bag_1);
	cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void getCurrentSize()
{
	cout << "Printing Current Size" << endl;
	cout << "-----------------------------  ----------------" << endl;
	cout << "Current size for Bag 1: " << bag_1.getCurrentSize() << endl;
	cout << "Current size for Bag 2: " << bag_2.getCurrentSize() << endl;
	cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void Testing_Equal_and_NotEqual()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

    cout << "-----------------------------  ----------------\n";
	cout << "Testing == and !=\n" << endl;

	vec_1 = bag_1.toVector();
	vec_2 = bag_2.toVector();

	cout << "Bag 1:" << endl;

	for (unsigned int i = 0; i < vec_1.size(); i++)
	{
		cout << vec_1[i] << " ";
	}

	cout << endl;
	Print_LetterBag(bag_1);
	cout << endl;

	cout << "Bag 2:" << endl;
	for (unsigned int i = 0; i < vec_2.size(); i++)
	{
		cout << vec_2[i] << " ";
	}
	cout << endl;
	Print_LetterBag(bag_2);
	cout << endl;

	if (bag_1 == bag_2)
		cout << "Bag 1 and Bag 2 are same\n" << endl;
	else
		cout << "Bag 1 and Bag 2 are not the same\n" << endl;

	if (bag_1.is_Subbag(bag_2))
		cout << "Bag2 is Subbag of Bag 1\n" << endl;
	else
		cout << "Bag2 is not Subbag of Bag 1\n" << endl;

	cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void Removing_h_and_adding_a()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

    cout << "-----------------------------  ----------------\n";
	cout << "Removing h and adding a\n" << endl;

	bag_2.removeAll('h');
	bag_2.Add('a');

	vec_1 = bag_1.toVector();
	vec_2 = bag_2.toVector();

	cout << "Bag 1:" << endl;
	for (unsigned int i = 0; i < vec_1.size(); i++)
	{
		cout << vec_1[i] << " ";
	}
	cout << endl;
	Print_LetterBag(bag_1);
	cout << endl;

	cout << "Bag 2:" << endl;
	for (unsigned int i = 0; i < vec_2.size(); i++)
	{
		cout << vec_2[i] << " ";
	}
	cout << endl;
	Print_LetterBag(bag_2);
	cout << endl;

	if (bag_1 == bag_2)
		cout << "Bag1 and Bag2 are same" << endl << endl;
	else
		cout << "Bag1 and Bag2 are not the same" << endl << endl;

	if (bag_1.is_Subbag(bag_2))
		cout << "Bag2 is Subbag of Bag 1" << endl;
	else
		cout << "Bag2 is not Subbag of Bag 1" << endl;

    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void Removed_a_from_Bag1()
{
	bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

	cout << "-----------------------------  ----------------\n";
	bag_1.removeAll('a');
	cout << "Removed a from Bag1\n";
	cout << "Current size: " << bag_1.getCurrentSize() << '\n' << endl;

	vec_1 = bag_1.toVector();
	for (unsigned int i = 0; i < vec_1.size(); i++)
	{
		cout << vec_1[i] << " ";
	}
	cout << endl;
	Print_LetterBag(bag_1);
	cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void isEmpty()
{
	bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

	cout << "Bag 1 is set to clear:" << endl << endl;
	bag_1.clear();
	cout << "Bag 1 is Now: " << (bag_1.isEmpty() ? "Empty" : "NOT EMPTY") << endl;
	cout << "Printing Bag 1 to Ensure it's Empty." << endl;
	//Print_LetterBag(bag_1);
	cout << "----------------------------------------------" << endl;
	cout << "Bag 2 is set to clear:" << endl << endl;
	bag_2.clear();
	cout << "Bag 2 is Now: " << (bag_2.isEmpty() ? "Empty" : "NOT EMPTY") << endl;
	cout << "Printing Bag 2 to Ensure it's Empty." << endl;
	//Print_LetterBag(bag_2);
	cout << "----------------------------------------------" << endl;
	cout << "\n\n";
    system("PAUSE");
    system("CLS");

	return;
}
void operator_plus_char_ch()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

    cout << "This is Bag 1:  " << bag_1 << endl;
    cout << endl;
    cout << "This is Bag 2: " << bag_2 << endl;
    cout << "---------------------------------------" << endl;
    cout << "Original Bag 1 content: " << flush << bag_1 << endl << endl;
    cout << "Original Bag 2 content: " << flush << bag_2 << endl;
    cout << "---------------------------------------" << endl;
    cout << "Operator addition (+) over-loader Adding the CHAR for Bag 1: " << bag_1 + ch << endl;
    cout << endl;
    cout << "Operator addition (+) over-loader Adding the CHAR for Bag 2: " << bag_2 + ch << endl;
    cout << "---------------------------------------" << endl;
    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void operator_PlusEqual_char_ch()
{
	bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

    cout << "Original Bag content: " << flush << bag_1 << endl << endl;

    cout << "Operator addition (+=) over-loader adding CHAR: " << endl << endl;
    bag_1+=ch;

    cout << "RESULT (+=): " << flush << bag_1 << endl << endl;
    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void operator_plus_LetterBag_other()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

    Print_LetterBag(bag_1);

    // This does not make changes to bag_1, only returns a copy of the answer.
    cout << "This is Bag 1:  " << bag_1  << endl;
    cout << endl;
    cout << "This is Bag 2: " << bag_2 << endl;
    cout << "---------------------------------------" << endl;
    cout << "Adding Bag 1 + Bag 2: " << bag_1 + bag_2 << endl;
    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void operator_PlusEqual_LetterBag_other()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

    Print_LetterBag(bag_1);

    cout << "This is Bag 1:  " << bag_1 << endl;
    cout << endl;
    cout << "This is Bag 2: " << bag_2 << endl;
    cout << "---------------------------------------" << endl;
    // Now making changes to bag_1
    bag_1 += bag_2;
    cout << "Adding Bag 1 += Bag 2: " << bag_1 << endl;
    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void operator_minus_char_ch()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

    cout << "This is Bag 1: " << bag_1 << endl;
    cout << endl;
    cout << "This is Bag 2: " << bag_2 << endl;
    cout << "---------------------------------------" << endl;
    cout << "Original Bag 1 content: " << flush << bag_1 << endl << endl;
    cout << "Original Bag 2 content: " << flush << bag_2 << endl;
    cout << "---------------------------------------" << endl;
    cout << "Operator minus (-) over-loader Minus the CHAR for Bag 1: " << bag_1 - ch << endl;
    cout << endl;
    cout << "Operator minus (-) over-loader Minus the CHAR for Bag 2: " << bag_2 - ch << endl;
    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void operator_MinusEqual_char_ch()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

    cout << "Original Bag content: " << flush << bag_1 << endl << endl;

    cout << "Operator minus (-=) over-loader minus the CHAR for Bag 1: " << endl;

    bag_1-=ch;

    cout << "RESULT for Bag 1 (-=): " << flush << bag_1 << endl << endl;

    cout << "----------------------------------------------------------" << endl;

    cout << "Operator minus (-=) over-loader minus the CHAR for Bag 1: " << endl;

    bag_2-=ch;

    cout << "RESULT for Bag 2 (-=): " << flush << bag_2 << endl << endl;
    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void operator_minus_LetterBag_other()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

    Print_LetterBag(bag_1);

    // This does not make changes to bag_1, only returns a copy of the answer.
    cout << "This is Bag 1:  " << bag_1  << endl;
    cout << endl;
    cout << "This is Bag 2: " << bag_2 << endl;
    cout << "---------------------------------------" << endl;
    cout << "Adding Bag 1 + Bag 2: " << bag_1 - bag_2 << endl;
    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void operator_MinusEqual_LetterBag_other()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

    Print_LetterBag(bag_1);

    cout << "This is Bag 1:  " << bag_1 << endl;
    cout << endl;
    cout << "This is Bag 2: " << bag_2 << endl;
    cout << "---------------------------------------" << endl;
    // Now making changes to bag_1
    bag_1 -= bag_2;
    cout << "Adding Bag 1 += Bag 2: " << bag_1 << endl;
    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void removeAll()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

    cout << "This is Bag 1:  " << bag_1 << endl;
    cout << endl;
    cout << "This is Bag 2: " << bag_2 << endl << endl;
    cout << "---------------------------------------" << endl;
    cout << "Removing 'a' from Bag 1: " << bag_1.removeAll('a') << endl;
    cout << "Removing 'a' from Bag 2: " << bag_2.removeAll('a') << endl;
    cout << "---------------------------------------" << endl;
    cout << "Removing 'b' from Bag 1: " << bag_1.removeAll('b') << endl;
    cout << "Removing 'b' from Bag 2: " << bag_2.removeAll('b') << endl;
    cout << "---------------------------------------" << endl;
    cout << "Removing 'c' from Bag 1: " << bag_1.removeAll('c') << endl;
    cout << "Removing 'c' from Bag 2: " << bag_2.removeAll('c') << endl;
    cout << "---------------------------------------" << endl;
    cout << "Removing 'c' from Bag 1: " << bag_1.removeAll('c') << endl;
    cout << "Removing 'h' from Bag 2: " << bag_2.removeAll('h') << endl;
    cout << "---------------------------------------" << endl;
    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void clear()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

	cout << "===============================================" << endl;
	cout << "Bag 1 is set to clear:" << endl << endl;
	bag_1.clear();
	cout << "Bag 1 is Now: " << (bag_1.isEmpty() ? "Empty" : "NOT EMPTY") << endl;
	cout << endl;
	cout << "Printing Bag1 to Ensure it's Empty." << endl;
	Print_LetterBag(bag_1);
    cout << "-----------------------------------------------" << endl;
	cout << "Bag 2 is set to clear:" << endl << endl;
	bag_2.clear();
	cout << "Bag 2 is Now: " << (bag_2.isEmpty() ? "Empty" : "NOT EMPTY") << endl;
	cout << endl;
	cout << "Printing Bag 2 to Ensure it's Empty." << endl;
	Print_LetterBag(bag_1);
    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void getFrequency()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

    cout << "This is Bag 1:  " << bag_1 << endl;
    cout << endl;
    cout << "This is Bag 2: " << bag_2 << endl << endl;
    cout << "===============================================" << endl;
    cout << "Getting the Frequency for letters inside Bag 1:" << endl;
    cout << "The Frequency for letter 'a' in Bag 1: " << bag_1.getFrequency('a') << endl;
    cout << "The Frequency for letter 'a' in Bag 1: " << bag_1.getFrequency('a') << endl;
    cout << "The Frequency for letter 'b' in Bag 1: " << bag_1.getFrequency('b') << endl;
    cout << "The Frequency for letter 'c' in Bag 1: " << bag_1.getFrequency('c') << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Getting the Frequency for letters inside Bag 2:" << endl;
    cout << "The Frequency for letter 'a' in Bag 2: " << bag_2.getFrequency('a') << endl;
    cout << "The Frequency for letter 'b' in Bag 2: " << bag_2.getFrequency('b') << endl;
    cout << "The Frequency for letter 'c' in Bag 2: " << bag_2.getFrequency('c') << endl;
    cout << "The Frequency for letter 'h' in Bag 2: " << bag_2.getFrequency('h') << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}

void toVector()
{
    cout << "Adding characters now..." << endl << endl;

	bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('h').Add('c').Add('a');

	cout << "Printing Vector" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Current size: " << bag_1.getCurrentSize() << endl;

	for (unsigned int i = 0; i < vec_1.size(); i++)
	{
		cout << vec_1[i] << " ";
	}
    cout << endl;
	Print_LetterBag(bag_1);
	cout << endl;

    for(unsigned int j = 0; j < vec_2.size(); j++)
    {
        cout << vec_2[j] << " ";
    }
    cout << endl;
    Print_LetterBag(bag_2);
    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void toString()
{
   bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
   bag_2.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');

   Print_LetterBag(bag_1);
   cout << "--------------------------------" << endl;

   cout << "String - This is Bag 1: " << bag_1.toString() << endl;
   cout << endl;
   cout << "String - This is Bag 2: " << bag_2.toString() << endl;
   cout << "\n\n";
   cout << "\n\n";
   system("PAUSE");
   system("CLS");

   return;
}
void operator_less_than_LetterBag_other()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');

    Print_LetterBag(bag_1);
    //this does not make changes to bag_1, only returns a copy of the answer
    cout << "--------------------------------------------------" << endl;
    cout << "For Operator (<)" << endl;
    cout << endl;
    if(bag_1 < bag_2)
    {
        cout << "Yes, Bag 1 is a proper subbag of Bag 2." << endl;
    }
    else
    {
        cout << "No, Bag 1 is not a proper subbag of Bag 2." << endl;
    }
    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void operator_less_than_equal_LetterBag_other()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');

    Print_LetterBag(bag_1);
    cout << "--------------------------------------------------" << endl;
    cout << "For Operator (<=)" << endl;
    cout << endl;
    if (bag_1 <= bag_2)
    {
        cout << "Yes, Bag 1 is a subbag of Bag 2." << endl;
    }
    else
    {
        cout << "Bag 1 is not a subbag of Bag 2." << endl;
    }
    cout << "--------------------------------------------------" << endl;
    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void operator_greater_than_LetterBag_other()
{
    cout << "--------------------------------------------------" << endl;
    cout << "Operator (>)" << endl;
    cout << endl;
    if(bag_1 > bag_2)
    {
        cout << "Yes, Bag 2 is a proper subbag of  Bag 1" << endl;
    }
    else
    {
        cout << "No, Bag 2 is not a proper subbag of Bag 2" << endl;
    }
    cout << "--------------------------------------------------" << endl;
    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void operator_greater_than_equal_LetterBag_other()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');

    Print_LetterBag(bag_1);
    cout << "--------------------------------------------------" << endl;
    cout << "Operator (>=)" << endl;
    cout << endl;
    if(bag_1 >= bag_2)
    {
        cout << "Yes, Bag 2 is a SubBag of  Bag 1." << endl;
    }
    else
    {
        cout << "No, Bag 2 is not a SubBag of Bag 1." << endl;
    }
    cout << "--------------------------------------------------" << endl;
    cout << "\n\n";
    system("PAUSE");
    system("CLS");

    return;
}
void operator_equal_LetterBag_other()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');

    Print_LetterBag(bag_1);
    cout << "--------------------------------------------------" << endl;
    cout << "Operator (==)" << endl;
    cout << endl;
    if(bag_1 == bag_2)
    {
        cout << "Yes, Bag 1 is equal to Bag 2." << endl;
    }
    else
    {
        cout << "No, Bag is not equal to Bag 2." << endl;
    }
    cout << "--------------------------------------------------" << endl;
    cout << "\n\n";
    system("PAUSE");
    system("CLS");
    return;
}
void operator_NOT_equal_LetterBag_other()
{
    bag_1.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');
	bag_2.Add('b').Add('a').Add('c').Add('b').Add('a').Add('c').Add('a');

    Print_LetterBag(bag_1);
    cout << "--------------------------------------------------" << endl;
    cout << "Operator (!=)" << endl;
    cout << endl;
    if(bag_1 != bag_2)
    {
        cout << "Yes, Bag 1 is NOT equal to Bag 2." << endl;
        cout << endl;
    }
    else
    {
        cout << "No, Bag 1 is equal to Bag 2." << endl;
        cout << endl;
    }
    cout << "--------------------------------------------------" << endl;
    cout << "\n\n";
    system("PAUSE");
    system("CLS");
    return;
}
void SHOW_EVERYTHING()
{
    getCurrentSize();
    isEmpty();
    operator_plus_char_ch();
    operator_PlusEqual_char_ch();
    operator_plus_LetterBag_other();
    operator_PlusEqual_LetterBag_other();
    operator_minus_char_ch();
    operator_MinusEqual_char_ch();
    operator_minus_LetterBag_other();
    operator_MinusEqual_LetterBag_other();
    removeAll();
    clear();
    getFrequency();
    toVector();
    toString();
    operator_less_than_LetterBag_other();
    operator_less_than_equal_LetterBag_other();
    operator_greater_than_LetterBag_other();
    operator_greater_than_equal_LetterBag_other();
    operator_equal_LetterBag_other();
    operator_NOT_equal_LetterBag_other();
    Testing_Equal_and_NotEqual();
    cout << "\n\n";
    system("PAUSE");
    system("CLS");
    return;
}
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
    cout << setw(55) << "\t\1 CSCI 20 - LetterBag Driver (Assignment 1) \2" << endl;
    cout << "\n\n";
}
int main()
{
    bool again = true;
    intmax_t choice;

    while (again)
    {
        DisplayTitle();
        cout << "(1.) - LetterBag(const vector<char> & v);" << endl;
        cout << endl;
        cout << "(2.) - int getCurrentSize() const;" << endl;
        cout << endl;
        cout << "(3.) - bool isEmpty() const;" << endl;
        cout << endl;
        cout << "(4.) - LetterBag operator+(char ch) const;" << endl;
        cout << endl;
        cout << "(5.) - LetterBag & operator+=(char ch);" << endl;
        cout << endl;
        cout << "(6.) - LetterBag operator+(const LetterBag & other) const;" << endl;
        cout << endl;
        cout << "(7.) - LetterBag & operator+=(const LetterBag & other);" << endl;
        cout << endl;
        cout << "(8.) - LetterBag operator-(char ch) const;" << endl;
        cout << endl;
        cout << "(9.) - LetterBag & operator-=(char ch);" << endl;
        cout << endl;
        cout << "(10.) - LetterBag operator-(const LetterBag & other) const;" << endl;
        cout << endl;
        cout << "(11.) - LetterBag & operator-=(const LetterBag & other);" << endl;
        cout << endl;
        cout << "(12.) - void removeAll(char ch);" << endl;
        cout << endl;
        cout << "(13.) - void clear();" << endl;
        cout << endl;
        cout << "(14.) - int getFrequency(char c) const; " << endl;
        cout << endl;
        cout << "(15.) - vector<char> toVector() const;" << endl;
        cout << endl;
        cout << "(16.) - string toString()const;" << endl;
        cout << endl;
        cout << "(17.) - bool operator<(const LetterBag & other) const;" << endl;
        cout << endl;
        cout << "(18.) - bool operator<=(const LetterBag & other) const;" << endl;
        cout << endl;
        cout << "(19.) - bool operator>(const LetterBag & other) const;" << endl;
        cout << endl;
        cout << "(20.) - bool operator>=(const LetterBag & other) const;" << endl;
        cout << endl;
        cout << "(21.) - bool operator ==(const LetterBag & other) const;" << endl;
        cout << endl;
        cout << "(22.) - bool operator !=(const LetterBag & other) const;" << endl;
        cout << endl;
        cout << "(23.) - Testing Equal & NOT Equal." << endl;
        cout << endl;
        cout << "(24.) - SHOW ALL THE RESULTS." << endl;
        cout << endl;
        cout << "(25.) - Quit." << endl;
        cout << "\n\n";
        cout << "Enter your choice from (1 to 25.): ";
        cin >> choice;

        choice = abs(choice);

        cout << "\n\n";
        system("PAUSE");
        system("CLS");


                switch(choice)
                {
                    case 1:
                           Printing_Vector();
                            break;

                    case 2:
                           getCurrentSize();
                            break;

                    case 3:
                            isEmpty();
                            break;

                    case 4:
                            operator_plus_char_ch();
                            break;

                    case 5:
                            operator_PlusEqual_char_ch();
                            break;

                    case 6:
                            operator_plus_LetterBag_other();
                            break;

                    case 7:
                            operator_PlusEqual_LetterBag_other();
                            break;

                    case 8:
                            operator_minus_char_ch();
                            break;

                    case 9:
                            operator_MinusEqual_char_ch();
                            break;

                    case 10:
                            operator_minus_LetterBag_other();
                            break;

                    case 11:
                            operator_MinusEqual_LetterBag_other();
                            break;

                    case 12:
                            removeAll();
                            break;

                    case 13:
                            clear();
                            break;

                    case 14:
                            getFrequency();
                            break;

                    case 15:
                            toVector();
                            break;

                    case 16:
                            toString();
                            break;

                    case 17:
                            operator_less_than_LetterBag_other();
                            break;

                    case 18:
                            operator_less_than_equal_LetterBag_other();
                            break;

                    case 19:
                            operator_greater_than_LetterBag_other();
                            break;

                    case 20:
                            operator_greater_than_equal_LetterBag_other();\
                            break;

                    case 21:
                            operator_equal_LetterBag_other();
                            break;

                    case 22:
                            operator_NOT_equal_LetterBag_other();
                            break;

                    case 23:
                            Testing_Equal_and_NotEqual();
                            break;

                    case 24:
                            SHOW_EVERYTHING();
                            break;

                    case 25:
                            cout << "\1 Good BYE! \2" << endl;
                            again = false;
                            cout << "\n\n";
                            system("PAUSE");
                            system("CLS");

                            break;

                    default:
                            cout << "Sorry! Please select an option on the MENU from (1 to 25)." << endl;
                            cout << "\n\n";
                            system("PAUSE");
                            system("CLS");
                }
    }

	return EXIT_SUCCESS;
}

/**
    Derek J. Russell
    Professor Jonathan Traugott
    LetterBag - (Assignment 1)
    CSCI 20 - Data Structures C++ - Spring 2018
    Chabot Community College
    Date: February 1st, 2018
    ===========================================
**/
#include "LetterBag.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;

char LetterBag::toLower(char c)
{
    if( 'a' <= c && c <= 'z' )
        return c + ('a' - 'A');

    return c;
}
LetterBag::LetterBag()
{
    /// No-parameter constructor for an empty LetterBag.
	for (int i = 0; i < 26; i++)
	{
		this->counts[i] = 0;
		this->size = 0;
	}
}
LetterBag::LetterBag(const vector<char> &v)
{
	/**
        - Initialize counts using letter in v, omitting non letters.
        - e.g.  v = {'6','A','b','C','a','G','g','G','g','B','b','%','g'}
        - means counts = {2,3,1,0,0,0,5,...} and size = 10.
	**/
	for (int j = 0; v[j] != '\0'; j++)
	{
		this->Add(v[j]);
	}
}
LetterBag& LetterBag::Add(char c)
{
	if (in_Range(c))
	{
		this->counts[c - 97]++;
		this->size++;
	}
	return *this;
}
LetterBag::LetterBag(const string &s) /// Normal constructor to accept the string and work off of that.
{
    /// Similar to the vector constructor but using a string to initialize.
    for(int j = 0; j < s.length(); j++)
    {
        this->Add(s.at(j));
    }
}
intmax_t LetterBag::getCurrentSize() const
{
	/// return this->size.
	return this->size;
}
bool LetterBag::isEmpty() const
{
	/// return true iff this->size is zero.
	if (this->size == 0)
		return true;
	return false;
}
LetterBag LetterBag::operator+(char ch) const
{
    /// Insert ch into a copy of the current object and return the copy.
    /// if ch is out of range, do nothing.
    LetterBag temp;
    temp = *this;

    if(in_Range(ch))
    {
        temp.counts[tolower(ch) - 'a']++;
		temp.size++;
    }

    return temp;
}
LetterBag & LetterBag::operator+=(char ch)
{
    /// insert ch into the current object and return the current object
    /// if ch is out of range, do nothing.
    if(in_Range(ch))
    {
        this->counts[tolower(ch) - 'a']++;
        this->size++;
    }
    return *this;
}
LetterBag LetterBag::operator+(const LetterBag & other) const
{
    /// add the contents of other to a copy of the
    /// current object and return the copy.
    LetterBag temp;

    for(int j = 0; j < 26; j++)
    {
        temp.counts[j] = this->counts[j] + other.counts[j];

    }
    temp.size = this->size + other.size;

    return temp; /// return temp.
}
LetterBag & LetterBag::operator+=(const LetterBag & other)
{
    /// add the contents of other the current object
    /// and return the current object.
    for(int count = 0; count < 26; count++)
    {
        this->counts[count] += other.counts[count];
    }
    this->size += other.size;

    return *this;
}
LetterBag LetterBag::operator-(char ch) const
{
    /// remove 1 occurrence of ch from a copy of the current object and return the copy.
    /// if ch is out of range or has count equal to zero do nothing.
    LetterBag temp;
    temp = *this;

    if(in_Range(ch))
    {
        if(counts[tolower(ch) - 'a'] > 0)
        {
           temp.counts[tolower(ch) - 'a']--;
           temp.size--;
        }
    }
    return temp;
}
LetterBag & LetterBag::operator-=(char ch)
{
    /// remove 1 occurrence of ch from the current object and return the current object.
    /// if ch is out of range or has count equal to zero do nothing.
    if(in_Range(ch))
    {
        this->counts[tolower(ch) - 'a']--;
        this->size--;
    }
    return *this;
}
LetterBag LetterBag::operator-(const LetterBag & other) const
{
    /// remove the contents of other from a copy of the current object and return the copy.
    /// note: anytime the count of a letter in other exceeds the count in this, set count to zero.
    /// size should be changed appropriately.
    LetterBag temp;
    for(int j = 0; j < 26; j++)
    {
        temp.counts[j] = this->counts[j] - other.counts[j];
    }
    temp.size = this->size - other.size;
    return temp; /// return temp.
}
LetterBag & LetterBag::operator-=(const LetterBag & other)
{
    /// remove the contents of other from  the current object and return the current object.
    /// You can do this cone by calling operator-.
    for(int j = 0; j < 26; j++)
    {
        intmax_t toSubtract = other.counts[j];  /// the number of copies to subtract
        if (toSubtract > this->counts[j])
            toSubtract = this->counts[j];  /// except if it's bigger than this->counts[j]
                                           /// in that case we just want to subtract this->counts[j]
        this->counts[j] -= toSubtract;
        this->size -= toSubtract;
    }
    return *this;
}
LetterBag& LetterBag::removeAll(char ch)
{
	/// remove all occurrence of ch from the current object.
	/// if ch is out of range or has count equal to zero do nothing.
	if(this->counts[tolower(ch) - 'a'] > 0)
    {
        this->counts[tolower(ch) - 'a']--;
        this->size--;
    }
	return *this;
}
LetterBag& LetterBag::clear()
{
	/// remove all occurrences of all letters from the current object and set size to zero.
	for (int count = 0; count < 26; count++)
		this->counts[count] = 0;
	this->size = 0;
	return *this;
}

bool LetterBag::in_Range(char c)
{
	if( (c >= 'a' && c <= 'z') || ( c >= 'A' && c <= 'Z') )
        return true;
	return false;
}
intmax_t LetterBag::getFrequency(char c) const
{
	/// return the number of occurrence of ch in the current object.
	return this->counts[c - 97];
}
vector<char> LetterBag::toVector() const
{
	/// return a vector with the letters in this object, in sorted order and lowercase.
	vector<char> Sorted_Temp;

	for (int i = 0; i < 26; i++)
    {
       for (int j = 0; j < this->counts[i]; j++)
       {
           Sorted_Temp.push_back(i + 97);
       }
    }
	return Sorted_Temp;
}
string LetterBag::toString()
{
    /// return a string with the letters in this object, in sorted order and lowercase.
    string Sorted_String_TEMP = "";

    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < this->counts[i]; j++)
        {
             Sorted_String_TEMP += (i + 97);
        }
    }
    return Sorted_String_TEMP;
}
bool LetterBag::operator<(const LetterBag & other) const
{
    /// return if the current object is a proper subbag of other.
    for(int i = 0; i < 26; i++)
    {
        if(!(other.counts[i] < this->counts[i]))
        {
            return false;
        }
    }
    return true;
}
bool LetterBag::operator<=(const LetterBag & other) const
{
    /// return true if the current object is a subbag of other and false otherwise.
    for(int j = 0; j < 26; j++)
    {
        if(!(other.counts[j] <= this->counts[j]))
        {
            return false;
        }
    }
    return true;
}
bool LetterBag::operator>(const LetterBag & other) const
{
    /// return true if the other is a proper subbag of the current object and false otherwise.
    /// note proper subbag means it's a subbag but not equal to the other bag.
    for(int k = 0; k < 26; k++)
    {
        if(!(other.counts[k] > this->counts[k]))
        {
            return false;
        }
    }
    return true;
}
bool LetterBag::operator>=(const LetterBag & other) const
{
    for(int h = 0; h < 26; h++)
    {
        if(!(other.counts[h] >= this->counts[h]))
        {
            return false;
        }
    }
    return true;
}
bool LetterBag::operator==(const LetterBag & other) const
{
    for(int count = 0; count < 26; count++)
    {
        if(!(other.counts[count]) == this->counts[count])
        {
            return false;
        }
    }
    return true;
}
bool LetterBag::operator!=(const LetterBag& other) const
{
	if (*this == other)
		return false;
	return true;
}
bool LetterBag::is_Subbag(const LetterBag & other) const
{
    if(this->size < other.size)
        return false;
    for(int j = 0; j < 26; j++)
        if(other.counts[j] > this->counts[j])
            return false;
    return true;
}

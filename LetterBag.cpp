/**
    Derek J. Russell
    Professor Jonathan Traugott
    Anagram - (Assignment)
    CSCI 20 - Data Structures C++ - Spring 2018
    Chabot Community College
    Date: May 17th, 2018
    =================================================================================================
    Implement a Dictionary class to work with the attached tester program.

    Your Dictionary stores a map of key-value pairs where the key is a suitably stored bag of letters
    (e.g. a LetterBag object or a sorted string containing the letters) and the value is a set of words
    where each word contains exactly those letters.  The key-value pair is called an AnagramSet.

    For example: If the key is  "art"  then value might be {"art", "rat", "tar"}  i.e. a set of three
    words with the letter 'a', 'r' and 't'.  (Note "tart" wouldn't be in the set since it has a different key: "artt")

    The client can look up a string of letters in the dictionary and get back an AnagramSet object with that key.

    To make things easier, the client doesn't need to presort the lookup string since the Dictionary
    will automatically see it as a bag of letters, disregarding order (e.g. "rta" and "tra"
    would get back the same AnagramSet).

    To make this work, the dictionary will need a function makeKey that takes a string
    and generates the corresponding key (i.e. a LetterBag or sorted string depending
    on how you do it).

    You'll need to implement AnagramSet.  There is very little required by the tester in terms of
    public functions. Mainly you need to be able to output an AnagramSet object, test whether
    it's empty (i.e. no words found for a particular key). and get the size.

    One way to implement AnagramSet is a LetterBag object for the key and some data
    structure to hold a set of  strings (e.g. BST,  list,  array).

    For the Dictionary you should use a hash table as the underlying data structure.
    Use chaining rather than linear probing since our load factors will greatly
    exceed 1 in some of the tests.

    Write everything from scratch. That means you aren't allowed to use any
    STL container data structures, including map, multimap, hash_map, list, vector etc.

    Exception: you may use the built in string data type.

    Notice that we overload the stream insertion operator for both AnagramSet and Dictionary.

    For AnagramSet, you should output both the key and the set of associated words (e.g. aet: { eat, tea }).

    I output the Dictionary in a slightly odd format to manifest its underlying structure in the hash table.
    That means you will see more than one AnagramSet per line (exclosed in braces) whenever a collision
    occurred (i.e. both AnagramSets mapped to the same hash index). You don't need to duplicate this output
    format. Your output will look different in terms of the order of entries in the hash table since that
    depends on the particular hash function.

    I didn't provide header files for Dictionary or AnagramSet. You can deduce constructor and function
    prototypes from the calls in tester.cpp. Notice we can specify the "table size" for the Dictionary.
    That should correspond to the size of your underlying hash table. Big file sizes with small hash table
    size is a stress test for your implementation. Times are provided as an indicator of the efficiency
    you're shooting for.
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
        return (c + ('a' - 'A'));
    return (c);
}
LetterBag::LetterBag()
{
    /// No-parameter constructor for an empty LetterBag.
	for (int i = 0; i < 26; i++)
	{
		this->counts[i] = 0;
	}
    this->size = 0;
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
	return (*this);
}
LetterBag::LetterBag(const string &s) /// Normal constructor to accept the string and work off of that.
{
    /// Similar to the vector constructor but using a string to initialize.
	for (int i = 0; i < 26; i++)
	{
		this->counts[i] = 0;
	}
    this->size = 0;

    for(unsigned int j = 0; j < s.length(); j++)
    {
        this->Add(s.at(j));
    }
}
intmax_t LetterBag::getCurrentSize() const
{
	/// return this->size.
	return (this->size);
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

    return (temp);
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
    return (*this);
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
    for(unsigned int k = 0; k < 26; k++)
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
    for(unsigned int count = 0; count < 26; count++)
    {
        if(!((other.counts[count]) == this->counts[count]))
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

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
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "AnagramSet.h"
#include <iostream>
#include <string>

using namespace std;

class Dictionary
{
	friend ostream& operator<<(ostream & out, const Dictionary &d)
	{
	    out << "Print Print Print" << endl;
		string temp;
		for (int i = 0; i < d.tableSize; i++)
		{
			if (d.HashTable[i] != NULL)
			{
				Item *current = d.HashTable[i];
				while (current != NULL)
				{
					//out << "{ ";
					temp = (current->set).key.toString();
					//index += index*(i+1) + key.getFrequency( 'a' + i);
					out << temp << ": ";
					out << current->set << endl;
					current = current->next;
				}
			}
		}
		return out;
	}

    protected:
                struct Item
                {
                    AnagramSet set;
                    Item *next;
                };
                Item **HashTable;															// Array of Item pointers Hashtable that contains pointer
                int tableSize;
    public:
            int numCollisions;
            int wordCount;
            Dictionary(int tableSize);
            Dictionary(string words[], int wordCount, int tableSize);
            AnagramSet getSet(string word);
            unsigned long long int hash_index(string key);										// Calculates the key using letterbag which is also the address
            void insert(string word);													// Insert into hash table;
            void remove(string word);													// Remove word from hash table
            void convertToLower(string word);
            bool findSet(string word);
            bool contains(string word);
};
#endif
#pragma once

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "AnagramSet.h"
#include <iostream>
#include <string>

using namespace std;

class Dictionary
{
	friend ostream& operator<<(ostream & out, const Dictionary &d)
	{
	    out << "Print Print Print" << endl;
		string temp;
		for (int i = 0; i < d.tableSize; i++)
		{
			if (d.HashTable[i] != NULL)
			{
				Item *current = d.HashTable[i];
				while (current != NULL)
				{
					//out << "{ ";
					temp = (current->set).key.toString();
					//index += index*(i+1) + key.getFrequency( 'a' + i);
					out << temp << ": ";
					out << current->set << endl;
					current = current->next;
				}
			}
		}
		return out;
	}

    protected:
                struct Item
                {
                    AnagramSet set;
                    Item *next;
                };
                Item **HashTable;															// Array of Item pointers Hashtable that contains pointer
                int tableSize;
    public:
            int numCollisions;
            int wordCount;
            Dictionary(int tableSize);
            Dictionary(string words[], int wordCount, int tableSize);
            AnagramSet getSet(string word);
            unsigned long long int hash_index(string key);										// Calculates the key using letterbag which is also the address
            void insert(string word);													// Insert into hash table;
            void remove(string word);													// Remove word from hash table
            void convertToLower(string word);
            bool findSet(string word);
            bool contains(string word);
};
#endif // DICTIONARY_H
#pragma once

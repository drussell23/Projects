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
#include "Dictionary.h"
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

unsigned long long int Dictionary::hash_index(string word)
{
        LetterBag key( word );
		int index = 1;
		for (unsigned int i = 0; i < 26; i++)
		{
			index += index * (i + 1) + key.getFrequency('a' + i);
			index %= tableSize;
		}
		return (index);
}
Dictionary::Dictionary(int tableSize)
{
    this->numCollisions = 0;
    this->wordCount = 0;

	HashTable = new Item*[tableSize];
	this->tableSize = tableSize;

	for (int i = 0; i < tableSize; i++)
		HashTable[i] = NULL;
}
Dictionary::Dictionary(string wordList[], int wordCount, int tableSize)
{
    this->numCollisions = 0;
    this->wordCount = 0;
	HashTable = new Item*[tableSize];
	this->tableSize = tableSize;

	for (int i = 0; i < tableSize; i++)
		HashTable[i] = NULL;
	for (int i = 0; i < wordCount; i++)
		this->insert(wordList[i]);
}
void Dictionary::insert(string word)
{
	int index = hash_index(word);
	bool found = false;
	LetterBag key;

	for (unsigned int i = 0; i < word.length(); i++)
		key.Add(word[i]);

	if (HashTable[index] == NULL)
	{
		HashTable[index] = new Item;
		HashTable[index]->next = NULL;
			HashTable[index]->set.words.insert(word);
		for (unsigned int i = 0; i < word.length(); i++)
			HashTable[index]->set.key.Add(word[i]);
	}
	else
	{
		++numCollisions;
		Item *temp = HashTable[index];

		while (temp != NULL && !found)
		{
			if (temp->set.key == key)
			{
				if (temp->set.words.find(word) == -1)
					temp->set.words.insert(word);
				found = true;
			}
			temp = temp->next;
		}
		if (!found)
		{
			Item *current = HashTable[index];
			while (current->next != NULL)
				current = current->next;
			Item *new_item = new Item;
			new_item->next = NULL;
			for (unsigned int i = 0; i < word.length(); i++)
				new_item->set.key.Add(word[i]);
			new_item->set.words.insert(word);
			current->next = new_item;
		}
	}
	++wordCount;
}
void Dictionary::remove(string word)
{
	int index = hash_index(word);
	LetterBag key(word);
    Item *p = HashTable[index];
    Item *q = NULL;
    Item *toDelete;

    while( p != NULL )
    {
        if( (p->set).key == key )
        {
            if( (p->set).words.find( word ) != -1)
            {
                p->set.words.remove(word);
                if( p->set.words.isEmpty() )
                {
                    if( q == NULL )
                    {
                        toDelete = p;
                        HashTable[index] = p->next;
                        delete toDelete;
                    }
                    else
                    {
                        toDelete = p;
                        q->next = p->next;
                        delete toDelete;
                    }
                }
                wordCount--;
                break;
            }
        }
        q = p;
        p = p->next;
    }
}
bool Dictionary::contains(string word)
{
	int index = hash_index(word);
	LetterBag key( word );

	if (HashTable[index] == NULL)
	{
		return (false);
	}
	else													// not in first node of bucket. must traverse
	{
		Item *temp = HashTable[index];
		while (temp != NULL)
		{
			if (temp->set.key == key)
			{
				if (temp->set.words.find(word) != -1)
					return (true);
			}
			temp = temp->next;
		}
	}
	return (false);
}
bool Dictionary::findSet(string word)				// same exact thing as contains except returns true when word's key value exists w
{													// this means that the set for that word exists
	int index = hash_index(word);
	LetterBag key;

	for (unsigned int i = 0; i < word.length(); i++)
	{
		if (word[i] >= 'A' && word[i] <= 'Z')
			word[i] -= 'Z' - 'z';
	}
	for (unsigned int i = 0; i < word.length(); i++) // to find matching anagram set
		key.Add(word[i]);

	if (HashTable[index] == NULL)
		return (false);
	else if (HashTable[index]->set.key == key)
		return (true);
	else
	{
		Item *temp = HashTable[index];
		while (temp != NULL)
		{
			if (temp->set.key == key)
			{
				return (true);
			}
			temp = temp->next;
		}
	}
	return false;
}
AnagramSet Dictionary::getSet(string word) // HOW DO I RETURN ANAGRAMSET IF IT DOES NOT EXIST
{
	int index = hash_index(word);
	LetterBag key;

	for (unsigned int count = 0; count < word.length(); count++)
	{
		if (word[count] >= 'A' && word[count] <= 'Z')
			word[count] -= 'Z' - 'z';
	}
	for (unsigned int i = 0; i < word.length(); i++) // to find matching anagram set
		key.Add(word[i]);

	if (HashTable[index] == NULL)
	{
		return (AnagramSet());
	}
	else if (HashTable[index]->set.key == key)
	{
		return HashTable[index]->set;
	}
	else
	{
		Item *temp = HashTable[index];
		while (temp != NULL)
		{
			if (temp->set.key == key)
			{
				return (temp->set);
			}
			temp = temp->next;
		}
		return (AnagramSet());
	}
}

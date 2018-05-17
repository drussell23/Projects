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
#include <iostream>
#include "AnagramSet.h"
#include "Dictionary.h"
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int maxWords = 200000;
string words[maxWords], reversedWords[maxWords];
int tfine; // used for timer

void resetTimer() ;  // reset the timer
int getTime();  // get elapsed time

// read file into wordList. Return number of words read in
int readInWords(string wordList[],  int maxSize, string fileName) ;

// return the reverse of s
string reverse(const string & s);

// count the number of words in wordList that are in d
void countHits (string wordList[], int length,  Dictionary & d);

// write the dictionary to a file
void toFile(const Dictionary & d, const string & fileName) ;

// find palindromic words (bob) and palindrome pairs (live evil)
void findPalindromes(Dictionary & d, int numWords);

// count anagrams
void countAnagrams( Dictionary & d, int minimum, string wordList[], int length);

// remove words from dictionary
void removalTest( Dictionary & d, int numWords, int howMany) ;

// insert words to dictionary
void insertionTest( Dictionary & d, int numWords);

// find words whose letters match a given string
void unScramble(Dictionary & d);

int main()
{

	int  tableSize;
	cout << "What is the hash table size? ";
	cin >> tableSize;
	resetTimer();

	cout << "Starting" << endl;
	int numWords = readInWords(words, maxWords,"words(4).txt");

	cout << "Read in " << numWords << " words " << endl;
	cout << "Done reading words, elapsed time = " << getTime() << endl << endl;

	resetTimer();
	Dictionary d(words, numWords, tableSize );
	cout << "Done creating dictionary, elapsed time = " << getTime() << endl;
	countHits(words,numWords,d);

	resetTimer();
	toFile(d, "full.txt");
	cout << "Done writing to file, elapsed time = " << getTime() << endl;

	findPalindromes(d,numWords);

	for (int i = 2; i <= 13; i++)
		countAnagrams(d,i,words,numWords);

	removalTest(d, numWords, numWords-30);
	removalTest(d, numWords, numWords);

	insertionTest(d, numWords);
	insertionTest(d, numWords);

	unScramble(d);
	cout << "Bye!" << endl;
		return (0);
}
void resetTimer()
{
	tfine = clock();
}
int getTime()
{
	return clock() - tfine;
}
int readInWords(string wordList[],  int maxSize, string fileName)
{
    int i = 0;
	ifstream infile;
	infile.open(fileName.c_str());
	if (!infile) cout <<"Failed to open file" << endl;
    while (infile && i < maxSize) {
        string s;
        infile >> s;
        if (infile) {
            wordList[i] = s;
            i++;
        }
    }
    return (i);  // the number of words read in
}
void countHits (string wordList[], int length,  Dictionary & d)
{
	resetTimer();
	int count = 0;
	for (int i = 0; i < length; i++)
		if (d.contains(wordList[i]) )
			count++;
	cout << "Hit count = " << count
		<< ",  elapsed time = " << getTime() << endl << endl;
}
string reverse(const string & s)
{
	string t;
	for (int i = s.length()-1; i >= 0; i--)
		t.push_back(s[i]);
	return t;
}
void toFile(const Dictionary & d, const string & fileName)
{
	ofstream out;
	out.open(fileName.c_str());
	out << d << endl;
	out.close();
}
void countAnagrams( Dictionary & d, int howMany, string wordList[], int length)
{
	// There's a faster way of counting if we know d contains the same words
	// as wordList, but for the sake of testing we'll ignore that fact.
	resetTimer();
	int sum = 0;
	for (int i = 0; i < length; i++)  {
        if (!d.contains(wordList[i])) continue;
		AnagramSet  a = d.getSet(wordList[i]);
		if (a.getSize() == howMany)
			sum++;
	}
	cout	<< "Found " << setw(5) << sum
			<< " words with  " << setw(3) << howMany << " anagrammatic forms. Elapsed time = "
			<< getTime() << endl;
}
void findPalindromes(Dictionary & d, int numWords)
 {
	Dictionary pal(2000);
	cout << "Creating reversed word list...";
	for (int i = 0; i < numWords; i++)
		reversedWords[i] = reverse(words[i]);
	cout << endl << "Counting palindromes.";
	countHits(reversedWords, numWords, d);
	cout <<  "Creating palindrome dictionary...";
	for (int i = 0; i < numWords; i++)  {
		if (d.contains(reversedWords[i])) {
			pal.insert(words[i]);
			pal.insert(reversedWords[i]);
		}
	}
	cout << "done.  " << endl;
	toFile(pal, "palindromes.txt");

	cout << endl << endl;
}
void removalTest( Dictionary & d, int numWords, int howMany)
 {
	resetTimer();
	for (int i = 0, j = 0; j < howMany; i = ( i + 22079) % numWords, j++)
			d.remove(words[i]);
	cout << endl << "Done removing " << howMany << ", elapsed time = " << getTime() << endl << endl;
	cout <<"Current dictionary = " << endl <<  d;
	countHits(words,numWords,d);
}
void insertionTest( Dictionary & d, int numWords)
{
	resetTimer();
	for (int i = numWords-1; i >= 0; i--)
		d.insert(words[i]);
	cout << "Done inserting, elapsed time = " << getTime() << endl;
	countHits(words,numWords,d);

}
void unScramble(Dictionary & d)
{
	string s;
	do {
		cout << "Enter an anagram or q to quit: ";
		cin >> s;
		if (s != "q") {
            AnagramSet a = d.getSet(s);
			if (a.isEmpty())
				cout << "Not found " << endl;
			else
				cout << "Found it: " << a << endl;
		}
	} while (s != "q");
}

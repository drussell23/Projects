/**
    Derek J. Russell
    Professor Jonathan Traugott
    LetterBag - (Assignment 1)
    CSCI 20 - Data Structures C++ - Spring 2018
    Chabot Community College
    Date: February 1st, 2018
    ===========================================
**/
#ifndef LETTERBAG_H
#define LETTERBAG_H

#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class LetterBag
{
    friend ostream & operator << (ostream & out, const LetterBag &l)
    {
        vector<char> vec_1 = l.toVector();
        for (unsigned int i = 0; i < vec_1.size(); i++)
        {
            out << vec_1[i] << " ";
        }
        return out;
    }
	private:
			int counts[26];
			static bool in_Range(char c);
			char toLower( char c );
			int size;
	public:
            LetterBag();

            LetterBag(const vector<char> & v);

            LetterBag& Add(char c);

            LetterBag(const string & s);

            intmax_t getCurrentSize() const;  // return the current size of the LetterBag

            bool isEmpty() const;

            LetterBag operator+(char ch) const;

            LetterBag & operator+=(char ch);

            LetterBag operator+(const LetterBag & other) const;

            LetterBag & operator+=(const LetterBag & other);

            LetterBag operator-(char ch) const;

            LetterBag & operator-=(char ch);

            LetterBag operator-(const LetterBag & other) const;

            LetterBag & operator-=(const LetterBag & other);

            LetterBag & removeAll(char ch);

            LetterBag & clear();

            intmax_t getFrequency(char c) const;

            vector<char> toVector() const;

            string toString();

            bool operator<(const LetterBag & other) const;

            bool operator<=(const LetterBag & other) const;

            bool operator>(const LetterBag & other) const;

            bool operator>=(const LetterBag & other) const;

            bool operator==(const LetterBag & other) const;

            bool operator!=(const LetterBag & other) const;

            bool is_Subbag(const LetterBag & other) const;

};
#endif // LETTERBAG_H
#pragma once

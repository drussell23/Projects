/**
    Derek J. Russell
    Professor Jonathan Traugott
    Last Programming Assignment - Graphs
    CSCI 20 - Data Structure C++ - Spring 2018
    ==========================================
    Last Programming Assignment (Due May 24th)
    ------------------------------------------

    Write a program to find a sequence of cities representing the fewest number of connections needed to fly from one city to another.

    For example, say the user enters San Francisco and Osaka as the starting city and destination city.
    If the program outputs San Francisco --> Tokyo --> Osaka.
    That means you can fly from San Francisco to Osaka through Tokyo, but you can't fly directly From San Francisco to Osaka.
    Connections file is attached (connections.txt).   You may assume this is the only file the program will be used with.

    1) Program asks for the starting city.

    2) User enters a starting city name or  a sub-string of the name (of length 2 or more). The program displays all the matching cities.  (Or "Not found" or "No matches" if there are no matches, and asks for another name.)

    3) User selects from the list.

    4) Program ask user for the destination city as in steps 1, 2 and 3.

    5) Program displays the route. You only need to display one possible route.
       The route may be any route that has the least number of connecting cities.

    6) User can do more searches if they want.
**/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <locale>

using namespace std;

struct Graph_MAP
{
	string Location;
	vector<string> The_List_Of_Cities;
};
class Graph
{
	public:
		Graph_MAP MyList[300];
		int Count_City;

	public:
		Graph()
		{
			Count_City = 0;
		}
		void ADDCity_start(string N)
		{
			MyList[Count_City++].Location = N;
		}
		void AddToCity_end(int n, string A)
		{
			MyList[Count_City].The_List_Of_Cities.push_back(A);
		}
		int FindCity_find(string City)
		{
			vector<int> List;
			int a = 0;

			for (int count = 0; count < Count_City; count++)
			{
				if (MyList[count].Location.find(City) != -1)
				{
					List.push_back(count);
					cout << a << ". " << MyList[count].Location << endl;
					a++;
				}
			}
			cout << endl;

			if (a > 0)
			{
				int decision = -1;

				while (decision < 0 || decision > a)
				{
					cout << "Make a decision: (0-" << a - 1 << "): ";
					cin >> decision;
				}
				cout << endl;
				return(List[decision]);
			}
			else
			{
				return (-1);
			}
		}
		void Flight(int Flight_Route, int T)
		{
			cout << "Now leaving: " << MyList[Flight_Route].Location << " going to: " << MyList[T].Location << endl;

			int a[300];

			for (int i = 0; i < 300; i++)
			{
				a[i] = -1;
			}
			string b[300];
			a[Flight_Route] = Flight_Route;
			b[0] = MyList[Flight_Route].Location;
			int y = 0, c = 0;

			while (y >= c)
			{
				int point = 0;

				for (int i = 0; i < Count_City; i++)
				{
					if (b[c] == MyList[i].Location)
					{
						point = i;
					}
				}
				for (unsigned int i = 0; i < MyList[point].The_List_Of_Cities.size(); i++)
				{
					string q = MyList[point].The_List_Of_Cities[i];

					for (int j = 0; j < Count_City; j++)
					{
						if (MyList[j].Location == q && a[j] == -1)
						{
							y++;
							b[y] = q;
							a[j] = point;
						}
					}
				}
				c++;
			}
			if(a[y] == -1)
			{
				cout << "Restricted Flight." << endl;
			}
			else
			{
				vector<string> r;
				r.push_back(MyList[T].Location);
				int e = a[y];

				while (e != Flight_Route)
				{
					r.push_back(MyList[e].Location);
					e = a[e];
				}
				r.push_back(MyList[Flight_Route].Location);

				for (int i = r.size() - 1; i >= 0; i--)
				{
					cout << r[i] << endl;
				}
				cout << endl;
			}
		}
};
#endif // GRAPH_H
#pragma once

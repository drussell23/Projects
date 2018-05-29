#include "Graph.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <locale>

using namespace std;

void Print_From_File(Graph & object)
{
	ifstream File;
	File.open("connections.txt");

	if (!File)
	{
		cout << "Sorry! Not able to locate the file." << endl;
	}
	string temp, temp2;
	getline(File, temp);

	while (!File.eof())
	{
		temp2 = temp.substr(0, 7);
		temp.erase(0, 7);

		if (temp2 == "From:  ")
		{
			object.ADDCity_start(temp);
		}
		else
		{
		    object.AddToCity_end(object.Count_City - 1, temp);
		}
		getline(File, temp);
	}
	File.close();
}
int main()
{
	Graph Graph_Main;

	cout << "Reading Cities from the File." << endl;
	Print_From_File(Graph_Main);
	cout << "Finished Reading from the File." << endl;

	string option = "";

	while (true)
	{
		cout << "Enter the City Name or 'Q' to Quit the Program:" << endl;
		cout << "-----------------------------------------------" << endl;

		int s = -1;

		while (s == -1)
		{
			cout << "Start City: ";
			getline(cin, option, '\n');
			cout << endl;

			if (option == "q")
			{
				cout << "Good Bye!" << endl;
				return 0;
			}

			s = Graph_Main.FindCity_find(option);
			cin.ignore(100, '\n');

			if (s == -1)
			{
				cout << "Sorry! Can't find the Start City." << endl;
			}
		}
		int t = -1;

		while (t == -1)
		{
			cout << "Destination City: ";
			getline(cin, option, '\n');
			cout << endl;

			if (option == "q")
			{
				cout << "Good Bye!" << endl;
				return 0;
			}
			t = Graph_Main.FindCity_find(option);
			cin.ignore(100, '\n');

			if (t == -1)
			{
				cout << "Sorry! Can't find the Destination City." << endl;
			}
			Graph_Main.Flight(s, t);
			system("PAUSE");
			system("CLS");
		}
	}
	return 0;
}

/**
    Derek J. Russell
    Professor Jonathan Traugott
    OList - (Assignment 2)
    CSCI 20 - Data Structures C++ - Spring 2018
    Chabot Community College
    Date: February 13st, 2018
    ===========================================
**/
#include <stdexcept>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "OList.h"
using namespace std;


template <class T>
void printInfo(const OList<T> & myList)
{
	cout << "List = " << myList << "\tSize = " << myList.getSize() ;

	if (!myList.isEmpty())
        cout << "\tRange = " << myList.getSmallest() << "..." <<  myList.getBiggest();
        cout << endl;
}
void testDefaultConstructor()
{
	cout << "Begin testDefaultConstructor " << endl;
	OList<int> list1;
	printInfo(list1);
	OList<double> list2;
	printInfo(list2);
	cout << "End testDefaultConstructor " << endl << endl;
}
void testArrayConstructor()
{
	cout << "Begin testArrayConstructor " << endl;
	int nums[] = {6, 4, 8, 2, 9, 9, 1, 3, 8, 1, 0, 7, 2, 2, 1};
	OList<int> list1(nums,15);
	printInfo(list1);
	string strings[] = {"Table", "Chair", "Couch", "Book", "Chair", "Table", "Cookbook",  "Chair"};
	OList<string> list2(strings,8);
	printInfo(list2);
	cout << "End testArrayConstructor " << endl << endl;
}

void testCopyConstructor()
 {
	cout << "Begin testCopyConstructor " << endl;
	int nums[] = {1,2,3,4,5};
	OList<int> list1(nums,5);
	OList<int> list2 = list1;
	printInfo(list1);
	printInfo(list2);
	list2.clear();
	printInfo(list1);
	printInfo(list2);
	cout << "End testCopyConstructor " << endl << endl;
}
void testInsertAndRemove()
{
	cout << "Begin testInsertAndRemove" << endl;
	OList<char> list;
	list.insert('A');
	printInfo(list);
	list.remove('B');
	printInfo(list);
	list.remove('A');
	printInfo(list);
	for (int i = 0; i < 3; i++) {
		list.insert('C');
		list.insert('A');
	}
	printInfo(list);
	list.remove('C');
	printInfo(list);
	for (int i = 0; i < 3; i++) {
		list.remove('A',false);
		printInfo(list);
	}
	printInfo(list);
	for (char c = 'Z'; c >= 'A'; c--)
		list.insert(c);
	printInfo(list);
	for (char c = 'Z'; c >= 'A'; c-=2)
		list.remove(c);
	printInfo(list);
	for (char c = 'A'; c <= 'Z'; c++)
		list.remove(c);
	printInfo(list);
	for (char c = 'A'; c <= 'Z'; c++)
		list.insert(c);
	printInfo(list);
	list.clear();
	printInfo(list);
	for (int i = 0; i < 4; i++)
		list.insert('B');
	for (int i = 0; i < 4; i++)
		list.insert('A');
	printInfo(list);
	list.remove('A', false);
	printInfo(list);
	list.remove('A', true);
	printInfo(list);
	list.insert('A');
	list.insert('C');
	printInfo(list);
	list.remove('B');
	printInfo(list);
	list.insert('B');
	printInfo(list);

	cout << "End testInsertAndRemove" << endl << endl;
}
void testPrint()
{
	cout << "Begin testPrint" << endl;
	int values[] = { 4, 3, 5, 1, 2, 3};
	OList<int> list(values,6);
	list.print();
	list.printBackwards();
	list.clear();
	list.printBackwards();
	list.insert(3);
	list.printBackwards();
	list.insert(4);
	list.printBackwards();
	cout << "End testPrint" << endl << endl;
}
void testAssignment()
{
	cout << "Begin testAssignment" << endl;
	string strings1[] = {"a", "b", "c", "d"};
	string strings2[] = {"e", "f", "g"};
	OList<string> list1(strings1,4);
	OList<string> list2(strings2,3);
	printInfo(list1);
	printInfo(list2);
	list2 = list1;
	printInfo(list1);
	printInfo(list2);
	list1.insert("x");
	list2.insert("y");
	printInfo(list1);
	printInfo(list2);
	list2 = list2;
	printInfo(list2);
	cout << "End testAssignment" << endl << endl;
}
void testEquals()
{
	cout << "Begin testEquals" << endl;
	OList<int> list1;
	OList<int> list2;
	cout << (list1 == list1) << endl;
	cout << (list1 != list1) << endl;
	cout << (list1 == list2) << endl;
	cout << (list1 != list2) << endl;
	list1.insert(3);
	cout << (list1 == list2) << endl;
	cout << (list1 != list2) << endl;
	list2.insert(3);
	cout << (list1 == list2) << endl;
	cout << (list1 != list2) << endl;
	list1.insert(3);
	cout << (list1 == list2) << endl;
	cout << (list1 != list2) << endl;
	list2.insert(3);
	cout << (list1 == list2) << endl;
	cout << (list1 != list2) << endl;
	cout << "End testEquals" << endl << endl;
}
void testFind()
{
	cout << "Begin testFind" << endl;
	int nums[] = {3,1,4,2,5,1};
	OList<int> list(nums,6);
	printInfo(list);
	for (int i = 0; i < 7; i++)
		cout << i << ": " << list.find(i) << endl;
	cout << "End testFind" << endl << endl;
}
void testMerge()
{
	cout << "Begin testMerge" << endl;

	int nums1[] = {1,3,5,7,9,11};
	int nums2[] = {0,2,4,6,8,10};
	OList<int> list1(nums1,6), list2(nums2,6);
	printInfo(list1);
	printInfo(list2);
	printInfo(list1 + list2);
	printInfo(list2 + list1);
	printInfo(list1);
	printInfo(list2);
	list2 += list1;
	printInfo(list1);
	printInfo(list2);
	int nums3[10000];
	for (int i = 9999; i >= 0; i--)
		nums3[i] = i;
	OList<int> list3(nums3,10000);
	unsigned int startTime = (unsigned int) time(0);
	cout << "\tMerging big list...";
	for (int i = 0; i < 10; i++)
		list3 += list3;
	cout << "\tfinal size = " << list3.getSize() << endl;
	cout << "\telapsed time = " << time(0) - startTime << endl;
	cout << "End testMerge" << endl << endl;
}
void testConst()
{
	cout << "Begin testConst " << endl;
	int nums[] = {3,2,1};
	OList<int> list1(nums,3);
	const OList<int> list2(nums,3);
	cout << list2.find(1) << endl;
	cout << (list1 == list2) << endl;
	cout << (list2 == list1) << endl;
	list1 = list2;
	list1+=list2;
	cout << list1 << endl;
	list1 = list2 + list2;
	cout << list1 << endl;
	cout << list2 << endl;
	cout << list2.getSize() << endl;
	cout << list2.getSmallest() << " " << list2.getBiggest() << endl;
	cout << "End testConst " << endl << endl;
}
void testMemoryLeak()
{
	const int size = 10000;
	cout << "Begin testMemoryLeak "<< endl;
	unsigned int startTime;

	int nums[size];
	for (int i = 0; i < size; i++)
		nums[i] = i;
	OList<int> myList1(nums, size);
	startTime = (unsigned int) time(0);
	cout << "Test 1" << endl;
	for (int i = 0; i < 10000; i++) {
		OList<int> myList2 = myList1;
		if (i % 1000 == 0) cout << ".";
	}
	cout << "Elapsed Time for Test 1 = " << time(0) - startTime << endl;

	OList<int> myList2;
	cout << "Test 2" << endl;
	startTime = (unsigned int) time(0);
	for (int i = 0; i < 10000; i++) {
		myList2 = myList1;
		if (i % 1000 == 0) cout << ".";
	}
	cout << "Elapsed Time for Test 2 = " << time(0) - startTime << endl;

	cout << "Test 3" << endl;
	startTime = (unsigned int) time(0);
	OList<int> myList3;
	myList3.insert(1);
	myList3.insert(3);
	for (int i = 0; i < 1000000; i++) {
		for (int j = 0; j < 100; j++)
			myList3.insert(2);
		myList3.remove(2);
		if (i % 100000 == 0) cout << ".";
	}
	cout << "Elapsed Time for Test 3 = " << time(0) - startTime << endl;
	cout << "End testMemoryLeak" << endl << endl;
}
int main()
{
	cout << "START TESTS " << endl;
	testDefaultConstructor();
	testArrayConstructor();
	testCopyConstructor();
	testInsertAndRemove();
	testPrint();
	testAssignment();
	testEquals();
	testFind();
	testMerge();
	testConst();
	testMemoryLeak();
	cout << "DONE WITH ALL TESTS " << endl;

	return 0;
}

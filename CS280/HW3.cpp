/*
	CS280 HW3
	@file hw3.cpp
	@author Emmet Blassingame
	@version 9/23/2022
*/

#include <iostream>
#include <fstream>
#include <typeinfo>
#include <sstream>
#include "linkedList.h"
using namespace std;

int main() {
	string inputFile = "cities.txt";
	ifstream f(inputFile);
	linkedList list = linkedList();

	if (!f.is_open()) {
		cout << "Could not open file!" << endl;
	}

	else {
		string inputLine;
		string prevLine = "";
		while (getline(f, inputLine, '\n')) {
			list.addCity(prevLine, inputLine);
			prevLine = inputLine;
		}
	}

	bool ok = true;

	while (ok)
	{
		string choice;
		cout << "Enter a choice:\nAdd a node (1)\nDelete a node (2)\nSend a message(3)\nQuit(4)" << endl;
		getline(cin, choice);
		cout << "You entered: " << choice << endl;

		if (choice == "1")
		{
			string newCity, prevCity;
			cout << "Enter the name of the new city: " << endl;
			getline(cin, newCity, '\n');
			cout << "Enter the city you would like to enter " << newCity << " after: "<<endl;
			getline(cin, prevCity, '\n');
			list.addCity(prevCity, newCity);
		}

		else if (choice == "2") {
			string cityToDelete;
			cout << "Enter the name of the city you want to delete: " << endl;
			getline(cin, cityToDelete, '\n');
			list.deleteCity(cityToDelete);
		}

		else if (choice == "3") {
			string message, fromCity;
			cout << "Enter the message you want to send: " << endl;
			getline(cin, message, '\n');
			cout << "Enter the name of the city you want to send from: "<<endl;
			getline(cin, fromCity, '\n');
			list.sendMessage(message, fromCity);
		}

		else if (choice == "4")
		{
			cout << "EXITING" << endl;
			cout << "\n" << endl;
			ok = false;
		}

		else {
			cout << "Invalid choice, exiting!" << endl;
			ok = false;
		}
	}

	cout << "====LIST FORWARD====" << endl;
	list.printList();
	cout << "\n" << endl;
	cout << "====LIST BACKWARD====" << endl;
	list.printListBack();
	cout << "\n" << endl;

	list.deleteList();
	return 0;
}
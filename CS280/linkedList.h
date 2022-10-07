/*
	CS280 linked list header file
	@file linked-list.h
	@author Emmet Blassingame
	@version 9/23/2022
*/

#ifndef LL_H_
#define LL_H_
#include <iostream>
using namespace std;

struct city {
	string name;
	string message;
	city* next;
	city* previous;
};

class linkedList {
private:
	city* head;
	city* tail;
public:
	linkedList();
	void addCity(string prev, string name);
	void deleteCity(string name);
	void sendMessage(string message, string cityName);
	void deleteList();
	void printList();
	void printListBack();
};

linkedList::linkedList() {
	head = NULL;
	tail = NULL;
}

void linkedList::addCity(string prev, string name) {
	city* newCity = new city();
	newCity->name = name;
	newCity->next = NULL;
	newCity->previous = NULL;

	if (prev == "") {
		if (head == NULL) {
			head = newCity;
			tail = newCity;
		}

		else {
			newCity->next = head;
			head->previous = newCity;
			head = newCity;
		}
	}

	else {
		city* prevNode = head;

		while (prevNode != NULL && prevNode->name != prev) {
			prevNode = prevNode->next;
		}

		if (prevNode != NULL) {
			if (prevNode->name == tail->name) {
				tail->next = newCity;
				newCity->previous = tail;
				tail = newCity;
			}

			else {
				prevNode->next->previous = newCity;
				newCity->next = prevNode->next;

				prevNode->next = newCity;
				newCity->previous = prevNode;
			}
		}
	}
}

void linkedList::deleteCity(string name) {
	if (head != NULL) {
		if (head->name == name) {
			head = head->next;
			if (head == NULL) {
				tail = NULL;
			}

			else {
				head->previous = NULL;
			}
		}

		else if (tail->name == name) {
			tail = tail->previous;

			if (tail == NULL) {
				head = NULL;
			}

			else {
				tail->next = NULL;
			}
		}

		else {
			city* temp = head;
			while (temp != NULL && temp->name != name) {
				temp = temp->next;
			}

			if (temp != NULL) {
				temp->previous->next = temp->next;
				temp->next->previous = temp->previous;
			}
		}
	}
}

void linkedList::sendMessage(string message, string cityName ) {
	if (head != NULL) {
		city* temp = head;

		while (temp != NULL && temp->name != cityName ) {
			temp = temp->next;
		}

		if (temp != NULL) {
			if (temp->next != NULL) {
				temp->next->message = message;
			}
			if (temp->previous != NULL) {
				temp->previous->message = message;
			}
		}
	}
}


void linkedList::deleteList() {
	city* temp = new city();

	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
	cout << "All nodes have been deleted successfully.\n";
}

void linkedList::printList() {
	city* temp;
	temp = head;

	while (temp != NULL)
	{
		cout << temp->name << " has message: " << temp->message << endl;
		temp = temp->next;
	}
}

void linkedList::printListBack() {
	city* temp = tail;

	while (temp != NULL) {
		cout << temp->name << " has message: " << temp->message << endl;
		temp = temp->previous;
	}
}

#endif

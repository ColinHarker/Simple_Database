#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include "Database.h"
#include <fstream>
#include <sstream>

using namespace std;

int Database::create(string n, string e, string p) {

	if (head == nullptr) {//if there is nothing yet in the list, create node and add it to list
		newNode = new node;
		newNode->info.email = e;
		newNode->info.name = n;
		newNode->info.phone = p;
		newNode->next = nullptr;
		newNode->previous = nullptr;
		head = newNode;
		return 1;
	}
	else if (head != nullptr) {//if there is already and element in the list
		cout << "Database has already been created";
		return 0;
	}
}
int Database::insertElement(int i, string n, string e, string p) {

	//create the node to be added to the list
	int insertType = i;
	newNode = new node;
	newNode->info.email = e;
	newNode->info.name = n;
	newNode->info.phone = p;

	if (head != nullptr) { //check to see if the database has been initialized

		switch (insertType) {

		case 1: //insert element at front of list
			head->previous = newNode;
			newNode->next = head;
			newNode->previous = nullptr;
			head = newNode;
			return 1;
			break;

		case 2: //insert element at back of list if there is only one element of the list
			if (tail == nullptr) {
				tail = newNode;
				tail->previous = head;
				tail->next = nullptr;
				head->next = tail;
				return 1;
				break;
			}
			else { //insert element at back if there is more than one element
				tail->next = newNode;
				newNode->next = nullptr;
				newNode->previous = tail;
				tail = newNode;
				return 1;
				break;
			}



		}
	}
	else {//if there is no element at the head, then there are no elements in the list
		cout << "You must create the database first";
		return 0;
	}
}
void Database::print(void) {

	PrintHeader ph("Name", "Email", "Phone Number");
	PrintHeader dh;

	cout << ph;
	cout << dh;

	node* elements = head;
	while (elements != nullptr) {
		PrintHeader element(elements->info.name, elements->info.email, elements->info.phone);
		cout << element;
		elements = elements->next;
	}
}
void Database::saveToFile(void){
	
	const char *path = "Desktop";

	ofstream file(path);
	file.open("save.txt", ios::app); //appends data to the end of file);
	if(!file){
		cerr << "Error in creating save file";
	}
	else {
		cout << "File created successfully";
	}


	node* elements = head;

	while (elements != nullptr) {
		file << elements->info.name  << ","
		     << elements->info.email << ","
		     << elements->info.phone << endl;
		elements = elements->next;
	}
	
	file.close();

}
void Database::readFromFile(int insertType) {

	ifstream file;
	string name_1, name_2, email, phone, test;
	int wordNum = 1;

	file.open("save.txt");
	if (!file) {
		cerr << "Error locating file";
	}
	while (file){
		int iteration = 1;
		string name, email, phone;
		getline(file, test);
		istringstream ss(test);
		while (!ss.eof()) {
			string x;
			getline(ss, x, ',');

			switch (iteration) {
			case 1:
				name = x;
				break;
			case 2:
				email = x;
				break;
			case 3:
				phone = x;
				break;
			}
			iteration++;
		}
		if (insertType == 0) {
			create(name, email, phone);
			insertType = 2;
		}
		else {
			insertElement(insertType, name, email, phone);
		}
	}

	file.close();
}
void Database::createFromFile(void) {
	system("cls");
	cout << "Database Created" << endl;
	readFromFile(0);
}
int Database::check(void) {
	return int(head != nullptr);
}

ostream& operator<< (ostream& os, const PrintHeader& ph)
{
	os << left << setw(15) << ph.name << left << setw(25) << ph.email << left << setw(10) << ph.phone << endl;
	return os;
};
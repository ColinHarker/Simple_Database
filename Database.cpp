#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include "Database.h"
#include <fstream>
#include <sstream>

using namespace std;

int Database::create(string n, string e, string p) {

	if (head == NULL) {//if there is nothing yet in the list, create node and add it to list
		newNode = new node;
		newNode->info.email = e;
		newNode->info.name = n;
		newNode->info.phone = p;
		newNode->next = NULL;
		newNode->previous = NULL;
		head = newNode;
		return 1;
	}
	else if (head != NULL) {//if there is already and element in the list
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

	if (head != NULL) { //check to see if the database has been initialized

		switch (insertType) {

		case 1: //insert element at front of list
			head->previous = newNode;
			newNode->next = head;
			newNode->previous = NULL;
			head = newNode;
			return 1;
			break;

		case 2: //insert element at back of list if there is only one element of the list
			if (tail == NULL) {
				tail = newNode;
				tail->previous = head;
				tail->next = NULL;
				head->next = tail;
				return 1;
				break;
			}
			else { //insert element at back if there is more than one element
				tail->next = newNode;
				newNode->next = NULL;
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
	//cout << "Name\tEmail\t\t\tPhone Number" << endl;
	cout << left << setw(15) << "Name" << left << setw(25) << "Email" << left << setw(10) << "Phone Number" << endl;
	cout << left << setw(15) << "----" << left << setw(25) << "-----" << left << setw(10) << "------------\n" << endl;
	node* elements = head;
	while (elements != NULL) {
		cout << left << setw(15) << elements->info.name  
			 << left << setw(25) << elements->info.email  
			 << left << setw(10) << elements->info.phone << endl;
		elements = elements->next;
	}
}
void Database::saveToFile(void){
	
	const char *path = "Desktop/";

	ofstream file(path);
	file.open("save.txt", ios::app); //appends data to the end of file);
	if(!file){
		cerr << "Error in creating save file";
	}
	else {
		cout << "File created successfully";
	}


	node* elements = head;

	while (elements != NULL) {
		file << elements->info.name  << "\t"
		     << elements->info.email << "\t"
		     << elements->info.phone << endl;
		elements = elements->next;
	}
	
	file.close();

}
void Database::readFromFile(void) {

	ifstream file;
	string name_1, name_2, email, phone, test;
	int wordNum = 1;

	file.open("save.txt");
	if (!file) {
		cerr << "Error locating file";
	}
	while (file){
		 
		getline(file, test);

		cout << test;


		char str[] = stringToChar(test);

		// Returns first token  
		char* token = strtok(str, " ");

		// Keep printing tokens while one of the 
		// delimiters present in str[]. 
		while (token != NULL)
		{
			printf("%s\n", token);
			token = strtok(NULL, " ");
		}

		//string name = name_1.append(" " + name_2);
		
	}


	file.close();
	

}

char[] stringToChar(string input) {
	string s = input;

	int n = s.length();

	// declaring character array 
	char char_array[20];

	// copying the contents of the 
	// string to char array 
	strcpy(char_array, s.c_str());

	return char_array;
}
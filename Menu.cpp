#include <iostream>
#include <string>
#include <conio.h>
#include "Database.h"
#include "Menu.h"

using namespace std;

string phoneRefactor(string phone) {
	string newPhone = "";
	int size = phone.size();
	if (size == 10) {
		char cstr[10];
		phone.copy(cstr, 10);
		char phoneCharArray[14];
		phoneCharArray[0] = '(';
		phoneCharArray[4] = ')';
		phoneCharArray[8] = '-';
		for (int i = 0; i < 3; i++) {
			phoneCharArray[i + 1] = cstr[i];
		};
		for (int i = 3; i < 6; i++) {
			phoneCharArray[i + 2] = cstr[i];
		}
		for (int i = 6; i < 10; i++) {
			phoneCharArray[i + 3] = cstr[i];
		}
		for (int i = 0; i < 13; i++) {
			newPhone += phoneCharArray[i];
		}
		//newPhone = phoneCharArray;
	}
	else {
		newPhone = "null";
	}
	return newPhone;
}

void login(void) {
	string pass = "";
	char ch;
	cout << "\n\n\n\n\t\tEnter Password: ";
	ch = _getch();
	while (ch != 13) {//character 13 is enter
		pass.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	if (pass == "pass") {
		system("cls");
		cout << "\n\n\t\t\Welcome to my database!" << endl;
		cout << "    \t\This program allows for storage of:" << endl;
		cout << "    \t\t-Names" << endl;
		cout << "    \t\t-Emails" << endl;
		cout << "    \t\t-Phone numbers\n" << endl;
	}
	else {
		cout << "\n\n\t\tWrong Password\n\n";
		system("pause");
		system("cls");
		login();
	}
	system("PAUSE");
	system("cls");
}



void list(void) {
	cout << "\n\t------------------------------------\n"
		<< "\t-           My Database            -\n"
		<< "\t------------------------------------\n\n";

	cout << "\t1. Create Database and insert element\n"
		<< "\t2. Insert Element\n"
		<< "\t3. Print Elements\n"
		<< "\t4. Save to file\n"
		<< "\t5. Open file\n"
		<< "\t6. Exit Program\n";
}
int next() {
	int choice;
	int cho_ice;
	cout << "\nGo back to menu?" << endl;
	cout << "1. Yes\t2. No" << endl;
	cin >> choice;
	system("cls");

	if (choice == 1) {
		list();
		cout << "Enter: ";
		cin >> cho_ice;
	}
	else {
		return 4;
	}
	return cho_ice;
}
int checkInsertType(int i, string s) {
	int insertType;
	switch (i) {

	case 1:
		do {
			cout << s;
			if (!(cin >> insertType)) {
				cout << "Please enter numbers only." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		} while (insertType != 1 && insertType != 2);
		break;

	}
	return insertType;
}

people getData(people p) {
	
	cout << "Name (First & Last):";
	getline(cin, p.name);
	cout << "\nEmail:";
	getline(cin, p.email);
	cout << "\nPhone Number:";
	getline(cin, p.phone);

	return p;
}
#include <iostream>
#include <string>
#include <conio.h>
#include "Database.h"
#include "Menu.h"

using namespace std;

int main(){
	
	int choice;
	int insertType;
	Database DB;
	string name, email, phone;
	
	system("My Database");
	system("cls");
	login();
	list();

	do {
		cout << "\nEnter: ";
		if (!(cin >> choice)) {
			cout << "Not Valid Entry" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		if (choice > 6) {
			cout << "Not Valid Entry" << endl;
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);

	while (1) {
		switch (choice) {
		case 1:
			system("cls");
			cout << "Database created.\n";
			cin.ignore();
			cout << "Name (First & Last):";
			getline(cin, name);
			cout << "\nEmail:";
			getline(cin, email);
			cout << "\nPhone Number:";
			getline(cin, phone);

			phone = phoneRefactor(phone);
			while (phone.compare("null") == 0) {
				cout << "Please enter a full 10 digit phone number:" << endl;
				getline(cin, phone);
				phone = phoneRefactor(phone);
			}

			DB.create(name, email, phone);
			choice = next();
			break;

		case 2:
			system("cls");
			
			do {
				cout << "Where in the list do you want data inserted?\n 1.Front\n 2.Back\n";
				if (!(cin >> insertType)) {
					cout << "Please enter numbers only." << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}
			} while (insertType != 1 && insertType != 2);
			
			cin.ignore();
			cout << "Name (First & Last):";
			getline(cin, name);
			cout << "\nEmail:";
			getline(cin, email);
			cout << "\nPhone Number:";
			getline(cin, phone);
			
			phone = phoneRefactor(phone);
			while (phone.compare("null") == 0) {
				cout << "Please enter a full 10 digit phone number:" << endl;
				getline(cin, phone);
				phone = phoneRefactor(phone);
			}

			DB.insertElement(insertType, name, email, phone);
			choice = next();
			break;

		case 3:
			system("cls");
			DB.print();
			choice = next();
			break;

		case 4:
			system("cls");
			DB.saveToFile();
			choice = next();
			break;

		case 5:
			system("cls");
			DB.readFromFile();
			choice = next();
			break;
		case 6:
			system("cls");
			exit(EXIT_SUCCESS);
			break;

		default:
			cout << "Incorrect Selection" << endl;
			cout << "Enter: ";
			cin >> choice;
			break;
		}
	}
	return 0;
}

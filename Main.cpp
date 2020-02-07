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
	people p;
	bool running = true;
	
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

	while (running) {
		switch (choice) {
		case 1:
			system("cls");
			if (DB.check() == 1) {
				cout << "Database has already been created" << endl;
			}
			else {

				cout << "Database created.\n\n";

				cin.ignore();
			
				p = getData(p);

				p.phone = phoneRefactor(p.phone);
				while (p.phone.compare("null") == 0) {
					cout << "Please enter a full 10 digit phone number:" << endl;
					getline(cin, p.phone);
					p.phone = phoneRefactor(p.phone);
				}

				DB.create(p.name, p.email, p.phone);
			}
			choice = next();
			break;

		case 2:
			system("cls");
			if (DB.check() == 0) {
				cout << "You must create database first." << endl;
			}
			else {
				
				insertType = checkInsertType(1, "Where in the list do you want data inserted?\n 1.Front\n 2.Back\n");

				cin.ignore();
				
				p = getData(p);

				p.phone = phoneRefactor(p.phone);
				while (p.phone.compare("null") == 0) {
					cout << "Please enter a full 10 digit phone number:" << endl;
					getline(cin, p.phone);
					p.phone = phoneRefactor(p.phone);
				}

				DB.insertElement(insertType, p.name, p.email, p.phone);
			}
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
			if (!DB.check()) {
				cout << "no database here" << endl;

				insertType = checkInsertType(1, "Do you want to create a database to insert contents of file?\n 1.Yes\n 2.No\n");
		
				if (insertType == 1) {
					DB.createFromFile();
				}
				choice = next();
				break;
			}

			insertType = checkInsertType(1, "Where in the list do you want data inserted?\n 1.Front\n 2.Back\n");

			DB.readFromFile(insertType);
			choice = next();
			break;

		case 6:
			system("cls");
			running = false;
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

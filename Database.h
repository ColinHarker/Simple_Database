#pragma once
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct people {
	string name;
	string email;
	string phone;
};

struct node {
	people info;
	node* next;
	node* previous;
};

class Database {

private:
	node* head; node* tail; node* newNode;

public:
	Database() {
		head = NULL;
		tail = NULL;
		newNode = NULL;
	}
	int create(string n, string e, string p);
	int insertElement(int i, string n, string e, string p);
	void print(void);
	void saveToFile(void);
	void readFromFile(void);
};
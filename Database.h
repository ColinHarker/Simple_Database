#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>

using namespace std;

struct people
{

	string name;
	string email;
	string phone;

	people(){};
	people(string n, string e, string p)
	{
		name = n;
		email = e;
		phone = p;
	}
};

struct node
{
	people info;
	node *next = nullptr;
	node *previous = nullptr;
};

class Database
{

private:
	node *head = nullptr;
	node *tail = nullptr;
	node *newNode = nullptr;

public:
	Database(){};
	int create(string n, string e, string p);
	int insertElement(int i, string n, string e, string p);
	void print(void);
	void saveToFile(void);
	void readFromFile(int);
	void createFromFile(void);
	int check(void);
};

class PrintHeader
{
	string name, email, phone;

public:
	PrintHeader() : name("----"), email("----"), phone("------------\n"){};
	PrintHeader(string n, string e, string p)
	{
		name = n;
		email = e;
		phone = p;
	}
	friend ostream &operator<<(ostream &os, const PrintHeader &ph);
};

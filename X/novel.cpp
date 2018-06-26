#include "book.h"
#include "index.h"
#include "novel.h"
#include "iostream"
#include "STRING.h"
using namespace std;

void novel::Sleep()
{
	for (int i = 0; i < 1000000000; i++);
}

void novel::Welcome()
{
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "						WELCOME TO" << endl;
	cout << "					    Text Search Engine" << endl;
	cout << "					          By M01z" << endl;
	Sleep();
}

novel::novel(STRING n, STRING a, STRING t) :book(n, a, t)
{}

novel::~novel()
{}

void novel::display()
{
	system("cls");
	cout << "***************************************************************************" << endl;
	cout << "Book name is: " << this->getBookName() << endl;
	cout << "Author name is: " << this->getAuthorName() << endl;
	cout << "Book type is: " << this->getType() << endl;
	cout << "***************************************************************************" << endl;
	system("pause");
}

void novel::menu()
{
	int choice;

	this->Welcome();

	while (true)
	{
		system("cls");

		cout << "***************************************************************************" << endl;
		cout << "*		Enter 1 To Make Novel Index.				  *" << endl;
		cout << "*		Enter 2 To Search A Word From Index.			  *" << endl;
		cout << "*		Enter 3 To Display Novel Info.				  *" << endl;
		cout << "*		Enter 4 To Exit.					  *" << endl;
		cout << "*		Please Enter Your Choice?				  *" << endl;
		cout << "***************************************************************************" << endl;
		cout << "Choice: ";
		cin >> choice;

		if (choice == 4)
			break;
		if (choice == 3)
			this->display();
		if (choice == 1)
		{
			system("cls");
			this->object.createIndex();
		}
		if (choice == 2)
		{
			char word[20];
			cout << "Enter word: ";
			cin >> word;
			this->object.searchWord(word);
		}
	}
	
}

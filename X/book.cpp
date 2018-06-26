#include "book.h"
#include "iostream"
using namespace std;

book::book(STRING name, STRING author, STRING type)
{
	this->setBookName(name);
	this->setAuthorName(author);
	this->setType(type);
}

book::~book()
{ }

STRING book::getBookName()
{
	return this->bookname;
}

STRING book::getAuthorName()
{
	return this->author;
}

STRING book::getType()
{
	return this->type;
}

void book::setType(STRING t)
{
	this->type = t;
}

void book::setBookName(STRING name)
{
	this->bookname = name;
}

void book::setAuthorName(STRING name)
{
	this->author = name;
}

void book::display()
{}
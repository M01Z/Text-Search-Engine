#pragma once
#include "STRING.h"

class book
{
	STRING bookname;
	STRING author;
	STRING type;

public:
	book(STRING = '\0', STRING = '\0', STRING = '\0');
	~book();

	STRING getBookName();
	STRING getAuthorName();
	STRING getType();

	void setType(STRING);
	void setBookName(STRING);
	void setAuthorName(STRING);
	virtual void display() = 0;
};
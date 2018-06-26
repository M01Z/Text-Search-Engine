#pragma once
#include "iostream"
using namespace std;

class STRING
{
	char*data;
	int length;

public:
	STRING();
	STRING(char*);
	STRING(const STRING&);

	void swap(STRING&);
	void setString(char*);

	char* getString() const;
	int getLength(char*) const;

	void operator = (const STRING&);
	bool operator==(const STRING&);
	void operator+(const STRING&);

	//********************TOOK THESE TWO FUNCTIONS FROM INTERNET*****************************
	friend ostream& operator << (ostream & OS, const STRING &S);
	friend istream& operator >> (istream & IS, STRING &S);
};



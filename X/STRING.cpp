#include "STRING.h"
#include "iostream"
using namespace std;

STRING::STRING()
{
	this->data = NULL;
	this->length = 0;
}

STRING::STRING(char*data_)
{
	this->setString(data_);
}

void STRING::setString(char* data_)
{
	this->length = getLength(data_);
	this->data = new char[length + 1];

	for (int i = 0; i < length; i++)
		this->data[i] = data_[i];

	this->data[length] = NULL;
}

STRING::STRING(const STRING& obj)
{
	this->setString(obj.getString());
}

void STRING::swap(STRING& obj)
{
	STRING temp(obj);

	obj.setString(this->getString());
	this->setString(temp.getString());
}

char* STRING::getString() const
{
	return this->data;
}

int STRING::getLength(char*obj) const
{
	return strlen(obj);
}

ostream& operator <<(ostream & OS, const STRING& S)
{
	if (S.getString() == NULL)
	{
		OS << "";
		return OS;
	}

	OS << S.getString();
	return OS;
}

void STRING::operator=(const STRING& obj)
{
	this->setString(obj.getString());
}

void STRING::operator+(const STRING& obj)
{
	int l1 = strlen(this->data) + strlen(obj.data) + 3;
	char*temp = new char[l1];
	
	int index = 0;
	l1 = strlen(this->data);

	for (int i = 0; i < l1; i++, index++)
		temp[index] = this->data[i];

	temp[index] = ' ';
	index++;

	l1 = strlen(obj.data);
	for (int i = 0; i < l1; i++, index++)
		temp[index] = obj.data[i];

	temp[index] = NULL;

	this->setString(temp);
}

bool STRING::operator==(const STRING& obj)
{
	if (this->getLength(this->data) == obj.getLength(obj.data))
	{
		int length = this->getLength(this->data);

		for (int i = 0; i < length; i++)
		{
			if (this->data[i] != obj.data[i])
				return false;
		}

		return true;
	}

	return false;
}

istream& operator >>(istream & IS, STRING& S)
{
	char* input = new char[100];
	IS.getline(input, 100);

	int i = 0;
	while (input[i] != '\0')
	{
		i++;
	}
	S.length = i + 1;
	delete[]S.data;
	S.data = new char[(i + 1)];
	for (int j = 0; j < (i); j++)
	{
		S.data[j] = input[j];
	}
	S.data[i] = '\0';
	delete[]input;
	return IS;
}

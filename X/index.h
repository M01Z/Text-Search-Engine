#pragma once

class index
{
	void toLowerCase(char[]);
	void sortIndex();
	void removeDuplicates();
	bool checkDuplicates(char[]);
	bool compare(char[],char[]);
public:
	index();
	~index();

	void searchWord(char[]);
	void createIndex();
};
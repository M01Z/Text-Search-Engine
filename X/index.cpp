#include "iostream"
#include "fstream"
#include "index.h"
using namespace std;

index::index()
{ }

index::~index()
{ }

void index::searchWord(char find[])
{
	int l1 = strlen(find), l2;
	char word[5000];
	char temp[200];
	int index = 0;
	bool flag = false;

	ifstream input("index.txt");
	if (!input.is_open())
		cout << "WARNING ! INDEX FILE MISSING" << endl;

	while (true)
	{
		input.getline(word, 5000, ',');
		if (input.eof())
			break;

		for (int i = 0; true; i++)
		{
			if (word[i] != ' ' && word[i] != '\n')
			{
				temp[index] = word[i];
				index++;
			}

			if (word[i] == ' ')
			{
				temp[index] = '\0';
				l2 = strlen(temp);

				if (l2 == l1)
				{
					if (compare(find, temp))
					{
						cout << word << endl;
						system("pause");
						flag = true;
					}
				}

				index = 0;
				break;
			}
		}

		if (flag)
			break;
	}

	if (!flag)
	{
		cout << "No such word found" << endl;
		system("pause");
	}

}
void index::toLowerCase(char word[])
{
	int length = strlen(word);
	for (int i = 0; i < length; i++)
	{
		if (word[i] >= 65 && word[i] <= 90)
			word[i] = word[i] + 32;
	}
}

void index::sortIndex()
{
	ifstream input;
	ofstream output("temp2.txt");

	char word[50];
	int num1, num2;

	for (int i = 97; i <= 122; i++)
	{
		input.open("temp.txt");
		while (true)
		{
			input >> word >> num1 >> num2;

			if (word[0] == i)
				output << word << " " << num1 << " " << num2 << endl;

			if (input.eof())
				break;
		}
		input.close();
	}

	output.close();
}

bool index::compare(char word1[], char word2[])
{
	int length = strlen(word1);

	for (int i = 0; i < length; i++)
	{
		if (word1[i] != word2[i])
			return false;
	}
	return true;
}

bool index::checkDuplicates(char find[])
{
	int length1 = strlen(find), length2;
	char sentence[5000];
	char word[100];
	int index = 0;

	ifstream input("index.txt");
	while (true)
	{
		index = 0;
		input.getline(sentence, 5000);

		for (int j = 0; true; j++)
		{
			if (sentence[j] != ' ' && sentence[j] != '\0')
			{
				word[index] = sentence[j];
				index++;
			}

			if (sentence[j] == ' ' || sentence[j] == '\0')
				break;
		}

		word[index] = '\0';
		length2 = strlen(word);

		if (length1 == length2)
		{
			if (compare(find, word))
				return false;
		}

		if (input.eof())
			break;
	}

	return true;
}

void index::removeDuplicates()
{
	int count = 0;
	char word[200], temp[200];
	int file, line, temp_file, temp_line;
	int l1, l2;
	bool flag;

	ofstream output("index.txt");
	ifstream input("temp2.txt");
	ifstream input2;

	while (true)
	{
		input >> word >> file >> line;
		if (input.eof())
			break;

		flag = checkDuplicates(word);

		if (flag)
		{
			l1 = strlen(word);

			cout << word << " ";
			output << word << " ";

			input2.open("temp2.txt");
			while (true)
			{
				input2 >> temp >> temp_file >> temp_line;
				l2 = strlen(temp);
				if (input2.eof())
					break;

				if (l2 == l1)
				{
					if (compare(temp, word))
					{
						count++;
						cout << temp_file << " " << temp_line << " ";
						output << temp_file << " " << temp_line << " ";
					}
				}
			}
			input2.close();

			cout << endl;
			output << "," << endl;
		}
	}
}

void index::createIndex()
{
	char filename[7];
	int file;
	char sentence[500];
	char word[200];
	int line_Number = 1, index = 0;

	ofstream output("temp.txt");
	ifstream input("filenames.txt");
	if (!input.is_open())
		cout << "Warning ! filenames.txt Not Opened" << endl;
	ifstream input2;

	for (int i = 0; i < 50; i++)
	{
		line_Number = 1;
		input >> filename;
		input >> file;

		if (input.eof())
			break;

		input2.open(filename);
		while (true)
		{
			input2.getline(sentence, 500);
			if (input2.eof())
				break;

			for (int i = 0; true; i++)
			{
				if (sentence[i] != ' ' && sentence[i] != '\0' && sentence[i] != '‘' && sentence[i] != '-' && sentence[i] != '.' && sentence[i] != ',' && sentence[i] != '?' && sentence[i] != '!' && sentence[i] != '”' && sentence[i] != '“' && sentence[i] != ';' && sentence[i] != '’')
				{
					word[index] = sentence[i];
					index++;
				}

				if (sentence[i] == ' ')
				{
					word[index] = '\0';
					toLowerCase(word);

					output << word << "  " << file << "  " << line_Number << endl;
					index = 0;
				}

				if (sentence[i] == '\0')
					break;
			}

			line_Number++;
		}
		input2.close();

	}
	input.close();
	output.close();

	sortIndex();

	cout << "Making index! It may take some time! Please wait" << endl;
	removeDuplicates();

	system("cls");
	cout << "-----------------FINISHED------------------" << endl;
}

#include "book.h"
#include "index.h"

class novel :private book
{
	index object;
	void display();
	void Sleep();
	void Welcome();

public:
	novel(STRING = '\0', STRING = '\0', STRING = '\0');
	~novel();
	void menu();
};
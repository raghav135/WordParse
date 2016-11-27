#pragma once
#include <ostream>
using namespace std;

class Item
{
public:
	Item();
	Item(char c);
	char get() const;
	bool operator==(const Item& in);
	Item& operator=(const Item& in);
	int getIndex();
	void setComplete();
	bool isComplete();
	friend ostream& operator<<(ostream& os, const Item& in);
private:
	char _c;
};
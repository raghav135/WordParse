#pragma once
class Item
{
public:
	Item(char c);
	char get();
	bool operator==(const Item& in);
	int getIndex();
private:
	char _c;
};
#pragma once
class Item
{
public:
	Item(char c);
	char get() const;
	bool operator==(const Item& in);
	int getIndex();
	void setComplete();
	bool isComplete();
private:
	char _c;
};
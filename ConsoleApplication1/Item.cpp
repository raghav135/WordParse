#include "stdafx.h"
#include "Item.h"

Item::Item()
{
	_c = '\0';
}

Item::Item(char c)
{
	_c = c;
}

// store two information in this char (_c)
// store the character (a-z)
// In the Most significant bit, store if with this item, there is a word in the tree.

char Item::get() const
{
	return 0x7F & _c;
}

bool Item::operator==(const Item& in)
{
	return get() == in.get();
}

int Item::getIndex()
{
	return _c - 'a';
}

void Item::setComplete()
{
	_c = 0x80 | _c;
}

bool Item::isComplete()
{
	return 0x80 & _c;
}

Item& Item::operator=(const Item& in)
{
	_c = in._c;
	return *this;
}


ostream& operator<<(ostream& os, const Item& in) {
	os << in.get();
	return os;
}

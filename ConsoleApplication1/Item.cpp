#include "stdafx.h"
#include "Item.h"

Item::Item(char c)
{
	_c = c;
}

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

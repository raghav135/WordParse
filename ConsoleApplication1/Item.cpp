#include "stdafx.h"
#include "Item.h"

Item::Item(char c)
{
	_c = c;
}

char Item::get()
{
	return _c;
}

bool Item::operator==(const Item& in)
{
	return _c == in._c;
}

int Item::getIndex()
{
	return _c - 'a';
}

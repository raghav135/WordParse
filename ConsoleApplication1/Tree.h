#pragma once
#include <vector>
#include <ostream>
#include <iostream>
using namespace std;

template <class T> class Tree
{
public:
	Tree() : _parent(NULL), _childNodes(NULL) {}
	void set(const T& obj) {
		_obj = obj;
	}
	void addChild(Tree<T>* in) {
		if (!_childNodes) {
			_childNodes = new vector<Tree<T>* >();
		}
		in->_parent = this;
		_childNodes->push_back(in);
	}
	void print(string indent) {
		cout << indent << _obj << endl;
		if (_childNodes) {
			for (std::vector<Tree<T>*>::iterator it = (*_childNodes).begin(); it != (*_childNodes).end(); ++it) {
				(**it).print(indent + indent);
			}
		}
	}
private:
	T _obj;
	Tree<T>* _parent;
	vector<Tree<T>*>* _childNodes;
};

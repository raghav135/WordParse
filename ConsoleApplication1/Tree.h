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
	T& get() {
		return _obj;
	}
	Tree<T>* getChild(const T& in) {
		if (!_childNodes)
		{
			return NULL;
		}
		Tree<T>* ret = NULL;
		for (vector<Tree<T>*>::iterator it = (*_childNodes).begin(); it != (*_childNodes).end(); ++it)
		{
			if ((*it)->_obj == in)
			{
				ret = *it;
				break;
			}
		}
		return ret;
	}
	Tree<T>* addChild(const T& in) {
		if (!_childNodes) {
			_childNodes = new vector<Tree<T>* >();
		}
		Tree<T>* ret = NULL;
		for (vector<Tree<T>*>::iterator it = (*_childNodes).begin(); it != (*_childNodes).end(); ++it)
		{
			if ((*it)->_obj == in)
			{
				ret = *it;
				break;
			}
		}
		if (!ret)
		{
			ret = new Tree<T>();
			ret->set(in);
			ret->_parent = this;
			_childNodes->push_back(ret);
		}
		return ret;
	}
	void print(string indent) {
		cout << indent << _obj << endl;
		if (_childNodes) {
			for (std::vector<Tree<T>*>::iterator it = (*_childNodes).begin(); it != (*_childNodes).end(); ++it) {
				(**it).print(indent + indent[0]);
			}
		}
	}
	vector<Tree<T>*>* getChildren() {
		return _childNodes;
	}
private:
	T _obj;
	Tree<T>* _parent;
	vector<Tree<T>*>* _childNodes;
};

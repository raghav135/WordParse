// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Tree.h"
#include "Item.h"
using namespace std;

void parseString(const string& in, Tree<Item>& tree)
{
	string& ncIn = const_cast<string&>(in);
	Tree<Item>* curTree = &tree;

	for (string::iterator it = ncIn.begin(); it != ncIn.end(); ++it)
	{
		Item item(*it);
		curTree = curTree->addChild(item);
	}
	curTree->get().setComplete();
}

void printWordsFromTree(const string& prefix, Tree<Item>* mytree)
{
	vector<Tree<Item>*>* children = mytree->getChildren();
	if (!children) {
		return;
	}
	for (vector<Tree<Item>*>::iterator it = (*children).begin(); it != (*children).end(); ++it) {
		if ((**it).get().isComplete()) {
			cout << prefix << (**it).get().get() << endl;
		}
		printWordsFromTree(prefix + (**it).get().get(), *it);
	}

}

void printSuggestions(const string& in, Tree<Item>& mytree)
{
	string& ncIn = const_cast<string&>(in);
	Tree<Item>* curTree = &mytree;

	for (string::iterator it = ncIn.begin(); it != ncIn.end(); ++it)
	{
		Item item(*it);
		curTree = curTree->getChild(item);
		if (!curTree)
			break;
	}
	if (curTree && curTree->get().isComplete()) {
		cout << in << endl;
	}
	if (curTree)
		printWordsFromTree(in, curTree);
	else
		cout << "no words found" << endl;
}



int main()
{
	ifstream file("dict.txt");
	Tree<Item> mytree;
	mytree.set(Item(' '));

	if (!file.is_open()) {
		cerr << "Unable to open dictionary" << endl;
		return 1;
	}
	string abc;
	cout << "parsing started, please wait for few minutes..." << endl;
	while (getline(file, abc))
	{
		parseString(abc, mytree);
	}
	cout << "parsing complete..." << endl;

	string in;

	do
	{
		cout << "Enter part of string to search: ";
		cin >> in;
		printSuggestions(in, mytree);
	} while (1 == 1);
	
	file.close();
    return 0;
}


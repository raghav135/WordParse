// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Tree.h"
#include "Item.h"
using namespace std;

int main()
{
	ifstream file("dict.txt");
	Tree<int> mytree;
	mytree.set(1);
	Tree<int>* mytree1 = new Tree<int>();
	mytree1->set(2);
	mytree.addChild(mytree1);
	Tree<int>* mytree12 = new Tree<int>();
	mytree12->set(3);
	mytree.addChild(mytree12);
	Tree<int>* mytree2 = new Tree<int>();
	mytree2->set(3);
	mytree1->addChild(mytree2);
	mytree.print(" ");

	if (!file.is_open()) {
		cerr << "Unable to open dictionary" << endl;
		return 1;
	}
	string abc;
	//while (getline(file, abc))
	//{
		//cout << abc << endl;
	//}
	file.close();
    return 0;
}


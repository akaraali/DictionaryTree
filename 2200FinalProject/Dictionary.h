#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string>
#include "WordNode.h"
using namespace std;

class Dictionary
{
public:
	Dictionary();
	bool isEmpty();
	int getSize();
	void insert(string word);
	bool find(string word, WordNode *& x);
	void printSorted();
	void remove(string word);

private:
	WordNode *&  t;
};


#endif
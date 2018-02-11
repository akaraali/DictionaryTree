#include "DictionaryImp.cpp"
#include "Dictionary.h"


int main()
{
	Dictionary test1;
	test1.insert("sgsdgdsg");
	test1.insert("ok");
	test1.insert("ak");
	test1.insert("bk");
	test1.insert("ak");
	test1.printSorted();
}

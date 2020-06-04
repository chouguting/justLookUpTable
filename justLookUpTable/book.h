#pragma once
#include <string>
#include <iostream>
struct treeNodeTP;
class LookUpTable;
using namespace std;
class book
{
	friend ostream& operator<<(ostream&, const book&);
	friend class adaptee;
	friend class adaptee2;
	friend int sumTree(treeNodeTP*& tree);
	friend int max(treeNodeTP*& tree, int& i, treeNodeTP*& temp);
	friend int min(treeNodeTP*& tree, int& i, treeNodeTP*& temp);
	friend void test(LookUpTable* ptr);
	friend void printFun(book a);
	friend int compareFun(book a, book b);
private:
	string* bookName;
	string* authors;
	int price;

	// ...
public:

	book() :price(0) {}
	
	book(const char* b, const char* a, const int p)
	{
		bookName = new string(b);		authors = new string(a);		price = p;
	}

	
	void assign(const char* b, const char* a, const int p)
	{
		bookName =  new string(b) ;		authors = new string(a);		price = p;
	}

	
	
};

ostream& operator<<(ostream& os, const book& b);

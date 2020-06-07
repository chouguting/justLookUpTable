#include "book.h"
#include "lookUpTable.h"





void test(LookUpTable* ptr);

void main()
{
	LookUpTable* ptr;
	
	// Adaptee 1
	ptr = new 	adapter_class;
	test(ptr);
	delete ptr;

	system("pause");
	system("cls");
	
	ptr = new 	adapter_object;
	test(ptr);
	delete ptr;

	system("pause");
	system("cls");

	// Adaptee 2
	ptr = new 	adapter_class2;
	test(ptr);
	delete ptr;

	system("pause");
	system("cls");

	ptr = new 	adapter_object2;
	test(ptr);
	delete ptr;

	system("pause");
	system("cls");
	
	// Adaptee 3
	ptr = new 	adapter_class3;
	test(ptr);
	delete ptr;


	system("pause");
	system("cls");

	
	ptr = new 	adapter_object3;
	test(ptr);
	delete ptr;


	system("pause");
	system("cls");


	// Adaptee 4
	ptr = new 	adapter_class4;
	test(ptr);
	delete ptr;


	system("pause");
	system("cls");


	ptr = new 	adapter_object4;
	test(ptr);
	delete ptr;


	system("pause");
	system("cls");

	
}
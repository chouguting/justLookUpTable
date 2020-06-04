#include "book.h"
#include "lookUpTable.h"

void run_LookupTable(LookUpTable* ptr) {
	cout << "Test LookupTable " << endl;
	//add 
	cout << "Test add" << endl;
	book val("��q���ǿ��ѧ޳N�G����ABBYY FineReader 11 OCR", "�����q", 371);
	cout << ptr->add(val) << endl;	//�^�Ǧ��\(1)  
	val.assign("VISUAL FORTRAN�{���]�p�P�}�o", "�i�űj�B���E��", 402);
	cout << ptr->add(val) << endl;	//�^�Ǧ��\(1)  
	val.assign("�{���]�p�Шϥ�C++", "���خx", 420);
	cout << ptr->add(val) << endl;	//�^�Ǧ��\(1) 

	val.assign("VISUAL FORTRAN�{���]�p�P�}�o", "�i�űj�B���E��", 404);
	cout << ptr->add(val) << endl;	//�^�ǥ���(0) 
	val.assign("�{���]�p�Шϥ�C++", "���خx", 420);
	cout << ptr->add(val) << endl;	//�^�ǥ���(0) 

//remove 
	cout << endl << "Test remove" << endl;
	val.assign("VISUAL FORTRAN�{���]�p�P�}�o", "�i�űj�B���E��", 200);
	cout << ptr->remove(val) << endl;	//�^�Ǧ��\(1)  
	cout << ptr->remove(val) << endl;	//�^�ǥ���(0) 
	
//get 
	cout << endl << "Test get" << endl;

	cout << ptr->find("��q���ǿ��ѧ޳N�G����ABBYY FineReader 11 OCR") << endl;	//�^�Ǧ��\(1) 
	cout << ptr->find("VISUAL FORTRAN�{���]�p�P�}�o") << endl;	//�^�ǥ���(0)
	cout << ptr->find("�{���]�p�Шϥ�C++", "���خx") << endl;	//�^�Ǧ��\(1)

	cout << "most expensive: " << ptr->mostExpensive() << endl;
	cout << "cheapest: " << ptr->cheapest() << endl;

}

void testMap()
{
	map<string, book> mapbook;		//key:string value:book
	cout << "Test Map" << endl;

	//add: ���J����
	book val("��q���ǿ��ѧ޳N�G����ABBYY FineReader 11 OCR", "�����q", 371);
	mapbook.insert(pair<string, book>("��q���ǿ��ѧ޳N�G����ABBYY FineReader 11 OCR", val));

	val.assign("VISUAL FORTRAN�{���]�p�P�}�o", "�i�űj�B���E��", 400);
	mapbook.insert(pair<string, book>("VISUAL FORTRAN�{���]�p�P�}�o", val));

	val.assign("�{���]�p�Шϥ�C++", "���خx", 420);
	mapbook.insert(pair<string, book>("�{���]�p�Шϥ�C++", val));

	for (auto it = mapbook.begin(); it != mapbook.end(); it++)
		cout << "key:" << it->first << ' ' << it->second << endl;

	//find 
	auto f = mapbook.find("VISUAL FORTRAN�{���]�p�P�}�o");
	if (f == mapbook.end())
		cout << "�S��� VISUAL FORTRAN�{���]�p�P�}�o" << endl;
	else
		cout << "��� VISUAL FORTRAN�{���]�p�P�}�o" << endl;

	f = mapbook.find("VISUAL FORTRAN");
	if (f == mapbook.end())
		cout << "�S��� VISUAL FORTRAN" << endl;
	else
		cout << "��� VISUAL FORTRAN" << endl;

	//�R������ find and erase the element
	f = mapbook.find("VISUAL FORTRAN�{���]�p�P�}�o");
	if (f == mapbook.end())
		cout << "�S��� VISUAL FORTRAN�{���]�p�P�}�o" << endl;
	else
	{
		cout << "�R�� VISUAL FORTRAN�{���]�p�P�}�o" << endl;
		mapbook.erase(f);
	}

	f = mapbook.find("VISUAL FORTRAN�{���]�p�P�}�o");
	if (f == mapbook.end())
		cout << "�S��� VISUAL FORTRAN�{���]�p�P�}�o" << endl;
	else
		cout << "��� VISUAL FORTRAN�{���]�p�P�}�o" << endl;

	cout << endl << endl;
}

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
}
#include "book.h"
#include "lookUpTable.h"

void run_LookupTable(LookUpTable* ptr) {
	cout << "Test LookupTable " << endl;
	//add 
	cout << "Test add" << endl;
	book val("精通光學辨識技術：應用ABBYY FineReader 11 OCR", "黃敦義", 371);
	cout << ptr->add(val) << endl;	//回傳成功(1)  
	val.assign("VISUAL FORTRAN程式設計與開發", "張嘉強、陳鴻智", 402);
	cout << ptr->add(val) << endl;	//回傳成功(1)  
	val.assign("程式設計－使用C++", "黃建庭", 420);
	cout << ptr->add(val) << endl;	//回傳成功(1) 

	val.assign("VISUAL FORTRAN程式設計與開發", "張嘉強、陳鴻智", 404);
	cout << ptr->add(val) << endl;	//回傳失敗(0) 
	val.assign("程式設計－使用C++", "黃建庭", 420);
	cout << ptr->add(val) << endl;	//回傳失敗(0) 

//remove 
	cout << endl << "Test remove" << endl;
	val.assign("VISUAL FORTRAN程式設計與開發", "張嘉強、陳鴻智", 200);
	cout << ptr->remove(val) << endl;	//回傳成功(1)  
	cout << ptr->remove(val) << endl;	//回傳失敗(0) 
	
//get 
	cout << endl << "Test get" << endl;

	cout << ptr->find("精通光學辨識技術：應用ABBYY FineReader 11 OCR") << endl;	//回傳成功(1) 
	cout << ptr->find("VISUAL FORTRAN程式設計與開發") << endl;	//回傳失敗(0)
	cout << ptr->find("程式設計－使用C++", "黃建庭") << endl;	//回傳成功(1)

	cout << "most expensive: " << ptr->mostExpensive() << endl;
	cout << "cheapest: " << ptr->cheapest() << endl;

}

void testMap()
{
	map<string, book> mapbook;		//key:string value:book
	cout << "Test Map" << endl;

	//add: 插入元素
	book val("精通光學辨識技術：應用ABBYY FineReader 11 OCR", "黃敦義", 371);
	mapbook.insert(pair<string, book>("精通光學辨識技術：應用ABBYY FineReader 11 OCR", val));

	val.assign("VISUAL FORTRAN程式設計與開發", "張嘉強、陳鴻智", 400);
	mapbook.insert(pair<string, book>("VISUAL FORTRAN程式設計與開發", val));

	val.assign("程式設計－使用C++", "黃建庭", 420);
	mapbook.insert(pair<string, book>("程式設計－使用C++", val));

	for (auto it = mapbook.begin(); it != mapbook.end(); it++)
		cout << "key:" << it->first << ' ' << it->second << endl;

	//find 
	auto f = mapbook.find("VISUAL FORTRAN程式設計與開發");
	if (f == mapbook.end())
		cout << "沒找到 VISUAL FORTRAN程式設計與開發" << endl;
	else
		cout << "找到 VISUAL FORTRAN程式設計與開發" << endl;

	f = mapbook.find("VISUAL FORTRAN");
	if (f == mapbook.end())
		cout << "沒找到 VISUAL FORTRAN" << endl;
	else
		cout << "找到 VISUAL FORTRAN" << endl;

	//刪除元素 find and erase the element
	f = mapbook.find("VISUAL FORTRAN程式設計與開發");
	if (f == mapbook.end())
		cout << "沒找到 VISUAL FORTRAN程式設計與開發" << endl;
	else
	{
		cout << "刪除 VISUAL FORTRAN程式設計與開發" << endl;
		mapbook.erase(f);
	}

	f = mapbook.find("VISUAL FORTRAN程式設計與開發");
	if (f == mapbook.end())
		cout << "沒找到 VISUAL FORTRAN程式設計與開發" << endl;
	else
		cout << "找到 VISUAL FORTRAN程式設計與開發" << endl;

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
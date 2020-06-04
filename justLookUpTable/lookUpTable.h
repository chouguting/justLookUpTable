#pragma once
#include <map>

#include "book.h"
#include "adaptee.h"



class LookUpTable
{
public:
	virtual int add(const book) = 0; //�[�J�@�ӭ� �^�Ǧ��\(1) ����(0)
	virtual int remove(const book) = 0; //�R���@�ӭ� �^�Ǧ��\(1) ����(0)
	virtual int   remove(const char* bookName, const char* authors, const int price)=0;
	virtual book* find(const char* bookName) = 0;	//�d�ߤ@�ӭ�
	virtual book* find(const char* bookName, const char* authors)=0;
	virtual book mostExpensive() = 0;  //�^�ǳ̶Q���� 
	virtual book cheapest() = 0;  	  //�^�ǳ̫K�y���� 
	virtual float   average() = 0;    //�^�ǥ����ѻ���
	virtual void  clean( ) =0;        //�M������ LookUpQueue Data
	
	

};




class adapter_class :public LookUpTable, public adaptee {
	int result;
public:
	int add(const book a) {
		adaptee::add(a, result);
		return result;
	} //TODO //�[�J�@�ӭ� �^�Ǧ��\(1) ����(0)
	int remove(const book a) {
		adaptee::remove(a, result);
		return result;
	} //TODO //�R���@�ӭ� �^�Ǧ��\(1) ����(0)

	int   remove(const char* bookName, const char* authors, const int price)
	{
		book temp(bookName,authors,price);
		adaptee::remove(temp, result);
		return result;
	}
	book* find(const char* bookName) {
		\
			book* ptr;
		adaptee::find(bookName, ptr);
		return ptr;
	} //TODO //�d�ߤ@�ӭ�
	book* find(const char* bookName, const char* authors)
	{
		book* ptr;
		adaptee::find(bookName, authors, ptr);
		return ptr;

	}
	
	
	book mostExpensive()
	{
		book* ptr;
		adaptee::mostExpensive( ptr);
		return *ptr;
	}
	book cheapest()
	{
		book* ptr;
		adaptee::cheapest(ptr);
		return *ptr;
	}  	  
	float   average()
	{
		return  adaptee::average();
	}  
	void  clean()
	{
		adaptee::clean();
	}

};


class adapter_object :public LookUpTable {
private:
	adaptee ad;
	int result;
public:
	int add(const book a) {
		ad.add(a, result);
		return result;
	} //TODO //�[�J�@�ӭ� �^�Ǧ��\(1) ����(0)
	int remove(const book a) {
		ad.remove(a, result);
		return result;
	} //TODO //�R���@�ӭ� �^�Ǧ��\(1) ����(0)

	int   remove(const char* bookName, const char* authors, const int price)
	{
		book temp(bookName, authors, price);
		ad.remove(temp, result);
		return result;

	}
	book* find(const char* bookName) {
		book* ptr;
		ad.find(bookName, ptr);
		return ptr;
	}
	book* find(const char* bookName, const char* authors)
	{
		book* ptr;
		ad.find(bookName,authors, ptr);
		return ptr;

	}
	book mostExpensive()
	{
		book* ptr;
		ad.mostExpensive(ptr);
		return *ptr;
	}
	book cheapest()
	{
		book* ptr;
		ad.cheapest(ptr);
		return *ptr;
	}
	float   average()
	{
		return  ad.average();
	}
	 void  clean()
	{
		ad.clean();
	}

};



class adapter_class2 :public LookUpTable, public adaptee2 {
	int result;
public:
	int add(const book a) {
		adaptee2::add(a, result);
		return result;
	} //TODO //�[�J�@�ӭ� �^�Ǧ��\(1) ����(0)
	int remove(const book a) {
		adaptee2::remove(a, result);
		return result;
	} //TODO //�R���@�ӭ� �^�Ǧ��\(1) ����(0)

	int   remove(const char* bookName, const char* authors, const int price)
	{
		book temp(bookName, authors, price);
		adaptee2::remove(temp, result);
		return result;
	}
	book* find(const char* bookName) {
		\
			book* ptr;
		adaptee2::find(bookName, ptr);
		return ptr;
	} //TODO //�d�ߤ@�ӭ�
	book* find(const char* bookName, const char* authors)
	{
		book* ptr;
		adaptee2::find(bookName, authors, ptr);
		return ptr;

	}


	book mostExpensive()
	{
		book* ptr;
		adaptee2::mostExpensive(ptr);
		return *ptr;
	}
	book cheapest()
	{
		book* ptr;
		adaptee2::cheapest(ptr);
		return *ptr;
	}
	float   average()
	{
		return  adaptee2::average();
	}
	void  clean()
	{
		adaptee2::clean();
	}

};


class adapter_object2 :public LookUpTable {
private:
	adaptee2 ad;
	int result;
public:
	int add(const book a) {
		ad.add(a, result);
		return result;
	} //TODO //�[�J�@�ӭ� �^�Ǧ��\(1) ����(0)
	int remove(const book a) {
		ad.remove(a, result);
		return result;
	} //TODO //�R���@�ӭ� �^�Ǧ��\(1) ����(0)

	int   remove(const char* bookName, const char* authors, const int price)
	{
		book temp(bookName, authors, price);
		ad.remove(temp, result);
		return result;

	}
	book* find(const char* bookName) {
		book* ptr;
		ad.find(bookName, ptr);
		return ptr;
	}
	book* find(const char* bookName, const char* authors)
	{
		book* ptr;
		ad.find(bookName, authors, ptr);
		return ptr;

	}
	book mostExpensive()
	{
		book* ptr;
		ad.mostExpensive(ptr);
		return *ptr;
	}
	book cheapest()
	{
		book* ptr;
		ad.cheapest(ptr);
		return *ptr;
	}
	float   average()
	{
		return  ad.average();
	}
	void  clean()
	{
		ad.clean();
	}

};


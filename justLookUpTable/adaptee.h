#pragma once
#include <map>
#include <set>
#include <vector>
#include <xlocmon>



#include "binaryTree.h"


class adaptee
{
private:
	map<string, book> mapbook;

	//TODO
public:
	void add(const book value, int& result)
	{
		auto f = mapbook.find(*(value.bookName));
		if (f == mapbook.end())
		{
			result = 1;
			mapbook.insert(pair<string, book>(*(value.bookName), value));
		}
		else
		{
			result = 0;
		}
	}

	//加入一個值 成功result設成1  失敗result設成0
	void remove(const book value, int& result)
	{
		auto f = mapbook.find(*(value.bookName));
		if (f == mapbook.end())
		{
			//cout << "沒找到 " << *(value.bookName) << endl;
			result = 0;
		}
		else
		{
			//cout << "刪除 " << *(value.bookName) << endl;
			mapbook.erase(f);
			result = 1;
		}
	}

	//刪除一個值 成功result設成1  失敗result設成0
	void find(const char* bookName, book*& ptr)
	{
		auto f = mapbook.find(bookName);
		if (f == mapbook.end())
		{
			ptr = nullptr;
		}
		else
		{
			ptr = &(f->second);
		}
	}

	void find(const char* bookName, const char* authors, book*& ptr)
	{
		auto f = mapbook.find(bookName);
		if (f == mapbook.end())
		{
			ptr = nullptr;
		}
		else
		{
			if (strcmp((f->second.authors)->c_str(), authors) == 0)
			{
				ptr = &(f->second);
			}
			else
			{
				ptr = nullptr;
			}
		}
	}

	void mostExpensive(book*& ptr)
	{
		auto it = mapbook.begin();
		int mostCost = it->second.price;
		ptr = &(it->second);
		while (it != mapbook.end())
		{
			if (it->second.price > mostCost)
			{
				mostCost = it->second.price;
				ptr = &(it->second);
			}
			++it;
		}
	}

	void cheapest(book*& ptr)
	{
		auto it = mapbook.begin();
		int mostCost = it->second.price;
		ptr = &(it->second);
		while (it != mapbook.end())
		{
			if (it->second.price < mostCost)
			{
				mostCost = it->second.price;
				ptr = &(it->second);
			}
			++it;
		}
	}

	float average()
	{
		float sum = 0.0f;
		int count = 0;
		auto it = mapbook.begin();


		while (it != mapbook.end())
		{
			sum += it->second.price;
			count++;
			++it;
		}
		return sum / count;
	}

	void clean()
	{
		mapbook.clear();
	}

	//查詢一個值   成功 指標ptr指到table的值
	//失敗 指標ptr設成0
};

//TODO: YAYUN 

class adaptee2
{
private:
	treeNodeTP* rootNode = nullptr;
	//TODO
public:
	void add(const book value, int& result)
	{
		
		result=insertNodeTP(rootNode, value);
	}

	//加入一個值 成功result設成1  失敗result設成0
	void remove(const book value, int& result)
	{
		result=deleteNodeTP(rootNode, value);
	}

	//刪除一個值 成功result設成1  失敗result設成0
	void find(const char* bookName, book*& ptr)
	{
		book temp;
		temp.assign(bookName, "0", 371);
 		ptr = &(locateNode(rootNode,temp)->data);
	}

	void find(const char* bookName, const char* authors, book*& ptr)
	{
		book temp;
		temp.assign(bookName, authors, 371);
		ptr = &(locateNode(rootNode, temp)->data);
	}

	void mostExpensive(book*& ptr)
	{
		treeNodeTP* temp = nullptr;
		int maxN = 0;
		max(rootNode, maxN, temp);
		if(temp!=nullptr)
		{
			ptr = &temp->data;
		}
	}

	void cheapest(book*& ptr)
	{
		treeNodeTP* temp = nullptr;
		int minN = 1000000;
		min(rootNode, minN, temp);
		if (temp != nullptr)
		{
			ptr = &temp->data;
		}
	}

	float average()
	{
		int sum = sumTree(rootNode);
		int count = binarytree_count(rootNode);
		return (float)sum / count;
	}

	void clean()
	{
		deleteTree(rootNode);
	}
};




class adaptee3
{
private:
	std::multimap<string, book> multiMapBook;

	//TODO
public:
	void add(const book value, int& result)
	{
		auto f = multiMapBook.find(*(value.bookName));
		if (f == multiMapBook.end())
		{
			result = 1;
			multiMapBook.insert(pair<string, book>(*(value.bookName), value));
		}
		else
		{
			result = 0;
		}
	}

	//加入一個值 成功result設成1  失敗result設成0
	void remove(const book value, int& result)
	{
		auto f = multiMapBook.find(*(value.bookName));
		if (f == multiMapBook.end())
		{
			//cout << "沒找到 " << *(value.bookName) << endl;
			result = 0;
		}
		else
		{
			//cout << "刪除 " << *(value.bookName) << endl;
			multiMapBook.erase(f);
			result = 1;
		}
	}

	//刪除一個值 成功result設成1  失敗result設成0
	void find(const char* bookName, book*& ptr)
	{
		auto f = multiMapBook.find(bookName);
		if (f == multiMapBook.end())
		{
			ptr = nullptr;
		}
		else
		{
			ptr = &(f->second);
		}
	}

	void find(const char* bookName, const char* authors, book*& ptr)
	{
		auto f = multiMapBook.find(bookName);
		if (f == multiMapBook.end())
		{
			ptr = nullptr;
		}
		else
		{
			if (strcmp((f->second.authors)->c_str(), authors) == 0)
			{
				ptr = &(f->second);
			}
			else
			{
				ptr = nullptr;
			}
		}
	}

	void mostExpensive(book*& ptr)
	{
		auto it = multiMapBook.begin();
		int mostCost = it->second.price;
		ptr = &(it->second);
		while (it != multiMapBook.end())
		{
			if (it->second.price > mostCost)
			{
				mostCost = it->second.price;
				ptr = &(it->second);
			}
			++it;
		}
	}

	void cheapest(book*& ptr)
	{
		auto it = multiMapBook.begin();
		int mostCost = it->second.price;
		ptr = &(it->second);
		while (it != multiMapBook.end())
		{
			if (it->second.price < mostCost)
			{
				mostCost = it->second.price;
				ptr = &(it->second);
			}
			++it;
		}
	}

	float average()
	{
		float sum = 0.0f;
		int count = 0;
		auto it = multiMapBook.begin();


		while (it != multiMapBook.end())
		{
			sum += it->second.price;
			count++;
			++it;
		}
		return sum / count;
	}

	void clean()
	{
		multiMapBook.clear();
	}

};



class adaptee4
{
private:
	vector<pair<string, book>> vectorBook;

	//TODO
public:
	void add(const book value, int& result)
	{
		auto it = std::find_if(vectorBook.begin(), vectorBook.end(),
			[&value](const std::pair<std::string, book>& element) { return element.first == *value.bookName; });
		if (it == vectorBook.end())
		{
			result = 1;
			vectorBook.push_back(make_pair(*value.bookName,value));
		}
		else
		{
			result = 0;
		}
	}

	//加入一個值 成功result設成1  失敗result設成0
	void remove(const book value, int& result)
	{
		auto f = std::find_if(vectorBook.begin(), vectorBook.end(),
			[&value](const std::pair<std::string, book>& element) { return element.first == *value.bookName; });
		if (f == vectorBook.end())
		{
			//cout << "沒找到 " << *(value.bookName) << endl;
			result = 0;
		}
		else
		{
			//cout << "刪除 " << *(value.bookName) << endl;
			vectorBook.erase(f);
			result = 1;
		}
	}

	//刪除一個值 成功result設成1  失敗result設成0
	void find(const char* bookName, book*& ptr)
	{
		auto it = std::find_if(vectorBook.begin(), vectorBook.end(),
			[&](const std::pair<std::string, book>& element) { return element.first == bookName; });
		if (it == vectorBook.end())
		{
			ptr = nullptr;
		}
		else
		{
			ptr = &(it->second);
		}
	}

	void find(const char* bookName, const char* authors, book*& ptr)
	{
		auto f = std::find_if(vectorBook.begin(), vectorBook.end(),
			[&](const std::pair<std::string, book>& element) { return element.first == bookName; });
		if (f == vectorBook.end())
		{
			ptr = nullptr;
		}
		else
		{
			if (strcmp((f->second.authors)->c_str(), authors) == 0)
			{
				ptr = &(f->second);
			}
			else
			{
				ptr = nullptr;
			}
		}
	}

	void mostExpensive(book*& ptr)
	{
		auto it = vectorBook.begin();
		int mostCost = it->second.price;
		ptr = &(it->second);
		while (it != vectorBook.end())
		{
			if (it->second.price > mostCost)
			{
				mostCost = it->second.price;
				ptr = &(it->second);
			}
			++it;
		}
	}

	void cheapest(book*& ptr)
	{
		auto it = vectorBook.begin();
		int mostCost = it->second.price;
		ptr = &(it->second);
		while (it != vectorBook.end())
		{
			if (it->second.price < mostCost)
			{
				mostCost = it->second.price;
				ptr = &(it->second);
			}
			++it;
		}
	}

	float average()
	{
		float sum = 0.0f;
		int count = 0;
		auto it = vectorBook.begin();


		while (it != vectorBook.end())
		{
			sum += it->second.price;
			count++;
			++it;
		}
		return sum / count;
	}

	void clean()
	{
		vectorBook.clear();
	}
	
};

#pragma once
#include <map>


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

	//�[�J�@�ӭ� ���\result�]��1  ����result�]��0
	void remove(const book value, int& result)
	{
		auto f = mapbook.find(*(value.bookName));
		if (f == mapbook.end())
		{
			//cout << "�S��� " << *(value.bookName) << endl;
			result = 0;
		}
		else
		{
			//cout << "�R�� " << *(value.bookName) << endl;
			mapbook.erase(f);
			result = 1;
		}
	}

	//�R���@�ӭ� ���\result�]��1  ����result�]��0
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

	//�d�ߤ@�ӭ�   ���\ ����ptr����table����
	//���� ����ptr�]��0
};


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

	//�[�J�@�ӭ� ���\result�]��1  ����result�]��0
	void remove(const book value, int& result)
	{
		result=deleteNodeTP(rootNode, value);
	}

	//�R���@�ӭ� ���\result�]��1  ����result�]��0
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

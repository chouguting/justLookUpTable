#define _CRT_SECURE_NO_WARNINGS
#include "binaryTree.h"

#include <iostream>
#include "binaryTree.h"
#include "book.h"
using namespace std;


int compareFun(book a, book b)
{
	if (strcmp(a.bookName->c_str(), b.bookName->c_str()) > 0)
	{
		return -1;
	}
	if (strcmp(a.bookName->c_str(), b.bookName->c_str()) < 0)
	{
		return 1;
	}
	return 0;
}





int insertNodeTP(treeNodeTP*& tree, book input)
{
	if (tree == nullptr)
	{
		tree = static_cast<treeNodeTP*>(malloc(sizeof(treeNodeTP)));
		tree->data = input;
		tree->leftPtr = nullptr;
		tree->rightPtr = nullptr;
		return 1;
	}
	if (compareFun(input, tree->data) == -1)
	{
		insertNodeTP(tree->rightPtr, input);
	}
	else if (compareFun(input, tree->data) == 1)
	{
		insertNodeTP(tree->leftPtr, input);
	}
	else
	{
		return 0;
	}
}





void reConnect(treeNodeTP*& tree, treeNodeTP*& connectPtr)
{
	if (tree == nullptr)
	{
		tree = static_cast<treeNodeTP*>(malloc(sizeof(treeNodeTP)));
		tree = connectPtr;
	}
	else
	{
		if (compareFun(connectPtr->data, tree->data) == -1)
		{
			reConnect(tree->rightPtr, connectPtr);
		}
		else if (compareFun(connectPtr->data, tree->data) == 1)
		{
			reConnect(tree->leftPtr, connectPtr);
		}
		else
		{
			cout << "same value has already been stored" << endl;
		}
	}
}


treeNodeTP* locateUpper(treeNodeTP*& tree, book input)
{
	if (tree == nullptr)
	{
		return nullptr;
	}
	if (tree->rightPtr != nullptr)
	{
		if (compareFun(input, tree->rightPtr->data) == 0)
		{
			return tree;
		}
	}
	if (tree->leftPtr != nullptr)
	{
		if (compareFun(input, tree->leftPtr->data) == 0)
		{
			return tree;
		}
	}


	if (compareFun(input, tree->data) == -1)
	{
		locateUpper(tree->rightPtr, input);
	}
	else if (compareFun(input, tree->data) == 1)
	{
		locateUpper(tree->leftPtr, input);
	}
}


treeNodeTP* locateNode(treeNodeTP*& tree, book input)
{
	if (tree == nullptr)
	{
		return nullptr;
	}
	if (compareFun(input, tree->data) == -1)
	{
		locateNode(tree->rightPtr, input);
	}
	else if (compareFun(input, tree->data) == 1)
	{
		locateNode(tree->leftPtr, input);
	}
	else
	{
		return tree;
	}
}


int deleteNodeTP(treeNodeTP*& treePtr, book keyToDelete)
{
	treeNodeTP* deleteNode = locateNode(treePtr, keyToDelete);
	if (deleteNode == nullptr)
	{
		//cout << "not Found" << endl;
		return 0;
	}

	//cout << "�Y�N�R��:";
	//printFun(deleteNode->data);


	treeNodeTP* deleteUpper = locateUpper(treePtr, keyToDelete);

	if (deleteUpper == nullptr)
	{
		treePtr = deleteNode->rightPtr;
		if (deleteNode->rightPtr == nullptr)
		{
			treePtr = deleteNode->leftPtr;
			free(deleteNode);
			return 1;
		}
		if (deleteNode->leftPtr != nullptr)
		{
			reConnect(treePtr, deleteNode->leftPtr);
		}
		free(deleteNode);
		return 1;
	}
	//printFun(deleteUpper->data);
	if (deleteUpper->leftPtr == deleteNode)
	{
		deleteUpper->leftPtr = deleteNode->rightPtr;

		if (deleteNode->rightPtr == nullptr)
		{
			deleteUpper->leftPtr = deleteNode->leftPtr;
			free(deleteNode);
			return 1;
		}
		if (deleteNode->leftPtr != nullptr)
		{
			reConnect(deleteUpper->leftPtr, deleteNode->leftPtr);
		}

		free(deleteNode);
		return 1;
	}
	if (deleteUpper->rightPtr == deleteNode)
	{
		deleteUpper->rightPtr = deleteNode->rightPtr;
		if (deleteNode->rightPtr == nullptr)
		{
			deleteUpper->rightPtr = deleteNode->leftPtr;
			free(deleteNode);
			return 1;
		}
		if (deleteNode->leftPtr != nullptr)
		{
			reConnect(deleteUpper->rightPtr, deleteNode->leftPtr);
		}

		free(deleteNode);
		return 1;
	}


	return 1;
}

void deleteTreeALL(treeNodeTP* node)
{
	if (node == NULL) return;

	deleteTreeALL(node->leftPtr);
	deleteTreeALL(node->rightPtr);

	//cout << "\n Deleting node: " << node->data;
	free(node);
}
void deleteTree(treeNodeTP*& node)
{
	
	deleteTreeALL(node);
	node = nullptr;
}


int sumTree(treeNodeTP*& tree)
{
	if (tree == nullptr)
	{
		return 0;
	}
	return sumTree(tree->rightPtr) + sumTree(tree->leftPtr) + tree->data.price;
}

int binarytree_count_recursive(const treeNodeTP* root)
{
	int count = 1;
	if (root->leftPtr != nullptr)
	{
		count += binarytree_count_recursive(root->leftPtr);
	}
	if (root->rightPtr != nullptr)
	{
		count += binarytree_count_recursive(root->rightPtr);
	}
	return count;
}

int binarytree_count(const treeNodeTP* tree)
{
	unsigned int count = 0;
	if (tree != nullptr)
	{
		count = binarytree_count_recursive(tree);
	}
	return count;
}


int max(treeNodeTP*& tree, int& i, treeNodeTP*& temp)
{
	if (tree != nullptr)
	{
		if (tree->data.price > i)
		{
			i = tree->data.price;
			temp = tree;
		}
		max(tree->rightPtr, i, temp);
		max(tree->leftPtr, i, temp);
		return 1;
	}
	return 0;
}

int min(treeNodeTP*& tree, int& i, treeNodeTP*& temp)
{
	if (tree != nullptr)
	{
		if (tree->data.price < i)
		{
			i = tree->data.price;
			temp = tree;
		}
		min(tree->rightPtr, i, temp);
		min(tree->leftPtr, i, temp);

		return 1;
	}
	return 0;
}


/*int main()
{
	treeNodeTP<book>* rootNode = nullptr;
	doStuff(rootNode);

}



 ����:
1
��q���ǿ��ѧ޳N�G����ABBYY FineReader 11 OCR
�����q
371
1
VISUAL FORTRAN�{���]�p�P�}�o
�i�űj�B���E��
400
1
�{���]�p�Шϥ�C++
���خx
420
1
��Ʈw�t�Ρ�MTA�{�Ҽv���о�
���K��
336
1
���P�d�wGoogle���ݧ޳N�GMaps.Android.App Engine.Cloud SQL�P�q�l�Ӱ�API��ҸѪR
���@��
560
1
�H�u���z�G���z���t�ξɽ�(�ĤT��)
���p�� ��ҹ�w �¬F��
590
1
�q����������(�ĤG��)
�����s
420
1
���ں����P�q�l�Ӱ�(�ĤT��)
������
450
1
��Ʈw�t�βz�סШϥ�SQL Server 2008
���K��
650
1
�ʵe�ϸѸ�Ʈw�t�βz�סШϥ�Access 2010��@(�ĤG��)
���K��
600
 */

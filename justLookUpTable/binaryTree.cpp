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

	//cout << "即將刪除:";
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



 測資:
1
精通光學辨識技術：應用ABBYY FineReader 11 OCR
黃敦義
371
1
VISUAL FORTRAN程式設計與開發
張嘉強、陳鴻智
400
1
程式設計－使用C++
黃建庭
420
1
資料庫系統－MTA認證影音教學
李春雄
336
1
輕鬆搞定Google雲端技術：Maps.Android.App Engine.Cloud SQL與電子商務API實例解析
陳世興
560
1
人工智慧：智慧型系統導論(第三版)
李聯旺 廖珗洲 謝政勳
590
1
電腦網路概論(第二版)
陳雲龍
420
1
網際網路與電子商務(第三版)
朱正忠
450
1
資料庫系統理論－使用SQL Server 2008
李春雄
650
1
動畫圖解資料庫系統理論－使用Access 2010實作(第二版)
李春雄
600
 */

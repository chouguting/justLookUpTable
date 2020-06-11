#pragma once
#include <cstdio>

#include "book.h"


struct treeNodeTP
{
	book data;
	treeNodeTP* leftPtr;
	treeNodeTP* rightPtr;
};


int compareFun(book a, book b);






int insertNodeTP(treeNodeTP*& tree, book input);




void reConnect(treeNodeTP*& tree, treeNodeTP*& connectPtr);


treeNodeTP* locateUpper(treeNodeTP*& tree, book input);


treeNodeTP* locateNode(treeNodeTP*& tree, book input);


int deleteNodeTP(treeNodeTP*& treePtr, book keyToDelete);


void deleteTree(treeNodeTP*& node);
void deleteTreeALL(treeNodeTP* node);

int sumTree(treeNodeTP*& tree);

int binarytree_count_recursive(const treeNodeTP* root);

int binarytree_count(const treeNodeTP* tree);


int max(treeNodeTP*& tree, int& i, treeNodeTP*& temp);

int min(treeNodeTP*& tree, int& i, treeNodeTP*& temp);

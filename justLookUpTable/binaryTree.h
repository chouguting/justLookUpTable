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



void printFun(book a);


void printFun(int a);

void printFun(float a);



int insertNodeTP(treeNodeTP*& tree, book input);

void inOrderTP(treeNodeTP* tree);


void preOrderTP(treeNodeTP* tree);

void postOrderTP(treeNodeTP* tree);



void reConnect(treeNodeTP*& tree, treeNodeTP*& connectPtr);


treeNodeTP* locateUpper(treeNodeTP*& tree, book input);


treeNodeTP* locateNode(treeNodeTP*& tree, book input);


int deleteNodeTP(treeNodeTP*& treePtr, book keyToDelete);


void deleteTree(treeNodeTP*& node);

int sumTree(treeNodeTP*& tree);

int binarytree_count_recursive(const treeNodeTP* root);

int binarytree_count(const treeNodeTP* tree);


int max(treeNodeTP*& tree, int& i, treeNodeTP*& temp);

int min(treeNodeTP*& tree, int& i, treeNodeTP*& temp);

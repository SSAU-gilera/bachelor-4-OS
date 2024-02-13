#pragma once
#include <Windows.h>
#include <cstdio>
struct nodeTree {
	int key; // Ключ 
	char* value; // Данные 
	struct nodeTree* left;
	struct nodeTree* right;
};

class BinaryTree {
	nodeTree* root;
	int size;

	void leftPrint(nodeTree* tree);
public:
	BinaryTree();

	//добавление элемента
	void add(int key, const char* value);

	//левый обход дерева
	void leftPrint();

	//дружественные функцию
	friend void writeInFile(BinaryTree tree, HANDLE file);

};

BinaryTree readInFile(HANDLE file);

//создание элемента
 nodeTree* createNode(int key, const char* value);
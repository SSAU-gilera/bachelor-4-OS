#pragma once
#ifdef BINARYTREEDLL_EXPORTS
#define BINARYTREEDLL_API __declspec(dllimport)
#else
#define BINARYTREEDLL_API __declspec(dllexport)
#endif // 

#include <Windows.h>
#include <cstdio>
struct BINARYTREEDLL_API nodeTree {
	int key; // Ключ 
	char* value; // Данные 
	struct nodeTree* left;
	struct nodeTree* right;
};

class BINARYTREEDLL_API BinaryTree {
	nodeTree* root;
	int size;

	void _leftPrint(nodeTree* tree);
public:
	BinaryTree();

	const nodeTree* getRoot();

	//добавление элемента
	void add(int key, const char* value);

	//левый обход дерева
	void leftPrint();

};

BINARYTREEDLL_API BinaryTree readInFile(HANDLE file);

BINARYTREEDLL_API void writeInFile(BinaryTree tree, HANDLE file);

//создание элемента
BINARYTREEDLL_API nodeTree* createNode(int key, const char* value);
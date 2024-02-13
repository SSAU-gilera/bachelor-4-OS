#pragma once
#ifdef BINARYTREEDLL_EXPORTS
#define BINARYTREEDLL_API __declspec(dllimport)
#else
#define BINARYTREEDLL_API __declspec(dllexport)
#endif // 

#include <Windows.h>
#include <cstdio>
struct BINARYTREEDLL_API nodeTree {
	int key; // ���� 
	char* value; // ������ 
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

	//���������� ��������
	void add(int key, const char* value);

	//����� ����� ������
	void leftPrint();

};

BINARYTREEDLL_API BinaryTree readInFile(HANDLE file);

BINARYTREEDLL_API void writeInFile(BinaryTree tree, HANDLE file);

//�������� ��������
BINARYTREEDLL_API nodeTree* createNode(int key, const char* value);
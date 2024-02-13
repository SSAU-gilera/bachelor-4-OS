#pragma once
#include <Windows.h>
#include <cstdio>
struct nodeTree {
	int key; // ���� 
	char* value; // ������ 
	struct nodeTree* left;
	struct nodeTree* right;
};

class BinaryTree {
	nodeTree* root;
	int size;

	void leftPrint(nodeTree* tree);
public:
	BinaryTree();

	//���������� ��������
	void add(int key, const char* value);

	//����� ����� ������
	void leftPrint();

	//������������� �������
	friend void writeInFile(BinaryTree tree, HANDLE file);

};

BinaryTree readInFile(HANDLE file);

//�������� ��������
 nodeTree* createNode(int key, const char* value);
#include "pch.h"
#include "BinaryTreeDll.h"


void writeFile(const nodeTree* tree, HANDLE file) {
	if (tree == NULL) return;
	DWORD dw = 0;
	int l = strlen(tree->value);
	int key = tree->key;
	WriteFile(file, &key, sizeof(int), &dw, NULL);
	WriteFile(file, &l, sizeof(int), &dw, NULL);
	WriteFile(file, _strdup(tree->value), l, &dw, NULL);
	writeFile(tree->left, file);
	writeFile(tree->right, file);
}

void writeInFile(BinaryTree tree, HANDLE file)
{
	writeFile(tree.getRoot(), file);
}

BinaryTree readInFile(HANDLE file)
{
	BinaryTree tree;
	DWORD end = SetFilePointer(file, 0, 0, FILE_END);
	SetFilePointer(file, 0, 0, FILE_BEGIN);
	DWORD dw = 0;
	int key;
	int length = 0;
	char value[16];
	if (SetFilePointer(file, 0, 0, FILE_CURRENT) < end)
	{
		ReadFile(file, &key, sizeof(int), &dw, NULL);
		ReadFile(file, &length, sizeof(int), &dw, NULL);
		ReadFile(file, value, length, &dw, NULL);
		value[length] = '\0';
		tree.add(key, value);
	}

	while (SetFilePointer(file, 0, 0, FILE_CURRENT) < end)
	{
		ReadFile(file, &key, sizeof(int), &dw, NULL);
		ReadFile(file, &length, sizeof(int), &dw, NULL);
		ReadFile(file, &value, length, &dw, NULL);
		value[length] = '\0';
		tree.add(key, value);
	}
	return tree;
}


nodeTree* createNode(int key, const char* value)
{
	struct nodeTree* node = new nodeTree;
	node->key = key;
	node->value = _strdup(value);

	node->left = NULL;
	node->right = NULL;

	return node;
}

void BinaryTree::_leftPrint(nodeTree* tree)
{
	if (tree == NULL) return;
	_leftPrint(tree->left);
	_leftPrint(tree->right);
	printf("key: %d; value: %s\n", tree->key, tree->value);
}

const nodeTree* BinaryTree::getRoot()
{
	return root;
}

void BinaryTree::add(int key, const char* value)
{
	struct nodeTree* parent;
	parent = NULL;
	if (root == NULL) {
		root = createNode(key, value);
		size++;
	}
	else {
		nodeTree* tree = root;
		while (tree != NULL) {
			parent = tree;
			if (key < tree->key) {
				tree = tree->left;
			}
			else if (key > tree->key) {
				tree = tree->right;
			}
			else {
				return;
			}
		}
		/* Создаем элемент и связываем с узлом */
		nodeTree* node = createNode(key, value);
		if (key < parent->key)
			parent->left = node;
		else
			parent->right = node;
		size++;
	}
}

void BinaryTree::leftPrint()
{
	_leftPrint(root);
}

void BinaryTree::callAdd(int key, const char* value)
{
	HANDLE bufFull = OpenEvent(EVENT_ALL_ACCESS, TRUE, L"bufFull");
	HANDLE bufEmpty = OpenEvent(EVENT_ALL_ACCESS, TRUE, L"bufEmpty");
	WaitForSingleObject(bufEmpty, INFINITE);
	buf_key = key;
	buf_value = _strdup(value);
	SetEvent(bufFull);
}

DWORD WINAPI ThreadFunc(PVOID p)
{
	BinaryTree& tree = *((BinaryTree*)p);
	HANDLE stopThread = OpenEvent(EVENT_ALL_ACCESS, TRUE, L"stopThread");
	HANDLE bufFull = OpenEvent(EVENT_ALL_ACCESS, TRUE, L"bufFull");
	HANDLE bufEmpty = OpenEvent(EVENT_ALL_ACCESS, TRUE, L"bufEmpty");

	while (WaitForSingleObject(stopThread, 0)!=WAIT_OBJECT_0) {
		WaitForSingleObject(bufFull, INFINITE);
		tree.add(tree.buf_key, _strdup(tree.buf_value));
		HANDLE fileTo = CreateFile(L"C:\\Users\\Lera\\Desktop\\University\\Study\\Osi\\Lab8\\file.txt", GENERIC_ALL, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		writeInFile(tree, fileTo);
		CloseHandle(fileTo);
		SetEvent(bufEmpty);
	}
	return 0;
}

BinaryTree::BinaryTree()
{
	root = NULL;
	size = 0;
	
}

BinaryTree::BinaryTree(bool f)
{
	root = NULL;
	size = 0;
	buf_key = 0;
	buf_value = _strdup("");
	DWORD id;
	HANDLE fileTo = CreateFile(L"C:\\Users\\Lera\\Desktop\\University\\Study\\Osi\\Lab8\\file.txt", GENERIC_ALL, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	CloseHandle(fileTo);
	hThread = CreateThread(NULL, 0, ThreadFunc, this, 0, &id);
}

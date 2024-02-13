#include "BinaryTree.h"

void writeFile(nodeTree* tree, HANDLE file) {
	if (tree == NULL) return;
	DWORD dw = 0;
	int l = strlen(tree->value);
	int key = tree->key;
	char* value = _strdup(tree->value);
	WriteFile(file, &key, sizeof(int), &dw, NULL);
	WriteFile(file, &l, sizeof(int), &dw, NULL);
	WriteFile(file, &(value), strlen(tree->value), &dw, NULL);
	writeFile(tree->left, file);
	writeFile(tree->right, file);
}

void writeInFile(BinaryTree tree, HANDLE file)
{
	writeFile(tree.root, file);
}

BinaryTree readInFile(HANDLE file)
{
	BinaryTree tree;
	DWORD end = SetFilePointer(file, 0, 0, FILE_END);
	SetFilePointer(file, 0, 0, FILE_BEGIN);
	DWORD dw = 0;
	int key;
	int length = 0;
	if (SetFilePointer(file, 0, 0, FILE_CURRENT) < end)
	{
		ReadFile(file, &key, sizeof(int), &dw, NULL);
		ReadFile(file, &length, sizeof(int), &dw, NULL);
		char* value = new char[length + 1];
		ReadFile(file, &value, length, &dw, NULL);
		value[length] = '\0';
		tree.add(key, value);
		delete[]value;
	}

	while (SetFilePointer(file, 0, 0, FILE_CURRENT) < end)
	{
		ReadFile(file, &key, sizeof(int), &dw, NULL);
		ReadFile(file, &length, sizeof(int), &dw, NULL);
		char* value = new char[length + 1];
		ReadFile(file, &value, length, &dw, NULL);
		value[length] = '\0';
		tree.add(key, value);
		delete[]value;
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

void BinaryTree::leftPrint(nodeTree* tree)
{
	if (tree == NULL) return;
	leftPrint(tree->left);
	leftPrint(tree->right);
	printf("key: %d; value: %s\n", tree->key, tree->value);
}

BinaryTree::BinaryTree()
{
	root = NULL;
	size = 0;
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
	leftPrint(root);
}

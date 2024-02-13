#include "BinaryTree.h"
#include <windows.h>

const TCHAR szCounterFileName[] = L"file.txt";

//создание элемента
struct bstree* bstree_create(int key, const char* value)
{
	struct bstree* node;
	node = (bstree*)malloc(sizeof(*node));
	if (node != NULL) {
		node->key = key;
		node->value = _strdup(value);
		//node->value = value;

		node->left = NULL;
		node->right = NULL;
	}
	return node;
}

//добавление элемента
void bstree_add(struct bstree* tree,
	int key, const char* value)
{
	struct bstree* parent, * node;
	parent = NULL;
	if (tree == NULL)
		return;
	/* Отыскиваем листовой узел */
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
	node = bstree_create(key, value);
	if (key < parent->key)
		parent->left = node;
	else
		parent->right = node;
}


//поиск элемента в дереве
struct bstree* bstree_lookup(struct bstree* tree,
	int key)
{
	while (tree != NULL) {
		if (key == tree->key) {
			return tree;
		}
		else if (key < tree->key) {
			tree = tree->left;
		}
		else {
			tree = tree->right;
		}
	}
	return tree;
}

//поиск минимального элемента дерева
struct bstree* bstree_min(struct bstree* tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

//поиск максимального элемента дерева
struct bstree* bstree_max(struct bstree* tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}





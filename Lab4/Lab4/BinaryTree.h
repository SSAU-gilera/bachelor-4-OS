#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bstree {
	int key; // Ключ 
	char* value; // Данные 
	struct bstree* left;
	struct bstree* right;
};

//создание элемента
struct bstree* bstree_create(int key, const char* value);

//добавление элемента
void bstree_add(struct bstree* tree,
	int key, const char* value);

//поиск элемента в дереве
struct bstree* bstree_lookup(struct bstree* tree,
	int key);

//поиск минимального элемента дерева
struct bstree* bstree_min(struct bstree* tree);

//поиск максимального элемента дерева
struct bstree* bstree_max(struct bstree* tree);

void writeInFile();
void readFile();


#include <iostream>
#include <Windows.h>
#include "..\\BinaryTreeDll\\BinaryTreeDll.h"
void main() {
	setlocale(LC_ALL, "RUS");
	HINSTANCE dll = LoadLibrary(L"..\\Debug\\BinaryTreeDll.dll");
	if (dll == NULL) {
		printf("Ошибка при загрузке dll\n");
		system("pause");
		return;
	}
	
	printf("Требуется реализовать структуру данных Ђассоциативный массивї, использу¤ бинарное дерево\n");

	void(BinaryTree::*constructor)();
	(FARPROC&)constructor = GetProcAddress(dll, "??0BinaryTree@@QAE@XZ");
	
	void (BinaryTree:: * add)(int, const char*);
	(FARPROC&)add = GetProcAddress(dll, "?add@BinaryTree@@QAEXHPBD@Z");

	void (BinaryTree:: * leftPrint)();
	(FARPROC&)leftPrint = GetProcAddress(dll, "?leftPrint@BinaryTree@@QAEXXZ");

	char _c[sizeof(BinaryTree)];
	BinaryTree& a = *(BinaryTree*)_c;
	(a.*constructor)();

	(a.*add)(28, "Ситникова");
	(a.*add)(23, "Гижевская");
	(a.*add)(60, "Борисова");
	(a.*add)(11, "Иванов");
	(a.*add)(22, "Петров");
	(a.*add)(33, "Сидоров");
	(a.*add)(44, "Лукашевич");
	(a.*add)(55, "Ёфи");
	(a.*add)(66, "Йофи");
	(a.*add)(77, "Иофи");
	(a.*add)(88, "Карамзин");
	(a.*add)(99, "Салтыков");


	printf("Исходное дерево (левый обход):\n");
	(a.*leftPrint)();
	system("pause");
}
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
	(a.*add)(11, "Булатник");
	(a.*add)(22, "Петрова");
	(a.*add)(33, "Корень");
	(a.*add)(44, "Азаматов");
	(a.*add)(55, "Сухов");
	(a.*add)(66, "Кротков");
	(a.*add)(77, "Абрамов");
	(a.*add)(88, "Мбингу");
	(a.*add)(99, "Черкасов");



	printf("Исходное дерево (левый обход):\n");
	(a.*leftPrint)();
	system("pause");
}
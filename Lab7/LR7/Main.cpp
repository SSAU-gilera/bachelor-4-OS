#include <iostream>
#include "BinaryTreeDll.h"
void main() {
	HANDLE bufEmpty = CreateEvent(NULL, FALSE, TRUE, L"bufEmpty");
	HANDLE bufFull = CreateEvent(NULL, FALSE, FALSE, L"bufFull");
	HANDLE stopThread = CreateEvent(NULL, TRUE, FALSE, L"stopThread");

	setlocale(LC_ALL, "russian");
	printf("Требуется реализовать структуру данных «ассоциативный массив», используя бинарное дерево\n");
	BinaryTree* a = new BinaryTree(true);


	a->callAdd(28, "Ситникова");
	a->callAdd(23, "Гижевская");
	a->callAdd(60, "Борисова");
	a->callAdd(11, "Булатник");
	a->callAdd(22, "Петрова");
	a->callAdd(33, "Корень");
	a->callAdd(44, "Азаматов");
	a->callAdd(55, "Сухов");
	a->callAdd(66, "Кротков");
	a->callAdd(77, "Абрамов");
	a->callAdd(88, "Мбингу");
	a->callAdd(99, "Черкасов");
	
	WaitForSingleObject(bufEmpty, INFINITE);
	SetEvent(stopThread);

	printf("Дерево (левый обход):\n");
	HANDLE fileFrom = CreateFile(L"C:\\Users\\Lera\\Desktop\\University\\Study\\Osi\\Lab7\\file.txt", GENERIC_READ, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	*a = readInFile(fileFrom);
	CloseHandle(fileFrom);
	a->leftPrint();

	system("pause");
}
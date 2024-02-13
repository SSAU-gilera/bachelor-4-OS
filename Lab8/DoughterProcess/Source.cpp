#include <Windows.h>
#include "BinaryTreeDll.h"

int main() {
	HANDLE stopThread = OpenEvent(EVENT_ALL_ACCESS, TRUE, L"stopThread");
	HANDLE bufEmpty = OpenEvent(EVENT_ALL_ACCESS, TRUE, L"bufEmpty");

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

	system("pause");
	return 0;
}
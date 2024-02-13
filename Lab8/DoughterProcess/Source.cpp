#include <Windows.h>
#include "BinaryTreeDll.h"

int main() {
	HANDLE stopThread = OpenEvent(EVENT_ALL_ACCESS, TRUE, L"stopThread");
	HANDLE bufEmpty = OpenEvent(EVENT_ALL_ACCESS, TRUE, L"bufEmpty");

	BinaryTree* a = new BinaryTree(true);

	a->callAdd(28, "���������");
	a->callAdd(23, "���������");
	a->callAdd(60, "��������");
	a->callAdd(11, "��������");
	a->callAdd(22, "�������");
	a->callAdd(33, "������");
	a->callAdd(44, "��������");
	a->callAdd(55, "�����");
	a->callAdd(66, "�������");
	a->callAdd(77, "�������");
	a->callAdd(88, "������");
	a->callAdd(99, "��������");

	WaitForSingleObject(bufEmpty, INFINITE);
	SetEvent(stopThread);

	system("pause");
	return 0;
}
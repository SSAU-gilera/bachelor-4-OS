#include <iostream>
#include "BinaryTreeDll.h"
void main() {
	HANDLE bufEmpty = CreateEvent(NULL, FALSE, TRUE, L"bufEmpty");
	HANDLE bufFull = CreateEvent(NULL, FALSE, FALSE, L"bufFull");
	HANDLE stopThread = CreateEvent(NULL, TRUE, FALSE, L"stopThread");

	setlocale(LC_ALL, "russian");
	printf("��������� ����������� ��������� ������ �������������� ������, ��������� �������� ������\n");
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

	printf("������ (����� �����):\n");
	HANDLE fileFrom = CreateFile(L"C:\\Users\\Lera\\Desktop\\University\\Study\\Osi\\Lab7\\file.txt", GENERIC_READ, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	*a = readInFile(fileFrom);
	CloseHandle(fileFrom);
	a->leftPrint();

	system("pause");
}
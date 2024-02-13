#include <iostream>
#include <Windows.h>
#include "..\\BinaryTreeDll\\BinaryTreeDll.h"
void main() {
	setlocale(LC_ALL, "RUS");
	HINSTANCE dll = LoadLibrary(L"..\\Debug\\BinaryTreeDll.dll");
	if (dll == NULL) {
		printf("������ ��� �������� dll\n");
		system("pause");
		return;
	}
	
	printf("��������� ����������� ��������� ������ �������������� ������, �������� �������� ������\n");

	void(BinaryTree::*constructor)();
	(FARPROC&)constructor = GetProcAddress(dll, "??0BinaryTree@@QAE@XZ");
	
	void (BinaryTree:: * add)(int, const char*);
	(FARPROC&)add = GetProcAddress(dll, "?add@BinaryTree@@QAEXHPBD@Z");

	void (BinaryTree:: * leftPrint)();
	(FARPROC&)leftPrint = GetProcAddress(dll, "?leftPrint@BinaryTree@@QAEXXZ");

	char _c[sizeof(BinaryTree)];
	BinaryTree& a = *(BinaryTree*)_c;
	(a.*constructor)();

	(a.*add)(28, "���������");
	(a.*add)(23, "���������");
	(a.*add)(60, "��������");
	(a.*add)(11, "��������");
	(a.*add)(22, "�������");
	(a.*add)(33, "������");
	(a.*add)(44, "��������");
	(a.*add)(55, "�����");
	(a.*add)(66, "�������");
	(a.*add)(77, "�������");
	(a.*add)(88, "������");
	(a.*add)(99, "��������");



	printf("�������� ������ (����� �����):\n");
	(a.*leftPrint)();
	system("pause");
}
#include <iostream>
#include "BinaryTreeDll.h"
void main() {
	setlocale(LC_ALL, "russian");
	printf("��������� ����������� ��������� ������ �������������� ������, ��������� �������� ������\n");
	BinaryTree a;
	a.add(28, "���������");
	a.add(23, "���������");
	a.add(60, "��������");
	a.add(11, "��������");
	a.add(22, "�������");
	a.add(33, "������");
	a.add(44, "��������");
	a.add(55, "�����");
	a.add(66, "�������");
	a.add(77, "�������");
	a.add(88, "������");
	a.add(99, "��������");


	printf("�������� ������ (����� �����):\n");
	a.leftPrint();

	system("pause");
}
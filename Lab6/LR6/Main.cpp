#include <iostream>
#include "BinaryTreeDll.h"
void main() {
	setlocale(LC_ALL, "russian");
	printf("Требуется реализовать структуру данных «ассоциативный массив», используя бинарное дерево\n");
	BinaryTree a;
	a.add(28, "Ситникова");
	a.add(23, "Гижевская");
	a.add(60, "Борисова");
	a.add(11, "Булатник");
	a.add(22, "Петрова");
	a.add(33, "Корень");
	a.add(44, "Азаматов");
	a.add(55, "Сухов");
	a.add(66, "Кротков");
	a.add(77, "Абрамов");
	a.add(88, "Мбингу");
	a.add(99, "Черкасов");


	printf("Исходное дерево (левый обход):\n");
	a.leftPrint();

	system("pause");
}
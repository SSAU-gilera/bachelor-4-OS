// Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void PrintArray(float* a, int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%10.3f", *(a + i * m + j));

		}
		printf("\n");
	}
}
void InputArray(float* a, int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%f", (a + i * m + j));
		}
	}
}
void DivByMaxEl(float* a, int n, int m)
{
	float* max = NULL;
	HANDLE heap = GetProcessHeap();
	max = (float*)HeapAlloc(heap, NULL, n * sizeof(float));
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{

			if (a[j] > max[i])
			{
				max[i] = a[j];
			}
		}
		for (j = 0; j < m; j++)  // цикл по столбцам
		{
			printf("%10.3f", *(a + i * m + j) / max[i]);
		}
		printf("\n");
	}


}
int main()
{
	setlocale(LC_ALL, "");
	int i, j, n, m;
	printf(" Вариант 3 | Гижевская Валерия | 6213 \n");
	printf("\nВведите количество строк: ");
	scanf("%d", &n);
	printf("Введите количество столбцов: ");
	scanf("%d", &m);

	HANDLE heap = GetProcessHeap();
	if (heap != NULL) {
		float* a = NULL;
		a = (float*)HeapAlloc(heap, NULL, n * m * sizeof(float));
		if (a != NULL)
		{
			InputArray(a, n, m);
			PrintArray(a, n, m);
			printf("\nМассив, в котором каждый элемент строки разделён на наибольший элемент строки: \n");
			DivByMaxEl(a, n, m);
			HeapFree(heap, NULL, a);
		}
	}
	getchar();
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

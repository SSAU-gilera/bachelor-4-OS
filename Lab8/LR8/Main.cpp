#include <iostream>
#include "BinaryTreeDll.h"
void main() {
	setlocale(LC_ALL, "RUS");

	HANDLE bufEmpty = CreateEvent(NULL, FALSE, TRUE, L"bufEmpty");
	HANDLE bufFull = CreateEvent(NULL, FALSE, FALSE, L"bufFull");
	HANDLE stopThread = CreateEvent(NULL, TRUE, FALSE, L"stopThread");

	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
	si.cb = sizeof(STARTUPINFO);
	
	CreateProcess(L"..\\Debug\\DoughterProcess.exe", NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);

	printf("Дерево (левый обход):\n");
	HANDLE fileFrom = CreateFile(L"C:\\Users\\Lera\\Desktop\\University\\Study\\Osi\\Lab8\\file.txt", GENERIC_ALL, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	
	BinaryTree a = readInFile(fileFrom);
	CloseHandle(fileFrom);
	a.leftPrint();

	system("pause");
}
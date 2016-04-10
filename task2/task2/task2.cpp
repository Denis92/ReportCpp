// task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void func(int n, int m){

	if ((n <= m) || (m == 0))return;

	int *vector = new int[n];
	for(int i = 0; i < n; i++) vector[i] = 0;

	int pSize = n/m;
	int bSize = (n%m)/2;

	
	int bIndex = bSize;
	int eIndex = bIndex + pSize - 1;
	
	for(int i = 1; i <= m; i++){
		printf("Part %d:\n", i);
		printf("  Begin index %d:\n", bIndex);
		printf("  End index: %d:\n", eIndex);
		for(int j = bIndex; j <= eIndex; j++) vector[j] = i;
		bIndex += pSize;
		eIndex += pSize;
	}

	/*
	printf("\n Vector: ");
	for(int i = 0; i < n; i++){
		printf("%d ", vector[i]);
	}
	printf("\n");
	*/

	delete vector;
}

int _tmain(int argc, _TCHAR* argv[])
{
	func(26, 9);
	system("PAUSE");
	return 0;
}


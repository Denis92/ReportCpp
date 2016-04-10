// task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

bool simple(int n){
	if(n == 1) return false;
	if(n == 2) return true;
	for(int i = 2; i <= n/2; i++){
		if((n % i) == 0) return false;
	}
	return true;
}

int func(int n){
	int *simpleList = new int[n];
	int simpleNum = 0;
	for(int i = 2; i <= n; i++){
		if(simple(i)){
			simpleList[simpleNum++] = i;
		}
	}

	for(int i = 1; i <= n; i++){
		printf("%d: ", i);
		if(simple(i)){
			printf("simple\n");
			continue;
		}

		int cur = i;
		while(cur > 1){
			for(int j = 0; (simpleList[j] <= cur) && (j <= simpleNum); j++){
				if((cur % simpleList[j]) == 0){
					printf("%d ", simpleList[j]);
					cur /= simpleList[j];
					continue;
				}			
			}
		}
		printf("\n");
	}

	delete simpleList;
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	func(1000);
	system("pause");
	return 0;
}


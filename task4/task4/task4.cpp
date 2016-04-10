// task4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Item{
	int val;
	Item *next;
};

void print(Item * cur){
	while (cur){
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

int func(int n){
	if(!n) return 1;

	Item *first, *cur;
	first = new Item;
	cur = first;
	cur->val = 1;
	cur->next = NULL;
	for(int i = 2; i <= n; i++){
		cur->next = new Item;
		cur = cur->next;
		cur->val = i;
		cur->next = NULL;
	}
	
	print(first);

	
	cur = first;
	while(cur->next){
		if(!cur->next->next) break;
		Item *tmp = cur;
		Item *last = cur->next;
		while (last->next){
			tmp = last;
			last = last->next;
		}
		last->next = cur->next;
		cur->next = last;
		tmp->next = NULL;
		cur = last->next;
	}
	

	print(first);


	//--- delete list:
	cur = first;
	while (cur){
		first = cur;
		cur = cur->next;
		delete first;
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	func(4);
	system("PAUSE");
	return 0;
}


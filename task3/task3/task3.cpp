// task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#define PAR_NUM 5

typedef enum PType{T_INT, T_FLOAT, T_STRING, T_BOOL};

struct param{
	char* title;
	bool req = false;
	PType type;
	char* val;
};

struct progArgs_t{
	int intParam = 0;
	char* strParam = "";
	float floatParam = 0;
	bool boolParam = false;
	bool helpParam = false;
};

progArgs_t progArgs;

void printHelp(param* par){
	printf("Help:\n");
	printf("prog_name ");
	for (int i = 0; i < PAR_NUM; i++){
		if (par[i].req)
			printf("--%s ", par[i].title);
		else
			printf("[--%s] ", par[i].title);
	}

	printf("\n\n");
}

int getopt(int argc, char *argv[], param* par){

	char buff1[20], buff2[20];
	for (int i = 0; i < PAR_NUM; i++){
		strcpy_s(buff1, 20, "--");
		bool find = false;
		strcat_s(buff1, 20, par[i].title);
		for (int j = 1; j < argc; j++){
			char *n = strchr(argv[j], '=');
			if (!n){
				strcpy_s(buff2, 20, argv[j]);
			}
			else{
				strncpy_s(buff2, 20, argv[j], strcspn(argv[j], "="));
			}
			if (strcmp(buff1, buff2) == 0){
				find = true;
				if (par[i].type == T_BOOL){
					par[i].val = "TRUE";
				}
				else{
					if (!n){
						if ((j + 1) < argc)
							par[i].val = argv[j + 1];
					}
					else{
						par[i].val = n + sizeof(char);
					}
				}
			}
		}
		if (par[i].req && !find){
			return -1;
		}
	}

	if (strcmp(par[0].val, "TRUE") == 0){
		progArgs.helpParam = true;
	}
	if (strcmp(par[1].val, "TRUE") == 0){
		progArgs.helpParam = true;
	}

	progArgs.intParam = atoi(par[2].val);
	progArgs.floatParam = atof(par[3].val);
	progArgs.strParam = par[4].val;

	if (progArgs.helpParam) printHelp(par);

	return 0;
}


int main(int argc, char* argv[])
{
	param par[PAR_NUM];
	par[0].title = "help";
	par[0].type = T_BOOL;
	par[0].req = false;
	par[0].val = "FALSE";

	par[1].title = "bool";
	par[1].type = T_BOOL;
	par[1].req = false;
	par[1].val = "FALSE";


	par[2].title = "int";
	par[2].type = T_INT;
	par[2].req = true;
	par[2].val = "";

	par[3].title = "float";
	par[3].type = T_FLOAT;
	par[3].req = false;
	par[3].val = "";

	par[4].title = "string";
	par[4].type = T_STRING;
	par[4].req = false;
	par[4].val = "";

	if (getopt(argc, argv, par) < 0){
		printf("ERROR!!!\n");
	}
	
	printf("Params:\n");
	printf("BOOL param: ");
	if (progArgs.boolParam)
		printf("TRUE\n");
	else
		printf("FALSE\n");
	printf("INT param: %i\n", progArgs.intParam);
	printf("FLOAT param: %f\n", progArgs.floatParam);
	printf("STRING param: %s\n", progArgs.strParam);


	system("PAUSE");
	return 0;
}


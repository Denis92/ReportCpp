#pragma once

#include <iostream>

//#include <vector>
#include "myvector.h"


using namespace std;
//-----------------------------------------------

struct cslLvl;
class cslTbl; // таблица уровней ЗАМКА

//--------------------------------------------------

struct cslLvl //таблица характеристик замка
{
	int yield; //доходность
	int maxhp;
	int spd;
	int cost;
};

class cslTbl //таблица характеристик башни
{
private:
	vector<cslLvl> tbl;
	int maxlvl;
public:
	cslTbl();
	cslTbl(int);
	int setMlvl(int m);
	int setYld(int l, int y){return tbl[l].yield = y;}
	int setMhp(int l, int h){return tbl[l].maxhp = h;}
	int setSpd(int l, int s){return tbl[l].spd = s;}
	int setCost(int l, int c){return tbl[l].cost = c;}
	int load(FILE *);
	//cslLvl * getTbl()const{return tbl;}
	int getMlvl()const{return maxlvl;}
	int getYld(int l)const{return tbl[l].yield;} //вернуть характеристики
	int getMhp(int l)const{return tbl[l].maxhp;}
	int getSpd(int l)const{return tbl[l].spd;}
	int getCost(int l)const{return tbl[l].cost;}
	int save(FILE *);
	void print();
};

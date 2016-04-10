#pragma once

#include <iostream>

//#include <vector>
#include "myvector.h"


using namespace std;
//-------------------------------------------------

struct twrLvl;
class twrTbl;//таблица уровней БАШНИ

//--------------------------------------------------

struct twrLvl //характеристики башни
{
	int rds;
	int dmg;
	int spd;
	int cost;
};

class twrTbl
{
private:
	vector<twrLvl> tbl;
	int maxlvl;
public:
	twrTbl();
	twrTbl(int);
	int setMlvl(int);
	//twrLvl* setTbl(twrLvl *t){return tbl = t;}
	int setRds(int l, int r){return tbl[l].rds = r;}
	int setDmg(int l, int d){return tbl[l].dmg = d;}
	int setSpd(int l, int s){return tbl[l].spd = s;}
	int setCost(int l, int c){return tbl[l].cost = c;}
	int load(FILE *);
	//twrLvl * getTbl(){return tbl;}
	int getMlvl()const{return maxlvl;}
	int getRds(int l)const{return tbl[l].rds;} //вернуть характеристики
	int getDmg(int l)const{return tbl[l].dmg;}
	int getSpd(int l)const{return tbl[l].spd;}
	int getCost(int l)const{return tbl[l].cost;}
	int save(FILE *);
	void print();
};


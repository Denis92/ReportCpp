#include "StdAfx.h"
#include "twrTbl.h"

#include "options.h"

twrTbl :: twrTbl()
{
	maxlvl = 0;
	tbl.resize(0);
}

twrTbl :: twrTbl(int m)
{
	maxlvl = m;
	tbl.resize(m);
	for(int i = 0; i < m; i++) //убрать потом
	{
		setRds(i,i);
		setDmg(i,i);
		setSpd(i,i);
		setCost(i,i);
	}
}

int twrTbl :: setMlvl(int m)
{
	int i;
	tbl.resize(m);
	for(i = maxlvl; i < m; i++)
	{
		setRds(i,i);
		setDmg(i,i);
		setSpd(i,i);
		setCost(i,i);
	}
	maxlvl = m;
	return m;
}

int twrTbl :: save(FILE *stm)
{
	int i;
	fwrite(&maxlvl, sizeof(int), 1, stm);
	for(i = 0; i < maxlvl; i++)
	{
		fwrite(&tbl[i], sizeof(twrLvl), 1, stm);
	}
	return 0;
}

int twrTbl :: load(FILE *stm)
{
	int i;
	fread(&maxlvl, sizeof(int), 1, stm);
	tbl.resize(maxlvl);
	for(i = 0; i < maxlvl; i++)
	{
		fread(&tbl[i], sizeof(twrLvl), 1, stm);
	}
	return 0;
}

void twrTbl :: print()
{
	for(int i = 0; i < maxlvl; i++)
	{
		std::cout << "level:" << i;
		std::cout << " cost:" << tbl[i].cost;
		std::cout << " damage:" << tbl[i].dmg;
		std::cout << " speed:" << tbl[i].spd;
		std::cout << " radius:" << tbl[i].rds <<std::endl;
	}
}
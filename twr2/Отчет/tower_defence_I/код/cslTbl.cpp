#include "StdAfx.h"
#include "cslTbl.h"


cslTbl :: cslTbl()
{
	maxlvl = 0;
	tbl.resize(0);
}

cslTbl :: cslTbl(int m)
{
	maxlvl = m;
	tbl.resize(m);
	for(int i = 0; i < m; i++) //убрать потом
	{
			setYld(i,i);
			setMhp(i,i);
			setSpd(i,i);
			setCost(i,i);
	}
}

int cslTbl :: setMlvl(int m)
{
	int i;
	tbl.resize(m);
	for(i = maxlvl; i < m; i++)
	{
		setYld(i,i);
		setSpd(i,i);
		setCost(i,i);
		setMhp(i, i);
	}
	maxlvl = m;
	return m;
}

int cslTbl :: save(FILE *stm)
{
	int i;
	fwrite(&maxlvl, sizeof(int), 1, stm);
	for(i = 0; i < maxlvl; i++)
	{
		fwrite(&tbl[i], sizeof(cslLvl), 1, stm);
	}
	return 0;
}

int cslTbl :: load(FILE *stm)
{
	int i;
	fread(&maxlvl, sizeof(int), 1, stm);
	tbl.resize(maxlvl);
	for(i = 0; i < maxlvl; i++)
	{
		fread(&tbl[i], sizeof(cslLvl), 1, stm);
	}
	return 0;
}

void cslTbl :: print()
{
	for(int i = 0; i < maxlvl; i++)
	{
		std::cout << "level:" << i;
		std::cout << " cost:" << tbl[i].cost;
		std::cout << " maxHP:" << tbl[i].maxhp;
		std::cout << " speed:" << tbl[i].spd;
		std::cout << " yield:" << tbl[i].yield << std::endl;
	}
}
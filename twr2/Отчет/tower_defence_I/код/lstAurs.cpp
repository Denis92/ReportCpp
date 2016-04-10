#include "StdAfx.h"
#include "lstAurs.h"
#include <iostream>


Aura* lstAurs :: addAura(Aura* a)
{
	Aura *tmpA;
	if(a)
		if(!aur)
			aur = a;
		else
		{
			tmpA = aur;
			while(tmpA->next)
				tmpA = tmpA->next;
			tmpA->next = a;
		}
	return a;
}

Aura* lstAurs :: addAura(int mhp, int reg, int mov, int dmg)
{
	Aura* tmpA;
	if(!aur)
	{
		aur = new Aura;
		tmpA = aur;
	}
	else
	{
		tmpA = aur;
		while(tmpA->next)
			tmpA = tmpA->next;
		tmpA->next = new Aura;
		tmpA = tmpA->next;
	}
	tmpA->maxhp = mhp;
	tmpA->regspd = reg;
	tmpA->movspd = mov;
	tmpA->dmg = dmg;
	tmpA->next = NULL;
	return tmpA;
}

int lstAurs :: getMhp()
{	
	int hp = 0;
	Aura *tmpA;
	tmpA = aur;
	while(tmpA)
	{
		hp += tmpA->maxhp;
		tmpA = tmpA->next;
	}
	return hp;
}

int lstAurs :: getRegs()
{	
	int reg = 0;
	Aura *tmpA;
	tmpA = aur;
	while(tmpA)
	{
		reg += tmpA->regspd;
		tmpA = tmpA->next;
	}
	return reg;
}

int lstAurs :: getMovs()
{	
	int mov = 0;
	Aura *tmpA;
	tmpA = aur;
	while(tmpA)
	{
		mov = mov + tmpA->maxhp;
		tmpA = tmpA->next;
	}
	return mov;
}

int lstAurs :: getDmg()
{	
	int dmg = 0;
	Aura *tmpA;
	tmpA = aur;
	while(tmpA)
	{
		dmg = dmg + tmpA->maxhp;
		tmpA = tmpA->next;
	}
	return dmg;
}

int lstAurs :: save(FILE * stm)
{
	int n = 0;
	Aura *par;
	par = aur;
	while(par)
	{
		fwrite(&(par->dmg), sizeof(int), 1, stm);
		fwrite(&(par->maxhp), sizeof(int), 1, stm);
		fwrite(&(par->movspd), sizeof(int), 1, stm);
		fwrite(&(par->regspd), sizeof(int), 1, stm);
		n++;
		par = par->next;
	}
fwrite(&n, sizeof(int), 1, stm);
return n;
}

int lstAurs :: load(FILE * stm)
{
	int n = 0, i, d, h, m, r;
	Aura *par;
	par = aur;
	fseek(stm, -4, SEEK_END);
	fread(&n, sizeof(int), 1, stm);
	fseek(stm, 0, SEEK_SET);
	for(i = 0; i < n; i++)
	{
		fread(&d, sizeof(int), 1, stm);
		fread(&h, sizeof(int), 1, stm);
		fread(&m, sizeof(int), 1, stm);
		fread(&r, sizeof(int), 1, stm);
		addAura(h, r, m, d);
	}
fwrite(&n, sizeof(int), 1, stm);
return n;
}

void lstAurs :: print()
{
	Aura *par;
	par = aur;
	while(par)
	{
		std::cout << "dmg:" << par->dmg;
		std::cout << " maxHP:" << par->maxhp;
		std::cout << " movspd:" << par->movspd;
		std::cout << " regspd:" << par->regspd << std::endl;
		par = par->next;
	}
	std::cout << std::endl;
	std::cout << "SUM :" << std:: endl;
	std::cout << "dmg:" << getDmg();
	std::cout << " maxHP:" << getMhp();
	std::cout << " movspd:" << getMovs();
	std::cout << " regspd:" << getRegs() << std::endl;
}

lstAurs :: ~lstAurs()
{
	Aura *tmpA;
	while(aur)
	{
		tmpA = aur->next;
		delete aur;
		aur = tmpA;
	}
};
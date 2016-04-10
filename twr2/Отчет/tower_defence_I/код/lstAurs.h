#pragma once

//--------------------------------------

struct Aura;
class lstAurs;

//--------------------------------------

struct Aura // ауры героя в виде списка
{
	int maxhp;
	int regspd;
	int movspd;
	int dmg;
	struct Aura *next;
};

class lstAurs 
{
private:
	struct Aura *aur;
public:
	lstAurs():aur(NULL){};
	Aura* addAura(int, int, int, int);
	Aura* addAura(Aura*);
	int getMhp();
	int getRegs();
	int getMovs();
	int getDmg();
	int save(FILE *);
	int load(FILE *);
	void print();
	~lstAurs();
};

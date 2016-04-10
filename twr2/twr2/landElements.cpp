#include "StdAfx.h"
#include "landElements.h"


//=====================Lee Algorithm============================

bool lgAlw(int x, int y, Land *l)
{
	Square *sqr;
	bool res;
	sqr = l->getSqr(x, y);
	if(sqr)
		return ((typeid(*sqr) != typeid(Wall)) && (typeid(*sqr) != typeid(Water)));
	else
		return true;
}

bool hvAlw(int x, int y, Land *l)
{
	Square *sqr;
	sqr = l->getSqr(x, y);
	if(sqr)
		return (typeid(*sqr) != typeid(Water));
	else
		return true;
}

bool flAlw(int x, int y, Land *l)
{
	Square *sqr;
	sqr = l->getSqr(x, y);
	if(sqr)
		return (typeid(*sqr) != typeid(Mountain));
	else
		return true;
}


Point * srCastle(int x, int y, Land *l)
{
	Point * crd;
	int xC, yC, i, j, bX, eX, bY, eY;
	bool flag;
	crd = new Point;
	crd->next = NULL;
	bX=eX=bY=eY=flag=0;
	Square *tmpSqr;

	if(x)
		bX = x - 1;
	if(y)
		bY = y - 1;
	if(x < (l->getX() - 1))
		eX = x + 1;
	if(y < (l->getY() - 1))
		eY = y + 1;
	while((eX < (l->getX() - 1)) || (eY < (l->getY() - 1)) || (bX > 0) || (bY > 0))
	{

		for(i = bX; i <= eX; i++)
		{
			for(j = bY; j <= eY; j++)
			{
				tmpSqr = l->getSqr(i, j);
				if(tmpSqr)
					if(typeid(*(l->getSqr(i, j))) == typeid(Castle))
					{
						xC = i;
						yC = j;
						flag = 1;
						break;
					}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		if(flag)
			break;
		if(bX > 0)
			bX = bX - 1;
		if(bY > 0)
			bY = bY - 1;
		if(eX < (l->getX() - 1))
			eX = eX + 1;
		if(eY < (l->getY() - 1))
			eY = eY + 1;
	}
	if(!flag)
		return NULL;
	crd->x = xC;
	crd->y = yC;
	return crd;
}

Point * srCastle(int x, int y, int r, Land *l)
{
	Point * crd;
	int xC, yC, i, j, bX, eX, bY, eY;
	bool flag;
	crd = new Point;
	crd->next = NULL;
	bX=eX=bY=eY=flag=0;
	Square *tmpSqr;

	if(x)
		bX = x - 1;
	if(y)
		bY = y - 1;
	if(x < (l->getX() - 1))
		eX = x + 1;
	if(y < (l->getY() - 1))
		eY = y + 1;
	while((eX < (l->getX() - 1)) || (eY < (l->getY() - 1)) || (bX > 0) || (bY > 0))
	{

		for(i = bX; i <= eX; i++)
		{
			for(j = bY; j <= eY; j++)
			{
				tmpSqr = l->getSqr(i, j);
				if(tmpSqr)
					if(typeid(*(l->getSqr(i, j))) == typeid(Castle))
					{
						xC = i;
						yC = j;
						flag = 1;
						break;
					}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		if(flag)
			break;
		if(bX > 0)
			bX = bX - 1;
		if(bY > 0)
			bY = bY - 1;
		if(eX < (l->getX() - 1))
			eX = eX + 1;
		if(eY < (l->getY() - 1))
			eY = eY + 1;
		if((bX < (x - r)) || (bY < (y - r)) || (eX > (x + r)) || (eY > (y + r)))
		{
			break;
		}
	}
	if(!flag)
		return NULL;
	crd->x = xC;
	crd->y = yC;
	return crd;
}

Point * srEnemy(int x, int y, int r, Land *l)
{
	Point * crd;
	int xC, yC, i, j, bX, eX, bY, eY;
	bool flag;
	crd = new Point;
	crd->next = NULL;
	bX=eX=bY=eY=flag=0;
	Enemy *tmpEnm;

	if(x)
		bX = x - 1;
	if(y)
		bY = y - 1;
	if(x < (l->getX() - 1))
		eX = x + 1;
	if(y < (l->getY() - 1))
		eY = y + 1;
	while((eX < (l->getX() - 1)) || (eY < (l->getY() - 1)) || (bX > 0) || (bY > 0))
	{

		for(i = bX; i <= eX; i++)
		{
			for(j = bY; j <= eY; j++)
			{
				tmpEnm = l->getEnm(i, j);
				if(tmpEnm)
				{
						xC = i;
						yC = j;
						flag = 1;
						break;
				}
			if(flag)
					break;
			}
		if(flag)
			break;
		}
		if(flag)
			break;
		if(bX > 0)
			bX = bX - 1;
		if(bY > 0)
			bY = bY - 1;
		if(eX < (l->getX() - 1))
			eX = eX + 1;
		if(eY < (l->getY() - 1))
			eY = eY + 1;
		if((bX < (x - r)) || (bY < (y - r)) || (eX > (x + r)) || (eY > (y + r)))
		{
			break;
		}
	}
	if(!flag)
		return NULL;
	crd->x = xC;
	crd->y = yC;
	return crd;
}


Point * getWay(Point **mtr, int xB, int yB, int xE, int yE, int szX, int szY)
{
	int x, y;
	Point *pnt, *way;
	if(mtr[xE][yE].data != 0)
		return NULL;
	x = xB;
	y = yB;
	way = new Point;
	way->x = x;
	way->y = y;
	way->data = mtr[x][y].data;
	way->next = NULL;
	while(mtr[x][y].data != 0)
	{	
		pnt = new Point;
		pnt->next = way;
		way = pnt;

		if(y < szY-1)
			if((mtr[x][y+1].data) == (mtr[x][y].data-1))
			{
				way->x = x;
				way->y = ++y;
				way->data = mtr[x][y].data;
				continue;
			}
		if(x < szX-1)
			if((mtr[x+1][y].data) == (mtr[x][y].data-1))
			{
				way->x = ++x;
				way->y = y;
				way->data = mtr[x][y].data;
				continue;
			}
		if(y > 0)
			if((mtr[x][y-1].data) == (mtr[x][y].data-1))
			{
				way->x = x;
				way->y = --y;
				way->data = mtr[x][y].data;
				continue;
			}
		if(x > 0)
			if((mtr[x-1][y].data) == (mtr[x][y].data-1))
			{
				way->x = --x;
				way->y = y;
				way->data = mtr[x][y].data;
				continue;
			}
	}
	return way;
}


int letlgWave(Point **mtr, int xB, int yB, int xE, int yE, Land *l, wFront *buf)
{
	if(xB == xE && yB == yE)
		return -1;

	if(yB < l->getY()-1)
		if(((mtr[xB][yB+1].data) >= (mtr[xB][yB].data)) && lgAlw(xB,yB+1, l)) 
		{
			mtr[xB][yB+1].data = mtr[xB][yB].data + 1;
			//buf->size++;
			buf->mas[buf->size].x = xB;
			buf->mas[buf->size].y = yB+1;
			buf->size++;
		}
	
	if(xB < l->getX()-1)
		if(((mtr[xB+1][yB].data) >= (mtr[xB][yB].data)) && lgAlw(xB+1,yB, l))
		{
			mtr[xB+1][yB].data = mtr[xB][yB].data + 1;
			//buf->size++;
			buf->mas[buf->size].x = xB+1;
			buf->mas[buf->size].y = yB;
			buf->size++;
		}

	if(yB > 0)
		if(((mtr[xB][yB-1].data) >= (mtr[xB][yB].data)) && lgAlw(xB,yB-1, l))
		{
			mtr[xB][yB-1].data = mtr[xB][yB].data + 1;
			//buf->size++;
			buf->mas[buf->size].x = xB;
			buf->mas[buf->size].y = yB-1;
			buf->size++;
		}

	if(xB > 0)
		if(((mtr[xB-1][yB].data) >= (mtr[xB][yB].data)) && lgAlw(xB-1,yB, l))
		{
			mtr[xB-1][yB].data = mtr[xB][yB].data + 1;
			//buf->size++;
			buf->mas[buf->size].x = xB-1;
			buf->mas[buf->size].y = yB;
			buf->size++;
		}
		return buf->size;
}

Point * getlgWay(int xB , int yB, int xE, int yE, Land *l)
{
	Point *way = NULL, **mtr;
	wFront buf1, buf2;
	int i, j, x, y,  numLetWaves;
	x = l->getX();
	y = l->getY();
	mtr = new(Point * [x]);
	for(i = 0; i < x; i++)
	{
		mtr[i] = new (Point[y]);
		for(j = 0; j < y; j++)
		{
			mtr[i][j].x = i;
			mtr[i][j].y = j;
			mtr[i][j].data = MAX_DATA;
		}
	}
	mtr[xB][yB].data = 0;
	buf1.mas[0].x = xB;
	buf1.mas[0].y = yB;
	buf1.size = 1;
	do
	{
		buf2 = buf1;
		buf1.size = 0;
		for(i = 0; i < buf2.size; i++)
			if((numLetWaves = (letlgWave(mtr, buf2.mas[i].x, buf2.mas[i].y, xE, yE, l, &buf1))) < 0)
				break;
		if(numLetWaves < 0)
			break;
	}
	while(buf1.size);

	//if(numLetWaves == 0)
	//	return NULL;

	//----------------------------------------------
	way = getWay(mtr, xE, yE, xB, yB, x, y);
	
	for(i = 0; i < x; i++)
		delete [] mtr[i];
	delete [] mtr;
	
	return way;
}

Point * srlgWay(int xB, int yB, Land *l)
{
	Point *csl;
	csl = srCastle(xB, yB, l);
	if(!csl)
		return NULL;
	return getlgWay(xB, yB, csl->x, csl->y, l);
}


int lethvWave(Point **mtr, int xB, int yB, int xE, int yE, Land *l, wFront *buf)
{
	if(xB==xE && yB == yE)
		return -1;

	if(yB < l->getY()-1)
		if(((mtr[xB][yB+1].data) >= (mtr[xB][yB].data)) && hvAlw(xB,yB+1, l)) 
		{
			mtr[xB][yB+1].data = mtr[xB][yB].data + 1;
			//buf->size++;
			buf->mas[buf->size].x = xB;
			buf->mas[buf->size].y = yB+1;
			buf->size++;
		}
	
	if(xB < l->getX()-1)
		if(((mtr[xB+1][yB].data) >= (mtr[xB][yB].data)) && hvAlw(xB+1,yB, l))
		{
			mtr[xB+1][yB].data = mtr[xB][yB].data + 1;
			//buf->size++;
			buf->mas[buf->size].x = xB+1;
			buf->mas[buf->size].y = yB;
			buf->size++;
		}

	if(yB > 0)
		if(((mtr[xB][yB-1].data) >= (mtr[xB][yB].data)) && hvAlw(xB,yB-1, l))
		{
			mtr[xB][yB-1].data = mtr[xB][yB].data + 1;
			//buf->size++;
			buf->mas[buf->size].x = xB;
			buf->mas[buf->size].y = yB-1;
			buf->size++;
		}

	if(xB > 0)
		if(((mtr[xB-1][yB].data) >= (mtr[xB][yB].data)) && hvAlw(xB-1,yB, l))
		{
			mtr[xB-1][yB].data = mtr[xB][yB].data + 1;
			//buf->size++;
			buf->mas[buf->size].x = xB-1;
			buf->mas[buf->size].y = yB;
			buf->size++;
		}
		return buf->size;
}

Point * gethvWay(int xB , int yB, int xE, int yE, Land *l)
{
	Point *way = NULL, **mtr;
	wFront buf1, buf2;
	int i, j, x, y, numLetWaves;
	x = l->getX();
	y = l->getY();
	mtr = new(Point * [x]);
	for(i = 0; i < x; i++)
	{
		mtr[i] = new (Point[y]);
		for(j = 0; j < y; j++)
		{
			mtr[i][j].x = i;
			mtr[i][j].y = j;
			mtr[i][j].data = MAX_DATA;
		}
	}
	mtr[xB][yB].data = 0;
	buf1.mas[0].x = xB;
	buf1.mas[0].y = yB;
	buf1.size = 1;
	do
	{
		buf2 = buf1;
		buf1.size = 0;
		for(i = 0; i < buf2.size; i++)
			if((numLetWaves = (lethvWave(mtr, buf2.mas[i].x, buf2.mas[i].y, xE, yE, l, &buf1))) < 0)
				break;
		if(numLetWaves < 0)
			break;
	}
	while(buf1.size);

	//if(numLetWaves == 0)
	//	return NULL;

	way = getWay(mtr, xE, yE, xB, yB, x, y);
	
	for(i = 0; i < x; i++)
		delete [] mtr[i];
	delete [] mtr;
	
	return way;
}

Point * srhvWay(int xB, int yB, Land *l)
{
	Point *csl;
	csl = srCastle(xB, yB, l);
	if(!csl)
		return NULL;
	return gethvWay(xB, yB, csl->x, csl->y, l);
}


int letflWave(Point **mtr, int xB, int yB, int xE, int yE, Land *l, wFront *buf)
{
	if(xB==xE && yB == yE)
		return -1;

	if(yB < l->getY()-1)
		if(((mtr[xB][yB+1].data) >= (mtr[xB][yB].data)) && flAlw(xB,yB+1, l)) 
		{
			mtr[xB][yB+1].data = mtr[xB][yB].data + 1;
			//buf->size++;
			buf->mas[buf->size].x = xB;
			buf->mas[buf->size].y = yB+1;
			buf->size++;
		}
	
	if(xB < l->getX()-1)
		if(((mtr[xB+1][yB].data) >= (mtr[xB][yB].data)) && flAlw(xB+1,yB, l))
		{
			mtr[xB+1][yB].data = mtr[xB][yB].data + 1;
			//buf->size++;
			buf->mas[buf->size].x = xB+1;
			buf->mas[buf->size].y = yB;
			buf->size++;
		}

	if(yB > 0)
		if(((mtr[xB][yB-1].data) >= (mtr[xB][yB].data)) && flAlw(xB,yB-1, l))
		{
			mtr[xB][yB-1].data = mtr[xB][yB].data + 1;
			//buf->size++;
			buf->mas[buf->size].x = xB;
			buf->mas[buf->size].y = yB-1;
			buf->size++;
		}

	if(xB > 0)
		if(((mtr[xB-1][yB].data) >= (mtr[xB][yB].data)) && flAlw(xB-1,yB, l))
		{
			mtr[xB-1][yB].data = mtr[xB][yB].data + 1;
			//buf->size++;
			buf->mas[buf->size].x = xB-1;
			buf->mas[buf->size].y = yB;
			buf->size++;
		}
		return buf->size;
}

Point * getflWay(int xB , int yB, int xE, int yE, Land *l)
{
	Point *way = NULL, **mtr;
	wFront buf1, buf2;
	int i, j, x, y, numLetWaves;
	x = l->getX();
	y = l->getY();
	mtr = new(Point * [x]);
	for(i = 0; i < x; i++)
	{
		mtr[i] = new (Point[y]);
		for(j = 0; j < y; j++)
		{
			mtr[i][j].x = i;
			mtr[i][j].y = j;
			mtr[i][j].data = MAX_DATA;
		}
	}
	mtr[xB][yB].data = 0;
	buf1.mas[0].x = xB;
	buf1.mas[0].y = yB;
	buf1.size = 1;
	do
	{
		buf2 = buf1;
		buf1.size = 0;
		for(i = 0; i < buf2.size; i++)
			if((numLetWaves = (letflWave(mtr, buf2.mas[i].x, buf2.mas[i].y, xE, yE, l, &buf1))) < 0)
				break;
		if(numLetWaves < 0)
			break;
	}
	while(buf1.size);

	//if(numLetWaves == 0)
	//	return NULL;

	way = getWay(mtr, xE, yE, xB, yB, x, y);

	for(i = 0; i < x; i++)
		delete [] mtr[i];
	delete [] mtr;

	return way;
}

Point * srflWay(int xB, int yB, Land *l)
{
	Point *csl;
	csl = srCastle(xB, yB, l);
	if(!csl)
		return NULL;
	return getflWay(xB, yB, csl->x, csl->y, l);
}

//=========================================================

//======================Table of Enemy=======================

void tblEnm :: addEnm(Enemy *enm, double inl)
{
	dsrEnm *tmp;
	if(!turn)
	{
		fEnm = turn = new dsrEnm;
		turn->enemy = enm;
		turn->interval = inl;
		turn->time = inl;
		turn->next = turn;
	}
	else
	{
		tmp = turn->next;
		turn->next = new dsrEnm;
		turn->next->next = tmp;
		turn->next->enemy = enm;
		turn->next->interval = inl;
		turn->next->time = inl;
	}
}

Enemy* tblEnm :: getEnm()
{
	if(!turn)
		return NULL;
	turn = turn->next;
	turn->time += turn->interval;
	return turn->enemy;
}

Enemy* tblEnm :: getEnm(double day)
{	
	if(!turn)
		return NULL;
	dsrEnm *res;
	res = turn;
	if(turn->time <= day)
	{
		turn = turn->next;
		res->time += res->interval;
		return res->enemy;
	}
	res = res->next;
	while((res->time <= day) && res != turn)
		res = res->next;
	if(res == turn)
		return NULL;
	turn = res->next;
	res->time += res->interval; 
	return res->enemy;
}

void tblEnm :: print()
{
	dsrEnm *tmp;
	if(!turn)
		return;
	cout << "Interval:" << turn->interval;
	cout << " " << typeid(*(turn->enemy)).name();
	cout << " name:" << turn->enemy->getName();
	cout << " max HP:" << turn->enemy->getMhp();
	cout << " mov spd:" << turn->enemy->getMovs();
	cout << " reg spd:" << turn->enemy->getRegs() << endl;
	tmp = turn->next;
	while(tmp != turn)
	{
		cout << "Interval:" << tmp->interval;
		cout << " " << typeid(*(tmp->enemy)).name();
		cout << " name:" << tmp->enemy->getName();
		cout << " max HP:" << tmp->enemy->getMhp();
		cout << " mov spd:" << tmp->enemy->getMovs();
		cout << " reg spd:" << tmp->enemy->getRegs() << endl;
		tmp = tmp->next;
	}
}

int tblEnm :: save(FILE *stm)
{
	dsrEnm *tmp;
	int n, m = 0, bufI;

	if(!fEnm)
	{
		fwrite(&m, sizeof(int), 1, stm);
		return 1;
	}

	tmp = fEnm;
	bufI = tmp->interval;
	fwrite(&bufI, sizeof(int), 1, stm);
	if(typeid(*(tmp->enemy)) == typeid(lgEnemy))
	{
		n = 1;
		fwrite(&n, sizeof(int), 1, stm);
	}
	else if(typeid(*(tmp->enemy)) == typeid(hvEnemy))
	{
		n = 2;
		fwrite(&n, sizeof(int), 1, stm);
	}
	else if(typeid(*(tmp->enemy)) == typeid(flEnemy))
	{
		n = 3;
		fwrite(&n, sizeof(int), 1, stm);
	}
	else if(typeid(*(tmp->enemy)) == typeid(lgHero))
	{
		n = 4;
		fwrite(&n, sizeof(int), 1, stm);
	}
	else if(typeid(*(tmp->enemy)) == typeid(hvHero))
	{
		n = 5;
		fwrite(&n, sizeof(int), 1, stm);
	}
	else if(typeid(*(tmp->enemy)) == typeid(flHero))
	{
		n = 6;
		fwrite(&n, sizeof(int), 1, stm);
	}
	bufI = tmp->enemy->getDmg();
	fwrite(&bufI, sizeof(int), 1, stm);
	bufI = tmp->enemy->getMhp();
	fwrite(&bufI, sizeof(int), 1, stm);
	bufI = tmp->enemy->getMovs();
	fwrite(&bufI, sizeof(int), 1, stm);
	fwrite(tmp->enemy->getName(), sizeof(char[10]), 1, stm);
	bufI = tmp->enemy->getRegs();
	fwrite(&bufI, sizeof(int), 1, stm);
	tmp = tmp->next;	
	m = 1;
	while(tmp != fEnm)
	{
		m++;
		bufI = tmp->interval;
		fwrite(&bufI, sizeof(int), 1, stm);
		if(typeid(*(tmp->enemy)) == typeid(lgEnemy))
		{
			n = 1;
			fwrite(&n, sizeof(int), 1, stm);
		}
		else if(typeid(*(tmp->enemy)) == typeid(hvEnemy))
		{
			n = 2;
			fwrite(&n, sizeof(int), 1, stm);
		}
		else if(typeid(*(tmp->enemy)) == typeid(flEnemy))
		{
			n = 3;
			fwrite(&n, sizeof(int), 1, stm);
		}
		else if(typeid(*(tmp->enemy)) == typeid(lgHero))
		{
			n = 4;
			fwrite(&n, sizeof(int), 1, stm);
		}
		else if(typeid(*(tmp->enemy)) == typeid(hvHero))
		{
			n = 5;
			fwrite(&n, sizeof(int), 1, stm);
		}
		else if(typeid(*(tmp->enemy)) == typeid(flHero))
		{
			n = 6;
			fwrite(&n, sizeof(int), 1, stm);
		}
		bufI = tmp->enemy->getDmg();
		fwrite(&bufI, sizeof(int), 1, stm);
		bufI = tmp->enemy->getMhp();
		fwrite(&bufI, sizeof(int), 1, stm);
		bufI = tmp->enemy->getMovs();
		fwrite(&bufI, sizeof(int), 1, stm);
		fwrite(tmp->enemy->getName(), sizeof(char[10]), 1, stm);
		bufI = tmp->enemy->getRegs();
		fwrite(&bufI, sizeof(int), 1, stm);
		tmp = tmp->next;
	}
	fwrite(&m, sizeof(int), 1, stm);
	return 0;
}

int tblEnm :: load(FILE * stm, lstAurs *lAurs)
{
	int m, n, i, bufI, inl;
	char *bufCh;
	Enemy *enm;
	lgHero *lgH;
	hvHero *hvH;
	flHero *flH;
	fEnm = turn = NULL;
	fseek(stm, -4, SEEK_END);
	fread(&m, sizeof(int), 1, stm);
	fseek(stm, 0, SEEK_SET);
	if(!m)
		return 1;

	for(i = 0; i < m; i++)
	{
		fread(&inl, sizeof(int), 1, stm);

		fread(&n, sizeof(int), 1, stm);
		if(n == 1)
			enm = new lgEnemy;
		else if(n == 2)
			enm = new hvEnemy;
		else if(n == 3)
			enm = new flEnemy;
		else if(n == 4)
		{
			lgH = new lgHero;
			lgH->setAur(lAurs);
			enm = lgH;
		}
		else if(n == 5)
		{
			hvH = new hvHero;
			hvH->setAur(lAurs);
			enm = hvH;
		}
		else if(n == 6)
		{
			flH = new flHero;
			flH->setAur(lAurs);
			enm = flH;
		}

		fread(&bufI, sizeof(int), 1, stm);
		enm->setDmg(bufI);
		fread(&bufI, sizeof(int), 1, stm);
		enm->setMhp(bufI);
		enm->setHp(bufI);
		fread(&bufI, sizeof(int), 1, stm);
		enm->setMovs(bufI);
		bufCh = new char[10];
		fread(bufCh, sizeof(char[10]), 1, stm);
		enm->setName(bufCh);
		fread(&bufI, sizeof(int), 1, stm);
		enm->setRegs(bufI);	

		addEnm(enm, inl);
	}

	return 0;
}

Enemy :: ~Enemy()
{
	Point *tmp;
	delete [] name;
	if(!way)
		return;
	do
	{
		tmp = way->next;
		delete way;
		way = tmp;
	}
	while(tmp);
}

//================================================================

//=============================Enemy==============================

Enemy :: Enemy(const Enemy &e)
{
	hp = e.hp;
	maxhp = e.maxhp;
	regspd = e.regspd;
	movspd = e.movspd;
	dmg = e.movspd;
	strcpy(name, e.name);
}

Enemy :: Enemy(char *n, int h, int mh, int r, int m, int d)
{
	name = n;
	hp = h;
	maxhp = mh;
	regspd = r;
	movspd = m;
	dmg = d;
}

Enemy & Enemy :: operator=(Enemy &enm)
{
	dmg = enm.dmg;
	maxhp = enm.maxhp;
	hp = enm.hp;
	movspd = enm.movspd;
	regspd = enm.regspd;
	name = enm.name;
	return *this;
}

void Enemy :: setFts(char *n, int h, int mh, int r, int m, int d)
{
	name = n;
	hp = h;
	maxhp = mh;
	regspd = r;
	movspd = m;
	dmg = d;
}

Enemy * Enemy :: stk(Land *l)
{
	int m = getMovs(l);
	for(int i = 0; i < m; i++)
	{
		if(way->next->next != NULL)
			if(!l->getEnm(way->next->x, way->next->y))
			{
				l->setEnm(way->next->x, way->next->y, this);
				l->setEnm(way->x, way->y, NULL);
				way = way->next;
			}
			else
				return this;
	}
	return this;
}

Square * Enemy :: atk(Land *l)
{
	int x, y;
	Point *pnt;
	Castle *csl;
	Square *sqr;
	int flag = 0;
	for(x = 0; x < l->getX(); x++)
	{
		for(y = 0; y < l->getY(); y++)
		{
			if((l->getEnm(x, y)) == this)
				flag = 1;
			if(flag)
				break;
		}
		if(flag)
			break;
	}
	pnt = srCastle(x, y, 1, l);
		if(!pnt)
			return NULL;
		sqr = l->getSqr(pnt->x, pnt->y);
		if(sqr)
		{
			csl = dynamic_cast<Castle*>(sqr);
			if(csl->harm(getDmg(l)*getHp()) <= 0)
			{
				l->setSqr(pnt->x, pnt->y, NULL);
				delete sqr;
				return NULL;
			}
		}

		return sqr;
}

int Enemy :: getMhp(Land *l)
{
	if(l->numAurs(way->x, way->y))
		return maxhp + l->adlMhp(way->x, way->y);
	else
		return maxhp;
}

int Enemy :: getRegs(Land *l)
{
	if(l->numAurs(way->x, way->y))
		return regspd + l->adlRegs(way->x, way->y);
	else
		return regspd;
}
	
int Enemy :: getMovs(Land *l)
{
	if(l->numAurs(way->x, way->y))
		return movspd + l->adlMovs(way->x, way->y);
	else
		return movspd;
}
	
int Enemy :: getDmg(Land *l)
{
	if(l->numAurs(way->x, way->y))
		return dmg + l->adlDmg(way->x, way->y);
	else
		return dmg;
} 


lgEnemy :: lgEnemy()
{
	name = NULL;
	dmg = maxhp = hp = regspd = movspd = dmg = 0;
}

lgEnemy :: lgEnemy(char *n, int h, int mh, int r, int m, int d)
{
	name = n;
	hp = h;
	maxhp = mh;
	regspd = r;
	movspd = m;
	dmg = d;
}


hvEnemy :: hvEnemy()
{
	name = NULL;
	dmg = maxhp = hp = regspd = movspd = dmg = 0;
}

hvEnemy :: hvEnemy(char *n, int h, int mh, int r, int m, int d)
{
	name = n;
	hp = h;
	maxhp = mh;
	regspd = r;
	movspd = m;
	dmg = d;
}

Square * hvEnemy :: atk(Land *l)
{
	int x, y;
	Point *pnt;
	Castle *csl;
	Square *sqr;
	Wall *pwl;
	int flag = 0;
	for(x = 0; x < l->getX(); x++)
	{
		for(y = 0; y < l->getY(); y++)
		{
			if((l->getEnm(x, y)) == this)
				flag = 1;
			if(flag)
				break;
		}
		if(flag)
			break;
	}
	sqr = l->getSqr(way->next->x, way->next->y);
	if(sqr)
		if(typeid(*sqr) == typeid(Wall))
		{
				pwl = dynamic_cast<Wall*>(l->getSqr(way->next->x, way->next->y));
				if(pwl->harm(getDmg(l)) >= 0)
				{
					delete pwl;
					l->setSqr(way->next->x, way->next->y, NULL);
					return NULL;
				}
				return sqr;
		}
	pnt = srCastle(x, y, 1, l);
		if(!pnt)
			return NULL;
		sqr = l->getSqr(pnt->x, pnt->y);
		if(sqr)
		{
			csl = dynamic_cast<Castle*>(sqr);
			if(csl->harm(getDmg()*getHp()) <= 0)
			{
				l->setSqr(pnt->x, pnt->y, NULL);
				delete sqr;
				return NULL;
			}
		}

		return sqr;
}


flEnemy :: flEnemy()
{
	name = NULL;
	dmg = maxhp = hp = regspd = movspd = dmg = 0;
}

flEnemy :: flEnemy(char *n, int h, int mh, int r, int m, int d)
{
	name = n;
	hp = h;
	maxhp = mh;
	regspd = r;
	movspd = m;
	dmg = d;
}


void Hero :: spreadAurs(int x, int y, int r, Land *l)
{
	if((x < 0) || (y < 0) || (x >= l->getX()) || (y >= l->getY()))
		return;
	int xB, yB, xE, yE, i, j;
	for(xB = x; (xB > x-r)&&(xB > 0); xB--);
	for(yB = y; (yB > y-r)&&(yB > 0); yB--);
	for(xE = x; (xE <= x+r)&&(xE < l->getX()-1); xE++);
	for(yE = y; (yE <= y+r)&&(yE < l->getY()-1); yE++);
	for(i = xB; i < xE; i++)
		for(j = yB; j < yE; j++)
			l->addAurs(i, j, aur);
}

Hero & Hero :: operator=(Hero &hr)
{
	aur = hr.aur;
	return *this;
}


lgHero :: lgHero()
{
	name = NULL;
	dmg = maxhp = hp = regspd = movspd = dmg = 0;
}

lgHero :: lgHero(char *n, int h, int mh, int r, int m, int d)
{
	name = n;
	hp = h;
	maxhp = mh;
	regspd = r;
	movspd = m;
	dmg = d;
}

lgHero :: lgHero(char *n, int h, int mh, int r, int m, int d, lstAurs *a)
{
	name = n;
	hp = h;
	maxhp = mh;
	regspd = r;
	movspd = m;
	dmg = d;
	aur = a;
}


hvHero :: hvHero()
{
	name = NULL;
	dmg = maxhp = hp = regspd = movspd = dmg = 0;
}

hvHero :: hvHero(char *n, int h, int mh, int r, int m, int d)
{
	name = n;
	hp = h;
	maxhp = mh;
	regspd = r;
	movspd = m;
	dmg = d;
}

hvHero :: hvHero(char *n, int h, int mh, int r, int m, int d, lstAurs *a)
{
	name = n;
	hp = h;
	maxhp = mh;
	regspd = r;
	movspd = m;
	dmg = d;
	aur = a;
}


flHero :: flHero()
{
	name = NULL;
	dmg = maxhp = hp = regspd = movspd = dmg = 0;
}

flHero :: flHero(char *n, int h, int mh, int r, int m, int d)
{
	name = n;
	hp = h;
	maxhp = mh;
	regspd = r;
	movspd = m;
	dmg = d;
}

flHero :: flHero(char *n, int h, int mh, int r, int m, int d, lstAurs *a)
{
	name = n;
	hp = h;
	maxhp = mh;
	regspd = r;
	movspd = m;
	dmg = d;
	aur = a;
}

//===========================================================

//=====================Tower==================================

Enemy * Tower :: atk(Land *l)
{
	int x, y, i;
	Point *pnt;
	Enemy *enm;
	int flag = 0;
	for(x = 0; x < l->getX(); x++)
	{
		for(y = 0; y < l->getY(); y++)
		{
			if((l->getSqr(x, y)) == this)
				flag = 1;
			if(flag)
				break;
		}
		if(flag)
			break;
	}
	pnt = srEnemy(x, y, getRds(), l);
	if(!pnt)
		return NULL;
	enm = l->getEnm(pnt->x, pnt->y);
	if(enm)
	{
		for(i = 0; i < getSpd(); i++)
			if(enm->harm(getDmg()) <= 0)
			{
				l->setEnm(pnt->x, pnt->y, NULL);
				delete enm;
				break;
				return NULL;
			}
	}

	return enm;
}

//===========================================================

//============================Wall===========================

int Wall :: setHp(int h)
{
	if(h < maxhp)
		hp = h;
	else
		hp = maxhp;
	return hp;
}

int Wall :: harm(int dmg) //нанести урон
{
	hp = hp - dmg;
	if(hp <= 0)
		throw "destroy";
	return hp;
}

int Wall :: rpr(int stg) // восстанавить stg процентов hp
{
	if(stg <= maxhp - hp)
		hp = hp + stg;
	else
		hp = maxhp;
	return hp;
}

//============================================================

//==============================Land==========================

Land :: Land()
{
	sizeX = 0;
	sizeY = 0;
	sqr.resize(0);
	enm.resize(0);
	aurs.resize(0);

}

Land :: Land(int x, int y)
{
	if((x >= 0) && (y >=0))
	{
		sizeX = x;
		sizeY = y;
		int area = x * y;
		sqr.resize(area);
		enm .resize(area);
		aurs.resize(area);
		for(int i = 0; i < area; i++)
		{
			sqr[i] =  NULL;
			enm[i] = NULL;
			aurs[i].resize(0);
		}
	}
}

Square* Land :: getSqr(int x, int y)
{
	if((x >= 0) && (y >=0) && (x < sizeX) && (y < sizeY))
	{
		return sqr[getInx(x, y)];
	}
	else
		return NULL;
}

Square* Land :: setSqr(int x, int y, Square *s)
{
	if((x >= 0) && (y >=0) && (x < sizeX) && (y < sizeY))
	{
		sqr[getInx(x, y)] = s;
		norm();
		return s;
	}
	else
	{
		return NULL;
	}
}

Enemy* Land :: getEnm(int x, int y)
{
	if((x >= 0) && (y >=0) && (x <= sizeX) && (y <= sizeY))
	{
		return enm[getInx(x, y)];
	}
	else
		return NULL;
}

Enemy* Land :: setEnm(int x, int y, Enemy *e)
{
	if((x >= 0) && (y >=0) && (x <= sizeX) && (y <= sizeY))
	{
		enm[getInx(x, y)] = e;
		return e;
	}
	else
	{
		return NULL;
	}
}

int Land :: numAurs(int x, int y)
{
	if((x >= 0) && (y >=0) && (x < sizeX) && (y < sizeY))
	{
		return aurs[getInx(x, y)].size();
	}
	else
		return 0;
}

int Land :: addAurs(int x, int y, lstAurs* a)
{
	if((x >= 0) && (y >=0) && (x < sizeX) && (y < sizeY) && a)
	{
		aurs[getInx(x, y)].resize(aurs[getInx(x, y)].size()+1);
		aurs[getInx(x, y)][aurs[getInx(x, y)].size()-1] = a;
		return aurs[getInx(x, y)].size();
	}
	else
	{
		return 0;
	}
}

void Land :: clrAurs(int x, int y)
{
	if((x >= 0) && (y >=0) && (x < sizeX) && (y < sizeY))
	{
		aurs[getInx(x, y)].resize(0);
	}
	else
	{
		return;
	}
}

int Land :: adlMhp(int x, int y)
{
	int mHP = 0, n, i, j;
	if(!numAurs(x, y))
		return 0;
	i = getInx(x, y);
	n = aurs[i].size();
	for(j = 0; j < n; j++)
		mHP += aurs[i][j]->getMhp();
	return mHP;
}
	
int Land :: adlDmg(int x, int y)
{
	int dmg = 0, n, i, j;
	if(!numAurs(x, y))
		return 0;
	i = getInx(x, y);
	n = aurs[i].size();
	for(j = 0; j < n; j++)
		dmg += aurs[i][j]->getDmg();
	return dmg;
}
	
int Land :: adlRegs(int x, int y)
{
	int regs = 0, n, i, j;
	if(!numAurs(x, y))
		return 0;
	i = getInx(x, y);
	n = aurs[i].size();
	for(j = 0; j < n; j++)
		regs += aurs[i][j]->getMhp();
	return regs;
}
	
int Land :: adlMovs(int x, int y)
{
	int movs = 0, n, i, j;
	if(!numAurs(x, y))
		return 0;
	i = getInx(x, y);
	n = aurs[i].size();
	for(j = 0; j < n; j++)
		movs += aurs[i][j]->getMhp();
	return movs;
}

void Land :: setSz(int x, int y)
{
	if((x >= 0) && (y >=0))
	{
		sizeX = x;
		sizeY = y;
		sqr.resize(x*y);
		enm.resize(x*y);
		aurs.resize(x*y);
	}
}

int Land :: dDay(int day)
{
	int i, j, k, flag;
	Enemy *e;
	lgHero *lgH;
	hvHero *hvH;
	flHero *flH;
	Tower *t;
	Lair *l;
	Square *s;
	vector<Enemy*> mem;
	mem.resize(1);
	mem[0] = NULL;
	//-----------------------------------------------
	for(i = 0; i < sizeX; i++)
		for(j = 0; j < sizeY; j++)
		{
			s = getSqr(i, j);
			e = getEnm(i, j);
			if(e)
			{
				e->atk(this);
			}
			if(s)
			{
				if(typeid(*s) == typeid(Tower))
				{
					t = dynamic_cast<Tower*>(s);
					t->atk(this);
				}
				if(typeid(*s) == typeid(Lair))
				{
					l = dynamic_cast<Lair*>(s);
					l->rls(this, day);
				}
			}
		}
	//-----------------------------------------------
	for(i = 0; i < sizeX; i++)
		for(j = 0; j < sizeY; j++)
		{
			e = getEnm(i, j);
			if(e)
			{
				for(k = 0, flag = 0; k < mem.size(); k++)
					if(mem[k] == e)
						flag = 1;
				if(!flag)
				{
					mem.resize(mem.size()+1);
					mem[mem.size() - 1] = e;
					e->stk(this);
				}
			}
		}
	//----------------------------------------------------
	for(i = 0; i < sizeX; i++)
		for(j = 0; j < sizeY; j++)
			clrAurs(i, j);
	//------------------------------------------------
	for(i = 0; i < sizeX; i++)
		for(j = 0; j < sizeY; j++)
		{
			e = getEnm(i, j);
			if(!e)
				continue;
			if(typeid(*e) == typeid(lgHero))
			{
				lgH = dynamic_cast<lgHero*>(e);
				lgH->spreadAurs(i, j, AURS_RADIUS, this);
			}
			else if(typeid(*e) == typeid(hvHero))
			{
				hvH = dynamic_cast<hvHero*>(e);
				hvH->spreadAurs(i, j, AURS_RADIUS, this);
			}
			else if(typeid(*e) == typeid(flHero))
			{
				flH = dynamic_cast<flHero*>(e);
				flH->spreadAurs(i, j, AURS_RADIUS, this);
			}
		}
	return day+1;
}

void Land :: print()
{
	int i, j, numA;
	Square *tmpSqr;
	Enemy *tmpEnm;
	for(i = sizeY-1; i >= 0; i--)
	{
		for(j = 0; j < sizeX; j++)
		{
			tmpEnm = getEnm(j, i);
			if(tmpEnm)
			{

				if(typeid(*tmpEnm) == typeid(lgHero))
				{
					cout << 'L';
					continue;
				}
				else if(typeid(*tmpEnm) == typeid(hvHero))
				{
					cout << 'H';
					continue;
				}
				else if(typeid(*tmpEnm) == typeid(flHero))
				{
					cout << 'F';
					continue;
				}
				if(typeid(*tmpEnm) == typeid(lgEnemy))
				{
					cout << 'l';
					continue;
				}
				else if(typeid(*tmpEnm) == typeid(hvEnemy))
				{
					cout << 'h';
					continue;
				}
				else if(typeid(*tmpEnm) == typeid(flEnemy))
				{
					cout << 'f';
					continue;
				}
			}
			tmpSqr = getSqr(j, i);
			if(tmpSqr == NULL)
			{
				numA = numAurs(j, i);
				if(numA)
				{
					cout << "A";
					continue;
				}
				cout << 'X';
				continue;
			}
			if(typeid(*tmpSqr) == typeid(Plain))
			{
				numA = numAurs(j, i);
				if(numA)
				{
					cout << "A";
					continue;
				}
				cout << '_';
				continue;
			}
			if(typeid(*tmpSqr) == typeid(Mountain))
			{
				numA = numAurs(j, i);
				if(numA)
				{
					cout << "A";
					continue;
				}
				cout << 'M';
				continue;
			}
			if(typeid(*tmpSqr) == typeid(Water))
			{
				numA = numAurs(j, i);
				if(numA)
				{
					cout << "A";
					continue;
				}
				cout << '~';
				continue;
			}
			if(typeid(*tmpSqr) == typeid(Wall))
			{
				cout << 'W';
				continue;
			}
			if(typeid(*tmpSqr) == typeid(Tower))
			{
				cout << 'T';
				continue;
			}
			if(typeid(*tmpSqr) == typeid(Castle))
			{
				cout << 'C';
				continue;
			}
			if(typeid(*tmpSqr) == typeid(Lair))
			{
				cout << 'L';
				continue;
			}
		}
		cout << endl;
	}
}

int Land :: save (FILE *stm)
{
	int i, n, buf;
	Tower *ptw;
	Wall *pwl;
	Castle *pcl;
	//Lair *plr;
	fwrite(&sizeX, sizeof(int), 1, stm);
	fwrite(&sizeY, sizeof(int), 1, stm);
	for(i = 0; i < sizeX*sizeY; i++)
	{
		if(sqr[i] == NULL)
		{
			n = 0;
			fwrite(&n, sizeof(int), 1, stm);
			continue;
		}
		//----------------------------------------------
		if(typeid(*(sqr[i])) == typeid(Plain))
		{
			n = 1;
			fwrite(&n, sizeof(int), 1, stm);
			continue;
		}
		//-----------------------------------------------
		if(typeid(*(sqr[i])) == typeid(Mountain))
		{
			n = 2;
			fwrite(&n, sizeof(int), 1, stm);
			continue;
		}
		//------------------------------------------------
		if(typeid((*sqr[i])) == typeid(Water))
		{
			n = 3;
			fwrite(&n, sizeof(int), 1, stm);
			continue;
		}
		//-------------------------------------------------
		if(typeid(*(sqr[i])) == typeid(Wall))
		{
			n = 4;
			fwrite(&n, sizeof(int), 1, stm);
			pwl = dynamic_cast<Wall*>(sqr[i]);
			buf = pwl->getMHp();
			fwrite(&buf, sizeof(int), 1, stm);
			continue;
		}
		//--------------------------------------------------
		if(typeid(*(sqr[i])) == typeid(Tower))
		{
			n = 5;
			fwrite(&n, sizeof(int), 1, stm);
			ptw = dynamic_cast<Tower*>(sqr[i]);
			buf = ptw->getLvl();
			fwrite(&buf, sizeof(int), 1, stm);
			continue;
		}
		//---------------------------------------------------
		if(typeid(*(sqr[i])) == typeid(Castle))
		{
			n = 6;
			fwrite(&n, sizeof(int), 1, stm);
			pcl = dynamic_cast<Castle*>(sqr[i]);
			buf = pcl->getLvl();
			fwrite(&buf, sizeof(int), 1, stm);
			fwrite(pcl->getName(), sizeof(char[10]), 1, stm);
			continue;
		}
		//----------------------------------------------------
		if(typeid(*(sqr[i])) == typeid(Lair))
		{
			n = 7;
			fwrite(&n, sizeof(int), 1, stm);
			continue;
		}
	}
	return 0;
}

int Land :: load (FILE *stm, twrTbl *tTbl, cslTbl *cTbl, tblEnm *eTbl)
{
	int i, j, n, buf;
	Wall *pwl;
	Tower *ptw;
	Castle *pcl;
	Lair *plr;
	fread(&sizeX, sizeof(int), 1, stm);
	fread(&sizeY, sizeof(int), 1, stm);
	sqr.resize(sizeX*sizeY);
	enm.resize(sizeX*sizeY);
	aurs.resize(sizeX*sizeY);
	for(i = 0; i < sizeX*sizeY; i++)
	{
		enm[i] = NULL;
		aurs[i].resize(0);
		fread(&n, sizeof(int), 1, stm);
		if(n == 0)
		{
			sqr[i] = NULL;
			continue;
		}
		//----------------------------------------------
		if(n == 1)
		{
			sqr[i] = new Plain;
			continue;
		}
		//-----------------------------------------------
		if(n == 2)
		{
			sqr[i] = new Mountain;
			continue;
		}
		//------------------------------------------------
		if(n == 3)
		{
			sqr[i] = new Water;
			continue;
		}
		//-------------------------------------------------
		if(n == 4)
		{
			pwl = new Wall;
			fread(&buf, sizeof(int), 1, stm);
			pwl->setMHp(buf);
			pwl->setHp(buf);
			sqr[i] = pwl;
			continue;
		}
		//--------------------------------------------------
		if(n == 5)
		{
			ptw = new Tower;
			fread(&buf, sizeof(int), 1, stm);
			ptw->setLvl(buf);
			ptw->setTbl(tTbl);
			sqr[i] = ptw;
			continue;
		}
		//---------------------------------------------------
		if(n == 6)
		{
			pcl = new Castle;
			fread(&buf, sizeof(int), 1, stm);
			pcl->setLvl(buf);
			pcl->setTbl(cTbl);
			fread(pcl->getName(), sizeof(char[10]), 1, stm);
			sqr[i] = pcl;
			continue;
		}
		//----------------------------------------------------
		if(n == 7)
		{
			plr = new Lair;
			plr->setTbl(eTbl);
			sqr[i] = plr;
			continue;
		}	
	}

	for(i = 0; i < sizeX; i++)
		for(j = 0; j < sizeY; j++)
			if(getSqr(i, j))
				if(typeid(*(getSqr(i, j))) == typeid(Lair))
					
				{
					plr = dynamic_cast<Lair*>(getSqr(i, j));
					plr->srWays(i, j, this);
				}

	return 0;
}

void Land :: norm()
{
	int x, y;
	Lair *plr;
	Square *psqr;
	for(x = 0; x < sizeX; x++)
		for(y = 0; y < sizeY; y++)
		{
			psqr = getSqr(x, y);
			if(psqr)
				if(typeid(*psqr) == typeid(Lair))
				{
					plr = dynamic_cast<Lair*>(psqr);
					plr->srWays(x, y, this);
				}
		}
}

//================================================================

//==========================Lair=================================

Lair :: Lair(int x, int y, tblEnm *t, Land *l)
{
	tbl = t;
	lgWay = srlgWay(x, y, l);
	hvWay = srhvWay(x, y, l);
	flWay = srflWay(x, y, l);
}

void Lair :: srWays(int x, int y, Land *l)
{
	lgWay = srlgWay(x, y, l);
	hvWay = srhvWay(x, y, l);
	flWay = srflWay(x, y, l);
}

Enemy* Lair :: rls(Land *l, int d)
{
	Enemy *rlr, *enm;
	lgHero *lgH;
	hvHero *hvH;
	flHero *flH;
	lstAurs *lAurs;
	if(tbl)
	{
		enm = tbl->getEnm(d);
		if(!enm)
			return NULL;
		if(typeid(*enm) == typeid(lgEnemy))
		{
			rlr = new (lgEnemy);
			*rlr = *enm;
			if(lgWay)
			{
				rlr->setWay(lgWay->next);
				l->setEnm(lgWay->next->x, lgWay->next->y, rlr);
			}
			else
				rlr->setWay(NULL);
		}
		else if(typeid(*enm) == typeid(hvEnemy))
		{
			rlr = new (hvEnemy);
			*rlr = *enm;
			if(hvWay)
			{
				rlr->setWay(hvWay->next); 
				l->setEnm(hvWay->next->x, hvWay->next->y, rlr);
			}
			else
				rlr->setWay(NULL);
		}
		else if(typeid(*enm) == typeid(flEnemy))
		{
			rlr = new (flEnemy);
			*rlr = *enm;
			if(flWay)
			{
				rlr->setWay(flWay->next); 
				l->setEnm(flWay->next->x, flWay->next->y, rlr);
			}
			else
				rlr->setWay(NULL);
		}
		else if(typeid(*enm) == typeid(lgHero))
		{
			lgH = dynamic_cast<lgHero*>(enm);
			lAurs = lgH->getAur();
			lgH = new (lgHero);
			lgH->setAur(lAurs);
			rlr = lgH;
			*rlr = *enm;
			if(lgWay)
			{
				rlr->setWay(lgWay->next);
				l->setEnm(lgWay->next->x, lgWay->next->y, rlr);
			}
			else
				rlr->setWay(NULL);
		}
		else if(typeid(*enm) == typeid(hvHero))
		{
			hvH = dynamic_cast<hvHero*>(enm);
			lAurs = hvH->getAur();
			hvH = new (hvHero);
			hvH->setAur(lAurs);
			rlr = hvH;
			*rlr = *enm;
			if(hvWay)
			{
				rlr->setWay(hvWay->next); 
				l->setEnm(hvWay->next->x, hvWay->next->y, rlr);
			}
			else
				rlr->setWay(NULL);
		}
		else if(typeid(*enm) == typeid(flHero))
		{
			flH = dynamic_cast<flHero*>(enm);
			lAurs = flH->getAur();
			flH = new (flHero);
			flH->setAur(lAurs);
			rlr = flH;
			*rlr = *enm;
			rlr->setWay(flWay->next); 
			l->setEnm(flWay->next->x, flWay->next->y, rlr);
		}

		return rlr;
	}
	return NULL;
}

//=============================================================
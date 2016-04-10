// twr0.1.cpp: определяет точку входа для консольного приложения.
// Вариант 25 Защитный башни I

#include "stdafx.h"
#include "landElements.h"

//---------------------------------------------------------------------


//------------------------------------------------------------------------

int game(Land *lnd, cslTbl *cTbl, twrTbl *tTbl, lstAurs *lAurs)
{
	int day = 1, x, y;
	char tmpCh;
	while(day < 40)
	{
		system("cls");
		cout << "                 DAY: " << day<< endl;
		cout << endl;
		lnd->print();
		day = lnd->dDay(day);
		
		cout << endl;
		cout << "      |-----------------------------------------------|" << endl;
		cout << "      |                ADD Tower(1)                   |" << endl;
		cout << "      |                ADD Wall(2)                    |" << endl;
		cout << "      |                  Check(9)                     |" << endl;
		cout << "      |                  EXIT(0)                      |" << endl;
		cout << "      |-----------------------------------------------|" << endl;
		cout << "Input NUMBER: ";
		cin >> tmpCh;
		switch(tmpCh)
		{
		case '0':
			return 0;
		case '1':  
			{	//----------------------------------------------------------//
			cout << "Coordinates of the TOWER" << endl;
			cout << "Input X: ";
			cin >> x;
			cout << "Input Y: ";
			cin >> y;
			lnd->setSqr(x, y, new Tower(0, tTbl));
			continue;
			}
			//----------------------------------------------------------------//
		case '2':
			{  //------------------------------------------------------------//
				cout << "Coordinates of the WALL" << endl;
				cout << "Input X: ";
				cin >> x;
				cout << "Input Y: ";
				cin >> y;
				lnd->setSqr(x, y, new Wall(100));
				continue;
			}  //----------------------------------------------------------------//
		case '9':
			{   //-----------------------TEST------------------------------------//
				continue;
				//cout << "-------------------------OK---------------------" << endl;
				//system("pause");
			}  //--------------------------TEST------------------------------------//
		}
	}
	system("cls");
	cout << endl << endl << endl;
	cout << "-----------------!!!END!!!------------------" << endl;
	cout << endl << endl << endl;
	system("pause");
	return 0;
}

int lvlConstructor(Land *lnd, cslTbl *cTbl, twrTbl *tTbl, tblEnm *tEnm, lstAurs *lAurs)
{
	int int1, int2, int3, int4, int5, x, y;
	bool hr;
	char tmpCh, *buf;
	FILE *fl;
	for(;;)
	{
		system("cls");
		cout << "-------------------EDIT LEVEL--------------------------" << endl;
		cout << "                 SIZE OF LAND: " << lnd->getX() << " X " << lnd->getY() << endl;
		cout << endl;
		lnd->print();
		
		cout << endl;
		cout << "      |-----------------------------------------------|" << endl;
		cout << "      |           ADD / Redefine Square(1)            |" << endl;
		cout << "      |                 Resize(2)                     |" << endl;
		cout << "      |             Edit CASTLE TABLE(3)              |" << endl;
		cout << "      |             Edit TOWER TABLE(4)               |" << endl;
		cout << "      |             Edit ENEMY TABLE(5)               |" << endl;
		cout << "      |              Edit AURS TABLE(6)               |" << endl;
		cout << "      |                  LOAD(7)                      |" << endl;
		cout << "      |                  SAVE(8)                      |" << endl;
		cout << "      |               !!!PLAY!!!(9)                   |" << endl;
		cout << "      |                  EXIT(0)                      |" << endl;
		cout << "      |-----------------------------------------------|" << endl;
		cout << "Input NUMBER: ";
		cin >> tmpCh;
		switch(tmpCh)
		{
		case '0':
			return 0;
		case '1':  
			{	//-------------------добавление квадрата--------------------------//
			cout << "Coordinates of the square" << endl;
			cout << "Input X: ";
			cin >> x;
			cout << "Input Y: ";
			cin >> y;
			cout << "|Plain(1)|Mountain(2)|Water(3)|Tower(4)|Wall(5)|Castle(6)|Lair(7)|Cancel(0)| :";
			cin >> tmpCh;
			switch(tmpCh)
			{
			case '1':
				lnd->setSqr(x, y, new Plain);
				continue;
			case '2':
				lnd->setSqr(x, y, new Mountain);
				continue;
			case '3':
				lnd->setSqr(x, y, new Water);
				continue;
			case '4':
				cout << "Input LEVEL of the TOWER: ";
				cin >> int1;
				lnd->setSqr(x, y, new Tower(int1, tTbl));
				continue;
			case '5':
				cout << "Input HP of the WALL: ";
				cin >> int1;
				lnd->setSqr(x, y, new Wall(int1));
				continue;
			case '6':
				cout << "Input HP of the CASTLE: ";
				cin >> int1;
				cout << "Input LEVEL of the CASTLE: ";
				cin >> int2;
				lnd->setSqr(x, y, new Castle(int1, int2, cTbl));
				continue;
			case '7':
				lnd->setSqr(x, y, new Lair(x, y, tEnm, lnd));
				continue;
			case '0':
				continue;
			}
			continue;
			}	//----------------------------------------------------------------//
		case '2':
			{  //------------------------------------------------//
				cout << "New SIZE of land" << endl;
				cout << "Input X: ";
				cin >> x;
				cout << "Input Y: ";
				cin >> y;
				lnd->setSz(x, y);
				continue;
			}  //----------------------------------------------------------------//
		case '3':
			{  //------------------------------------------------//
				while(true)
				{
					//tmpCh = '';
					system("cls");
					cout << "-----CASTLE TABLE----" << endl;
					cTbl->print();
					cout << endl;
					cout << "Input LEVEL: ";
					cin >> int1;
					cout <<"cost:"<<cTbl->getCost(int1)<<" Mhp:"<<cTbl->getMhp(int1)<<" yld:"<<cTbl->getYld(int1)<<" spd:"<<cTbl->getSpd(int1)<<endl;
					cout << "SET cost(1), Mhp(2), yld(3), spd(4), Mlvl(5), EXIT(0): ";
					cin >> tmpCh;
					if(tmpCh == '0')
						break;
					cout << "Input VALUE: ";
					cin >> int2;
					switch(tmpCh)
					{
					case '1':
						cTbl->setCost(int1, int2);
					continue;

					case '2':
						cTbl->setMhp(int1, int2);
					continue;

					case '3':
						cTbl->setYld(int1, int2);
					continue;
					
					case '4':
						cTbl->setSpd(int1, int2);
					continue;

					case '5':
						cTbl->setMlvl(int2);
					continue;
					}
				}
				continue;
			}

		case '4':
			{  //------------------------------------------------//
				while(true)
				{
					system("cls");
					cout << "-----TOWER TABLE----" << endl;
					tTbl->print();
					cout << endl;
					cout << "Input LEVEL: ";
					cin >> int1;
					cout <<"cost:"<<tTbl->getCost(int1)<<" dmg:"<<tTbl->getDmg(int1)<<" rds:"<<tTbl->getRds(int1)<<" spd:"<<tTbl->getSpd(int1)<<endl;
					cout << "SET cost(1), dmg(2), rds(3), spd(4), Mlvl(5), EXIT(0): ";
					cin >> tmpCh;
					if(tmpCh == '0')
						break;
					cout << "Input VALUE: ";
					cin >> int2;
					switch(tmpCh)
					{
					case '1':
						tTbl->setCost(int1, int2);
					continue;

					case '2':
						tTbl->setDmg(int1, int2);
					continue;

					case '3':
						tTbl->setRds(int1, int2);
					continue;
					
					case '4':
						tTbl->setSpd(int1, int2);
					continue;

					case '5':
						tTbl->setMlvl(int2);
					continue;
					}
				}
				continue;
			}

		case '5':
			{  //------------------------------------------------//
				while(true)
				{
					system("cls");
					cout << "-----ENEMY TABLE----" << endl;
					tEnm->print();
					cout << endl;
					cout << "Add(1), EXIT(0): ";
					cin >> tmpCh;
					if(tmpCh == '0')
						break;
					switch(tmpCh)
					{
					case '1':
						
						cout << "lg(1), hv(2), fl(3): ";
						cin >> tmpCh;
						cout << "enemy(0), hero(1) :";
						cin >> hr;
						cout << "interval: ";
						cin >> int1;
						cout << "max HP: ";
						cin >> int2;
						cout << "mov spd: ";
						cin >> int3;
						cout << "reg spd: ";
						cin >> int4;
						cout << "dmg: ";
						cin >> int5;
						cout << "name: ";
						buf = new char[10];
						cin >> buf;
						switch(tmpCh)
						{
						case '1':
							if(hr)
								tEnm->addEnm((new lgHero(buf, int2, int2, int3, int4, int5, lAurs)), int1);
							else
								tEnm->addEnm((new lgEnemy(buf, int2, int2, int3, int4, int5)), int1);
							continue;
						case '2':
							if(hr)
								tEnm->addEnm((new hvHero(buf, int2, int2, int3, int4, int5, lAurs)), int1);
							else
								tEnm->addEnm((new hvEnemy(buf, int2, int2, int3, int4, int5)), int1);
							continue;
						case '3':
							if(hr)
								tEnm->addEnm((new flHero(buf, int2, int2, int3, int4, int5, lAurs)), int1);
							else
								tEnm->addEnm((new flEnemy(buf, int2, int2, int3, int4, int5)), int1);
							continue;
						}
					continue;
					}
				}
				continue;
			}
		case '6':
			{  //--------------------TABLE of AURS-------------------------//
				while(true)
				{
					system("cls");
					cout << "-----AURS TABLE----" << endl;
					if(lAurs)
						lAurs->print();
					cout << endl;
					cout << "ADD(1), EXIT(0): ";
					cin >> tmpCh;
					if(tmpCh == '0')
						break;
					switch(tmpCh)
					{
					case '1':
						cout << "max HP: ";
						cin >> int1;
						cout << "reg spd: ";
						cin >> int2;
						cout << "mov spd: ";
						cin >> int3;
						cout << "dmg: ";
						cin >> int4;
						lAurs->addAura(int1, int2, int3, int4);
					continue;
					}
				}
				continue;
			} 
		case '7':
			{  //--------------------LOAD----------------------------//
				fl = fopen("test.twr", "r");
				tTbl->load(fl);
				fclose(fl);
				fl = fopen("test.csl", "r");
				cTbl->load(fl);
				fclose(fl);
				fl = fopen("test.aur", "r");
				lAurs->load(fl);
				fclose(fl);
				fl = fopen("test.enm", "rb");
				tEnm->load(fl, lAurs);
				fclose(fl);
				fl = fopen("test.lnd", "r");
				lnd->load(fl, tTbl, cTbl, tEnm);
				fclose(fl);
				continue;
			} 
			case '8':
			{  //--------------------SAVE----------------------------//
				fl = fopen("test.twr", "w");
				tTbl->save(fl);
				fclose(fl);
				fl = fopen("test.csl", "w");
				cTbl->save(fl);
				fclose(fl);
				fl = fopen("test.aur", "w");
				lAurs->save(fl);
				fclose(fl);
				fl = fopen("test.enm", "wb");
				tEnm->save(fl);
				fclose(fl);
				fl = fopen("test.lnd", "w");
				lnd->save(fl);
				fclose(fl);
				continue;
			} 
		
		case '9':
			{   //-----------------------TEST------------------------------------//
				game(lnd, cTbl, tTbl, lAurs);
				

				//cout << "-------------------------OK---------------------" << endl;
				//system("pause");
				
			}  //--------------------------TEST------------------------------------//
		}
	}
	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{
	Land land1(10, 10);
	twrTbl tTbl1(10);
	cslTbl cTbl1(10);
	tblEnm tEnm;
	lstAurs lAurs;
	lvlConstructor(&land1, &cTbl1, &tTbl1, &tEnm, &lAurs);
	return 0;
}


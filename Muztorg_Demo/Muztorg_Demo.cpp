// Muztorg_Demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;
// ��������� ����� ����� ��� �����������
class Guitar {
public:
	virtual void info() = 0;
	virtual ~Guitar() {}
};

class Drums {
public:
	virtual void info() = 0;
	virtual ~Drums() {}
};

class Piano {
public:
	virtual void info() = 0;
	virtual ~Piano() {}
};
// ����� ����������� ����� yamaha
class YamahaGuitar : public Guitar {
public:
	void info() {
		cout << "This is a Yamaha Guitar!" << endl;
	}
};

class YamahaDrums : public Drums {
public:
	void info() {
		cout << "This is a Yamaha Drums!" << endl;
	}
};

class YamahaPiano : public Piano {
public:
	void info() {
		cout << "This is a Yamaha Piano!" << endl;
	}
};
// ����� ����������� ����� fender
class FenderGuitar : public Guitar {
public:
	void info() {
		cout << "This is a Fender Guitar!" << endl;
	}
};

class FenderDrums : public Drums {
public:
	void info() {
		cout << "This is a Fender Drums!" << endl;
	}
};

class FenderPiano : public Piano {
public:
	void info() {
		cout << "This is a Fender Piano!" << endl;
	}
};
//����������� �������
class Store {
public: virtual Guitar * CreateGuitar() = 0;
		virtual Drums * CreateDrums() = 0;
		virtual Piano * CreatePiano() = 0;
		virtual ~Store() {};
};
//������� ����������� ����� yamaha
class YamahaStore : public Store {
public:
	Guitar * CreateGuitar() {
		return new YamahaGuitar;
	};
	Drums * CreateDrums() {
		return new YamahaDrums;
	};
	Piano * CreatePiano() {
		return new YamahaPiano;
	};
	virtual ~YamahaStore() {};
};
//������� ����������� ����� fender
class FenderStore : public Store {
public:
	Guitar * CreateGuitar() {
		return new FenderGuitar;
	};
	Drums * CreateDrums() {
		return new FenderDrums;
	};
	Piano * CreatePiano() {
		return new FenderPiano;
	};
	virtual ~FenderStore() {};
};

//���c, �� ������ �� �����������
class Sklad {
public:
	vector <Guitar*> sG;
	vector <Drums*> sD;
	vector <Piano*> sP;
	~Sklad() {
		unsigned int i;
		for (i = 0; i < sG.size(); ++i)
			delete sG[i];
		for (i = 0; i < sD.size(); ++i)
			delete sD[i];
		for (i = 0; i < sP.size(); ++i)
			delete sP[i];
	}
	void info() {
		unsigned int i;
		for (i = 0; i < sG.size(); ++i)
			sG[i]->info();
		for (i = 0; i < sD.size(); ++i)
			sD[i]->info();
		for (i = 0; i < sP.size(); ++i)
			sP[i]->info();
	}
};
//��� ����������� �������
class Place {
public:
	Sklad* createSklad(Store& store) {
		Sklad* p = new Sklad;
		p->sG.push_back(store.CreateGuitar());
		p->sD.push_back(store.CreateDrums());
		p->sP.push_back(store.CreatePiano());
		return p;
	}
};

void showMenu() {
	cout << "================================================================================" << endl;
	cout << "1. C������� ����������� ����� Yamaha." << endl;
	cout << "2. C������� ����������� ����� Fender." << endl;
	cout << "3. ����������� �����." << endl;
	cout << "4. �������� ������." << endl;
	cout << "5. �����" << endl;
	cout << "================================================================================" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	unsigned int i;
	Place place;
	YamahaStore ym_store;
	FenderStore fn_store;
	vector <Sklad*> vSkYa;
	vector <Sklad*> vSkFe;
	/*
	Sklad* p = new Sklad;
	Sklad* ym = place.createSklad(ym_store);
	Sklad* fn = place.createSklad(fn_store);
	cout << "Sklad Yamaha:" << endl;
	ym->info();
	cout << "Sklad Fender:" << endl;
	fn->info();
	*/
	int choise;
	do {
		showMenu();
		cout << "��� ����:"; cin >> choise;
		switch (choise)
		{
		case 1: vSkYa.push_back(place.createSklad(ym_store)); cout << "����!" << endl; break;
		case 2: vSkFe.push_back(place.createSklad(fn_store)); cout << "����!" << endl; break;
		case 3: 
			cout << "Sklad Yamaha:" << endl;
			for (i = 0; i < vSkYa.size(); ++i) {
				vSkYa[i]->info();
			}
			cout << "Sklad Fender:" << endl;
			for (i = 0; i < vSkFe.size(); ++i) {
				vSkFe[i]->info();
			}
			break;
		case 4: vSkYa.clear(); vSkFe.clear(); break;
		case 5: exit(0); break;
		default: cout << "������������ ����� ����." << endl;
			break;
		}
	} while (1);
	vSkYa.clear(); vSkFe.clear();
	system("pause");
	return 0;
}
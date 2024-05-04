#include <iostream>
#include <string>
using namespace std;

class Hero {
	protected:
		string name{};
		string attack{};
		string speed{};
		string health{};
		string defense{};
	public:
		Hero(string n, string a, string s, string h, string d) : name(n), attack(a), speed(s), health(h), defense(d) {}
		string GetName() { return name; }
		string GetAttack() { return attack; }
		string GetSpeed() { return speed; }
		string GetHealth() { return health; }
		string GetDefense() { return defense; }
};

class Human : public Hero {
	public:
		Human() : Hero("Human", "20", "20", "150", "0") {}
};

class Elf : public Hero {
	public:
		Elf() : Hero("Elf", "15", "30", "100", "0") {}
};

class HumanDecorator : public Hero {
	protected:
		Hero* hero;
	public:
		HumanDecorator(string n, string a, string s, string health, string d, Hero* h) : Hero(n, a, s, health, d), hero(h) {}
};

class ElfDecorator : public Hero {
	protected:
		Hero* hero;
	public:
		ElfDecorator(string n, string a, string s, string health, string d, Hero* h) : Hero(n, a, s, health, d), hero(h) {}
};

class HumanWarrior : public HumanDecorator {
	public:
		HumanWarrior(Hero* p) : HumanDecorator(
			p->GetName() + " Warrior",
			to_string(stoi(p->GetAttack()) + 20),
			to_string(stoi(p->GetSpeed()) + 10),
			to_string(stoi(p->GetHealth()) + 50),
			to_string(stoi(p->GetDefense()) + 20), p) { }
};

class HumanSwordBearer : public HumanDecorator {
	public:
		HumanSwordBearer(Hero* p) : HumanDecorator(
			p->GetName() + " SwordBearer",
			to_string(stoi(p->GetAttack()) + 40),
			to_string(stoi(p->GetSpeed()) - 10),
			to_string(stoi(p->GetHealth()) + 50),
			to_string(stoi(p->GetDefense()) + 40), p) { }
};

class HumanArcher : public HumanDecorator {
	public:
		HumanArcher(Hero* p) : HumanDecorator(
			p->GetName() + " Archer",
			to_string(stoi(p->GetAttack()) + 20),
			to_string(stoi(p->GetSpeed()) + 20),
			to_string(stoi(p->GetHealth()) + 50),
			to_string(stoi(p->GetDefense()) + 10), p) { }
};

class HumanHorseman : public HumanDecorator {
	public:
		HumanHorseman(Hero* p) : HumanDecorator(
			p->GetName() + " Horseman",
			to_string(stoi(p->GetAttack()) - 10),
			to_string(stoi(p->GetSpeed()) + 40),
			to_string(stoi(p->GetHealth()) + 200),
			to_string(stoi(p->GetDefense()) + 100), p) { }
};


class ElfWarrior : public ElfDecorator {
	public:
		ElfWarrior(Hero* p) : ElfDecorator(
			p->GetName() + " Warrior",
			to_string(stoi(p->GetAttack()) + 20),
			to_string(stoi(p->GetSpeed()) - 10),
			to_string(stoi(p->GetHealth()) + 100),
			to_string(stoi(p->GetDefense()) + 20), p) { }
};

class ElfMagician : public ElfDecorator {
	public:
		ElfMagician(Hero* p) : ElfDecorator(
			p->GetName() + " Magician",
			to_string(stoi(p->GetAttack()) + 10),
			to_string(stoi(p->GetSpeed()) + 10),
			to_string(stoi(p->GetHealth()) - 50),
			to_string(stoi(p->GetDefense()) + 10), p) { }
};

class ElfCrossbowman : public ElfDecorator {
	public:
		ElfCrossbowman(Hero* p) : ElfDecorator(
			p->GetName() + " Crossbowman",
			to_string(stoi(p->GetAttack()) + 20),
			to_string(stoi(p->GetSpeed()) + 10),
			to_string(stoi(p->GetHealth()) + 50),
			to_string(stoi(p->GetDefense()) - 10), p) { }
};

class ElfEvilMage : public ElfDecorator {
	public:
		ElfEvilMage(Hero* p) : ElfDecorator(
			p->GetName() + " Evil-Mage",
			to_string(stoi(p->GetAttack()) + 70),
			to_string(stoi(p->GetSpeed()) + 20),
			to_string(stoi(p->GetHealth()) + 0),
			to_string(stoi(p->GetDefense()) + 0), p) { }
};

class ElfGoodMage : public ElfDecorator {
	public:
		ElfGoodMage(Hero* p) : ElfDecorator(
			p->GetName() + " Good-Mage",
			to_string(stoi(p->GetAttack()) + 50),
			to_string(stoi(p->GetSpeed()) + 30),
			to_string(stoi(p->GetHealth()) + 100),
			to_string(stoi(p->GetDefense()) + 30), p) { }
};

void client(Hero* p) {
	cout << "Hero: " << p->GetName() << endl;
	cout << "Attack: " << p->GetAttack() << endl;
	cout << "Speed: " << p->GetSpeed() << endl;
	cout << "Health: " << p->GetHealth() << endl;
	cout << "Defense: " << p->GetDefense() << endl;
	cout << endl << endl;
}

int main() {
	Hero* p = new Human();
	client(p);

	p = new HumanWarrior(p);
	client(p);

	p = new HumanSwordBearer(p);
	p = new HumanArcher(p);
	p = new HumanHorseman(p);
	client(p);

	cout << endl;

	p = new Elf();
	client(p);

	p = new ElfWarrior(p);
	client(p);

	p = new ElfMagician(p);
	p = new ElfCrossbowman(p);
	p = new ElfEvilMage(p);
	p = new ElfGoodMage(p);
	client(p);

	cout << endl;
	system("pause");
}
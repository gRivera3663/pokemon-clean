#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <list>

using namespace std;

enum class element {
    fire = 0, water = 1, grass = 2, normal = 3, dragon = 4
};

struct PokeEntry
{
	int number;
	char name[20];
	char type[10];
	char description;
	PokeEntry() {};
	PokeEntry(int n) {};
};

class Pokemon {
private:
	PokeEntry userEntry;
	int id;
	std::string name;
	int level = 1;
protected:
	int maxHP = 20;
	int currentHP = maxHP;
	int speed = 10;
	int attack = 10;
	int defense = 10;
	int specialAttack = 10;
	int specialDefense = 10;
	std::list<element> weaknesses;

public:
	Pokemon(int i) {}
	~Pokemon() {}
	std::string get_name() {
		return name;
	}
	int get_level() {
		return level;
	}
	int get_maxHP() {
		return maxHP;
	}
	int get_currentHP() {
		return currentHP;
	}

	int take_damage(int damageAmount, std::list<element> damageTypes);

	friend Pokemon* make_pokemon(element type, std::string name);

	friend std::ostream& operator<< (std::ostream &out, Pokemon &pokemon);

	void write();

};

class Fire: public Pokemon {
public:
	Fire(int index);
};

class Water: public Pokemon {
public:
	Water(int index);
};

class Grass: public Pokemon {
public:
	Grass(int index);
};

#endif // POKEMON_H

#pragma once
#include <string>

class Character
{
private:
	std::string name;
	int hp;
	int mana;
	int def;
	int atackStat;
	int crit;
	int dodge;
	int block;
	int strenght;
	int inteli;
	int dex;
public:
	virtual void atack(std::string) = 0;
	virtual void useSkill(int) = 0;
	virtual void loadFromFile(std::string) = 0;
};
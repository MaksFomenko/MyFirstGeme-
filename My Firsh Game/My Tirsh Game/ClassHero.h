#pragma once
#include <iostream>
#include <string.h>
#include "ClassPlayer.h"
#include "ClassHero.h"
#include "HeroManager.h"
#include "PlayerManager.h"
#include "GameManager.h"
#include "PlayerHero.h"
#include "Session.h"
#include "TeamManager.h"

using namespace std;

class ClassHero
{
private:
	string name;
	int id = 0, hp = 0, damage = 0;
public:
	void SetCreateHero(int hp, int damage, string name) {
		this->hp = hp;
		this->damage = damage;
		this->name = name;
	}
	int GetHeroId() {
		return id;
	}
	int SetHeroId(int id) {
		this->id = id;
		return id;
	}
	int GetHP() {
		return hp;
	}
	int GetDMG() {
		return damage;
	}
	bool GetHeroName(string name) {
		if (this->name == name) {
			bool NameMatch = true;
			return NameMatch;
		}
		else if (this->name != name) { return 0; }
	}
	bool GetHeroID(int id) {
		if (this->id == id) {
			bool IIDmatch = true;
			return IIDmatch;
		}
		else if (this->id != id) { return 0; }
	}
	void ShowHeroInfo() {
		cout << "__________________________" << "\nClass is: " << name << "\nHP is: " << hp << "\nDMG is: " << damage << "\n__________________________" << endl;

	}
};


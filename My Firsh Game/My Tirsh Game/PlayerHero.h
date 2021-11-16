#pragma once
#include <iostream>
#include <string.h>
#include "ClassPlayer.h"
#include "ClassHero.h"
using namespace std;


class PlayerHero {
private:
	ClassPlayer p;
	ClassHero h;
	int id = 0, hp = 0, damage = 0;
public:
	void MatchingHeroPlayer(ClassPlayer a, ClassHero b, int id) {
		p = a;
		h = b;
		this->id = id;
		hp = b.GetHP();
		damage = b.GetDMG();
	}
	void View() {
		p.ShowPlayerInfo();
		h.ShowHeroInfo();
	}
	int GetID() {
		return id;
	}
	int GetHP() {
		return hp;
	}
	int GetDMG() {
		return damage;
	}
};


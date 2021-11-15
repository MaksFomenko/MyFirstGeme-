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

class GameManager
{
	Session s[5];
public:
	void GetSession(Session b, int i) {
		s[i] = b;
	}
	void GetSessionWin(int winner, int i) {
		s[i].sessionwinner = winner;
	}
	void SessionsList() {
		for (int i = 0; i < 5; i++) {
			s[i].SessionInfo(s[i].sessionwinner, i);
		}
	}
	int PerformGameSession() {
		int create;
		cout << "#######################################################" << endl;
		cout << "Perform game session that consists of 5 games?\n1.Yes\n2.No. I want to change players" << endl;
		cin >> create;
		cout << "#######################################################" << endl;
		return create;
	}
};


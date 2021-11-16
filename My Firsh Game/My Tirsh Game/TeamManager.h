#include <iostream>
#include <string.h>
#include "PlayerHero.h"

using namespace std;

class TeamManager
{
private:
	PlayerHero a[10], team1[5], team2[5];
	int hp1Final = 0, hp2Final = 0;
	int Team1HP = 0, Team1DMG = 0, Team2HP = 0, Team2DMG = 0;
	bool winner;
public:
	void GetPlayerHero(PlayerHero g, int i) {
		a[i] = g;
	}
	void GenerateTeams() {
		for (int i = 0; i < 10; i++) {
			if (a[i].GetID() == 1)	team1[0] = a[i];
			if (a[i].GetID() == 2)	team1[1] = a[i];
			if (a[i].GetID() == 3)	team1[2] = a[i];
			if (a[i].GetID() == 4)	team1[3] = a[i];
			if (a[i].GetID() == 5)	team1[4] = a[i];
			if (a[i].GetID() == 6)	team2[0] = a[i];
			if (a[i].GetID() == 7)	team2[1] = a[i];
			if (a[i].GetID() == 8)	team2[2] = a[i];
			if (a[i].GetID() == 9)	team2[3] = a[i];
			if (a[i].GetID() == 10) team2[4] = a[i];
		}
	};
	void GetTeamInfo1() {
		cout << "\n\n##############################" << "\nTeam1:" << endl;
		for (int i = 0; i < 5; i++) {
			team1[i].View();
		}

	}
	void GetTeamInfo2() {
		cout << "\n\n##############################" << "\nTeam2:" << endl;
		for (int i = 0; i < 5; i++) {
			team2[i].View();
		}

	}
	void TeamOne() {
		for (int i = 0; i < 5; i++) {
			Team1HP += team1[i].GetHP();
			Team1DMG += team1[i].GetDMG();
		}
	}
	void TeamTwo() {
		for (int i = 0; i < 5; i++) {
			Team2HP += team2[i].GetHP();
			Team2DMG += team2[i].GetDMG();
		}
	}
	int CalculateWinner() {
		hp1Final = Team1HP - Team2DMG;
		hp2Final = Team2HP - Team1DMG;
		if (hp1Final > hp2Final) {
			return 1;
		}
		else if (hp1Final < hp2Final) {
			return 0;
		}
		else if (hp2Final == hp1Final)
			return 2;
	}
};


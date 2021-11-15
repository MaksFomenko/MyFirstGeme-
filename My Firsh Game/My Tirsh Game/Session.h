#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Session
{
	TeamManager a;
public:
	int sessionwinner = 0;
	void GetTeamManager(TeamManager b) {
		a = b;
	}
	void SessionInfo(int team1win, int i) {
		if (team1win == 2) {
			cout << "#############################" << "\nDraw" << endl;
			a.GetTeamInfo1();
			a.GetTeamInfo2();
		}
		else {
			cout << "\n\n\n\n#############################" << "\nGame session " << i + 1 << ": " << "\nWinner team: " << endl;
			if (team1win == 1) a.GetTeamInfo1();
			else a.GetTeamInfo2();

			cout << "#############################" << "\nLoser team: " << endl;
			if (team1win == 0) a.GetTeamInfo1();
			else a.GetTeamInfo2();
		}
	}
	void SessionWinner(int win1) {
		sessionwinner = win1;
	}
	int SessionWin() {
		return sessionwinner;
	}

};


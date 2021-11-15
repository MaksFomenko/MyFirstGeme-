#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class ClassPlayer
{
private:
	string name;
	string rank;
	int id = 0, points = 0;

public:
	void  SetPlayerName(string name) {
		this->name = name;
	}
	int SetPlayerID(int id) {
		this->id = id;
	}
	int GetPlayerID() {
		return id;
	}
	void Createplayer() {
		cout << "Creating new player..." << endl;
		cout << "##############################" << endl << "Your name is: ";
		cin >> name;
		cout << "##############################" << endl;
	}
	void ShowPlayerInfo() {
		cout << "__________________________" << endl << "\nName: " << name << "\nRank: " << rank << "\nPoints: " << points << endl << "__________________________" << endl << endl;
	}
	bool GetPlayerName(string name) {
		if (this->name == name) {
			bool NameMatch = true;
			return NameMatch;
		}
		else if (this->id != id) { return 0; }
	}
	bool GetPlayerID(int id) {
		if (this->id == id) {
			bool IDmatch = true;
			return IDmatch;
		}
		else if (this->id != id) { return 0; }
	}
	void RankWin() {
		points = points + 25;
	}
	void RankLose() {
		points = points - 25;
	}
	void SetPoints(int rank) {
		this->points = rank;
	}
	void SetRank(string rank) {
		this->rank = rank;
	}
	int Points() {
		return points;
	}
};


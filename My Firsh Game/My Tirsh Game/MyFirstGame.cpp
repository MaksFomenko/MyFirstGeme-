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

int main() {

        srand(time(NULL));
        ClassPlayer p[10];
        ClassHero h[10];
        TeamManager a;
        PlayerHero ph[10];
        Session s[5];
        GameManager mngr;
        string bot1, bot2, bot3, bot4, bot5, bot6, bot7, bot8, bot9, bot10;
        int ses = 0;

        bot1 = "BOT Freddie";
        bot2 = "BOT Tom";
        bot3 = "BOT Frank";
        bot4 = "BOT Oliver";
        bot5 = "BOT Harry";
        bot6 = "BOT Jack";
        bot7 = "BOT Jacob";
        bot8 = "BOT Thomas";
        bot9 = "BOT Charlie";
        bot10 = "BOT William";

        p[0].SetPlayerName(bot1);
        p[1].SetPlayerName(bot2);
        p[2].SetPlayerName(bot3);
        p[3].SetPlayerName(bot4);
        p[4].SetPlayerName(bot5);
        p[5].SetPlayerName(bot6);
        p[6].SetPlayerName(bot7);
        p[7].SetPlayerName(bot8);
        p[8].SetPlayerName(bot9);
        p[9].SetPlayerName(bot10);

        h[0].SetCreateHero(75, 100, "Archi-Magician");
        h[1].SetCreateHero(100, 30, "Warrior");
        h[2].SetCreateHero(110, 50, "Spearman");
        h[3].SetCreateHero(70, 15, "Weapon carrier");
        h[4].SetCreateHero(50, 70, "Sagittarius");
        h[5].SetCreateHero(50, 80, "Mage");
        h[6].SetCreateHero(40, 90, "Necromancer");
        h[7].SetCreateHero(180, 70, "Berserker");
        h[8].SetCreateHero(120, 90, "Swordsman");
        h[9].SetCreateHero(80, 30, "Thief");

        for (int i = 0; i < 10; i++) {
            p[i].SetPoints(0);
        }

    start:;
        for (int i = 0; i < 10; i++) {
            int sw;
            cout << "##############################\n" << "Do you wish to add player?\n1.Yes\n2.No\n" << "##############################" << endl;
            cin >> sw;
            switch (sw) {
            case 1:
                p[i].Createplayer();
                break;
            case 2:
                goto aftercreating;
                break;
            default:
                cout << "Invalid number. Skipping..." << endl;
            }
        }
    aftercreating:;

        //Starting session;
        int st = mngr.PerformGameSession();
        if (st == 1) cout << "Initialising game session..." << endl;
        else if (st == 2) {
            cout << "Player creation is restarted" << endl;
            goto start;
        }
        else if (st != 2 && st != 1)cout << "Invalid option. Game session will be started anyway" << endl;

    sessionbegin:;

        const int k = 10;
        int m[k];
        bool alreadyId;
        for (int i = 0; i < k; i++)
        {
        a: m[i] = 1 + rand() % k;
            for (int j = 0; j < i; j++)
                if (m[j] == m[i]) goto a;
        }

        int v[k];

        for (int i = 0; i < k; i++)
        {
        b: v[i] = 1 + rand() % k;
            for (int j = 0; j < i; j++)
                if (v[j] == v[i]) goto b;
        }
        for (int i = 0; i < 10; i++) {
            p[i].SetPlayerID(m[i]);
        }
        for (int i = 0; i < 10; i++) {
            h[i].SetHeroId(v[i]);
        }
        a.GenerateTeams();
        a.TeamOne();
        a.TeamTwo();
        int win1;
        win1 = a.CalculateWinner();

        if (win1 == 1) {
            for (int i = 0; i < 10; i++) {
                if (p[i].GetPlayerID() == 1)	p[i].RankWin();
                if (p[i].GetPlayerID() == 2)	p[i].RankWin();
                if (p[i].GetPlayerID() == 3)	p[i].RankWin();
                if (p[i].GetPlayerID() == 4)	p[i].RankWin();
                if (p[i].GetPlayerID() == 5)	p[i].RankWin();
                if (p[i].GetPlayerID() == 6)	p[i].RankLose();
                if (p[i].GetPlayerID() == 7)	p[i].RankLose();
                if (p[i].GetPlayerID() == 8)	p[i].RankLose();
                if (p[i].GetPlayerID() == 9)	p[i].RankLose();
                if (p[i].GetPlayerID() == 10)   p[i].RankLose();
            }
        }
        else if (win1 == 0) {
            for (int i = 0; i < 10; i++) {
                if (p[i].GetPlayerID() == 10)p[i].RankWin();
                if (p[i].GetPlayerID() == 9)	p[i].RankWin();
                if (p[i].GetPlayerID() == 8)	p[i].RankWin();
                if (p[i].GetPlayerID() == 7)	p[i].RankWin();
                if (p[i].GetPlayerID() == 6)	p[i].RankWin();
                if (p[i].GetPlayerID() == 5)	p[i].RankLose();
                if (p[i].GetPlayerID() == 4)	p[i].RankLose();
                if (p[i].GetPlayerID() == 3)	p[i].RankLose();
                if (p[i].GetPlayerID() == 2)	p[i].RankLose();
                if (p[i].GetPlayerID() == 1)	p[i].RankLose();
            }
        }
        s[ses].GetTeamManager(a);
        s[ses].SessionWinner(win1);
        mngr.GetSession(s[ses], ses);
        mngr.GetSessionWin(win1, ses);

        if (ses < 4) {
            ses++;
            goto sessionbegin;
        }
        mngr.SessionsList();

        for (int i = 0; i < 10; i++) {
            if (p[i].Points() == 1000)
                p[i].SetRank("The global elite");
            if (p[i].Points() == 125)
                p[i].SetRank("Supreme master first class");
            if (p[i].Points() == 100)
                p[i].SetRank("Legendary eagle master");
            if (p[i].Points() == 75)
                p[i].SetRank("Legendary eagle");
            if (p[i].Points() == 50)
                p[i].SetRank("Distinguished master guardian");
            if (p[i].Points() == 25)
                p[i].SetRank("Master Guardian Elite");
            if (p[i].Points() == 0)
                p[i].SetRank("Master Guardian ");
            if (p[i].Points() == -25)
                p[i].SetRank("Gold Nova Master");
            if (p[i].Points() == -50)
                p[i].SetRank("Gold Nova ");
            if (p[i].Points() == -75)
                p[i].SetRank("Silver III");
            if (p[i].Points() == -100)
                p[i].SetRank("Silver II");
            if (p[i].Points() == -125)
                p[i].SetRank("Silver I");
        }
        cout << "\n\n\n" << "Final results" << endl;
        for (int i = 0; i < 10; i++) {
            p[i].ShowPlayerInfo();
        }
    }

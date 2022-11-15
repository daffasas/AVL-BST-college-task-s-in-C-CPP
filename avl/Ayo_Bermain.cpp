#include <bits/stdc++.h>
using namespace std;

int main()
{
    string seek;
    string playah1, playah2, playah3, playah4;
    //nama2 pemain

    vector<string> loser; //sifat

    vector<int> temp, playah1_move, playah2_move, playah3_move, playah4_move;
    
    int steps, player_move, area_next, seeker, rest;
    int playah1_stats = 1, playah2_stats = 1, playah3_stats = 1, playah4_stats = 1;

    cin >> playah1 >> playah2 >> playah3 >> playah4 >> steps >> seek; //masuk

    if (playah1 == seek)
        seeker = 1;

    else if (playah2 == seek)
        seeker = 2;

    else if (playah3 == seek)
        seeker = 3;

    else
        seeker = 4;

    for (int i = 0; i < steps; i++)
    {
        cin >> player_move >> area_next;
        if (player_move == seeker)
            temp.push_back(area_next);

        else
        {
            if (player_move == 1)
                playah1_move.push_back(area_next);

            else if (player_move == 2)
                playah2_move.push_back(area_next);

            else if (player_move == 3)
                playah3_move.push_back(area_next);

            else
                playah4_move.push_back(area_next);
        }
    }

    for (unsigned long long i = 0; i < temp.size(); i++)
    {
        if (playah1_stats && seeker != 1 && i < playah1_move.size() && temp.at(i) == playah1_move.at(i))
            playah1_stats = 0;

        else if (playah2_stats && seeker != 2 && i < playah2_move.size() && temp.at(i) == playah2_move.at(i))
            playah2_stats = 0;

        else if (playah3_stats && seeker != 3 && i < playah3_move.size() && temp.at(i) == playah3_move.at(i))
            playah3_stats = 0;

        else if (playah4_stats && seeker != 4 && i < playah4_move.size() && temp.at(i) == playah4_move.at(i))
            playah4_stats = 0;
    }

    if (seeker != 4 && !playah4_stats)
        loser.push_back(playah4);

    if (seeker != 3 && !playah3_stats)
        loser.push_back(playah3);

    if (seeker != 2 && !playah2_stats)
        loser.push_back(playah2);

    if (seeker != 1 && !playah1_stats)
        loser.push_back(playah1);

    if (loser.empty())
        cout << seek << " jaga lagi";
    
    else if (!loser.empty())
    {
        rest = loser.size();
        for (int i = 0; i < rest; i++)
        {
            cout << loser.back();
            if (i == rest - 2)
                cout << ", dan ";

            else if (i == rest - 1)
                cout << " ditangkap oleh " << seek;

            else
                cout << ", ";

            loser.pop_back();
        }
    }
}

#include <iostream>
#include <fstream>
#include <algorithm>

#define MAXN 100

using namespace std;

bool check_win(string sign1, string sign2)
{
    if(sign1 == sign2)
        return false;
    if(sign1 == "Rock")
    {
        if(sign2 == "Paper")
            return false;
        return true;
    }
    if(sign1 == "Paper")
    {
        if(sign2 == "Scissors")
            return false;
        return true;
    }
    if(sign1 == "Scissors")
    {
        if(sign2 == "Rock")
            return false;
        return true;
    }
}

int main()

{
    ifstream fin("hps.in");
    ofstream fout("hps.out");
    int games, moves_1[MAXN], moves_2[MAXN], wins = 0;
    string moves[3] = {"Rock", "Paper", "Scissors"};
    fin >> games;
    for(int i = 0; i < games; i++)
        fin >> moves_1[i] >> moves_2[i];
    do
    {
        int temp = 0;
        for(int i = 0; i < games; i++)
        {
            if(check_win(moves[moves_1[i] - 1], moves[moves_2[i] - 1]))
                temp++;
        }
        wins = max(temp, wins);
    }while(next_permutation(moves, moves+3));
    fout << wins << endl;
}

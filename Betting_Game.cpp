// Betting Game implemented in C++

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
using namespace std;

int money = 100;

void PlayGame(int bet)
{
    char C[5] = {'J','Q','K','A'};
    cout << "Shuffling..." << endl;
    srand(time(NULL));

    for(int i=0 ; i<10 ; i++)
    {
        int x = rand() % 4;
        int y = rand() % 4;
        int temp = C[x];
        C[x] = C[y];
        C[y] = temp;
    }

    int playersGuess;
    cout << "What is the position of ACE ? : 1 , 2 , 3 or 4? ";
    cin >> playersGuess;

    if(playersGuess == 0 || playersGuess > 4)
    {
        cout << "Invalid Choice" << endl;
        return;
    }

    if(C[playersGuess-1] == 'A')
    {
        money = money + 3*bet;
        cout << "CONGRATULATIONS! You Win! Result = " << C[0] << " " << C[1] << " " << C[2] << " " << C[3] << "\n\nTotal amount = Rs" << money << endl;
    }

    else
    {
        money = money - bet;
        cout << "SORRY ! You Loose! Result = " << C[0] << " " << C[1] << " " << C[2] << " " << C[3] << "\n\nTotal amount = Rs" << money << endl;
    }
}

void Instructions()
{
    cout << "Instructions!" << endl << endl;
    cout << "1.There are 4 cards : Jack Queen King ACE" << endl;
    cout << "2.Computer Shuffles these cards randomly." << endl;
    cout << "3.Player has to Guess the position of ACE." << endl;
    cout << "4.If the player guesses right , he wins 3*bet amount." << endl;
    cout << "5.If the player guesses wrong , he simply looses the bet amount." << endl;
    cout << "6.Player has Rs100 initially." << endl;
    cout << "_______________________________________________________________________________" << endl << endl;
}

int main()
{
    int bet;
    cout << "\t\t\t***** BETTING GAME *****" << endl << endl;
    Instructions();
    cout << "Total amount = Rs" << money << endl;

    while(money > 0)
    {
        cout << "\nHow much money you want to bet? Rs" ;
        cin >> bet;
        if(bet == 0)
        {
            cout << "You have to bet some money." << endl;
            break;
        }
        if(bet > money)
        {
            cout << "You do not have enough money." << endl;
            break;
        }
        PlayGame(bet);
        cout << "\n_________________________________________________" << endl;
    }
    return 0;
}


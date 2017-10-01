// A 2 player Tic Tac Toe Game implemented in C++
// player 1 (X) VS player 2 (O)

#include<iostream>
#include<cstdlib>
using namespace std;

char Grid[10]= {'0','1','2','3','4','5','6','7','8','9'};
char player = 'X';

void DrawBoard()
{
    system("cls");
    cout << " Tic Tac Toe " << endl << endl << endl;
    cout << "     |   |   " << endl;
	cout << "   " << Grid[1] << " | " << Grid[2] << " | " << Grid[3] << endl;

	cout << "  ___|___|___" << endl;
	cout << "     |   |    " << endl;

	cout << "   " << Grid[4] << " | " << Grid[5] << " | " << Grid[6] << endl;

	cout << "  ___|___|___" << endl;
	cout << "     |   |    " << endl;

	cout << "   " << Grid[7] << " | " << Grid[8] << " | " << Grid[9] << endl;

	cout << "     |   |   " << endl << endl;
}

void InputMove()
{
    int mov;
    cout << "\nIts " << player <<"'s" << " turn." << endl << "\nEnter your move : ";
    cin >> mov;

    if(mov==1)
    {
        if(Grid[1]=='1')
            Grid[1] = player;
        else
        {
            cout << "\nAlready filled. Choose another Grid!" << endl;
            InputMove();
        }
    }
    if(mov==2)
    {
        if(Grid[2]=='2')
            Grid[2] = player;
        else
        {
            cout << "\nAlready filled. Choose another Grid!" << endl;
            InputMove();
        }
    }
    if(mov==3)
    {
        if(Grid[3]=='3')
            Grid[3] = player;
        else
        {
            cout << "\nAlready filled. Choose another Grid!" << endl;
            InputMove();
        }
    }
    if(mov==4)
    {
        if(Grid[4]=='4')
            Grid[4] = player;
        else
        {
            cout << "\nAlready filled. Choose another Grid!" << endl;
            InputMove();
        }
    }
    if(mov==5)
    {
        if(Grid[5]=='5')
            Grid[5] = player;
        else
        {
            cout << "\nAlready filled. Choose another Grid!" << endl;
            InputMove();
        }
    }
    if(mov==6)
    {
        if(Grid[6]=='6')
            Grid[6] = player;
        else
        {
            cout << "\nAlready filled. Choose another Grid!" << endl;
            InputMove();
        }
    }
    if(mov==7)
    {
        if(Grid[7]=='7')
            Grid[7] = player;
        else
        {
            cout << "\nAlready filled. Choose another Grid!" << endl;
            InputMove();
        }
    }
    if(mov==8)
    {
        if(Grid[8]=='8')
            Grid[8] = player;
        else
        {
            cout << "\nAlready filled. Choose another Grid!" << endl;
            InputMove();
        }
    }
    if(mov==9)
    {
        if(Grid[9]=='9')
            Grid[9] = player;
        else
        {
            cout << "\nAlready filled. Choose another Grid!" << endl;
            InputMove();
        }
    }
    if(mov<=0 || mov>9)
    {
        cout << "\nInvalid Move. Try again!" << endl;
            InputMove();
    }
}

void ChangePlayer()
{
    if(player == 'X')
        player = 'O';
    else
        player = 'X';
}

char WinORDraw()
{
    // For player X
    if(Grid[1] == 'X' && Grid[2] == 'X' && Grid[3] == 'X')
        return('X');
    if(Grid[4] == 'X' && Grid[5] == 'X' && Grid[6] == 'X')
        return('X');
    if(Grid[7] == 'X' && Grid[8] == 'X' && Grid[9] == 'X')
        return('X');

    if(Grid[1] == 'X' && Grid[4] == 'X' && Grid[7] == 'X')
        return('X');
    if(Grid[2] == 'X' && Grid[5] == 'X' && Grid[8] == 'X')
        return('X');
    if(Grid[3] == 'X' && Grid[6] == 'X' && Grid[9] == 'X')
        return('X');

    if(Grid[1] == 'X' && Grid[5] == 'X' && Grid[9] == 'X')
        return('X');
    if(Grid[3] == 'X' && Grid[5] == 'X' && Grid[7] == 'X')
        return('X');

    // For player O
	if(Grid[1] == 'O' && Grid[2] == 'O' && Grid[3] == 'O')
        return('O');
    if(Grid[4] == 'O' && Grid[5] == 'O' && Grid[6] == 'O')
        return('O');
    if(Grid[7] == 'O' && Grid[8] == 'O' && Grid[9] == 'O')
        return('O');

    if(Grid[1] == 'O' && Grid[4] == 'O' && Grid[7] == 'O')
        return('O');
    if(Grid[2] == 'O' && Grid[5] == 'O' && Grid[8] == 'O')
        return('O');
    if(Grid[3] == 'O' && Grid[6] == 'O' && Grid[9] == 'O')
        return('O');

    if(Grid[1] == 'O' && Grid[5] == 'O' && Grid[9] == 'O')
        return('O');
    if(Grid[3] == 'O' && Grid[5] == 'O' && Grid[7] == 'O')
        return('O');

    return('D'); // In case of Draw
}

int main()
{
    int Moves = 0;
    DrawBoard();
    while(1)
    {
        Moves++;
        InputMove();
        DrawBoard();
        if(WinORDraw() == 'X')
        {
            cout << "\n X wins!\n" << endl;
            break;
        }
        else if(WinORDraw() == 'O')
        {
            cout << "\n O wins!\n" << endl;
            break;
        }
        else if(WinORDraw() == 'D' && Moves == 9)
        {
            cout << "\n It's a DRAW!\n" << endl;
            break;
        }
        ChangePlayer();
    }
    return 0;
}

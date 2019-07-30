# TIC TAC TOE

def display_board(board):
    print(board[1] + ' | ' + board[2] + ' | ' + board[3])
    print('__|___|__')
    print(board[4] + ' | ' + board[5] + ' | ' + board[6])
    print('__|___|__')
    print(board[7] + ' | ' + board[8] + ' | ' + board[9])
    print('  |   |  ')


def player_chooses_X_or_Y():
    marker = ''
    while marker != 'X' and marker != 'O':
        marker = input('Player1 : Choose X or O : ').upper()
    if marker == 'X':
        return ('X','O')
    else:
        return ('O','X')


import random
def who_goes_first():
    flip = random.randint(0,1)
    if flip == 0:
        return 'player1'
    else:
        return 'player2'


def place_position(board , marker , position):
    board[position] = marker


def win_check(board , marker):
    if ((board[1] == board[2] == board[3] == marker) or
       (board[4] == board[5] == board[6] == marker) or
       (board[7] == board[8] == board[9] == marker) or 
       (board[1] == board[4] == board[7] == marker) or 
       (board[2] == board[5] == board[8] == marker) or 
       (board[3] == board[6] == board[9] == marker) or 
       (board[1] == board[5] == board[9] == marker) or 
       (board[3] == board[5] == board[7] == marker)):
        return True
    else:
        return False


def space_available(board , position):
    return board[position] == ' '


def full_board_check(board):
    for i in range(1,10):
        if space_available(board , i):
            return False
    return True


def player_choice(board):
    position = 0
    while position not in [1,2,3,4,5,6,7,8,9] or not space_available(board,position):
        position = int(input('Choose a position : (1,9) '))
    return position


def play_again():
    choice = input('Do you want to play again? Yes or No : ')
    return choice == 'Yes'


print('Welcome to TIC TAC TOE')
while True:
    the_board = [' ']*10
    player1_marker , player2_marker = player_chooses_X_or_Y()
    turn = who_goes_first()
    print(turn + ' will go first')
    play_game = input('Ready to play? y or n : ')
    if play_game == 'y':
        game_on = True
    else:
        game_on = False

    while game_on:
        if turn == 'Player1':
            display_board(the_board)
            position = player_choice(the_board)
            place_position(the_board, player1_marker , position)
            if win_check(the_board , player1_marker):
                display_board(the_board)
                print('Player1 has WON!')
                game_on = False
            else:
                if full_board_check(the_board):
                    display_board(the_board)
                    print('TIE game!')
                    game_on = False
                else:
                    turn = 'Player2'
        else:
            display_board(the_board)
            position = player_choice(the_board)
            place_position(the_board, player2_marker , position)
            if win_check(the_board , player2_marker):
                display_board(the_board)
                print('Player2 has WON!')
                game_on = False
            else:
                if full_board_check(the_board):
                    display_board(the_board)
                    print('TIE game!')
                    game_on = False
                else:
                    turn = 'Player1'
    if not play_again():
        break
        
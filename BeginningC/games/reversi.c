#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

const int SIZE = 6;
const char comper_c = '*';
const char player_c = 'o';

void display(char disboard[][SIZE]);
int valid_moves(char mainboard[][SIZE], bool playermoves[][SIZE], char player);
void make_move(char mainboard[][SIZE], int row, int col, char player);
int get_score(char mainboard[][SIZE], char player);
int best_move(char mainboard[][SIZE], bool playermoves[][SIZE], char player);
void computer_move(char mainboard[][SIZE], bool playermoves[][SIZE], char player);

int main(void)
{
    bool next_player = true;
    char again = 'y';

    do
    {
        char board[SIZE][SIZE];
        bool moves[SIZE][SIZE];
        int no_of_moves = 4;
        int invalid_moves = 0;
        next_player = !next_player;

        for (int row = 0; row < SIZE; row++)
            for (int col = 0; col < SIZE; col++)
            {
                board[row][col] = ' ';
                moves[row][col] = false;
            }

        int mid = SIZE / 2;
        board[mid - 1][mid - 1] = board[mid][mid] = player_c;
        board[mid - 1][mid] = board[mid][mid - 1] = comper_c;

        do
        {
            display(board);

            if (next_player = !next_player)
            {
                if (valid_moves(board, moves, player_c))
                {
                    invalid_moves = 0;

                    while (true)
                    {
                        int x = 0;
                        char y = 0;

                        printf("Please enter your move (row column): ");
                        y = tolower(y) - 'a';
                        x--;
                        printf("%d %d\n", x, y);

                        if (x >= 0 && y >= 0 && x < SIZE && y < SIZE && moves[x][y])
                        {
                            make_move(board, x, y, player_c);
                            no_of_moves++;
                            break;
                        }
                        else
                        {
                            int c;
                            while ((c = getchar()) != '\n' && c != EOF);
                            printf("Not a valid move, try again.\n");
                        }
                    }
                }
                else if (++invalid_moves < 2)
                {
                    printf("\nYou have to pass, press Enter\n");
                    scanf("%c", &again);
                }
                else
                {
                    printf("\nNeither of us can go, so the game is over.\n");
                }
            }
            else
            {
                if (valid_moves(board, moves, comper_c))
                {
                    invalid_moves = 0;
                    computer_move(board, moves, comper_c);
                    no_of_moves++;
                }
                else if (++invalid_moves < 2)
                {
                    printf("\nI have to pass, your go\n");
                }
                else
                {
                    printf("\nNeither of us can go, so the game is over.\n");
                }
            }
        } while (no_of_moves < SIZE * SIZE && invalid_moves < 2);

        display(board);

        int comp_score = 0, user_score = 0;

        for (int row = 0; row < SIZE; row++)
            for (int col = 0; col < SIZE; col++)
            {
                comp_score += board[row][col] == comper_c;
                user_score += board[row][col] == player_c;
            }

        printf("The final score is:\n");
        printf(" Computer %d\n User %d\n\n", comp_score, user_score);

        printf("Do you want to play again (y/n): ");
        scanf(" %c", &again);
    } while ('y' == tolower(again));

    return 0;
}

void display(char disboard[][SIZE])
{
    printf("\n  ");
    for (int col = 0; col < SIZE; col++)
        printf("   %c", 'a' + col);
    printf("\n");

    for (int row = 0; row < SIZE; row++)
    {
        printf("   +");
        for (int col = 0; col < SIZE; col++)
            printf("---+");
        printf("\n");

        printf("%2d |", row + 1);
        for (int col = 0; col < SIZE; col++)
            printf(" %c |", disboard[row][col]);
        printf("\n");
    }

    printf("   +");
    for (int col = 0; col < SIZE; col++)
        printf("---+");
    printf("\n");
}

int valid_moves(char mainboard[][SIZE], bool playermoves[][SIZE], char player)
{
    char opponent = player == player_c ? comper_c : player_c;
    int no_of_moves = 0;

    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            playermoves[row][col] = false;

            if (mainboard[row][col] != ' ')
                continue;

            for (int rowdelta = -1; rowdelta <= 1; rowdelta++)
            {
                for (int coldelta = -1; coldelta <= 1; coldelta++)
                {
                    int x = row + rowdelta, y = col+coldelta;

                    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || (x == row && y == col))
                        continue;

                    if (mainboard[x][y] == opponent)
                    {
                        while (!(x < 0 || x >= SIZE || y < 0 || y >= SIZE))
                        {
                            x += rowdelta;
                            y += coldelta;

                            if (mainboard[x][y] == ' ')
                                break;

                            if (mainboard[x][y] == player)
                            {
                                playermoves[row][col] = true;
                                no_of_moves++;
                                //mainboard[row][col] = 'X';
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    return no_of_moves;
}

void make_move(char mainboard[][SIZE], int row, int col, char player)
{
    char opponent = player == player_c ? comper_c : player_c;

    mainboard[row][col] = player;

    for (int rowdelta = -1; rowdelta <= 1; rowdelta++)
    {
        for (int coldelta = -1; coldelta <= 1; coldelta++)
        {
            int x = row + rowdelta, y = col+coldelta;

            if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || (x == row && y == col))
                continue;

            if (mainboard[x][y] == opponent)
            {
                while (true)
                {
                    x += rowdelta;
                    y += coldelta;

                    if (mainboard[x][y] == ' ')
                        break;

                    if (mainboard[x][y] == player)
                    {
                        while (mainboard[x -= rowdelta][y -= coldelta] == opponent)
                        {
                            mainboard[x][y] = player;
                        }

                        break;
                    }
                }
            }
        }
    }
}

int get_score(char mainboard[][SIZE], char player)
{
    int score = 0;
    char opponent = player == player_c ? comper_c : player_c;

    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
        {
            score -= mainboard[row][col] == opponent;
            score += mainboard[row][col] == player;
        }

    return score;
}

int best_move(char mainboard[][SIZE], bool playermoves[][SIZE], char player)
{
    char opponent = player == player_c ? comper_c : player_c;
    char new_board[SIZE][SIZE];

    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            new_board[row][col] = ' ';

    int score = 0;
    int new_score = 0;

    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
        {
            if (playermoves[row][col])
            {
                memcpy(new_board, mainboard, sizeof(new_board));
                make_move(new_board, row, col, player);
                new_score = get_score(new_board, player);

                if (score < new_score)
                    score = new_score;
            }
        }

    return score;
}

void computer_move(char mainboard[][SIZE], bool playermoves[][SIZE], char player)
{
    int best_row = 0, best_col = 0, new_score = 0, score = 100;
    char temp_board[SIZE][SIZE];
    bool temp_moves[SIZE][SIZE];
    char opponent = player == player_c ? comper_c : player_c;

    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
        {
            temp_board[row][col] = ' ';
            temp_moves[row][col] = false;
        }

    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
        {
            if (playermoves[row][col])
            {
                memcpy(temp_board, mainboard, sizeof(temp_board));
                make_move(temp_board, row, col, player);
                valid_moves(temp_board, temp_moves, opponent);
                new_score = best_move(temp_board, temp_moves, opponent);

                if (new_score < score)
                {
                    score = new_score;
                    best_row = row;
                    best_col = col;
                }
            }
        }

    make_move(mainboard, best_row, best_col, player);
}
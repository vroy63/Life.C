#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char GetPlayerMove()
{
    char move;
    printf("Enter your move (r for rock, p for paper, s for scissors): \n");
    scanf(" %c", &move);

    if (move == 'r' || move == 'p' || move == 's')
    {
        printf("Player's move: %c\n", move);
        return move;
    }

    else
    {
        printf("Invalid move. Enter your move (r for rock, p for paper, s for scissors): ");
        return GetPlayerMove();
    }
}

char GetComputerMove()
{
    char val;
    int random = rand() % 3;
    if (random == 0)
    {
        val = 'r';
    }
    else if (random == 1)
    {
        val = 'p';
    }
    else
    {
        val = 's';
    }

    printf("Bot's move: %c\n", val);
        return val;
}

void PlayRockPaperScissorsGame()
{
    char player = GetPlayerMove();
    char comp = GetComputerMove();
    if (comp == 'r')
    {
        if (player == 'r')
        {
            printf("draw!\n");
        }

        else if (player == 'p')
        {
            printf("player wins\n");
        }
        else
        {
            printf("player loses\n");
        }
    }

    else if (comp == 'p')
    {
        if (player == 'r')
        {
            printf("player loses\n");
        }
        else if (player == 'p')
        {
            printf("draw!\n");
        }
        else
        {
            printf("player wins\n");
        }
    }
    else
    {
        if (player == 'r')
        {
            printf("player wins\n");
        }

        else if (player == 'p')
        {
            printf("player loses\n");
        }

        else
        {
            printf("draw\n");
        }
    }
}

int main()
{
    char key;
    printf("Welcome to Rock, Paper, Scissors! Press 'q' to quit or any other key to continue:");
    scanf(" %c", &key);

    while (key != 'q')
    {
        PlayRockPaperScissorsGame();
        printf("Press 'q' to quit or any other key to continue: ");
        scanf(" %c", &key);
    }
    printf("bye bye");
}

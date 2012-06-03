#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

int main (void) 
{
    char another_game = 'Y';
    bool correct = true;
    int counter = 0;
    int sequence_length = 0;
    int time_taken = 0;

    printf
    (
        "\nTo play Simple Simon, watch th screen for a sequence of digits.\n"
        "Watch carefully, as the digits are only displayed for a second!\n"
        "The computer will remove themand then prompt you to enter the same sequence.\n"
        "When you do, you must put spaces between the digits.\n"
        "Good Luck!\n\n"
        "Press Enter to play"
    );
    fflush(stdout);
    fflush(stdin);
    scanf("%c", &another_game);

    do
    {
        correct = true;
        counter = 0;
        sequence_length = 2;
        time_taken = clock();

        while (correct)
        {
            sequence_length += counter++ % 3 == 0;
            time_t seed = time(NULL);

            srand((unsigned int)seed);
            for (int i = 0; i < sequence_length; i++)
                printf("%d ", rand() % 10);

            fflush(stdout);
            for (time_t now = clock(); clock() - now < CLOCKS_PER_SEC;);

            printf("\r");
            for (int i = 0; i < sequence_length; i++)
                printf("  ");

            if (counter == 1)
                printf("\nNow you enter the sequence - don't forget the spaces.\n");
            else
                printf("\r");

            fflush(stdout);
            char *number = malloc(sequence_length * sizeof(char));
            scanf("%s", number);

            srand((unsigned int)seed);
            for (int i = 0; i < sequence_length; i++)
            {
                if (*(number + i) != (char)(rand() % 10 + '0'))
                {
                    correct = false;
                    break;
                }
            }

            free(number);
            printf("%s\n", correct ? "Correct!" : "Wrong!");
        }

        time_taken = (clock() - time_taken) / CLOCKS_PER_SEC;
        printf("\n\n Your score is %d", --counter * 100 / time_taken);

        printf("\nDo you want to play again (y/n)? ");
        fflush(stdout);
        fflush(stdin);
        scanf("%c", &another_game);
    } while ('Y' == toupper(another_game));

    return 0;
}
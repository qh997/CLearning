#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFFER_LEN (256)
#define SPACE ' '

int main (void)
{
    char input[BUFFER_LEN] = {'\0'};
    float result = 0.0F;

    while (0 != strcmp(fgets(input, BUFFER_LEN, stdin), "quit\n"))
    {
        size_t input_length = strlen(input);
        input[--input_length] = '\0';

        size_t ori_input_length = input_length;
        for (int index = 0, to = 0; index <= ori_input_length; index++)
            if (SPACE != *(input + index))
                *(input + to++) = *(input + index);
            else
                input_length--;

        char *number = NULL;
        int number_dig = 1;
        char op = '+';
        for (int index = 0; index <= input_length; index++)
        {
            if (index == 0)
                if ('=' == *(input + index))
                    continue;
                else
                    result = 0.0F;

            if (isdigit(*(input + index)) || '.' == *(input + index))
            {
                if (number == NULL)
                    number = malloc(sizeof(char));

                *(number + number_dig - 1) = *(input + index);
                number_dig++;
                number = realloc(number, (number_dig + 1) * sizeof(char));
                *(number + number_dig) = '\0';
            }
            else
            {
                float current = atof(number);

                switch (op)
                {
                    case '+':
                        result += current;
                        break;

                    case '-':
                        result -= current;
                        break;

                    case '*':
                        result *= current;
                        break;

                    case '/':
                        result /= current;
                        break;

                    case '%':
                        break;

                    case '^':
                        break;

                    default:
                        break;
                }
                op = *(input + index);
                free(number);
                number = NULL;
                number_dig = 1;
            }
        }

        printf("= %.2f\n", result);
    }

    return 0;
}
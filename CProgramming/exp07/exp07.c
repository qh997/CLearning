#include <stdio.h>
#include <string.h>

int ExA;

int max (int, int);
int factorial (int);
void hanoi (int, char, char, char);
float average (float*);
void static_val (int);
void get_extern ();
float legendre (int rank, float x);
int hex_to_dec (char hex[]);

int main ()
{
    printf("---------- EXP07 ----------\n");

    printf("---------- max() ----------\n");
    printf("Max = %d\n", max(34, 60));

    printf("-------- Factorial --------\n");
    printf("%d\n", factorial(10));

    printf("---------- Hanoi ----------\n");
    hanoi(4, 'A', 'B', 'C');

    printf("--------- Average ---------\n");
    float score1[] = {98.5,67.5,94.3,69.7,59.3,87,60,55};
    printf("Average = %f\n", average(score1));

    printf("---------- static ---------\n");
    static_val(23);
    static_val(12);
    static_val(33);

    printf("---------- extern ---------\n");
    ExA = 997;
    get_extern();
    ExA += 977;
    get_extern();

    printf("--------- Legendre --------\n");
    printf("legendre = %.2f\n", legendre(3, 4));

    printf("-------- Hex to Dec -------\n");
    printf("hex_to_dec = %d\n", hex_to_dec("A0"));

    return 0;
}

int max (int a, int b)
{
    return a > b ? a : b;
}

int factorial (int number)
{
    if (number == 0)
        return 1;
    else
        return  number * factorial(number - 1);
}

void hanoi (int n, char a, char b, char c)
{
    void move (char, char);
    if (n == 1)
        move(a, c);
    else
    {
        hanoi(n-1, a, c, b);
        move(a, c);
        hanoi(n-1, b, a, c);
    }
}

void move (char x, char y)
{
    printf("%c -> %c\n", x, y);
}

float average (float score[])
{
    int quantity = sizeof(score);
    float sum = 0;
    for (int i = 0; i < quantity; i++)
    {
        sum += score[i];
    }

    return sum / quantity;
}

void static_val (int a)
{
    static int money;
    money += a;
    printf("%d\n", money);
}
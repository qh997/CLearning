#include <stdio.h>
#include <stdlib.h>

void swap (int *p1, int *p2);
void exchange (int *p1, int *p2, int *p3);
void reverse (int *head, int n);
void sort (int *head, int n);
int average (int (*pt)[4], int stnu, int clnu);
int max (int a, int b);
int min (int a, int b);
int sum (int a, int b);
int ave (int a, int b);
void play (int a, int b, int (*func)(int, int));
int getout_3 (int total);

int main (int argc, char **argv)
{
    printf("---------- EXP08 ----------\n");
    int number1 = 123;
    int *pointer1 = &number1;
    printf("&number1 = %p\n", &number1);
    printf("pointer1 = %p\n", pointer1);

    printf("---------- swap() ---------\n");
    int number2 = 321;
    printf("number1 = %d; number2 = %d\n", number1, number2);
    swap (pointer1, &number2);
    printf("number1 = %d; number2 = %d\n", number1, number2);

    printf("-------- 3 numbers --------\n");
    int num1 = 677, num2 = 43, num3 = 321;
    int *pnum1 = &num1, *pnum2 = &num2, *pnum3 = &num3;
    printf("num1 = %d; num2 = %d; num3 = %d\n", num1, num2, num3);
    exchange(pnum1, pnum2, pnum3);
    printf("num1 = %d; num2 = %d; num3 = %d\n", num1, num2, num3);

    printf("------ Array pointer ------\n");
    int joins[] = {0,1,2,3,4,5,6,7,8,9};
    int *pj = joins;
    printf("pj   = %p\n", pj);
    printf("pj+1 = %p\n", pj + 1);
    char links[] = {'0','1','2','3','4','5','6','7','8','9'};
    char *pl = links;
    printf("pl   = %p\n", pl);
    printf("pl+1 = %p\n", pl + 1);
    printf("sizeof(pj) = %ld\n", sizeof(pj));
    printf("sizeof(pl) = %ld\n", sizeof(pl));

    printf("--------- Reverse ---------\n");
    int ori_arr[] = {0,4,5,2,9,6,7,7,8,3,1,5,6,4};
    for (int i = 0; i < sizeof(ori_arr)/sizeof(ori_arr[0]); i++)
        printf("%d ", *(ori_arr + i));
    printf("\n");
    reverse(ori_arr, sizeof(ori_arr)/sizeof(*ori_arr));
    for (int i = 0; i < sizeof(ori_arr)/sizeof(ori_arr[0]); i++)
        printf("%d ", *(ori_arr + i));
    printf("\n");

    printf("----------- sort ----------\n");
    sort(ori_arr, sizeof(ori_arr)/sizeof(*ori_arr));
    for (int i = 0; i < sizeof(ori_arr)/sizeof(ori_arr[0]); i++)
        printf("%d ", *(ori_arr + i));
    printf("\n");

    printf("---------- Matrix ---------\n");
    int score[][4] = {{65,67,70,60},{80,87,90,81},{60,78,51,43}};
    printf("average = %d\n", average(score, sizeof(score)/sizeof(*score), sizeof(*score)/sizeof(**score)));

    printf("------- char string -------\n");
    char * string = "Hello world!";
    printf("%s\n", string);
    string = "foo bar!";
    printf("%s\n", string);
    printf("%s\n", string + 4);

    printf("------- string copy -------\n");
    char *new_str = (char *)malloc(sizeof(string));
    char *p_str = string, *p_new = new_str;
    while (*p_new++ = *p_str++);
    printf("new_str = %s\n", new_str);
    free(new_str);

    char *wild;
    printf("wild = %p\n", &wild);

    printf("------ function point -----\n");
    int (*averf)(int(*)[4], int, int) = average;
    printf("averf = %d\n", (* averf)(score, 3, 4));
    play(23, 78, max);
    play(23, 78, min);
    play(23, 78, sum);
    play(23, 78, ave);

    printf("------ Pointer array ------\n");
    char * names[] = {"Follow me", "BASIC", "Great Wall", "Perl"};
    for (int i = 0; i < sizeof(names) / sizeof(*names); i++)
        printf("%s\n", names[i]);
    printf("%c\n", *(*(names + 3) + 1));

    printf("------- malloc free -------\n");
    int score_c[] = {93, 79, 85, 67, 78};
    int * np = malloc(sizeof(score_c));
    for (int i = 0; i < sizeof(score_c) / sizeof(*score_c); i++)
        *(np + i) = score_c[i];
    for (int i = 0; i < sizeof(score_c) / sizeof(*score_c); i++)
    {
        if (*(np + i) < 85) printf("%d : %d\n", i, *(np + i)); 
    }

    printf("---------- void * ---------\n");
    void * void_p = malloc(10);
    printf("%ld\n", sizeof(*((int *)void_p)));
    printf("%ld\n", sizeof(*((float *)void_p)));
    printf("%ld\n", sizeof(*((short *)void_p)));
    printf("%ld\n", sizeof(*((long *)void_p)));
    printf("%ld\n", sizeof(*((long long *)void_p)));
    printf("%ld\n", sizeof(*((double *)void_p)));
    printf("%ld\n", sizeof(*((char *)void_p)));
    printf("%ld\n", sizeof(*((void **)void_p)));

    printf("--------- getout 3 --------\n");
    printf("%d\n", getout_3(40) + 1);

    return 0;
}

void exchange (int *p1, int *p2, int *p3)
{
    if (*p1 > *p2) swap(p1, p2);
    if (*p1 > *p3) swap(p1, p3);
    if (*p2 > *p3) swap(p2, p3);
}

void swap (int *p1, int *p2)
{
    int tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void reverse (int *head, int n)
{
    int *tail;
    tail = head + n - 1;
    while (tail != head && tail - head != 1)
    {
        swap(head++, tail--);
    }
}

void sort (int *head, int n)
{
    for (int i = 0; i < n; i++, head++)
    {
        int *search = head + 1;
        for (int j = i + 1; j < n; j++, search++)
            if (*search < *head) swap(search, head);
    }
}

int average (int (*pt)[4], int stnu, int clnu)
{
    int sum = 0;
    int stu = stnu;
    while (stu--)
    {
        int cla = clnu;
        int *ps = *pt++;
        while (cla--)
            sum += *ps++;
    }
    return(sum / (stnu * clnu));
}

int max (int a, int b){return(a > b ? a : b);}
int min (int a, int b){return(a < b ? a : b);}
int sum (int a, int b){return(a + b);}
int ave (int a, int b){return((a + b) / 2);}

void play (int a, int b, int (*func)(int, int))
{
    printf("This is : %d\n", (*func)(a, b));
}

int getout_3 (int total)
{
    int *circle = malloc(total * sizeof(int));
    int counter = 0, outer = 0, result = 0;
    for (int i = 0; i < total; i++) circle[i] = 0;
    while (outer < total)
    {
        for (int i = 0; i < total; i++)
        {
            if (*(circle + i))
            {
                printf("-- ");
                continue;
            }
            if (++counter == 3)
            {
                *(circle + i) = 1;
                result = i;
                outer++;
                counter = 0;
                printf("!- ");
            }
            else
            {
                printf("%2d ", i);
            }
        }

        printf("\n");
    }

    return result;
}
#include <stdio.h>

#define DEBUG
#define ARRAY_LENGTH (13)

#ifdef DEBUG
#define show_var(fmt, var) printf("%s = "fmt"\n", #var, var)
#else
#define show_var(fmt, var)
#endif

void print_array(int *p, int n);
void quick_sort(int v[], int left, int right);
void swap(int v[], int i, int j);

int main(void)
{
    int array[ARRAY_LENGTH] = {17,24,4,29,18,7,19,27,6,7,51,43,2};

    print_array(array, ARRAY_LENGTH);
    printf("start:\n");
    quick_sort(array, 0, ARRAY_LENGTH);
    printf("finish:\n");
    print_array(array, ARRAY_LENGTH);
}

void print_array(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %2d ", i);
    }
    printf("\n");
    while (0 <= --n)
    {
        printf("[%2d]", *(p++));
    }
    printf("\n");
}

void quick_sort(int v[], int left, int right)
{
    printf("\nv[] %d -> %d\n", left, right);
    int i, last;

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if (v[i] < v[left])
        {
            printf("v[%d] < v[%d]\n", i, left);
            swap(v, ++last, i);
            for (int ij = 0; ij < ARRAY_LENGTH; ij++)
                if (last == ij)
                    printf(" *  ");
                else
                    printf("    ");
            printf("\n");
        }
        else
        {
            printf("v[%d] >= v[%d]\n", i, left);
        }
    }
    swap(v, left, last);
    quick_sort(v, left, last - 1);
    quick_sort(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
    printf("%d <=> %d\n", i, j);
    print_array(v, ARRAY_LENGTH);
}
#include <stdio.h>

#define show_var(fmt, var) printf("%s = "fmt"\n", #var, var)

typedef struct Point
{
    int x;
    int y;
} point;

typedef struct Rectangle
{
    point pt1;
    point pt2;
} rectangle;

point makepoint(int x, int y);
void paiting(rectangle rect);

int main(void)
{
    rectangle rect1;
    rect1.pt1 = makepoint(12, -7);
    rect1.pt2 = makepoint(-5, 15);
    paiting(rect1);

    return 0;
}

point makepoint(int x, int y)
{
    point temp;
    temp.x = x;
    temp.y = y;

    return temp;
}

void paiting(rectangle rect)
{
    int x_max = rect.pt1.x > rect.pt2.x ? rect.pt1.x : rect.pt2.x;
    int x_min = rect.pt1.x < rect.pt2.x ? rect.pt1.x : rect.pt2.x;
    int y_max = rect.pt1.y > rect.pt2.y ? rect.pt1.y : rect.pt2.y;
    int y_min = rect.pt1.y < rect.pt2.y ? rect.pt1.y : rect.pt2.y;
    int lx_max = x_max;
    int lx_min = x_min;
    int ly_max = y_max;
    int ly_min = y_min;

    if (lx_max * lx_min > 0)
    {
        if (lx_max < 0)
            lx_max = 0;
        else
            lx_min = 0;
    }
    if (ly_max * ly_min > 0)
    {
        if (ly_max < 0)
            ly_max = 0;
        else
            ly_min = 0;
    }

    for (int lx = lx_min - 1; lx <= lx_max + 1; lx++)
        printf("%c", lx == 0 ? '^' : ' ');

    printf("\n");

    for (int ly = ly_max + 1; ly >= ly_min - 1; ly--)
    {
        for (int lx = lx_min - 1; lx <= lx_max + 1; lx++)
        {
            printf
            (
                "%c", 
                lx == 0 && ly == 0 ? '+' :
                lx == 0 ? '|' :
                ly == 0 ? '-' :
                lx <  x_min || lx  > x_max ? ' ' :
                ly <  y_min || ly  > y_max ? ' ' :
                lx == x_min || lx == x_max ? '*' :
                ly == y_min || ly == y_max ? '*' : ' '
            );
        }
        printf(ly == 0 ? "->\n" : "\n");
    }
}
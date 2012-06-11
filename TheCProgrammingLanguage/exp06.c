#include "expxx.h"

typedef struct Point
{
    int x;
    int y;
} point;

typedef struct Rect
{
    point pt1;
    point pt2;
} rect;

void draw_rect(rect r);

int main(void)
{
    print_title("exp06");

    print_title("Rectangle");
    {
        rect rect1;
        rect1.pt1.x = 0;
        rect1.pt1.y = 3;
        rect1.pt2.x = 8;
        rect1.pt2.y = 2;
        draw_rect(rect1);
    }

    return 0;
}

void draw_rect(rect r)
{
    int maxx = r.pt1.x > r.pt2.x ? r.pt1.x : r.pt2.x;
    int minx = r.pt1.x < r.pt2.x ? r.pt1.x : r.pt2.x;
    int maxy = r.pt1.y > r.pt2.y ? r.pt1.y : r.pt2.y;
    int miny = r.pt1.y < r.pt2.y ? r.pt1.y : r.pt2.y;

    show_var("%d", maxx);
    show_var("%d", minx);
    show_var("%d", maxy);
    show_var("%d", miny);
}
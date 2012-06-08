#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#define TITLE_WIDTH (65)
#define TITLE_LINE '-'

#define show_var(fmt, var) printf("%s = "fmt"\n", #var, var)

void print_title(char *title);
long htoi(char *string);
char *squeeze(char *str_ori, char *str_del);
unsigned int setbits(unsigned x, int p, int n, unsigned int y);
unsigned int invert(unsigned int x, int p, int n);
unsigned int rightrot(unsigned int x, int n);

int main(void)
{
    print_title("exp02");

    print_title("hex to dex");
    {
        show_var("%ld", htoi("0xFFFF"));
        show_var("%ld", htoi("0X2aFe"));
    }

    print_title("squeeze");
    {
        char str[] = "acdbcdefcddcg";
        show_var("%s", squeeze(str, "cde"));
    }

    print_title("setbits invert");
    {
        show_var("%X", setbits(0x34A7, 5, 4, 0xB8));
        show_var("%X", invert(0x34A76E, 9, 4));
        show_var("%X", rightrot(0xFE, 99));
    }

    print_title("x &= (x - 1)");
    {
        unsigned x = 0x88;
        show_var("%X", x &= (x - 1));
    }

    return 0;
}

void print_title(char *title)
{
    if (strlen(title) >= TITLE_WIDTH)
    {
        printf("%s\n", title);
        return;
    }

    int side = (TITLE_WIDTH - strlen(title)), fill = 0;
    fill = side % 2 == 0 ? 0 : 1;
    side /= 2; side -= 1;

    char *title_string = malloc((TITLE_WIDTH + 1) * sizeof(char));
    char *p = title_string;

    for (int i = 0; i < side; i++)
        *(p++) = TITLE_LINE;
    *(p++) = ' ';
    for (int i = 0; i < strlen(title); i++)
        *(p++) = *(title + i);
    *(p++) = ' ';
    for (int i = 0; i < side + fill; i++)
        *(p++) = TITLE_LINE;
    *p = '\0';

    printf("%s\n", title_string);

    free(title_string);
}

long htoi(char *string)
{
    long result = 0;

    if (strstr(string, "0X") || strstr(string, "0x"))
    {
        string += 2;
    }

    char c;
    while ('\0' != (c = *string++))
    {
        assert(isxdigit(c));

        result *= 16;
        if (isdigit(c))
        {
            result += c - '0';
        }
        else
        {
            result += toupper(c) - 'A' + 10;
        }
    }

    return result;
}

char *squeeze(char *str_ori, char *str_del)
{
    char *pstro = str_ori, *pstrol = str_ori;
    show_var("%p", pstro);
    while ('\0' != *pstrol)
    {
        show_var("%c", *pstrol);
        int delfalg = 0;
        for (int i = 0; '\0' != *(str_del + i); i++, delfalg++)
        {
            show_var("%c", *(str_del + i));
            if (*(pstrol + i) != *(str_del + i))
            {
                delfalg = 0;
                break;
            }
        }
        show_var("%c", *(pstrol + delfalg));
        show_var("%c", *pstrol);
        *pstro = *(pstrol + delfalg);
        pstrol += delfalg;
        pstro++;
        pstrol++;
    }
    *pstro = '\0';

    return str_ori;
}

unsigned int setbits(unsigned x, int p, int n, unsigned int y)
{
    unsigned int xmask = ~((~(~0 << n)) << (p - 1));
    unsigned int ymask = (~(~0 << n) & y) << (p - 1);
    show_var("%X", xmask);
    show_var("%X", ymask);

    return x & xmask | ymask;
}

unsigned int invert(unsigned int x, int p, int n)
{
    show_var("%X", x);
    unsigned int x1 = ~(((x >> (p - 1)) | (~0 << n))) << (p - 1);
    show_var("%X", x1);
    x = x & ~(~(~0 << n) << (p - 1));
    show_var("%X", x);

    return x | x1;
}

unsigned int rightrot(unsigned int x, int n)
{
    show_var("%X", x);
    unsigned int mask = 0x80000000;
    unsigned int eax = x;
    show_var("%X", mask);
    for (int i = 0; i < n; i++)
    {
        if (1 == (x & 1))
        {
            x = (x >> 1) | mask;
        }
        else
        {
            x = (x >> 1) & ~mask;
        }
    }

    show_var("%X", eax);
    eax = (eax >> n) + (eax << (8 * sizeof(eax) - n));
    show_var("%X", eax);

    return x;
}
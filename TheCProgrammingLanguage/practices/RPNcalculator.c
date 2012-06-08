#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP (100)
#define NUMBER '0'

#define show_var(fmt, var) printf("%s = "fmt"\n", #var, var)

void push(double f);
double pop(void);
int getop(char s[]);
int getch(void);
void ungetch(int c);

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while (EOF != (type = getop(s)))
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() * pop());
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknow command %s\n", s);
                break;
        }
    }

    return 0;
}

#define MAXVAL (100)

double val[MAXVAL];
int sp = 0;

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g.\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0;
    }
}

int getop(char s[])
{
    int i, c;

    while (' ' == (s[0] = c = getch()) || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if ('.' == c)
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (EOF != c)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE (100)

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters.\n");
    else
        buf[bufp++] = c;
}
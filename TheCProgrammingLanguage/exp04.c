#include "expxx.h"

int strrindex(char *s, char *t);
double iatof(char *s);

int main(void)
{
    print_title("exp04");

    print_title("strrindex");
    {
        show_var("%d", strrindex("helxlxo worlxd", "lx"));
        show_var("%d", strrindex("helxlxo worlxd", "xlxlx"));
    }

    print_title("atof");
    {
        show_var("%.3lf", iatof("997.83"));
        show_var("%.3lf", iatof("99783"));
        show_var("%.3lf", iatof("-99.783"));
        show_var("%.3lf", iatof("9.97e2"));
        show_var("%.3lf", iatof("997e-2"));
    }

    return 0;
}

int strrindex(char *s, char *t)
{
    int index = -1;
    for (int i = 0; '\0' != *(s + i); i++)
    {
        bool match = false;
        for (int j = i, k = 0; '\0' != *(t + k); j++, k++)
        {
            match = false;
            if (*(t + k) != *(s + j))
                break;
            else
                match = true;
        }

        index = match ? i : index;
    }

    return index;
}

double iatof(char *s)
{
    double result = 0.0;
    bool sign = false;
    long int power = 0;
    bool exise = false;
    bool signe = false;
    int powere = 0;

    for (;'\0' != *s; s++)
    {
        if (isspace(*s))
            continue;

        if (result == 0 && ('-' == *s || '+' == *s))
        {
            sign = '-' == *s ? true : sign;
            continue;
        }
        else if (exise && ('-' == *s || '+' == *s))
        {
            signe = '-' == *s ? true : signe;
            continue;
        }

        if (isdigit(*s))
        {
            if (!exise)
            {
                result = 10 * result + *s - '0';
                power = power == 0 ? 0 : 10 * power;
            }
            else
            {
                powere = 10 * powere + *s - '0';
            }
        }

        if ('.' == *s)
            power = 1;
        else if ('e' == tolower(*s))
            exise = true;
    }

    power = power == 0 ? 1 : power;
    while (0 != powere--)
    {
        if (signe)
            power *= 10;
        else
            power /= 10;
    }

    result /= power ? power : 1;
    result *= sign ? -1 : 1;

    return result;
}
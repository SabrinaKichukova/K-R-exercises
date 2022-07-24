
#include <stdio.h>
#include <ctype.h>

int atoi(char* s);
int atoi2(char* s);


int main()
{
    
    printf("%d", atoi2("-123"));
    printf("%d", atoi("595"));
    
    return 0;
}


/* atoi chapter 2: convert s to integer */

int atoi(char* s)
{
    int n = 0;

    while(*s >= '0' && *s <= '9'){
        n = 10 * n + (*s - '0');
        s++;
    }
    return n;
}

 
// atoi: convert s to integer; version 2 
int atoi2(char *s)
{
    int i, n, sign;
    for (; isspace(*s); s++);
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    return sign * n;
}

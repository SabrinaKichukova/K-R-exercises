
int getop(char s[]);
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#define MAXOP   100
#define NUMBER  '0'

int getop(char []);


int main()
{
    char s[MAXOP];

    if (getop(s) == NUMBER) {
        printf("Yes");
    } else {
        printf("No");
    }
               
    return 0;
}

int getch(void);
void ungetch(int);


int getop(char *s)
{
    int c;
    
    while ((*s = c = getch()) == ' ' || c == '\t');

    *++s = '\0';
        if (!isdigit(c) && c != '.')
        return c;                           /* not a number */

    if (isdigit(c))
                                            /* collect integer part */
    while (isdigit(*++s = c = getch()));
    if (c == '.')
                                            /* collect fraction part */
    while (isdigit(*++s = c = getch()));
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

    char buf[BUFSIZE];
    int bufp = 0;

int getch(void) 
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){

    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
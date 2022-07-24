
#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

int getLine(char *, int);
void copy(char *, char *);


int main()
{
    
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > max) {
        max = len;
        copy(longest, line);
        }
    if (max > 0)
    printf("%s", longest);
    
    return 0;
}

/* getline chapter 4: pointer version */
// getline: read a line into s, return length

int getLine(char* s,int lim)
{
    char c;
    char *i = s;

    for (; --lim!=0 && (c=getchar())!=EOF && c != '\n'; ++s)
        *s = c;
    if (c == '\n') {
        *s = c;
    }
    *s = '\0';
    return i - s;
}

void copy(char *to, char *from)
{
    while ((*to = *from) != '\0')
    to++;
    from++;
}

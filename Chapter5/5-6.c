
#include <stdio.h>
ls

/* getline: pointer version */
// getline: read a line into s, return length

int getLine(char* s,int lim)
{
char *c;
int i;

for (i=0; i < lim-1 && (*c=getchar())!=EOF && *c != '\n'; ++i,++s)
*s = *c;
if (*c == '\n') {
*s = *c;
++i;
}
*s = '\0';
return i;
}
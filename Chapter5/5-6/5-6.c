
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1000

int getLine(char *, int);
void copy(char *, char *);
//int atoi(char* s);
//int atoi2(char* s);
void reverse(char *s);
void itoa(int n, char *s);

int main()
{
    /*
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
    */

   //printf("%d", atoi2("-123"));
    char str[] = "895-";
    reverse(str);
    printf("%s", str);

   int n = -598;
   char a[5]= "-155";

   itoa(n,a);

  printf("%s", a);

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
/* 

/* atoi chapter 2: convert s to integer */
/*
int atoi(char* s)
{
    int n = 0;

    while(*s >= '0' && *s <= '9'){
        n = 10 * n + (*s - '0');
        s++;
    }
    return n;
}
*/
/* 
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
*/
void itoa(int n, char *s)
{
	int sign;

	sign = n; /* record sign */

	do {    /* generate digits in reverse order */
		*s++ = (n % 10 + '0'); /* get the next digit */
	} while ((n /= 10) > 0); /* delete it */
	if (sign < 0)
		*s++ = '-';
	*s = '\0';
	reverse(s - strlen(s));
}

/* itoa: convert n to characters in s */
/*  void itoa(int n, char *s)
{
    int sign;
    if ((sign = n) < 0)         
        n = -n;                 
    do {                     
        *s = n % 10 + '0';
        s++;    
    } while ((n /= 10) > 0);
    if (sign < 0)
        *s++ = '-';
    *s++ = '\0';
    reverse(s);
}
*/

/* reverse: reverse string s in place */
/*void reverse(char *s)
{
    char c;
    char* j;
    j = s;
    while(*j != '\0'){
        j++;
    }
    for (; s < j; ++s, --j) {
        c = *j;
        *j = *s;
        *s = c;
    }
}*/
void reverse(char *s)
{
	char *p, *q, tmp;

	q = s + strlen(s) - 1;
	for (p = s; p < q; ++p, --q) {
		tmp = *p;
		*p = *q;
		*q = tmp;
	}
}
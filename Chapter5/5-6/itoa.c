
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *s);
void itoa(int n, char *s);

int main()
{
   /*
    char str[] = "5482";
    reverse(str);
    printf("%s", str);
    */
   
    int n = -2845;
    char a[1000]= "";
    itoa(n,a);
    printf("%s\n", a);      
    reverse(a);
    printf("%s\n", a);
    return 0;
}


/* reverse: reverse string s in place */
void reverse(char *s)
{
   char c;
   char *j,*i;
   j = s + strlen(s)-1;
    for (i = s; i < j; i++, j--) {
        c = *i;
        *i = *j;
        *j = c;
    }
}
/* itoa: convert n to characters in s */
void itoa(int n, char *s)
{
    int sign;
    if ((sign = n) < 0)         
        n = -n;                 
    do {                     
        *s++ = n % 10 + '0';

    } while ((n /= 10) > 0);
    if (sign < 0){
        *s++ = '-';
    }
    *s++ = '\0';
    reverse(s-(strlen(s)));
}
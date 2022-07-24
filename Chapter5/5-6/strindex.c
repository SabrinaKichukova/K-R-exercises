#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int strindex(char *s, char *t);

int main(int argc, char const *argv[])
{
    char str[] = "Outside it's 36 degree.";
    char str1[] = "side";
    printf("%d", strindex(str,str1));
    return 0;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t)
{
    char *k, *j;
    
    int ind = 0;

    while(*s != '\0'){

        if (*s == *t){
            k = s;
            j = t;

            while(*k++ == *j++){
                if (*j == '\0'){
                    return ind;
                }
            }
        }
        s++;
        ind++;
    }
    return -1;
}
    
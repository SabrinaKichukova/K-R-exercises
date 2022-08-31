#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFSIZE 100
#define MAXLEN 10

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
float getFloat(float *pn);

int main(){

    float num[MAXLEN];
    float* pn;
    pn = num;

	for(int i = 0; i < MAXLEN; i++){
        int c = getFloat(pn);
        printf("c = %d\n", c);
        pn++;
    }
        
    return 0;
}

float getFloat(float *pn){

    int c;
    int sign;

    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c); 
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    
    if (c == '+' || c == '-'){
        if(!isdigit(c = getch())){
            ungetch(c); 
            return 0;
        }
    }
    if (c == '.'){
        if(!isdigit(c = getch())){
            ungetch(c); 
            return 0;
        }
    }
    
    for (*pn = 0; isdigit(c) || c == '.'; c = getch()){
        *pn = 10 * *pn + (c - '0');
    }   
        *pn *= sign;

    if (c != EOF)
        ungetch(c);
    return c;
}
int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c){

    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
    buf[bufp++] = c;
}
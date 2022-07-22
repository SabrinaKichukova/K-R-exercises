#include <stdio.h>


void strncatt(char *s, char *t, size_t n);
int strncmpp(char *s, char *t,size_t n);
void *strncpyy(char *s, char* t,size_t n);


int main(int argc, char const *argv[])
{ 
// test strncat

char dest[] = "String";
char src[] = "concat";   
strncatt(dest,src,4);
printf("%s\n",dest);

// test strncmp

if(strncmpp("cmp", "cmpr", 2) >= 0){
    printf("s = t\n");
} else {
    printf("s != t\n");
}

// test strncpy

char s[] = "";
char c[] = "start";
strncpyy(s, c, 3);

printf("%s",s);

return 0;
}


//concatenate at most concatenate at most n characters of string s to string t 
void strncatt(char *t, char *s, size_t n)
{
while(*t){
    t++;
} /* find end of dest */

for (size_t i = 0; i < n;i++){
    *t = *s;
    t++;
    s++;
}
*t = '\0';
}


// compare at most n characters of string s to string t ; return <0 if s<t , 0 if s==t , or >0 if s>t .

int strncmpp(char *t, char *s, size_t n)
{
char *tend = t+n;
for (int i = 0; i < n; i++){
    if (*t == *s){
    s++;
    t++;
    }
}
if (t == tend) {
    return 0;  
} else{
    return -1;
}
}


//copy at most n characters of string c to s ; return s . Pad with '\0' if it has fewer than n characters.

void *strncpyy(char* s,char* c,size_t n){

    for(size_t i = 0; i < n; i++){
        
        if(*c == '\0'){
        *s = '\0';
        break;

        } else {
        *s = *c;
        s++;
        c++;
        }
        *s = '\0';
       
    } 
}
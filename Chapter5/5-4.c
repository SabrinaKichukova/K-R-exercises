/* Write the function strend(s,t) , which returns 1 if the string t occurs at the
end of the string s , and zero otherwise. */


#include <stdio.h>

int srend(char *s, char *t);

int main(int argc, char const *argv[])
{   
    if(srend("Overed","red")) {

            printf(" yes\n");
        } else {
             printf(" no\n");
        }

    if(srend("Overed","eed")) {

            printf(" yes\n");
        } else {
             printf (" no\n");
        } 
    return 0;
}

int srend(char *s, char *t){


    char* sstart = s;
    char* tstart  = t;
   

    while(*s){
        s++;
    }
    while (*t){
        t++;
    }

    while( tstart != t){
        t--;
        s--;
    }
    
    while(*t){

        if(*t == *s){
        tstart++;
        }
        t++;
        s++;
    }
    if (*tstart == '\0'){
        return 1;
    } else {
        return 0;
    }

}
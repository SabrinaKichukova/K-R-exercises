#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAXOP   100
#define NUMBER  '0'
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

int getop(char []);
void push(double);
double pop(void);


int main(int argc, char const *argv[]){
    
    int type;
    double num;
    double op2;
    int argCount = 1;
        
        while (argCount < argc) {
            
            argv++;

            if ((num = atof(*argv))){
                type = NUMBER;
            }
            else {
                type = **argv;
            }
        
            switch (type) {
                case NUMBER:
                    push(num);
                    break;
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else
                        printf("error: zero divisor\n");
                        break;
                default:
                    printf("error: unknown command argument: %d\n", argCount);
                break;    
            }
                argCount++;
        }
    printf(" %.1f\n", pop());
    return 0;
}

void push(double f){
    
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
    }
    
double pop(void){

    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
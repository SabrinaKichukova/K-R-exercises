#include <stdio.h>

int main(int argc, char const *argv[])
{
    int val = 6;
    int* pval = NULL;

    pval = &val;
      
    printf(" Address to val is %p \n", &val);
    printf(" Address to pval is %p \n", &pval);
    printf(" Value of pval is %p \n", pval);
    printf(" Value of what pval is pointing to is %d \n", *pval);


    return 0;
}

#include <stdio.h>

int countingString( const char *);

int main(int argc, char const *argv[])
{
    const char str[] = "Test";

    printf(" Number of chars in string are %d.\n", countingString(str));
    printf(" Number of chars in string are %d.\n", countingString("string test"));
    printf(" Number of chars in string are %d.\n", countingString(""));
    return 0;
}

int countingString(const char *string){

    const char *strEnd = string;

    while(*strEnd){
        strEnd++;
    }
    return strEnd - string;

}

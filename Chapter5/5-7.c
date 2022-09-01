#include <stdio.h>
#include <string.h>

#define MAXLINES 100   /* max #lines to be sorted */
#define MAXLEN 1000     /* max length of any input line */
#define SIZE 100 /* size of available space */

char *lineptr[MAXLINES];

int getLine(char *s, int lim);
int readlines(char *lineptr[], int maxlines, char ArrLines[]);
void writelines(char *lineptr[], int nlines);
void qsort(char *v[], int left, int right);
void swap(char* v[], int i, int j);

int main(){

    int nlines;
    char ArrLines[SIZE];

    if ((nlines = readlines(lineptr, MAXLINES, ArrLines)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int getLine(char *s, int lim){
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
  	s[i] = '\0';
  	return i;
}

int readlines(char *lineptr[], int maxlines, char ArrLines[]){
    
    int len, nlines;
    char *p, line[MAXLEN];
    p = ArrLines;
    nlines = 0;

    while ((len = getLine(line, MAXLEN)) > 0 )
    
    if (nlines >= maxlines || len > SIZE)
        return -1;
    else {
        line[len-1] = '\0';    
        strcpy(p, line);
        lineptr[nlines++] = p;

    }
    return nlines;
}

void writelines(char *lineptr[], int nlines){
    
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

void qsort(char *v[], int left, int right){

    int i, last;

    void swap(char *v[], int i, int j);

    if (left >= right)
        return;

    swap(v, left, (left + right)/2);
    last = left;

    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
        swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char* v[], int i, int j)
{
    char* temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


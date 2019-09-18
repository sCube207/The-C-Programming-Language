#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXLINES 5000
#define BUFSIZE 10000
#define LINES 10

char *line[MAXLINES];
int readlines(char *lineptr[], char *buf, int nlines);
void printlines(char *lien[], int nlines, int n);


int main(int argc, const char * argv[]) {
      int n, nlines;
      char buf[BUFSIZE];
      if (argc > 2 && argc == 1) {
            printf("error: wrong parametr\n");
            n = LINES;
      }
      else
            n = abs(atoi(argv[1]));
      
      if ((nlines = readlines(line, buf, MAXLINES)) >= 0) {
            system("clear");
            printlines(line, nlines, n);
            return 0;
      }
      else {
            printf("error: input too big to sort\n");
            return 1;
      }
            
            
      return 0;
}

#define MAXLEN 1000

int getLine(char *, int);

int readlines(char *lineptr[], char *buf, int maxlines) {
      int len, nlines = 0;
      char *p = buf, line[MAXLEN];
      char *stop = buf + BUFSIZE;
      
      
      while((len = getLine(line, MAXLEN)) > 0)
            if (nlines >= maxlines || p+len > stop)
                  return -1;
            else {
                  line[len-1] = '\0';
                  strcpy(p, line);
                  lineptr[nlines++] = p;
                  p += len;
            }
      return nlines;
}

void printlines(char *line[], int nlines, int n) {
      int i = 0;
      int quans;
      
      if (n < nlines) {
            line += (nlines-n);
            quans = n;
      }
      else
            quans = nlines;
      
      
      for (i = 0; i < quans ; i++)
            printf("%s\n", *line++);
      
}

int getLine(char *line, int len) {
      int i = 0;
      char c;
      
      for (i = 0; (c=getchar()) != EOF &&c != '\n' && i < len-1; i++)
            *line++ = c;
      if (c == '\n') {
            *line = '\0';
            i++;
      }
      return i;
}



















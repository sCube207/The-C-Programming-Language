#include <stdio.h>
#include <stdlib.h>

#define TAB 4
#define MAXLINE 1000

void getLine(char *s, int lim);
void detab(char *from,char *to, int n);
void entab(char *from,char *to, int n);

int main(int argc, const char * argv[]) {
      int ntab = 0;
      char inputLine[MAXLINE];
      char entabLine[MAXLINE];
      char detabLine[MAXLINE];
      system("clear");
      if (argc != 2) {
            printf("error: wrong argument\n");
            ntab = TAB;
      }
      else
            ntab = atoi(argv[1]);
      
      getLine(inputLine, MAXLINE);
      detab(inputLine, entabLine, ntab);
      entab(inputLine, detabLine, ntab);
      printf("Detabed:\n%s\nEntabed:\n%s\n", entabLine,  detabLine);
      return 0;
}

void getLine(char *s, int lim) {
      char c;
      int i = 0;
      for (i = 0; i < lim-1 && (c=getchar()) != EOF; s++ , i++)
            *s = c;
      *s++ = '\0';
 }

void detab(char *from, char *to, int n) {
      int i = 0;
      while (*from != '\0') {
            if (*from == '\t') {
                  *from++;
                  for (i = 0; i < n; i++)
                        *to++ = ' ';
            }
            else
                  *to++ = *from++;
      }
            
}

void entab(char *from, char *to, int n) {
      int nspaces = 0;
      while (*from != '\0') {
            *to++ = *from;
            if (*from++ == ' ') {
                  nspaces++;
                  if (nspaces%n == 0) {
                        to -= n;
                        *to++ = '\t';
                        nspaces = 0;
                  }
            }
      }
}







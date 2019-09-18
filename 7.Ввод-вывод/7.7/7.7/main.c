#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000
#define MAXNAME 30

int getLine(char *, int);

int main(int argc, char *argv[]) {
      char line[MAXLINE];
      long lineo = 0;
      int c, except = 0, number = 0, found = 0;
      char pattern[MAXNAME], filename[MAXNAME];
      FILE *fp;
      
      while (--argc >0 && (*argv)[0] == '-')
            while (c == *++argv[0])
                  switch(c) {
                        case 'x':
                              except = 1;
                              break;
                        case 'n':
                              number = 1;
                              break;
                        default:
                              fprintf(stderr, "find: illegal option %c\n", c);
                              argc = 0;
                              break;
                  }
      if (argc < 1) {
            fprintf(stderr, "Usage: find -x -n pattern\n");
            exit(1);
      }
      else
            strcpy(pattern, *argv);
      if (argc == 1)
            finput(pattern);
      else
            while (--argc != 0) {
                  strcpy(filename, *++argv);
                  fp = fopen(filename, "r");
                  lineo = 0;
                  while (fgets(line, MAXLINE, fp) != NULL) {
                        lineo++;
                        if (strstr(pattern, line) != NULL) {
                              if (number == 1)
                                    printf("%ld ", lineo);
                              printf("%s/n",line);
                        }
                  }
            }
}

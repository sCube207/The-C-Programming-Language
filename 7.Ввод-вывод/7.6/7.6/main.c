#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

int main(int argc, char *argv[]) {
      FILE *fp1, *fp2;
      void filecompare(FILE *, FILE *);
      char *prog = argv[0];
      
      if (argc != 3 )
            fprintf(stderr, "wrong parametrs");
      else {
            if ((fp1 = fopen(argv[1], "r")) == NULL) {
                  fprintf(stderr, "%s: can't open file\n", argv[1]);
                  exit(1);
            }
            else if ((fp2 = fopen(argv[2], "r")) == NULL) {
                  fprintf(stderr, "%s: can't open file\n", argv[2]);
                  exit(1);
            }
            else
                  filecompare(fp1, fp2);
      }
      
      if (ferror(stdout)) {
            fprintf(stderr, "%s: error writing stdout\n", prog);
            exit (2);
      }
      exit (0);
}

void filecompare(FILE *fp1, FILE *fp2) {
      char fLine[MAXLINE], sLine[MAXLINE];
      
      while (fgets(fLine, MAXLINE, fp1) != NULL && fgets(sLine, MAXLINE, fp2) != NULL) {
            if (strcmp(fLine, sLine) != 0) {
                  printf("Different strigs:\n%s\n%s\n", fLine, sLine);
                  break;
            }
      }
}

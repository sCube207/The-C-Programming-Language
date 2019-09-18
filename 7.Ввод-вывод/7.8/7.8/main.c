#include <stdio.h>
#include <string.h>

#define MAXNAME 30

int writeFile(char *, int);

int main(int argc, const char * argv[]) {
      char fileName[MAXNAME];
      int pageCount = 1;
      
      if (argc < 2)
            fprintf(stderr, "error: can't fini files names\n");
      else
            while (--argc != 0) {
                  strcpy(fileName, *++argv);
                  if (writeFile(fileName, pageCount) != 1)
                        pageCount++;
            }
      return 0;
}

int writeFile(char *fName, int pageNum) {
      FILE *fp = fopen(fName, "r");
      char c;
      
      if (fp == NULL) {
            fprintf(stderr, "error: can't open file %s\n", fName);
            fclose(fp);
            return 1;
      }
      else {
            fprintf(stdout,"------------------------------------\n");
            fprintf(stdout,"\nFile name: %s\n", fName);
            fprintf(stdout,"------------------------------------\n");
            
            while ((c=getc(fp)) != EOF)
                  putc(c, stdout);
            fprintf(stdout,"------------------------------------\n");
            fprintf(stdout,"\nPage num: %d\n", pageNum);
            fclose(fp);
            return 0;
      }
}

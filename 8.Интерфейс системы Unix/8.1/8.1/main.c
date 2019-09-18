#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
      FILE *fp;
      int fd;
      void filecopy(FILE *, FILE *);
      char *prog = argv[0];
      
      if (argc == 1)
            filecopy(stdin, stdout);
      else
            while (--argc > 0)
                  if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
                        fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                        exit (1);
                  } else {
                        filecopy(fp, stdout);
                        close(fd);
                  }
      if (ferror(stdout)) {
            fprintf(stderr, "%s: error writing stdout\n", prog);
            exit (2);
      }
      exit (0);
}

void filecopy(FILE *ifp, FILE *ofp) {
      int c;
      
      while ((c = getc(ifp)) != EOF)
            putc(c, ofp);
}


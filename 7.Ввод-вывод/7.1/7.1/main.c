#include <stdio.h>
#include <string.h>
#include <ctype.h>

void lower(void);
void upper(void);

int main(int argc, const char * argv[]) {
      if (argc < 2)
            printf("Error: wrong parametrs\n");
      else {
            if (strcmp(argv[1], "upper") == 0)
                  upper();
            else if (strcmp(argv[0], "lower") == 0)
                  lower();
            else
                  printf("Error: unknown params/n");
      }
      return 0;
}
//upper: conver symbols from lower to upper
void upper(void) {
      char c;
      
      while ((c=getchar()) != EOF) {
            putchar(toupper(c));
      }
}

//lower: convert symbols from upper to lower
void lower(void) {
      char c;
      
      while ((c=getchar()) != EOF) {
            putchar(tolower(c));
      }
}

#include <stdio.h>

#define MAX 1000

int MyGetline(char *s, int n);

char s[MAX];
int i;

int main(int argc, const char * argv[]) {
      printf("%d\n", MyGetline(s, MAX));
      return 0;
}

int MyGetline(char *s, int lim){
      int c, i;
      for(i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
            *s++ = c;
      if(c == '\n')
            *s++ = 'n';
      *s = '\0';
      return i;
}

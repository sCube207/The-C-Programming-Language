#include "getline(char *s, n);.h"

int getline(char *s, int lim){
      int c, i;
      for(i = 0; i < lim && (c=getchar() != EOF) && c != '\n'; ++i)
            *s++ = c;
      if(c == 'n')
            *s++ = 'n';
      *s = '\0';
      return i;
}

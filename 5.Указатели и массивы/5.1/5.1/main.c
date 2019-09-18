#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int getch(void);
//void ungetch(int);
int n, array[SIZE], getint(int *);

int main(int argc, const char * argv[]) {
      
      return 0;
}

int getint(int *pn){
      int c, sign, mark;
      
      while(iispace(c = getch()))
            ;
      if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
            ungetch(c);
            return 0;
      }
      sign = (c == '-') ? -1 : 1;
      if(c == '+' || c == '-'){
            mark = c;
            c = getch();
            if(c != EOF)
                  ungetch(c);
            ungetch(mark);
      }
      for(*pn = 0; isdigit(c); c = getch())
            *pn = 10 * *pn + (c - '0');
      *pn *= sign;
      if(c != EOF)
            ingetch(c);
      return 0;
}

#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int getch(void);
int n, array[SIZE], getfloat(float *);

int main(int argc, const char * argv[]) {
      
      return 0;
}

int getfloat(float *pn){
      int c, sign, mark;
      float f;
      
      while(isspace(c = getch())) //пропуск пробелов
            ;
      if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
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
      if(c == '.')
            c = getch();
      for(f = 1.0; isdigit(c); c = getch()){
            *pn = 10.0 * *pn + (c - '0');
            f *= 10.0;
      }
      *pn *= sign/f;
      
      if(c != EOF)
            ungetch(c);
      return c;
}


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char s[]);
void push(double);
double pop(void);

int main(int argc, char * argv[]) {
      int type, i = 0;
      double op2;
      int op1, op3;
      char s[MAXOP];
      char c;
      
      while (--argc > 0) {
            isdigit(argv[i]);
            i++;
            switch (type) {
                  case NUMBER:
                        push(atof(s));
                        break;
                  case '+':
                        push(pop() + pop() );
                        break;
                  case '*':
                        push(pop() * pop() );
                        break;
                  case '-':
                        op2 = pop();
                        push(pop() - op2);
                        break;
                  case '/':
                        op2 = pop();
                        if (op2 != 0.0)
                              push(pop() / op2);
                        else
                              printf("error: zero divisor\n");
                        break;
                  case '%':
                        op3 = pop();
                        op1 = pop();
                        if (op3 != 0)
                              push(op1 % op3);
                        else
                              printf("error: zero divisor\n");
                        break;
                  case '\n':
                        printf("\t%.8g\n", pop());
                        break;
                  default:
                        printf("error: unknown command %s\n", s);
                        break;
            }
      }
      printf("\t%.8g\n", pop());
      return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
      if (sp < MAXVAL)
            val[sp++] = f;
      else
            printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
      if (sp > 0)
            return val[--sp];
      else {
            printf("error: stack empty\n");
            return 0.0;
      }
}

#include <ctype.h>

int getch(void);
void ungetC(int);

int getop(char s[]) {
      int i, c;
      static int ungetch = 0;
      
      if (ungetch == 0)
            c = getch();
      else {
            c = ungetch;
            ungetch = 0;
      }
      
      while ((s[0] = c = getch()) == ' ' || c == '\t')
            ;
      s[1] = '\0';
      if (!isdigit(c) && c != '.' && c != '-')
            return c;
      
      i = 0;
      if (c == '-') {
            if(isdigit(c = getch()) || c == '.')
                  s[++i] = c;
            else
            {
                  if(c != EOF)
                        ungetch = c;
                  return '-';
            }
      }
      if (isdigit(c))
            while (isdigit(s[++i] = c = getch()))
                  ;
      if (c == '.')
            while (isdigit(s[++i] = c = getch()))
                  ;
      s[i] = '\0';
      if (c != EOF)
            ungetch = c;
      return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
char bufp = 0;

int getch(void) {
      return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetC(int c) {
      if (bufp >= BUFSIZE)
            printf("ungetch: too many characters\n");
      else
            buf[bufp++] = c;
}

























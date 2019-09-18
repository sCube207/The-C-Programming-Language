#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100

void push(double f);
double pop(void);

double val[MAXVAL];

int main(int argc, const char * argv[]) {
      char c;
      int i = 1;
      double op2;
      int op1, op3;
      argc--;
      while (isdigit(*argv[i])) {
            push(atof(argv[i]));
            i++;
            argc--;
      }
      
      while(--argc >= 0) {
            c = *argv[i];
            i++;
            switch (c) {
                  case '+':
                        push(pop() + pop() );
                        break;
                  case 'x':
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
                  default:
                        printf("error: unknown command %s\n", argv[i-1]);
                        break;
            }

      }
      printf("\t%.8g\n", pop());
      return 0;
}

int sp = 0;

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

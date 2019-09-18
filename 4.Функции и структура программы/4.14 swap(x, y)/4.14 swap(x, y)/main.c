#include <stdio.h>

#define swap(t, x, y)  {t tmp;\
tmp = y;\
y = x;\
x = tmp;}

int main(int argc, const char * argv[]) {
      int a = 3, b = 5;
      swap(int, a, b);
      printf("%d\n%d\n", a, b);
      return 0;
}

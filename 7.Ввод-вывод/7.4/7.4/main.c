#include <stdarg.h>
#include <stdio.h>

void minscanf(char *fmt, ...) {
      va_list ap;
      char *p, *sval;
      int ival;
      double dval;
      
      va_start(ap, fmt);
      for (p = fmt; *p; p++) {
            if (*p != '%') {
                  *(p)++ = getchar();
                  continue;
            }
            switch (*++p) {
                  case 'd':
                        scanf("%d",&ival);
                        break;
                  case 'f':
                        scanf("%lf", &dval);
                        break;
                  case 's':
                        scanf("%s", sval);
                              break;
                  default:
                        *p = getchar();
                        break;
            }
      }
      va_end(ap);
}

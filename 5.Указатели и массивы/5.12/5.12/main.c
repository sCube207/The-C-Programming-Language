#include <stdio.h>
#include <stdlib.h>

#define TAB 8

void entab(int m, int n);

int main(int argc, char **argv)
{
      int pos, tabinc;
      
      if(argc > 3)
      {
            printf("ERROR, wrong parameters\n");
            return 1;
      }
      if(argc <=1)
            entab(0, TAB);
      else if(argc == 3 && *(argv+1) == '-' && *(argv+2) == '+')
      {
            pos = atoi(*(argv+1));
            tabinc = atoi(*(argv+2));
            entab(pos, tabinc);
      }
      else
      {
            pos = atoi(*(argv+1));
            entab(pos, TAB);
      }
      return 0;
}

void entab(int m, int n)
{
      int c, ntab, nspace, symv;
      
      symv=1;
      ntab=0;
      nspace=0;
      m = -m;
      
      while((c=getchar()) != EOF)
      {
            if(m-- > 0)
                  putchar(c);
            else
                  symv++;
            if(c==' ')
            {
                  if(symv < (-1*m))
                        putchar(c);
                  if(symv % n == 0)
                  {
                        ntab++;
                        nspace=0;
                  }
                  else
                        nspace++;
            }
            else
            {
                  while(ntab>0)
                  {
                        putchar('\t');
                        ntab--;
                  }
                  if(c=='\t')
                  {
                        nspace=0;
                        putchar('\t');
                        symv=symv + (n- (symv % n));
                  }
                  else
                  {
                        while(nspace>0)
                        {
                              putchar(' ');
                              nspace--;
                        }
                        putchar(c);
                        if(c=='\n')
                        {
                              symv=0;
                              ntab=0;
                              nspace=0;
                        }
                  }
            }
      }
}

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define BUFSIZE 10000

char *lineptr[MAXLINES];

int myReadlines(char *lineptr[], char *buf, int nlines);
void myWritelines(char *lineptr[], int nlines);
void MyQsort(char *lineptr[], int left, int right);

int main(int argc, const char * argv[]) {
      
      int nlines;
      char buf[BUFSIZE];
      
      if ((nlines = myReadlines(lineptr, buf, MAXLINES)) >= 0) {
            MyQsort(lineptr, 0, nlines-1);
            printf("%d\n", nlines);
            myWritelines(lineptr, nlines);
            return 0;
      }
      else {
            printf("error: input too big to sort\n");
            return 1;
      }
}

#define MAXLEN 1000

int MyGetline(char *, int);

int myReadlines(char *lineptr[], char *buf, int maxlines) {
      int len, nlines = 0;
      char *p = buf, line[MAXLEN];
      char *stop = buf + BUFSIZE;
      
      
      while((len = MyGetline(line, MAXLEN)) > 0)
            if (nlines >= maxlines || p+len > stop)
                  return -1;
            else {
                  line[len-1] = '\0';
                  strcpy(p, line);
                  lineptr[nlines++] = p;
                  p += len;
            }
      return nlines;
}

void myWritelines(char *lineptr[], int nlines) {
      while (nlines-- > 0)
            printf("%s\n", *lineptr++);
}

void MyQsort(char *v[], int left, int right) {
      int i, last;
      void swap(char *v[], int i, int j);
      
      if (left >= right)
            return;
      swap(v, left, (left+right)/2);
      last = left;
      for (i = left+1; i <= right; i++)
            if (strcmp(v[i], v[left]) < 0)
                  swap(v, ++last, i);
      swap(v, left, last);
      MyQsort(v, left, last-1);
      MyQsort(v, last+1, right);
}
void swap(char *v[], int i, int j) {
      char *temp;
      
      temp = v[i];
      v[i] = v[j];
      v[j] = temp;
}

int MyGetline(char *s, int lim)
{
      int c = 0;
      char *tmp = s;
      for (; --lim > 0 && (c=getchar()) != EOF && c != '\n'; s++)
            *s = c;
      if (c=='\n')
            *s++ = c;
      *s = '\0';
      return s - tmp;
}





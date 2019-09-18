#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define BUFSIZE 10000

char *lineptr[MAXLINES];

int myReadLines(char *lineptr[], char *buf ,int nlines);
void writelines(char *lineptr[], int nlines);

void qSort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverse);
int numcmp(char *, char *);
int noRegStrcmp(char *, char *);

int main(int argc, const char * argv[]) {
      int nlines;
      int numeric = 0, reverse = 1, reg = 0;
      char buf[BUFSIZE];
      
      while (--argc >= 1) {
            if (strcmp(argv[argc], "-n") == 0)
                  numeric = 1;
            else if (strcmp(argv[argc], "-r") == 0)
                  reverse = -1;
            else if (strcmp(argv[argc], "-f") == 0)
                  reg = 1;
            
      }
      printf("Input your lines\n");
      
      if ((nlines = myReadLines(lineptr, buf, MAXLINES)) >= 0) {
            qSort((void **) lineptr, 0, nlines-1,
                  (int (*)(void*, void*))(numeric ? numcmp : (reg ? noRegStrcmp : strcmp)), reverse);
            printf("Sorted output\n");
            writelines(lineptr, nlines);
            return 0;
      }
      else {
            printf("input too big to sort\n");
            return 1;
      }
}

void qSort(void *v[], int left, int right,
           int (*comp)(void *, void *), int reverse) {
      
      int i, last;
      void swap(void *v[], int i, int j);
      
      if (left >= right)
            return;
      swap(v, left, (left+right)/2);
      last = left;
      
      for (i = left+1; i <= right; ++i)
            if (((*comp)(v[i], v[left]) * reverse) < 0)
                  swap(v, ++last, i);
      swap(v, left, last);
      qSort(v, left, last-1, comp, reverse);
      qSort(v, last+1, right, comp, reverse);
}


#include <stdlib.h>

int numcmp(char *s1, char *s2) {
      double v1, v2;
      v1 = atof(s1);
      v2 = atof(s2);
      if (v1 < v2)
            return -1;
      else if (v1 > v2)
            return 1;
      else
            return 0;
}

void swap(void *v[], int i, int j) {
      void *temp;
      
      temp = v[i];
      v[i] = v[j];
      v[j] = temp;
}

#define MAXLEN 1000

int MyGetline(char *, int);

int myReadLines(char *lineptr[], char *buf, int maxlines) {
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

void writelines(char *lineptr[], int nlines) {
      while (nlines-- > 0)
            printf("%s\n", *lineptr++);
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

#include <ctype.h>

int noRegStrcmp(char *s1, char *s2) {
      
      for(;tolower(*s1) == tolower(*s2); s1++, s2++)
            if(*s1 == '\0')
                  return 0;
      return tolower(*s1) - tolower(*s2);
}










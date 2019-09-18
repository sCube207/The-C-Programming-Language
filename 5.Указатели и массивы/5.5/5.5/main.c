#include <stdio.h>

void MyStrncpy(char *s, char *t, int n);
void MyStrncat(char *s, char *t, int n);
int MyStrncmd(char *s, char *t, int n);

int main(){
      char t[] = {"123456"};
      char s[10];
      MyStrncpy(s, t, 2);
      MyStrncat(s, t, 3);
      MyStrncmd(s, t, 3);
      printf("%s\n%d\n", s, MyStrncmd(s, t, 2));
      
}

void MyStrncpy(char *s, char *t, int n){ //копируе не более n символов из t в s
      while(n-- && *t)
            *s++ = *t++;
      while(*s)
            *s++='\0';
}

void MyStrncat(char *s, char *t, int n){
      while(*s++ != '\0')
            ;
      s--;
      while(n-- && (*s++ = *t++)!= '\0')
            ;
}

int MyStrncmd(char *s, char *t, int n){
      int i;
      for(i = 0; i < n && s[i] == t[i]; i++)
            ;
      if (i == n)
            return 0;
      else
            return s[i] - t[i];
      
}

int strend(char *s, char *t){
      char tmps = *s;
      char tmpt = *t;
      while(*s++ != '\0' )
            ;
      while(*t++ != '\0' )
            ;
      s--;
      while(*s == *t)
            if(tmps == *s || tmpt == *t){
                  break;
                  s--;
                  t--;
            }
      if(*s == *t && *t == tmpt && *s != '\0' )
            return 1;
      else
            return 0;
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define HASHSIZE 101
#define MAXWORD 100

struct nlist {
      struct nlist *next;
      char *name;
      char *defn;
};

struct nlist *lookup(char *);
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void getDefn();
int getword(char *, int);

static struct nlist *hashtab[HASHSIZE];

int main() {
      char word[MAXWORD];
      struct nlist *np;
      
      while (getword(word, MAXWORD) != EOF) {
            if (strcmp(word, "#") == 0)
                  getDefn();
      }
      return 0;
}

int getChar(void);
void ungetChar(int);
void skipSpace();

//getDefn: add name and definition to tashtab
void getDefn() {
      int c;
      int i;
      char name[MAXWORD], defn[MAXWORD], dif[MAXWORD];
      skipSpace();
      if(!isalpha(getword(dif, MAXWORD)))
            printf("Wrong parametrs. Skip this string");
      else if (strcmp(dif, "define") == 0) {
            skipSpace();
            if ((isalpha(getword(name, MAXWORD)) == 0))
                  printf("Wrong name. Skip this string.");
            else {
                  skipSpace();
                  for (i = 0; i < MAXWORD; i++) {
                        if ((defn[i] = getChar()) == EOF || defn[i] == '\n')
                            break;
                  }
                  defn[i] = '\0';
                  if (i > 0)
                        install(name, defn);
                  else
                        printf("Wrong definition. Skip this string.");
            }
      }
}
void skipSpace() {
      char c;
      while(isspace(c = getChar()))
            ;
      ungetChar(c);
}


/* getword: get next word or character from input */
int getword(char *word, int lim)
{
      int c;
      char *w = word;
      
      while(isspace(c = getChar()))
            ;
      if(c != EOF)
            *w++ = c;
      if(!isalpha(c)) {
            *w = '\0';
            return c;
      }
      for (; --lim > 0; w++)
            if (!isalnum(*w = getChar())) {
                  ungetChar(*w);
                  break;
            }
      *w = '\0';
      return word[0];
}


#define BUFSIZE 100

char buf[BUFSIZE];          //buffer for ungetch;
int bufp = 0;               //next free position in buf

int getChar(void) {
      return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetChar(int c) {
      if(bufp >= BUFSIZE)
            printf("ungetch: too many characnters\n");
      else
            buf[bufp++] = c;
}

//hash: form a index
unsigned hash(char *s) {
      unsigned hashval;
      
      for (hashval = 0; *s != '\0'; s++)
            hashval = *s + 31 * hashval;
      return hashval % HASHSIZE;
}

//lookup: find a element s in table hashtab[]
struct nlist *lookup(char *s) {
      struct nlist *np;
      
      for (np = hashtab[hash(s)]; np != NULL; np = np->next)
            if (strcmp(s, np->name) == 0)
                  return np;
      return NULL;
}

struct nlist *lookup(char *);

//install: upload name and definition to hashtab
struct nlist *install(char *name, char *defn) {
      struct nlist *np;
      unsigned hasval;
      
      if ((np = lookup(name)) == NULL) {
            np = (struct nlist *) malloc(sizeof(*np));
            if (np == NULL || (np->name = strdup(name)) == NULL)
                  return NULL;
            hasval = hash(name);
            np->next = hashtab[hasval];
            hashtab[hasval] = np;
      }
      else
            free((void *) np->defn);
      if ((np->defn = strdup(defn)) == NULL)
            return NULL;
      return np;
}

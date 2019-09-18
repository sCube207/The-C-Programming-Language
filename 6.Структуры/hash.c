#include <string.h>

struct nlist() {
      struct nlist *next;
      char *name;
      char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

//hash: form a index
unsigned hash(char *s) {
      unsigned hasval;
      
      for (hashval = 0; *s != '\0'; s++)
            hasval = *s + 31 * hasval;
      return hasval % HASHSIZE;
}

//lookup: find a element s in table hashtab[]
struct nlist *lookup(char *s) {
      struct nlist *np;
      
      for (np = hastab[hash(s)]; np != NULL; np = np->next)
            if (strcmp(s, np->name) == 0)
                  return np;
      return NULL;
}

struct nlist *lookup(char *);
char *strdup(char *);

//install: upload name and definition to hashtab
struct nlist *install(char *name, char *defn) {
      struct nlist *np;
      unsigned hasval;
      
      if ((np = lookup(name)) == NULL) {
            np = (struct nlist *) malloc(sizeof(*np));
            if (np == NULL || (np->name = strdup(name)) == NULL)
                  return NULL;
            hasval = hash(name);
            np->next = hastab[hasval];
            hastab[hasval] = np;
      }
      else
            free((void *) np->defn);
      if ((np->defn = strdup(defn)) == NULL)
            return NULL;
      return np;
}

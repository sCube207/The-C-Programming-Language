#include <string.h>

struct nlist {
      struct nlist *next;
      char *name;
      char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

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
            np->next = hashtab[hasval];
            hashtab[hasval] = np;
      }
      else
            free((void *) np->defn);
      if ((np->defn = strdup(defn)) == NULL)
            return NULL;
      return np;
}

//undef: remove name and definition from hashtab
void undef(char *s) {
      struct nlist *prev, np;
      int h;
      
      h = hash(s);
      for (np = hashtab[h]; np != NULL; np->next) {
            if (strcmp(s, np->name) == 0)
                  break;
            prev = np;
      }
      if (np != NULL) {
            if (prev == NULL)
                  hashtab[h] = np->next;
            else
                  prev->next = np->next;
            free((void *) np->name);
            free((void *) np->defn);
            free((void *) np);
      }
}

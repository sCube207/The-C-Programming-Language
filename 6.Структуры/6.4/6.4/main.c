#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode {
      char *word;
      int count;
      struct tnode *left;
      struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
struct tnode *addSortedTree(struct tnode *, char *, int);
void treeprint(struct tnode *);
void saveTree(struct tnode *, struct tnode **);
int getword(char *, int);

int main() {
      struct tnode *root, *sortedRoot;
      char word[MAXWORD];
      
      root = NULL;
      sortedRoot = NULL;
      while (getword(word, MAXWORD) != EOF)
            if (isalpha(word[0]))
                  root = addtree(root, word);
      saveTree(root, &sortedRoot);
      treeprint(sortedRoot);
      return 0;
}

struct tnode *talloc(void);
char *strDup(char *);

// addtree: добавление узла со словом w в дерево
struct tnode *addtree(struct tnode *p, char *w) {
      int cond;
      if (p == NULL) {
            p = talloc();
            p->word = strDup(w);
            p->count = 1;
            p->left = p->right = NULL;
      }
      else if ((cond=strcmp(w, p->word)) == 0)
            p->count++;
      else if (cond < 0)
            p->left = addtree(p->left, w);
      else
            p->right = addtree(p->right, w);
      return p;
}

//saveTree: rewrite tree to the sorted tree
void saveTree(struct tnode *from, struct tnode **to) {
      if (from != NULL) {
            saveTree(from->right, &(*to));
            *to = addSortedTree(*to, from->word, from->count);
            saveTree(from->left, &(*to));
      }
}
//addSortedTree: add new node to the tree sorted by count
struct tnode *addSortedTree(struct tnode *p, char *w, int count) {
      if (p == NULL) {
            p = talloc();
            p->word = strDup(w);
            p->count = count;
            p->left = p->right = NULL;
      }
      else if (count <= p->count)
            p->left = addSortedTree(p->left, w, count);
      else
            p->right = addSortedTree(p->right, w, count);
      return p;
}
//treeprint: вывод дерева в консоль
void treeprint(struct tnode *p) {
      if (p != NULL) {
            treeprint(p->right);
            printf("%4d %s\n", p->count, p->word);
            treeprint(p->left);
      }
}

#include <stdlib.h>

struct tnode *talloc(void) {
      return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strDup(char *s) {
      char *p;
      
      p = (char *) malloc(strlen(s) + 1);
      if (p != NULL)
            strcpy(p, s);
      return p;
}



/* getword: get next word or character from input */
int getword(char *word, int lim)
{
      int c, getChar(void);
      void ungetChar(int);
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


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
      char *word;
      int count;
      int collision;
      struct tnode *left;
      struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *, int find, int num);
void treeprint(struct tnode *);
int getword(char *, int);

int main(int argc, char *argv[]) {
      struct tnode *root;
      char word[MAXWORD];
      int comp = 0;
      
      if (argc == 1 || atoi(argv[1]) == 0) {
            printf("Wrong input. 6 sumbols will be compared\n");
            comp = 6;
      }
      else {
            comp = atoi(argv[1]);
            printf("Correct input. %d sumbols will be compared.\n", comp);
      }
      
      root = NULL;
      
      while (getword(word, MAXWORD) != EOF)
            if (isalpha(word[0]))
                  root = addtree(root, word, 0, comp);
      treeprint(root);
      return 0;
}

struct tnode *talloc(void);
char *strDup(char *);

// addtree: добавление узла со словом w в дерево
struct tnode *addtree(struct tnode *p, char *w, int find, int num) {
      int cond;
      int comp;
      if (p == NULL) {
            p = talloc();
            p->word = strDup(w);
            p->count = 1;
            p->collision = find;
            p->left = p->right = NULL;
      }
      else if ((cond=strcmp(w, p->word)) == 0)
            p->count++;
      
      else if (cond < 0) {
            if (strncmp(p->word, w, num) == 0) {
                  p->collision = 1;
                  find = 1;
            }
            p->left = addtree(p->left, w, find, num);
      }
      else {
            if (strncmp(p->word, w, num) == 0) {
                  p->collision = 1;
                  find = 1;
            }
            p->right = addtree(p->right, w, find, num);
      }
      return p;
}

//treeprint: вывод дерева в консоль
void treeprint(struct tnode *p) {
      if (p != NULL) {
            treeprint(p->left);
            if (p->collision == 1) printf("%s\n", p->word);
            treeprint(p->right);
      }
}
// talloc: create a new node of tree
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



// getword: get next word or character from input
int getword(char *word, int lim) {
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

//getChar: put char to the buffer
int getChar(void) {
      return (bufp > 0) ? buf[--bufp] : getchar();
}
//ungetChar: return the last char from the buffer
void ungetChar(int c) {
      if(bufp >= BUFSIZE)
            printf("ungetch: too many characnters\n");
      else
            buf[bufp++] = c;
}

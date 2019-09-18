#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
struct lineList {
      int num;
      struct lineList *next;
};


struct tnode {
      char *word;
      struct lineList *list;
      struct tnode *left;
      struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int);
void addLineNum(struct lineList **, int);
void printList(struct lineList *);
int iscommon(char *);

int main() {
      struct tnode *root;
      char word[MAXWORD];
      int lineNum = 1;
      
      root = NULL;
      while (getword(word, MAXWORD) != EOF) {
            if (isalpha(word[0]) && iscommon(word) == 0)
                  root = addtree(root, word, lineNum);
            else if (word[0] == '\n')
                  lineNum++;
      }
      treeprint(root);
      return 0;
}

int iscommon(char *w) {
      char *word[] = {"a", "an", "are", "in", "is", "of","or", "that", "the", "this", "to"};
      int cond, mid;
      int low = 0;
      int high = sizeof(word)/sizeof(char *) - 1;
      
      while(low <= high)
      {
            mid = (low + high)/2;
            if((cond = strcmp(w, word[mid])) < 0)
                  high = mid -1;
            else if(cond > 0)
                  low = mid + 1;
            else
                  return 1;
      }
      return 0;
}

struct tnode *talloc(void);
char *strDup(char *);

// addtree: добавление узла со словом w в дерево
struct tnode *addtree(struct tnode *p, char *w, int line) {
      int cond;
      if (p == NULL) {
            p = talloc();
            p->list = NULL;
            addLineNum(&(p->list), line);
            p->word = strDup(w);
            p->left = p->right = NULL;
      }
      else if ((cond = strcmp(w, p->word)) == 0)
            addLineNum(&(p->list), line);
      else if (cond < 0)
            p->left = addtree(p->left, w, line);
      else
            p->right = addtree(p->right, w, line);
      return p;
}

//treeprint: вывод дерева в консоль
void treeprint(struct tnode *p) {
      if (p != NULL) {
            treeprint(p->left);
            printf("%s\n",p->word);
            printList(p->list);
            treeprint(p->right);
      }
}


void printList(struct lineList *p) {
      while (p) {
            printf("%d ", p->num);
            p = p->next;
      }
      printf("\n");
}

#include <stdlib.h>

struct lineList *getLast(struct lineList *);


//addLineNum: add new node to list
void addLineNum(struct lineList **p, int line) {
      struct lineList *tmp = (struct lineList *) malloc(sizeof(struct lineList));
      if ((*p) == NULL || (*p)->num != line) {
            tmp->num = line;
            tmp->next = *p;
            (*p) = tmp;
      }
}

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
      
      while(isspace(c = getChar()) && c != '\n')
            ;
      
      if(c != EOF)
            *w++ = c;
      if(!isalpha(c) || c == '\n') {
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


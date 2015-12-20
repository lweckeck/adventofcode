#include<stdio.h>
#include<stdlib.h>

typedef struct Set {
  int x;
  int y;
  struct Set* left;
  struct Set* right;
} Set;

int cmp(int x1, int y1, int x2, int y2) {
  int d = x1 - x2;
  if (d==0) {
    d = y1 - y2;
  }
  return d;
}

Set* init_set(int x, int y) {
  Set* s = (Set*) malloc(sizeof(Set));
  s->x = x;
  s->y = y;
  s->left = NULL;
  s->right = NULL;
  return s;
}

void insert(Set* s, int x, int y) {
  int d = cmp(s->x, s->y, x, y);
  if (d < 0) {
    if (s->left == NULL) {
      s->left = (Set*) malloc(sizeof(Set));
      s->left->x = x;
      s->left->y = y;
    } else {
      insert(s->left, x, y);
    }
  } else if (d > 0) {
    if (s->right == NULL) {
      s->right = (Set*) malloc(sizeof(Set));
      s->right->x = x;
      s->right->y = y;
    } else {
      insert(s->right, x, y);
    }
  }
  return;
}

int size(Set* s) {
  int x = 1;
  if (s->left != NULL) {
    x += size(s->left);
  }
  if (s->right != NULL) {
    x += size(s->right);
  }
  return x;
}

int dx(char c) {
  if (c == '<') {
    return -1;
  } else if (c == '>') {
    return 1;
  } else {
    return 0;
  }
}

int dy(char c) {
  if (c == 'v') {
    return -1;
  } else if (c == '^') {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char** argv){
  FILE* f = fopen(argv[1], "r");

  char c;
  int i=0;
  int sx=0, sy=0;
  int rx=0, ry=0;
  Set* s = init_set(sx, sy);
  while((c = fgetc(f)) != EOF) {
    if (i%2 == 0) {
      sx += dx(c);
      sy += dy(c);
      insert(s, sx, sy);
    } else {
      rx += dx(c);
      ry += dy(c);
      insert(s, rx, ry);
    }
    i++;
  }
  printf("%d\n", size(s));
}

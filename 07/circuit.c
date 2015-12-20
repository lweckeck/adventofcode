#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Gate {
  char* out;
  char* op;
  char* in1;
  char* in2;
  short const_in;
} Gate;

typedef struct Tree {
  Gate* gate;
  struct Tree* left;
  struct Tree* right;
} Tree;

Tree* init_tree(Gate* gate) {
  Tree* t = (Tree*) malloc(sizeof(Tree));
  t->gate = gate;
  t->left = NULL;
  t->right = NULL;
}

void insert_tree(Tree* t, Gate* g) {
  Tree* new = (Tree*) malloc(sizeof(Tree));
  new->gate = g;
  new->left = NULL;
  new->right = NULL;
  if (strcmp(t->gate->out, g->out) < 0) {
    if (t->left == NULL) {
      t->left = new;
    } else {
      insert_tree(t->left, g);
    }
  } else {
    if (t->right == NULL) {
      t->right = new;
    } else {
      insert_tree(t->right, g);
    }
  }
}

Gate* get_from_tree(Tree* t, char* out) {
  int c = strcmp(t->gate->out, out);
  if (c==0) {
    return t->gate;
  } else if (c < 0) {
    return get_from_tree(t->left, out);
  } else {
    return get_from_tree(t->right, out);
  }
}

Tree* circuit;

short eval(Gate* g) {
  if (strcmp(g->op, "NONE") == 0) {
    return eval(get_from_tree(circuit, g->in1));
  } else if (strcmp(g->op, "CONST") == 0) {
    return g->const_in;
  } else if (strcmp(g->op, "OR") == 0) {
    short in1 = eval(get_from_tree(circuit, g->in1));
    short in2 = eval(get_from_tree(circuit, g->in2));
    return in1 | in2;
  } else if (strcmp(g->op, "AND") == 0) {
    short in1 = eval(get_from_tree(circuit, g->in1));
    short in2 = eval(get_from_tree(circuit, g->in2));
    return in1 & in2;
  } else if (strcmp(g->op, "NOT") == 0) {
    short in1 = eval(get_from_tree(circuit, g->in1));
    return ~in1;
  } else if (strcmp(g->op, "RSHIFT") == 0) {
    short in1 = eval(get_from_tree(circuit, g->in1));
    return in1 >> g->const_in;
  } else if (strcmp(g->op, "LSHIFT") == 0) {
    short in1 = eval(get_from_tree(circuit, g->in1));
    return in1 << g->const_in;
  }
}

int main(int argc, char** argv) {
  char* in;
  if (argc < 2) {
    return 1;
  }
  FILE *f = fopen(argv[1], "r");

  fscanf(f, "%s", in);
  do {
    Gate* g = (Gate*) malloc(sizeof(Gate));
    if (strcmp(in, "NOT") == 0) {
      g->op = in;
      fscanf(f, "%s -> %s", (g->in1), (g->out));
    } else if ('0' <= in[0] && in[0] <= '9') {
      g->const_in = atoi(in);
      fscanf(f, "-> %s", (g->out));
    } else {
      g->in1 = in;
      fscanf(f, "%s", (g->op));
      if (strcmp((g->op)+1, "SHIFT") == 0) {
	fscanf(f, "%hd", &(g->const_in));
      } else {
	fscanf(f, "%s", (g->in2));
      }
      fscanf(f, "-> %s", (g->out));
    }
    insert_tree(circuit, g);
    fscanf(f, "%s", in);
  } while(!feof(f));
}

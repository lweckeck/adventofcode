/*
Reads a graph from stdin, given as
n m
u1 v1 d1
u2 v2 d2
...
where n is the number of nodes, m is the number of edges,
and a (u1, v1) is a directed edge with weight d1.

Calculates the length of minimum weight hamilton path.
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int n;

// adjacency matrix
int** A;

// visited flags
int* visited;

int current_best = INT_MAX;

int min(int n, int* array) {
  int i, min = INT_MAX;
  for (i=0; i<n; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

int all_visited() {
  int i;
  for (i=0; i<n; i++) {
    if (!visited[i]) {
      return 0;
    }
  }
  return 1;
}

int roundtrip_from(int u, int current_length) {
  if (current_length > current_best) {
    return INT_MAX;
  }
  visited[u] = 1;
  if (all_visited()) {
    visited[u] = 0;
    return current_length;
  }
  int v, minv;
  int* candidate_solutions = (int*) malloc(n*sizeof(int));
  for (v=0; v<n; v++) {
    if (A[u][v] > 0 && !visited[v]) {
      candidate_solutions[v] = roundtrip_from(v, current_length + A[u][v]);
    } else {
      candidate_solutions[v] = INT_MAX;
    }
  }
  minv = min(n, candidate_solutions);
  if (minv < current_best) {
    current_best = minv;
  }
  visited[u] = 0;
  return minv;
}

int main(int argc, char** argv) {
  int i, j, m, u, v, d;
  int* data;
  int* candidate_solutions;
  
  scanf("%d %d\n", &n, &m);
  // init adjacency matrix
  data = (int*)(malloc(n*n*sizeof(int)));
  A = (int**)(malloc(n*sizeof(int*)));
  for (i=0; i<n; i++) {
    A[i] = data + i*n;
    for (j=0; j<n; j++) {
      A[i][j] = 0;
    }
  }
  // init visited list
  visited = (int*)(malloc(n*sizeof(int)));
  for (i=0; i<n; i++) {
    visited[i] = 0;
  }

  //read edges
  for (i=0; i<m; i++) {
    scanf("%d %d %d\n", &u, &v, &d);
    A[u][v] = d;
  }
  // solve
  candidate_solutions = (int*) malloc(n*sizeof(int));
  for (i=0; i<n; i++) {
    candidate_solutions[i] = roundtrip_from(i, 0);
  }
  d = min(n, candidate_solutions);
  if (d == INT_MAX) {
    printf("No roundtrip found!\n");
  } else {
    printf("%d\n", d);
  }
}

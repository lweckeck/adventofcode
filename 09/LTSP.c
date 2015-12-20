/*
Reads a graph from stdin, given as
n m
u1 v1 d1
u2 v2 d2
...
where n is the number of nodes, m is the number of edges,
and a (u1, v1) is a directed edge with weight d1.

Calculates the weight of the maximum weight hamilton path.
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int n;

// adjacency matrix
int** A;

// visited flags
int* visited;

int max(int n, int* array) {
  int i, max = 0;
  for (i=0; i<n; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
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
  visited[u] = 1;
  if (all_visited()) {
    visited[u] = 0;
    return current_length;
  }
  int v, maxv;
  int* candidate_solutions = (int*) malloc(n*sizeof(int));
  for (v=0; v<n; v++) {
    if (A[u][v] > 0 && !visited[v]) {
      candidate_solutions[v] = roundtrip_from(v, current_length + A[u][v]);
    } else {
      candidate_solutions[v] = 0;
    }
  }
  maxv = max(n, candidate_solutions);
  visited[u] = 0;
  return maxv;
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
  d = max(n, candidate_solutions);
  if (d == 0) {
    printf("No roundtrip found!\n");
  } else {
    printf("%d\n", d);
  }
}

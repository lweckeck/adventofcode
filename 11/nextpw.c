#include<stdio.h>
#include<string.h>

#define N 8
char pw [N];

int valid() {
  int i, n_pairs=0, increasing=0;
  char pair = '#';
  for (i=N-1; i>=0; i--) {
    if (pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'l') {
      return 0;
    }
    if (n_pairs < 2 && i > 0) {
      if (pw[i] != pair && pw[i] == pw[i-1]) {
	pair = pw[i];
	n_pairs++;
      }
    }
    if (!increasing && i > 1) {
      if (pw[i] == pw[i-1]+1 && pw[i-1] == pw[i-2]+ 1) {
	increasing = 1;
      }
    }
  }
  if (n_pairs >= 2) {
    return increasing;
  } else {
    return 0;
  }
}

void incpw() {
  int i;
  for (i=N-1; i>=0; i--) {
    if (pw[i] >= 'z') {
      pw[i] = 'a';
    } else {
      pw[i] += 1;
      return;
    }
  }
}

int main(int argc, char** argv) {
  strcpy(pw, argv[1]);

  do {
    incpw();
  } while(!valid());
  printf("%s\n", pw);
}
  
  

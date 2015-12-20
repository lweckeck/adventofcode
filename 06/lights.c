#include<stdio.h>
#include<string.h>

#define DIM 1000
int lights [DIM*DIM];

int main(int argc, char** argv) {
  int i, j, x1, x2, y1, y2, count;
  char command[8];

  FILE* f = fopen(argv[1], "r");
  // init lights
  for (i=0; i<DIM; i++) {
    for (j=0; j<DIM; j++) {
      lights[i*DIM+j] = 0;
    }
  }

  fscanf(f, "%s", command);    
  do {
    if (command == "turn") {
      fscanf(f, "%s", command);
    }
    fscanf(f, "%d,%d through %d,%d", &x1, &y1, &x2, &y2);

    if (strcmp(command, "on") == 0) {
      for (i=x1; i <= x2; i++) {
	for (j=y1; j <= y2; j++) {
	  lights[i*DIM+j] = 1;
	}
      }
    } else if (strcmp(command, "off") == 0) {
      for (i=x1; i <= x2; i++) {
	for (j=y1; j <= y2; j++) {
	  lights[i*DIM+j] = 0;
	}
      }
    } else if (strcmp(command, "toggle") == 0) {
      for (i=x1; i <= x2; i++) {
	for (j=y1; j <= y2; j++) {
	  lights[i*DIM+j] = 1-lights[i*DIM+j];
	}
      }
    }
    //    printf("%s, %d, %d, %d, %d\n", command, x1, y1, x2, y2);
    fscanf(f, "%s", command);
   } while(!feof(f));

  count = 0;
  for (i=0; i < DIM; i++) {
    for (j=0; j < DIM; j++) {
      count += lights[i*DIM+j];
    }
  }
  printf("%d\n", count);
}

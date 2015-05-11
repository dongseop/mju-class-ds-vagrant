#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "util.h"

void generate_seq_list(int list[], int length) {
  int i;
  for(i = 0; i < length; i++) {
    list[i] = i + 1;
  }
}

void generate_rev_list(int list[], int length) {
  int i;
  for(i = 0; i < length; i++) {
    list[i] = length - i;
  }
}

void generate_rand_list(int list[], int length) {
  int i;
  for(i = 0; i < length; i++) {
    list[i] = rand() % length;
  }
}

void print_list(int list[], int length) {
  int i;
  for (i = 0; i < length; i++) {
    printf("%d ", list[i]);
  }
  printf("\n");

}
void begin(Time* t) {
  t->start = clock();
}

void end(Time* t, char* msg) {
  t->end = clock();
  printf("%s\t%lu ms\n", msg, (t->end - t->start) / (CLOCKS_PER_SEC/1000));
}
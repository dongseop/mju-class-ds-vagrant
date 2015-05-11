#include <stdio.h>
#include <string.h>

#include "util.h"

extern void insert(int list[], int n);
extern void select_sort(int list[], int n);
extern void bubble(int list[], int n);
extern void quick(int list[], int n);
extern void merge(int list[], int n);
extern void heap(int list[], int n);
extern void radix(int list[], int n);
extern void count(int list[], int n);

#define MAXLEN_FOR_PRINT 31

int* g_list;
typedef void (*sort_func) (int [], int);

void simul(sort_func func, char* name, int seq_list[], int rev_list[], int rand_list[], int n) {
  Time t;
  char header[1000];
  sprintf(header, "Sort %s [%d]: ", name, n);

  memcpy(g_list, seq_list, sizeof(int) * n);
  sprintf(header, "Sort %s [%d]/sequential : ", name, n);
  begin(&t);
  func(g_list, n);
  end(&t, header);

  if (n < MAXLEN_FOR_PRINT) {
    print_list(g_list, n);
  }

  memcpy(g_list, rev_list, sizeof(int) * n);
  sprintf(header, "Sort %s [%d]/reverse : ", name, n);
  begin(&t);
  func(g_list, n);
  end(&t, header);

  if (n < MAXLEN_FOR_PRINT) {
    print_list(g_list, n);
  }

  memcpy(g_list, rand_list, sizeof(int) * n);
  sprintf(header, "Sort %s [%d]/random : ", name, n);
  begin(&t);
  func(g_list, n);
  end(&t, header);

  if (n < MAXLEN_FOR_PRINT) {
    print_list(g_list, n);
  }
}

int main(int argc, char* argv[]) {
  int* list1;
  int* list2;
  int* list3;
  int n;

  srand(time(0));

  if (argc > 1) {
    n = atoi(argv[1]);
  } else {
    n = 10;
  }

  g_list = (int*) malloc(sizeof(int) * n);
  list1 = (int*) malloc(sizeof(int) * n);
  list2 = (int*) malloc(sizeof(int) * n);
  list3 = (int*) malloc(sizeof(int) * n);

  Time t;  
  begin(&t);
  generate_seq_list(list1, n);
  generate_rev_list(list2, n);
  generate_rand_list(list3, n);
  end(&t, "List Generation: ");

  if (n < MAXLEN_FOR_PRINT) {
    print_list(list1, n);
    print_list(list2, n);
    print_list(list3, n);
  }

  simul(bubble, "Bubble", list1, list2, list3, n);
  simul(count, "Count", list1, list2, list3, n);

  free(g_list);
  free(list1);
  free(list2);
  free(list3);

  return 0;
}
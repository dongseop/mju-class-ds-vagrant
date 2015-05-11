#ifndef _UTIL_H
#define _UTIL_H

#include <stdlib.h>

#define SWAP(a, b, t)  ((t) = (a), (a) = (b), (b) = (t))

typedef struct t_time {
  clock_t start;
  clock_t end;
} Time;

extern void generate_seq_list(int list[], int length);
extern void generate_rev_list(int list[], int length);
extern void generate_rand_list(int list[], int length);
extern void print_list(int list[], int length);

extern void begin(Time* t);
extern void end(Time* t, char* msg);

#endif
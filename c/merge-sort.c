/**
 * Implement merge sort of integers.
 *
 * USAGE: merge-sort [VALUE]+
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Sort *valuesc* ints from *values* into *sorted*.
 */
void msort(const int *values, int valuesc, int *sorted) {
  // Split the array into two halves
  size_t lc = (valuesc / 2) + (valuesc % 2),
         rc = (valuesc / 2);

  int *l = malloc(sizeof(*l) * lc),
      *r = malloc(sizeof(*r) * rc),
      *nl,
      *nr;

  int *l_itr = l;
  int *r_itr = r;
  const int *values_itr = values;
  while (values_itr < values + lc) {
    *(l_itr++) = *(values_itr++);
  }

  while (values_itr < values + lc + rc) {
    *(r_itr++) = *(values_itr++);
  }

  if (!(lc <= 1 && rc <= 1)) {
    nl = malloc(sizeof(*nl) * lc);
    nr = malloc(sizeof(*nr) * rc);
    msort(l, lc, nl);
    msort(r, rc, nr);
  } else {
    nl = l;
    nr = r;
  }

  size_t sort_c = 0;
  int *nl_itr = nl;
  int *nr_itr = nr;

  while (sort_c < valuesc) {
    if (nl_itr >= nl + lc) {
      *(sorted++) = *(nr_itr++);
    } else if (nr_itr >= nr + rc) {
      *(sorted++) = *(nl_itr++);
    } else if (*nl_itr < *nr_itr) {
      *(sorted++) = *(nl_itr++);
    } else {
      *(sorted++) = *(nr_itr++);
    }

    sort_c++;
  }
}

int main(int argc, char **argv) {
  int *values = malloc(sizeof(*values) * (argc - 1));
  for (size_t idx = 1; idx < argc; idx++) {
    values[idx - 1] = atoi(argv[idx]);
  }
  int *sorted = malloc(sizeof(*sorted) * (argc - 1));
  msort(values, argc - 1, sorted);

  for (size_t idx = 0; idx < argc - 1; idx++) {
    printf("%d ", sorted[idx]);
  }

  printf("\n");
}

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

using std::vector;

/**
 * Sort input from *begin* to *end* from *obegin*.
 */
void msort(std::vector<int64_t>::iterator begin,
           std::vector<int64_t>::iterator end,
           std::vector<int64_t>::iterator obegin) {
  std::size_t len = end - begin;
  std::size_t split = len / 2;

  vector<int64_t> left(split);
  vector<int64_t> right(len - split);

  if (!(split <= 1 || len - split <= 1)) {
    msort(begin, begin + split, left.begin());
    msort(begin + split, begin + len, right.begin());
  } else {
    left.assign(begin, begin + split);
    right.assign(begin + split, begin + len);
  }

  auto left_begin = left.cbegin();
  auto right_begin = right.cbegin();
  auto left_end = left.cend();
  auto right_end = right.cend();

  while (left_begin < left_end || right_begin < right_end) {
    if (left_begin == left_end) {
      *(obegin++) = *(right_begin++);
    } else if (right_begin == right_end) {
      *(obegin++) = *(left_begin++);
    } else if (*left_begin < *right_begin) {
      *(obegin++) = *(left_begin++);
    } else {
      *(obegin++) = *(right_begin++);
    }
  }
}

int main(int argc, char **argv) {
  vector<int64_t> values(argc - 1);
  std::transform(argv + 1, argv + argc, values.begin(), [](char * s) {
    return std::atol(s);
  });

  vector<int64_t> sorted(argc - 1);
  msort(values.begin(), values.end(), sorted.begin());

  for (auto&& v : sorted) {
    std::cout << v << " ";
  }

  std::cout << std::endl;
}

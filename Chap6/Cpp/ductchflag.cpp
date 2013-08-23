#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cassert>

template <typename T>
void swap(T& a, T& b) {
  T tmp(a);
  a = b;
  b = tmp;
}

template <typename T>
void dutch_flag(std::vector<T>& A, const int index) {
  T pivot = A[index];

  int smaller = 0
    , equal   = 0;

  int larger  = A.size() - 1;

  while (equal <= larger) {
    if (A[equal] < pivot) {
      swap(A[equal++], A[smaller++]);
    } else if (A[equal] == pivot) {
      equal++;
    } else {
      swap(A[equal], A[larger--]);
    }
  }
}

int main() {
  int asc_arr[]  = {1, 2, 3, 4, 5, 6}
    , desc_arr[] = {6, 5, 4, 3, 2, 1}
    , same_arr[] = {1, 1, 1, 1, 1, 1}
    , rand_arr[] = {2, 100, -10, 2, -9, 7, 8};

  int expect_asc[]  = {1, 3, 4, 5, 6, 2}
    , expect_desc[] = {5, 4, 3, 2, 1, 6}
    , expect_same[] = {1, 1, 1, 1, 1, 1}
    , expect_rand[] = {-9, -10, 2, 2, 7, 8, 100};
        
  
  std::vector<int> asc_vec(asc_arr, asc_arr+6)
    , desc_vec(desc_arr, desc_arr+6)
    , same_vec(same_arr, same_arr+6)
    , rand_vec(rand_arr, rand_arr+7);


  dutch_flag(asc_vec,  0);
  dutch_flag(desc_vec, 0);
  dutch_flag(same_vec, 0);
  dutch_flag(rand_vec, 0);

  // copy(same_vec.begin(), same_vec.end(),
  //      std::ostream_iterator<int>(std::cout, " "));
  
  assert(std::equal(asc_vec.begin(),  asc_vec.end(),  expect_asc));
  assert(std::equal(desc_vec.begin(), desc_vec.end(), expect_desc));
  assert(std::equal(same_vec.begin(), same_vec.end(), expect_same));
  assert(std::equal(rand_vec.begin(), rand_vec.end(), expect_rand));

  return 0;
}

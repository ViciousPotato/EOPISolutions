#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <tr1/memory>

using std::tr1::shared_ptr;

template <typename T>
class BinaryTree {
  public:
    T data;
    shared_ptr<BinaryTree<T> > left, right;
};

#endif
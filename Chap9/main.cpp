#include "BinaryTree.h"

int main() {
  shared_ptr<BinaryTree<int> > D = new shared_ptr(new BinaryTree<int>());
  D->data = 28;
  
  return 0; 
}
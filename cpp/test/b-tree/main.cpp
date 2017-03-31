// Taken from http://www.cprogramming.com/tutorial/lesson18.html
#include <iostream>

struct node{
  int key_value;
  node *left;
  node *right;
};

class btree {
public:
  btree();
  ~btree();

  void insert(int key);
  node *search(int key);
  void destroy_tree();

private:
  void destroy_tree(node *leaf);
  void insert(int key, node *leaf);
  node *search(int key, node *leaf);

  node *root;
};

btree::btree() {
  root = NULL;
}

int main(int argc, char *argv[]) {
  std::cout << "Hello world!" << std::endl;
}

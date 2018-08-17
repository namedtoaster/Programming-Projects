#include <iostream>
#include <string>

using namespace std;

struct Node {
  string name;
  int num;

  Node *p_next_node;
};

Node *p_head_of_nodes = NULL;

Node *get_new_node(string name, int num) {
  Node *new_node = new Node;
  new_node->name = name;
  new_node->num = num;

  // set the next node of the new node to be the head
  // which is currently set to the node that the first node will be pointing to
  new_node->p_next_node = p_head_of_nodes;

  // the head is now the new node that we are creating here (which points to to the next node)
  p_head_of_nodes = new_node;

  return new_node;
}

void print_head() {
  cout << "Node Name: " << p_head_of_nodes->name << endl;
  cout << "Node Num: " << p_head_of_nodes->num << endl;
  cout << endl;
}

void print_and_delete_nodes() {
  while (p_head_of_nodes != NULL) {
    print_head();

    // create a temp node where you can delete the node from - i think this is what you should do...?
    Node *temp = p_head_of_nodes;
    delete temp;
    temp = NULL;

    p_head_of_nodes = p_head_of_nodes->p_next_node;
  }
}

int main() {
  Node *x = get_new_node("Bobby", 4);
  Node *y = get_new_node("Janice", 8);
  Node *z = get_new_node("Franklin", 2);

  print_and_delete_nodes();

  // do you have to do this? or is it done in the previous line?
  delete p_head_of_nodes;
  p_head_of_nodes = NULL;

  return 0;
}

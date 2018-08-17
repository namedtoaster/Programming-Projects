#include <iostream>
#include <string>

using namespace std;

struct Node {
  string name;

  Node* next;
};

Node *new_node(Node *head, string name) {
  Node *temp = new Node;
  temp->name = name;
  temp->next = head;

  return temp;
}

int main() {
  cout << "This program isn't complete. My brain hurts" << endl;
  Node *head = NULL;

  Node *x = new_node(head, "Bob");
  Node *y = new_node(head, "Joe");
  Node *z = new_node(head, "Fred");

  cout << head << endl;

  return 0;
}

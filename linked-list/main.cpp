#include <iostream>

class Node {
public:
  Node();
  Node(int val, Node *nx = NULL, Node *prev = NULL) {
    value = val; next = nx; previous = prev;
  }
  ~Node() { delete this; }

  friend class LinkedList;

private:
  int value;
  Node *next;
  Node *previous;
};

class LinkedList {
 public:
  LinkedList() : front(NULL), back(NULL) {}

  bool empty() { return front == NULL; }

  void pushBack(int val) {
    Node *nd = new Node(val);

    if (back == NULL) {
      front = nd;
      back = nd;
    }
    else {
      back = nd;
      nd->previous = back;
      back = nd;
    }
    std::cout << "Front: " << front << std::endl;
    std::cout << "Back: " << back << std::endl;
  }

  void popBack() {
    if (empty() == 1)
      std::cout << "List is empty" << std::endl;
    else if (front == back) {
      delete front;
      delete back;
    }
    else {
      back = back->previous;
      delete back->next;
    }
  }

  Node* topFront() { return front; }

  void print() {
    if (empty()) {
      std::cout << "List is empty" << std::endl;
    }
    else {
      std::cout << "Print list" << std::endl;

      Node *x = front;
      int count = 1;

      // First just print the first element, then the rest
      Node *y = front;
      std::cout << count << ": ";
      std::cout << y->value << std::endl;

      x = x->next;

      while (x != NULL) {
        count++;
        std::cout << count << ": ";
        int z = x->value; std::cout << z << std::endl;

        x = x->next;
      }
    }
  }

 private:
  Node* front;
  Node* back;
};

int main() {
  LinkedList ll;
  char input;
  char const *menu = {"Options:\n\n" \
                      "0. Quit\n" \
                      "1. Print linked-list\n" \
                      "2. pushBack -- add to the end of the LinkedList\n"};

  while (input != '0') {
    std::cout << menu << std::endl;
    std::cout << ":";
    std::cin >> input;

    if (input == '1') {
      ll.print();
    }
    else if (input == '2') {
      std::cout << "Value: ";
      int init;
      std::cin >> init;
      ll.pushBack(init);
    }
  }

  return 0;
}

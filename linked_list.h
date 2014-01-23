#include <cstdlib>
#include <cstdio>
#include <cstring>

typedef struct Node {
  Node* next;
  char *key, *value;
} Node;

class LinkedList {
public:
  LinkedList();
  ~LinkedList();
  int size();
  Node *at(int i);
  void push(Node *new_node);
  void push(const char *key, const char *value);
  bool destroy(int i);

private:
  Node *head;
};
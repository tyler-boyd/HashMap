#include "linked_list.h"

LinkedList::LinkedList() {
  head = 0;
}
LinkedList::~LinkedList() {
  while(head)
    destroy(0);
}
int LinkedList::size() {
  int size = 0;
  Node *node = head;

  while(node)
  {
    size++;
    node = node->next;
  }
  return size;
}

Node* LinkedList::at(int i) {
  Node *node = head;
  for(int c=0; c<i && node; c++)
    node = node->next;
  return node ? node : 0;
}

bool LinkedList::destroy(int i) {
  Node *parent = head;
  Node *after = 0;
  Node *node = 0;
  for(int c=0; c<i && parent; c++)
    parent = parent->next;
  if(!parent)
    return false;
  node = parent->next;
  if(!node)
  {
    head = 0;
    return true;
  }
  after = node->next;
  delete node;
  parent->next = after;
  return true;
}

void LinkedList::push(Node *new_node)
{
  int size = this->size();
  if(size == 0)
    head = new_node;
  else {
    Node *last = at(size-1);
    last->next = new_node;
  }
}

void LinkedList::push(const char *key, const char *value)
{
  Node *new_node = new Node;
  new_node->key = new char[256];
  new_node->value = new char[256];
  new_node->next = 0;
  strcpy(new_node->key, key);
  strcpy(new_node->value, value);
  this->push(new_node);
}
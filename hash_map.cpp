#include "hash_map.h"

HashMap::HashMap() {
  for(int i=0; i<100; i++)
    data.push_back(new LinkedList);
}
HashMap::~HashMap() {}

char *HashMap::get_value(const char *key) {
  int index = get_index(key);
  LinkedList *list = data.at(index);
  if(!list)
  {
    printf("Shitdicks");
  }
  int list_size = list->size();
  for(int i=0; i<list_size; i++)
  {
    Node *node = list->at(i);
    if(strcmp(node->key, key) == 0)
      return node->value;
  }
  return 0;
}

char *HashMap::set_value(const char *key, const char *value) {
  int index = get_index(key);
  LinkedList *list = data.at(index);
  if(!list) {
    list = new LinkedList;
  }
  list->push(key, value);
  return (char*) value;
}

int HashMap::hash_function(const char *input) {
  int len = strlen(input);
  int sum = 0;
  for(int i=0; i<len; i++)
  {
    sum += input[i];
  }

  return sum;
}

int HashMap::get_index(const char *input) {
  return hash_function(input) % data.size();
}

char *HashMap::operator[](const char *key) {
  return this->get_value(key);
}

// char *HashMap::operator<<(const char *key, const char *value) {
//   return this->set_value(key, value);
// }
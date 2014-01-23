#include "linked_list.h"
#include <vector>

using namespace std;

class HashMap {
public:
  HashMap();
  ~HashMap();
  char* get_value(const char *key);
  char* set_value(const char *key, const char *value);
  char* operator[](const char *key);
  // char *operator<<(const char *key, const char *value);
private:
  vector<LinkedList*> data;
  int hash_function(const char* input);
  int get_index(const char *input);
};
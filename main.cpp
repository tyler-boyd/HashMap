#include "hash_map.h"

int main()
{
  HashMap hash;
  hash.set_value("key1", "value1");
  printf("Value of hash[\"key1\"]: %s\n\n", hash["key1"]);

  return 0;
}
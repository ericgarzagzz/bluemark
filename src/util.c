#include "util.h"
#include <string.h>

void str_replace(char *str, const char search, const char replacement) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == search) {
      str[i] = replacement;
    }
  }
}

void str_append(char *str, const char append) {
  size_t len = strlen(str);
  str[len] = append;
  str[len + 1] = '\0';
}

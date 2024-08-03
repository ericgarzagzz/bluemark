#include "util.h"
#include <string.h>

void str_replace(char *str, const char search, const char replacement) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == search) {
      str[i] = replacement;
    }
  }
}

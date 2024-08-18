#include "lexer.h"
#include "parser.h"
#include "queue.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: bluemark <file>\n");
    return 0;
  }

  const char *file_path = argv[1];
  FILE *file = fopen(file_path, "rb");
  if (file == NULL) {
    char msg[256];
    strcat(msg, "bluemark: ");
    strcat(msg, file_path);

    perror(msg);
    return 1;
  }

  fseek(file, 0, SEEK_END);
  long fsize = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *buff = malloc(fsize + 1);
  if (buff == NULL) {
    perror("bluemark: ");
    return 1;
  }

  int count = 1;
  const size_t ret_code = fread(buff, fsize, count, file);
  if (ret_code != count) {
    if (feof(file)) {
      printf("bluemark: Error reading %s: unexpected end of file\n", file_path);
      return 1;
    } else if (ferror(file)) {
      perror("bluemark: Error reading file\n");
      return 1;
    }
  }

  fclose(file);

  buff[fsize] = 0;

  str_replace(buff, '\n', ' ');
  str_replace(buff, '\r', ' ');

  queue_t *tokens_q = lexer_parse(buff); 
  free(buff);

  ast_node_t *ast_root_node = parser_parse(tokens_q);

  for (int i = 0; i < ast_root_node->children_size; i++) {
    ast_node_t *child = ast_root_node->children[i];
    printf("%s", child->value->value);
  }
  printf("\n");

  free(tokens_q);
  free(ast_root_node);

  return 0;
}

#include "../inc/pathfinder.h"

static int is_valid_line(char *line) {
  int j = 0;

  while (mx_isalpha(line[j++])) {}
  if (j == 1 || line[j - 1] != '-') return 0;

  while (mx_isalpha(line[j++])) {}
  if (line[j - 1] != ',') return 0;

  while (mx_isdigit(line[j++])) {}

  return (line[j - 1] == '\0');
}

ErrorCode mx_error_lines(char **lines, int num) {
  for (int i = 1; i < num; i++) {
    if (!is_valid_line(lines[i])) {
      mx_printerr("error: line ");
      mx_printerr(mx_itoa(i + 1));
      mx_printerr(" is not valid\n");
      return INVALID_LINE;
    }
  }
  return SUCCESS;
}

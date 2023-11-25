#include "../inc/pathfinder.h"

ErrorCode mx_error_line_valid(char *first_line) {
  for (int i = 0; first_line[i]; i++) {
    if (!mx_isdigit(first_line[i])) {
      mx_printerr("error: line 1 is not valid\n");
      return INVALID_FIRST_LINE;
    }
  }
  return SUCCESS;
}

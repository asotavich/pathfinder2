#include "../inc/pathfinder.h"

ErrorCode mx_error_file_empty(char *filename, char *argv[]) {
  if (mx_strlen(filename) == 0) {
    mx_printerr("error: file ");
    mx_printerr(argv[1]);
    mx_printerr(" is empty\n");
    return EMPTY_FILE;
  }
  return SUCCESS;
}

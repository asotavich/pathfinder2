#include "../inc/pathfinder.h"

ErrorCode mx_error_file_exist(char *filename) {
  if (open(filename, O_RDONLY) < 0) {
    mx_printerr("error: file ");
    mx_printerr(filename);
    mx_printerr(" does not exist\n");
    return FILE_DOES_NOT_EXIST;
  }
  return SUCCESS;
}

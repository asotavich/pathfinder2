#include "../inc/pathfinder.h"

ErrorCode mx_error_args(int argc) {
  if (argc != 2) {
    mx_printerr("usage: ./pathfinder [filename]\n");
    return INVALID_ARGUMENTS;
  }
  return SUCCESS;
}

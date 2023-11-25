#include "../inc/pathfinder.h"

ErrorCode mx_error_island_num(char **islands, int numIslands, int size) {
  int count = 0;

  for (int i = 0; i < numIslands; i++) {
    if (islands[i][0] != ' ') {
      count++;
    }
  }
  if (count != size) {
    mx_del_strarr(&islands);
    mx_printerr("error: invalid number of islands\n");
    return INVALID_NUMBER_OF_ISLANDS;
  }
  return SUCCESS;
}

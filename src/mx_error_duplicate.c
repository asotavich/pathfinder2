#include "../inc/pathfinder.h"

ErrorCode mx_error_duplicate(char **lines, int num) {
  char **str = (char **)malloc((num + 1) * sizeof(char *));

  for (int i = 0; i < num; i++) {
    str[i] = mx_strndup(lines[i], mx_get_char_index(lines[i], ','));
  }
  str[num] = NULL;

  for (int i = 0; i < num; i++) {
    for (int j = 0; j < num; j++) {
      if (str[j][0] == '\0' || j == i) {
        continue;
      }
      if (mx_strcmp(str[i], str[j]) == 0) {
        mx_printerr("error: duplicate bridges\n");
        free(str);
        return DUPLICATE_BRIDGES;
      }
    }
  }
  mx_del_strarr(&str);
  return SUCCESS;
}

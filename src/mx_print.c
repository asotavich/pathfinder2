#include "../inc/pathfinder.h"

static void mx_print_edge(void) {
  for (int i = 0; i < 40; i++) {
    mx_printchar('=');
  }
  mx_printchar('\n');
}

static void mx_print_path_element(char *element, const char *delimiter) {
  mx_printstr(element);
  if (delimiter != NULL) {
    mx_printstr(delimiter);
  }
}

static void mx_print_path_for_print(char **islands, int *route) {
  mx_print_path_element(islands[route[1]], " -> ");
  mx_print_path_element(islands[route[0]], "\n");
}

static void mx_print_route(int count, int *route, char **islands) {
  for (int i = 1; i < count + 1; i++) {
    mx_print_path_element(islands[route[i]], (i < count) ? " -> " : "\n");
  }
}

static void mx_print_distance(int count, int *route, int **matr, int **paths) {
  if (count > 2) {
    for (int i = 1; i < count; i++) {
      int temp = matr[route[i]][route[i + 1]];
      mx_printint(temp);
      if (i < count - 1) {
        mx_printstr(" + ");
      }
    }
    mx_printstr(" = ");
  }
  mx_printint(paths[route[0]][route[1]]);
  mx_printchar('\n');
}

static void mx_process_path(char **isl, int **matr, int **paths, int *route, int s) {
  mx_print_edge();
  mx_printstr("Path: ");
  mx_print_path_for_print(isl, route);
  mx_printstr("Route: ");
  mx_print_route(s, route, isl);
  mx_printstr("Distance: ");
  mx_print_distance(s, route, matr, paths);
  mx_print_edge();
}

static void mx_print(char **isl, int **matr, int **paths, int size, int *route, int s) {
	int start = route[0];
	int end = route[s];

	for (int i = 0; i < size; i++) {
		if((matr[end][i] == paths[end][start] - paths[i][start]) && i != route[s]) {
			s++;
			route[s] = i;
			mx_print(isl, matr, paths, size, route, s);
			s--;
		}
	}
	if (route[s] != start) return;
	mx_process_path(isl, matr, paths, route, s);
}

void mx_solve(char **isl, int **matr, int **paths, int size, int *route, int s) {
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      route[1] = i;
      route[0] = j;
      mx_print(isl, matr, paths, size, route, s);
    }
  }
}

void mx_printerr(const char *str) {
  write(2, str, mx_strlen(str));
}

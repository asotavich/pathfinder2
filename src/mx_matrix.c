#include "../inc/pathfinder.h"

static int mx_index(char **arr, char *str) {
	for (int i = 0; arr[i]; i++) {
		if (mx_strcmp(arr[i], str) == 0) {
			return i;
		}
	}
	return -1;
}

static char **mx_path_print(char *line) {
	char **arr = (char **)malloc(4 * sizeof(char *));
	
	for (int i = 0; i <= 3; i++) {
		arr[i] = NULL;
	}
	
	arr[0] = mx_strndup(line, mx_get_char_index(line, '-'));
	line += mx_get_char_index(line, '-') + 1;
	arr[1] = mx_strndup(line, mx_get_char_index(line, ','));
	line += mx_get_char_index(line, ',') + 1;
	arr[2] = mx_strndup(line, mx_get_char_index(line, '\n'));

	return arr;
}

int **mx_matrix(char **lines, char **graph, int size) {
	int **matr = (int **) malloc(size * sizeof(int *));
	for (int i = 0; i < size; i++) {
		matr[i] = (int *)malloc(size * sizeof(int));
	}
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			matr[i][j] = INF;
		}
	}
	for (int i = 1; lines[i]; i++) {
		char **temp = mx_path_print(lines[i]);

		if (mx_atoi(temp[2]) >= __INT_MAX__) {
			mx_printerr("error: sum of bridges lengths is too big\n");
			exit(0);
		}
		
		int a = mx_index(graph, temp[0]);
		int b = mx_index(graph, temp[1]);
		
		matr[a][b] = mx_atoi(temp[2]);
		matr[b][a] = mx_atoi(temp[2]);
		mx_del_strarr(&temp);
	}
	return matr;
}



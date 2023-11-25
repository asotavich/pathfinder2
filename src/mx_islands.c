#include "../inc/pathfinder.h"

char **mx_islands(char *string, int size) {
	char *str = mx_strdup(string);
	int count = 0;
	char **islands = (char **)malloc((size + 1) * sizeof(char *));

	for (int i = 0; i < mx_strlen(str); i++) {
		if (str[i] == '-' || str[i] == ',' || str[i] == '\n') {
			str[i] = ' ';
		}
		if (mx_isdigit(str[i])) {
			str[i] = ' ';
		}
	}

	char *without_spaces = mx_del_extra_spaces(str);
	char **lines = mx_strsplit(without_spaces, ' ');
	while (lines[count]) {
		count++;
	}
	for (int i = 0, j = 1; i < count; i += 2, j++) {
		if(mx_strcmp(lines[i], lines[i + 1]) == 0) {
			mx_printerr("error: line ");
			mx_printerr(mx_itoa(j + 1));
			mx_printerr(" is not valid\n");
			exit(0);
		}
	}
	int k = 0;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (lines[j][0] == ' ' || j == i) {
				continue;
			}
			if (mx_strcmp(lines[i], lines[j]) == 0) {
				lines[j][0] = ' ';
			}
		}
		if(mx_isalpha(lines[i][0])) {
			islands[k] = mx_strdup(lines[i]);
			k++;
		}
	}
	islands[size] = NULL;
	mx_error_island_num(lines, count, size);

	mx_strdel(&str);
	mx_strdel(&without_spaces);
	mx_del_strarr(&lines);

	return islands;
}


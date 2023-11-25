#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_error_args(argc);
        return INVALID_ARGUMENTS;
    }

    ErrorCode fileExistError = mx_error_file_exist(argv[1]);
    if (fileExistError != SUCCESS) {
        return fileExistError;
    }

    char *str = mx_file_to_str(argv[1]);
    ErrorCode fileEmptyError = mx_error_file_empty(str, argv);
    if (fileEmptyError != SUCCESS) {
        return fileEmptyError;
    }

    char **lines = mx_strsplit(str, '\n');
    int count = 0;
    
    while (lines[count]) {
        count++;
    }

    ErrorCode firstLineError = mx_error_line_valid(lines[0]);
    if (firstLineError != SUCCESS) {
        return firstLineError;
    }

    ErrorCode linesError = mx_error_lines(lines, count);
    if (linesError != SUCCESS) {
        return linesError;
    }

    ErrorCode duplicateError = mx_error_duplicate(lines, count);
    if (duplicateError != SUCCESS) {
        return duplicateError;
    }

    int size = mx_atoi(lines[0]);
    char **islands = mx_islands(str, size);
    int **matrix = mx_matrix(lines, islands, size);

    int **paths = mx_floyd_warshall(matrix, size);
    int *route = (int *)malloc((size + 1) * sizeof(int));
    int steps = 1;
    
    mx_solve(islands, matrix, paths, size, route, steps);

    mx_strdel(&str);
    mx_del_strarr(&lines);
    mx_del_strarr(&islands);
    mx_del_arr(&matrix, size);
    mx_del_arr(&paths, size);
    free(route);

    return 0;
}

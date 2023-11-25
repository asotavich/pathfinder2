#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

#define INF 40000
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef enum {
    SUCCESS,
    INVALID_ARGUMENTS,
    FILE_DOES_NOT_EXIST,
    EMPTY_FILE,
    INVALID_FIRST_LINE,
    INVALID_LINE,
    INVALID_NUMBER_OF_ISLANDS,
    DUPLICATE_BRIDGES,
    BRIDGE_LENGTH_TOO_BIG
} ErrorCode;

ErrorCode mx_error_args(int argc);
ErrorCode mx_error_file_exist(char *filename);
ErrorCode mx_error_file_empty(char *filename, char *argv[]);
ErrorCode mx_error_line_valid(char *first_line);
ErrorCode mx_error_lines(char **lines, int num);
ErrorCode mx_error_island_num(char **islands, int numIslands, int size);
ErrorCode mx_error_duplicate(char **lines, int num);

char **mx_islands(char *string, int size);
int **mx_matrix(char **lines, char **graph, int size);

int **mx_floyd_warshall(int **matr, int size);
void mx_zero(int **arr, int size);

void mx_solve(char **isl, int **matr, int **paths, int size, int *route, int s);
void mx_printerr(const char *str);

#endif

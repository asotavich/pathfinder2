#include "libmx.h"

void mx_del_arr(int ***arr, int row) {
	for (int i = 0; i < row; i++) {
		free((*arr)[i]);
	}
	free(*arr);
	*arr = NULL;
}



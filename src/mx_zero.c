#include "../inc/pathfinder.h"

void mx_zero(int **arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i][j] == INF) {
				arr[i][j] = 0;
			}
		}
	}
}

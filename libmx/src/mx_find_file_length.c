#include "libmx.h"

int mx_find_file_length(const char *file) {
    int fl = open(file, O_RDONLY);
    
    if (fl == -1) {
        close(fl);
        return 0;
    }

    int length = 0;
    char c;

    while (read(fl, &c, 1) > 0) {
        length++;
    }

    close(fl);
    return length;
}

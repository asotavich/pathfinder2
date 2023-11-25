#include "libmx.h"

char *mx_file_to_str(const char *file) {
    int fl = open(file, O_RDONLY);
    int size = 0;
    
    if (fl == -1) {
        close(fl);
        return NULL;
    }
    size = mx_find_file_length(file);
    if (size == 0) {
        return NULL;
    }
    char *result = mx_strnew(size);
    read(fl, result, size);
    close(fl);
    
    return result;
}

#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long result = 0;
    int length = 0;

    while (hex[length] != '\0') {
        length++;
    }

    int i = 0;
    while (hex[i] == ' ' || hex[i] == '\t') {
        i++;
    }

    if (hex[i] == '0' && (hex[i + 1] == 'x' || hex[i + 1] == 'X')) {
        i += 2;
    }

    while (i < length) {
        char c = hex[i];
        unsigned long value = 0;

        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        } else {
            return result;
        }

        result = (result << 4) | value;
        i++;
    }

    return result;
}

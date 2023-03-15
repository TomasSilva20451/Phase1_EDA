#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void read_string(char *str, int max_length) {
    fgets(str, max_length, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int validate_nif(char *nif) {
    if (strlen(nif) != 9) {
        return 0;
    }

    for (int i = 0; i < 9; i++) {
        if (nif[i] < '0' || nif[i] > '9') {
            return 0;
        }
    }

    return 1;
}


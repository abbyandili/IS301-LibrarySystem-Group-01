#include "filehandling.h"

FILE* open_file(const char* filename, const char* mode) {
    FILE* fp = fopen(filename, mode);
    if (fp == NULL) {
        printf("[ERROR] Failed to open file: %s\n", filename);
    }
    return fp;
}

void close_file(FILE* fp) {
    if (fp != NULL) {
        fclose(fp);
    }
}
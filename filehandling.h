#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <stdio.h>

FILE* open_file(const char* filename, const char* mode);
void close_file(FILE* fp);

#endif
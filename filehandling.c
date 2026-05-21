#include <stdio.h>
#include "books.h"
#include "filehandling.h"

#define BOOKS_FILE "books.txt"

void load_books(void) {
    FILE *fp = fopen(BOOKS_FILE, "r");
    if (!fp) {
        printf("Error: Could not open %s\n", BOOKS_FILE);
        return;
    }

    char line[256];
    book_count = 0;

    while (fgets(line, sizeof(line), fp) && book_count < MAX_BOOKS) {
        Book *b = &books[book_count];
        // Matches the format: ID|Title|Author|Year|Status
        if (sscanf(line, "%7[^|]|%99[^|]|%59[^|]|%5[^|]|%d", 
                   b->id, b->title, b->author, b->year, &b->status) == 5) {
            book_count++;
        }
    }
    fclose(fp);
}
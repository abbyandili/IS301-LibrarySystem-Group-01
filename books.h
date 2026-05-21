#ifndef BOOKS_H
#define BOOKS_H

#define MAX_BOOKS 100

typedef struct {
    char id[10];
    char title[100];
    char author[60];
    char year[10];
    int status; // 0 for available, 1 for borrowed
} Book;

// External variables to be shared across the project
extern Book books[MAX_BOOKS];
extern int book_count;

// Function Prototypes
void add_book(void);
void load_books(void);

#endif
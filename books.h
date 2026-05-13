
#ifndef BOOKS_H
#define BOOKS_H

typedef struct {
    char bookID[10];
    char title[100];
    char author[100];
    char genre[50];
    int yearPublished;
    int quantity;
    char availabilityStatus[20];
} Book;

// Function prototype for searching
void searchBook(Book books[], int totalBooks);

#endif
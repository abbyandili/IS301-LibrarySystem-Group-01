#ifndef BOOKS_H
#define BOOKS_H

typedef struct {
    int id;
    char title[100];
    char author[100];
    char genre[50];
    int year;
    int quantity;
} Book;

void loadBooks();
void saveBooks();
void displayAllBooks();
void searchBook();
void addBook();
void updateQuantity();
void generateInventoryReport();

#endif
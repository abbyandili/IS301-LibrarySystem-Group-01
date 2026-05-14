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
// The Book structure based on the project requirements
typedef struct {
    char bookID[20];       // To store IDs like "001"
// The blueprint for every book in the system
// Make sure this structure matches your group's common definition!
struct Book {
    int bookID;
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
    char availabilityStatus[20]; // For the Inventory Report requirement
} Book;

// Function prototypes for Book Management (Section 3 of your requirements)
// This tells the compiler these functions exist somewhere in the project.

void displayAllBooks(Book books[], int count);
void searchBook(Book books[], int count);
void addBook(Book books[], int *count);
void updateQuantity(Book books[], int count);

#endif
};

// Function Prototypes (The tools available in this branch)
void displayAllBooks(struct Book library[], int count);
void updateQuantity(struct Book library[], int count);
void saveBooksToFile(struct Book library[], int count);

#endif



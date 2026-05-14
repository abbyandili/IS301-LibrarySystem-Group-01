#ifndef BOOKS_H
#define BOOKS_H
#define MAX_BOOKS 100

// The single, unified blueprint for a Book
typedef struct {
    char id[20];           // Changed to string to support "001"
    char title[100];
    char author[100];
    char genre[50];
    int yearPublished;
    int quantity;
    char status[20];       // e.g., "Available" or "Out of Stock"
} Book;

/* 
   Function Prototypes 
   These match the modular structure needed for books.c 
*/

// Display all books in a table format
void displayAllBooks();

// Search for a book by title or author
void searchBook();

// Add a new book to the inventory
void addBook();

// Update the quantity of a specific book by ID
void updateQuantity();

// Generate the inventory_report.txt file
void generateInventoryReport();

// Utility for case-insensitive searching (optional but recommended)
void toLowerCase(char str[]);

#endif // End of include guard - nothing should be outside after this


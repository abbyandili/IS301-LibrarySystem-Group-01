#include <stdio.h>
#include <string.h>
#include "books.h"
#include "filehandling.h" // Needed for save_books()

// Define the actual storage for books
Book books[MAX_BOOKS];
int book_count = 0;

void add_book(void) {
    if (book_count >= MAX_BOOKS) { 
        puts("Book catalogue full."); 
        return; 
    }
    
    Book b = {0};
    printf("\n--- Add New Book ---\n");
    printf("Title  : "); fgets(b.title,  sizeof(b.title),  stdin);
    printf("Author : "); fgets(b.author, sizeof(b.author), stdin);
    printf("Year   : "); fgets(b.year,   sizeof(b.year),   stdin);
    
    /* strip newlines */
    b.title[strcspn(b.title,"\n")]   = 0;
    b.author[strcspn(b.author,"\n")] = 0;
    b.year[strcspn(b.year,"\n")]     = 0;

    if (strlen(b.title) == 0 || strlen(b.author) == 0) {
        puts("Title and author cannot be empty."); 
        return;
    }

    // Assuming generate_id is a utility you've defined elsewhere
    generate_id("B", book_count + 1, b.id);
    b.status = 0;
    books[book_count++] = b;

    save_books(); // Updates the text file immediately
    printf("Book %s added successfully.\n", b.id);
}
#include <stdio.h>
#include "borrowing.h"
#include "books.h" // Needed to call updateBookQuantity()

void issueBook() {
    BorrowRecord record;
    printf("Book ID: "); scanf("%d", &record.bookID);
    printf("Member ID: "); scanf("%d", &record.memberID);
    
    // Logic: 
    // 1. Check if book exists and quantity > 0 (using functions in books.c)
    // 2. If yes, save record to borrowings.txt
    // 3. Call updateBookQuantity(record.bookID, -1);
}

void returnBook() {
    int bID, mID;
    printf("Enter Book ID to return: "); scanf("%d", &bID);
    // Logic: 
    // 1. Find record in borrowings.txt and change status to 1
    // 2. Call updateBookQuantity(bID, 1);
}

#include <stdio.h>
#include "borrowing.h"
#include "books.h" 

void issueBook() {
    BorrowRecord record;
    printf("Book ID: "); scanf("%d", &record.bookID);
    printf("Member ID: "); scanf("%d", &record.memberID);
    
void returnBook() {
    int bID, mID;
    printf("Enter Book ID to return: "); scanf("%d", &bID);
    
}

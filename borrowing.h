#ifndef BORROWING_H
#define BORROWING_H

typedef struct {
    int bookID;
    int memberID;
    char borrowDate[15];
    char returnDate[15];
    int status; 
} BorrowRecord;

void returnBook();
void issueBook();

#endif
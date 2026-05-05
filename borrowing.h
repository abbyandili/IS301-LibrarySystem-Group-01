#ifndef BORROWING_H
#define BORROWING_H

typedef struct {
    int bookID;
    int memberID;
    char borrowDate[15];
    char returnDate[15];
    int status; // 0 for Borrowed, 1 for Returned
} BorrowRecord;

// Function Prototypes
void issueBook();
void returnBook();

#endif

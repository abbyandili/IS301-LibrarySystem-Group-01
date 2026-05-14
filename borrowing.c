#include <stdio.h>
#include <string.h>
#include "borrowing.h"
#include "books.h" // To use updateQuantity

void returnBook() {
    int searchBookID, searchMemberID;
    int found = 0;
    BorrowRecord records[100]; // Array to hold records temporarily
    int count = 0;

    printf("\n--- Return Book ---\n");
    printf("Enter Book ID: ");
    scanf("%d", &searchBookID);
    printf("Enter Member ID: ");
    scanf("%d", &searchMemberID);

    // 1. Read current records into memory
    FILE *file = fopen("borrowings.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open borrowing records.\n");
        return;
    }

    // Read file line by line into our array
    // Format: BookID, MemberID, BorrowDate, ReturnDate, Status
    while (fscanf(file, "%d, %d, %[^,], %[^,], %d\n", 
           &records[count].bookID, 
           &records[count].memberID, 
           records[count].borrowDate, 
           records[count].returnDate, 
           &records[count].status) != EOF) {
        
        // 2. Check if this is the active loan (status 0 means borrowed)
        if (records[count].bookID == searchBookID && 
            records[count].memberID == searchMemberID && 
            records[count].status == 0) {
            
            // Update the record
            records[count].status = 1; // Mark as returned
            printf("Enter Return Date (DD-MM-YYYY): ");
            scanf("%s", records[count].returnDate);
            found = 1;
        }
        count++;
    }
    fclose(file);

    // 3. If found, write everything back to the file
    if (found) {
        file = fopen("borrowings.txt", "w"); // 'w' overwrites the file
        for (int i = 0; i < count; i++) {
            fprintf(file, "%d, %d, %s, %s, %d\n", 
                    records[i].bookID, 
                    records[i].memberID, 
                    records[i].borrowDate, 
                    records[i].returnDate, 
                    records[i].status);
        }
        fclose(file);

        // 4. Update the inventory (Add 1 back to the book quantity)
        // This function should be defined in your books.c
        updateBookQuantity(searchBookID, 1); 

        printf("\nSuccess: Book ID %d returned by Member %d.\n", searchBookID, searchMemberID);
    } else {
        printf("\nError: No active borrowing record found for these IDs.\n");
    }
}
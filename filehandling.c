#include <stdio.h>
#include <string.h>
#include "filehandling.h"

void generateInventoryReport(Book books[], int bookCount) {
    // Open the report file in write mode ("w")
    FILE *reportFile = fopen("inventory_report.txt", "w");

    if (reportFile == NULL) {
        printf("\n[Error] Could not create the inventory report file!\n");
        return;
    }

    // Header for the report (Optional but looks professional)
    fprintf(reportFile, "--- LIBRARY INVENTORY REPORT ---\n\n");

    for (int i = 0; i < bookCount; i++) {
        fprintf(reportFile, "BookID: %s\n", books[i].bookID);
        fprintf(reportFile, "Title: %s\n", books[i].title);
        fprintf(reportFile, "Author: %s\n", books[i].author);
        fprintf(reportFile, "Genre: %s\n", books[i].genre);
        fprintf(reportFile, "Year Published: %d\n", books[i].yearPublished);
        fprintf(reportFile, "Quantity: %d\n", books[i].quantity);
        
        // Logical check for availability status
        if (books[i].quantity > 0) {
            fprintf(reportFile, "Availability Status: Available\n");
        } else {
            fprintf(reportFile, "Availability Status: Out of Stock\n");
        }
        
        fprintf(reportFile, "----------------------------\n");
    }

    fclose(reportFile);
    printf("\n[Success] Inventory report generated in 'inventory_report.txt'.\n");
}
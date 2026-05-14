#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filehandling.h"
#include "books.h"

#define BOOKS_FILE "books.txt"

// FEATURE: Load books from the text file into an array
void loadBooks(Book books[], int *count) {
    FILE *fp = fopen(BOOKS_FILE, "r");
    if (!fp) {
        // If file doesn't exist, create it and return count 0
        fp = fopen(BOOKS_FILE, "w");
        if (fp) fclose(fp);
        *count = 0;
        return;
    }

    char line[256];
    int i = 0;

    // Matches format: BookID,Title,Author,Genre,Year,Quantity
    while (fgets(line, sizeof(line), fp) && i < MAX_BOOKS) {
        line[strcspn(line, "\n")] = 0; // Remove trailing newline
        
        if (strlen(line) < 5) continue; // Skip empty lines

        // Using comma as delimiter per original requirements
        int parsed = sscanf(line, " %[^,],%[^,],%[^,],%[^,],%d,%d", 
                            books[i].id, 
                            books[i].title, 
                            books[i].author, 
                            books[i].genre, 
                            &books[i].yearPublished, 
                            &books[i].quantity);
        
        if (parsed == 6) {
            i++;
        }
    }
    *count = i;
    fclose(fp);
}

// FEATURE: Save the current book array back to the text file
void saveBooks(Book books[], int count) {
    FILE *fp = fopen(BOOKS_FILE, "w");
    if (!fp) {
        printf("[Error] Could not open %s for writing!\n", BOOKS_FILE);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%s,%s,%s,%d,%d\n", 
                books[i].id, 
                books[i].title, 
                books[i].author, 
                books[i].genre, 
                books[i].yearPublished, 
                books[i].quantity);
    }
    fclose(fp);
}

// FEATURE: Generate a human-readable inventory report
void generateInventoryReport() {
    Book books[MAX_BOOKS];
    int count = 0;
    loadBooks(books, &count); // Get latest data

    FILE *reportFile = fopen("inventory_report.txt", "w");
    if (reportFile == NULL) {
        printf("\n[Error] Could not create the inventory report file!\n");
        return;
    }

    fprintf(reportFile, "--- LIBRARY INVENTORY REPORT ---\n");
    fprintf(reportFile, "Generated on: 2026-05-14\n\n");

    for (int i = 0; i < count; i++) {
        fprintf(reportFile, "BookID: %s\n", books[i].id);
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
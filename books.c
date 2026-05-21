#include <stdio.h>
#include <string.h>
#include "books.h"

Book inventory[100];
int bookCount = 0;

void loadBooks() {
    FILE *file = fopen("books.txt", "r");
    if (!file) return;
    bookCount = 0;
    while (fscanf(file, "%d, %[^,], %[^,], %[^,], %d, %d\n", 
           &inventory[bookCount].id, inventory[bookCount].title, 
           inventory[bookCount].author, inventory[bookCount].genre, 
           &inventory[bookCount].year, &inventory[bookCount].quantity) != EOF) {
        bookCount++;
    }
    fclose(file);
}

void saveBooks() {
    FILE *file = fopen("books.txt", "w");
    for (int i = 0; i < bookCount; i++) {
        fprintf(file, "%d, %s, %s, %s, %d, %d\n", 
                inventory[i].id, inventory[i].title, inventory[i].author, 
                inventory[i].genre, inventory[i].year, inventory[i].quantity);
    }
    fclose(file);
}

void displayAllBooks() {
    printf("\n%-5s %-25s %-20s %-5s\n", "ID", "Title", "Author", "Qty");
    for (int i = 0; i < bookCount; i++) {
        printf("%-5d %-25s %-20s %-5d\n", inventory[i].id, inventory[i].title, inventory[i].author, inventory[i].quantity);
    }
}

void searchBook() {
    char searchTerm[100];
    int found = 0;

    printf("\nEnter Title or Author to search: ");
    getchar(); // Clear the buffer from the menu input
    fgets(searchTerm, 100, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline

    printf("\n--- Search Results ---\n");
    printf("%-5s %-25s %-20s %-5s\n", "ID", "Title", "Author", "Qty");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < bookCount; i++) {
        // strcasestr is a common non-standard extension. 
        // If it fails to compile, use strstr for case-sensitive search:
        if (strstr(inventory[i].title, searchTerm) != NULL || 
            strstr(inventory[i].author, searchTerm) != NULL) {
            
            printf("%-5d %-25s %-20s %-5d\n", 
                   inventory[i].id, inventory[i].title, 
                   inventory[i].author, inventory[i].quantity);
            found = 1;
        }
    }

    if (!found) {
        printf("No books found matching '%s'.\n", searchTerm);
    }
    printf("------------------------------------------------------------\n");
}

void addBook() {
    Book b;
    printf("Enter Book ID: "); scanf("%d", &b.id);
    getchar(); // flush newline
    printf("Title: "); fgets(b.title, 100, stdin); b.title[strcspn(b.title, "\n")] = 0;
    printf("Author: "); fgets(b.author, 100, stdin); b.author[strcspn(b.author, "\n")] = 0;
    printf("Genre: "); scanf("%s", b.genre);
    printf("Year: "); scanf("%d", &b.year);
    printf("Quantity: "); scanf("%d", &b.quantity);
    
    inventory[bookCount++] = b;
    saveBooks();
    printf("Book added successfully!\n");
}

void updateQuantity() {
    int id, newQty, found = 0;
    printf("Enter Book ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (inventory[i].id == id) {
            printf("Current Quantity: %d. Enter new Quantity: ", inventory[i].quantity);
            scanf("%d", &newQty);
            inventory[i].quantity = newQty;
            found = 1;
            break;
        }
    }

    if (found) {
        saveBooks(); // Persist changes to books.txt
        printf("Quantity updated successfully!\n");
    } else {
        printf("Book ID %d not found.\n", id);
    }
}
void generateInventoryReport() {
    FILE *f = fopen("inventory_report.txt", "w");
    for (int i = 0; i < bookCount; i++) {
        fprintf(f, "BookID: %03d\nTitle: %s\nAuthor: %s\nGenre: %s\nYear Published: %d\nQuantity: %d\nAvailability Status: %s\n----------------------------\n",
                inventory[i].id, inventory[i].title, inventory[i].author, inventory[i].genre, 
                inventory[i].year, inventory[i].quantity, (inventory[i].quantity > 0 ? "Available" : "Out of Stock"));
    }
    fclose(f);
    printf("Report generated: inventory_report.txt\n");
}
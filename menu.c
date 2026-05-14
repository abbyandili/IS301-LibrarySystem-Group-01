#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "books.h"

void displayMenu() {
    printf("\n--- Library Management System ---\n");
    printf("1. Display All Books\n");
    printf("2. Search for a Book\n");
    printf("3. Add New Book\n");
    printf("4. Update Quantity\n");
    printf("5. Generate Inventory Report\n");
    printf("6. Exit\n");
    printf("Choice: ");
}

void handleChoice(int choice) {
    switch(choice) {
        case 1: displayAllBooks(); break;
        case 3: addBook(); break;
        case 5: generateInventoryReport(); break;
        case 6: exit(0);
        default: printf("Option under development or invalid.\n");
    }
}
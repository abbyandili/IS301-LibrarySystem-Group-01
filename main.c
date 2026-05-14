#include <stdio.h>
#include "auth.h"
#include "menu.h"
#include "books.h"
#include "members.h"

// This actually allocates the memory
Member members[MAX_MEMBERS]; 
int memberCount = 0; 

int main() {
    // Your menu logic here...
    return 0;
}

int main() {
    loadBooks();
    
    if (!login()) return 0;

    int choice;
    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) break;
        handleChoice(choice);
    }

    return 0;
}
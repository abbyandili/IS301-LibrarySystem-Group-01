#include <stdio.h>
#include <string.h>
#include "members.h"

void viewMembers(void) {
    // ... (Your code from above)
}

void registerMember(void) {
    // ... (Your code from above)
}

// Ensure members[] and memberCount are declared as 'extern' in members.h
// and defined in a .c file to avoid "undefined reference" errors.

void viewMembers(void) {
    printDoubleSep();
    printf("           MEMBER LIST\n");
    printDoubleSep();

    if (memberCount == 0) {
        printf("  No members registered.\n");
        return;
    }

    for (int i = 0; i < memberCount; i++) {
        printf("  [%d]\n", i + 1);
        printMember(&members[i]);
    }
    printf("  Total members: %d\n", memberCount);
}

void registerMember(void) {
    // Check for array overflow before registering
    if (memberCount >= MAX_MEMBERS) {
        printf("Error: Member limit reached!\n");
        return;
    }

    Member newMember;

    printf("Enter ID: ");
    if (scanf("%d", &newMember.memberID) != 1) {
        printf("Invalid ID input.\n");
        while(getchar() != '\n'); // Clear buffer
        return;
    }

    printf("Enter Name: ");
    // %[^\n] consumes the newline; the space before % handles leading whitespace
    scanf(" %[^\n]", newMember.name); 

    printf("Enter Contact: ");
    scanf("%19s", newMember.contact); // Assuming contact buffer is size 20

    // 1. Save to the persistent file
    saveMemberToFile(newMember); 

    // 2. IMPORTANT: Update the in-memory array and counter
    members[memberCount] = newMember;
    memberCount++;

    printf("Member Registered Successfully!\n");
}

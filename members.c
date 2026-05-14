#include <stdio.h>
#include "members.h"
#include <string.h>


// Ensure your global variables or struct arrays are accessible here
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

void registerMember() {
    Member newMember;
    printf("Enter ID: "); scanf("%d", &newMember.memberID);
    printf("Enter Name: "); scanf(" %[^\n]s", newMember.name);
    printf("Enter Contact: "); scanf("%s", newMember.contact);

    // Call a function from filehandling.c to save this to members.txt
    saveMemberToFile(newMember); 
    printf("Member Registered Successfully!\n");
}

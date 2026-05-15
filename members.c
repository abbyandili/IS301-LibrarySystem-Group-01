#include <stdio.h>
#include <string.h>
#include "members.h"

// 1. ALLOCATE MEMORY: These must be defined here to solve "undefined reference"
Member members[MAX_MEMBERS]; 
int memberCount = 0;

// 2. HELPER FUNCTIONS: Implement the functions the linker is looking for
void printDoubleSep() {
    printf("============================================\n");
}

void printMember(Member *m) {
    printf("  ID: %d\n", m->memberID);
    printf("  Name: %s\n", m->name);
    printf("  Contact: %s\n", m->contact);
    printf("--------------------------------------------\n");
}

void saveMemberToFile(Member m) {
    FILE *fp = fopen("members.txt", "a"); // 'a' for append
    if (fp == NULL) {
        printf("[ERROR] Could not open members.txt for writing.\n");
        return;
    }
    fprintf(fp, "%d,%s,%s\n", m.memberID, m.name, m.contact);
    fclose(fp);
}

// 3. MAIN FUNCTIONS
void viewMembers(void) {
    printDoubleSep();
    printf("           MEMBER LIST\n");
    printDoubleSep();

    if (memberCount == 0) {
        printf("  No members registered in memory.\n");
        return;
    }

    for (int i = 0; i < memberCount; i++) {
        printf("  [%d]\n", i + 1);
        printMember(&members[i]);
    }
    printf("  Total members: %d\n", memberCount);
}

void registerMember(void) {
    if (memberCount >= MAX_MEMBERS) {
        printf("Error: Member limit reached!\n");
        return;
    }

    Member newMember;

    printf("Enter ID: ");
    if (scanf("%d", &newMember.memberID) != 1) {
        printf("Invalid ID input.\n");
        while(getchar() != '\n'); 
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", newMember.name); 

    printf("Enter Contact: ");
    scanf("%19s", newMember.contact); 

    // Save to file
    saveMemberToFile(newMember); 

    // Update memory
    members[memberCount] = newMember;
    memberCount++;

    printf("Member Registered Successfully!\n");
}
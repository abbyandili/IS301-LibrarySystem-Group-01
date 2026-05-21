
#include <stdio.h>
#include <string.h>
#include "members.h"

Member members[MAX_MEMBERS]; 
int memberCount = 0;

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
    FILE *fp = fopen("members.txt", "a"); 
    if (fp == NULL) {
        printf("[ERROR] Could not open members.txt for writing.\n");
        return;
    }
    fprintf(fp, "%d,%s,%s\n", m.memberID, m.name, m.contact);
    fclose(fp);
}

// Function to save completely modified array contents state back to storage file
void rewriteAllMembersFile() {
    FILE *fp = fopen("members.txt", "w"); 
    if (fp == NULL) return;
    for (int i = 0; i < memberCount; i++) {
        fprintf(fp, "%d,%s,%s\n", members[i].memberID, members[i].name, members[i].contact);
    }
    fclose(fp);
}

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

    saveMemberToFile(newMember); 

    members[memberCount] = newMember;
    memberCount++;

    printf("Member Registered Successfully!\n");
}

// New requirement integration implementation
void updateMemberInfo(void) {
    int targetID, found = 0;
    printf("\n--- Update Member Information ---\n");
    printf("Enter Member ID: ");
    if (scanf("%d", &targetID) != 1) {
        while(getchar() != '\n');
        return;
    }

    for (int i = 0; i < memberCount; i++) {
        if (members[i].memberID == targetID) {
            found = 1;
            printf("Current Name: %s\n", members[i].name);
            printf("Enter New Name: ");
            scanf(" %[^\n]", members[i].name);

            printf("Current Contact: %s\n", members[i].contact);
            printf("Enter New Contact: ");
            scanf("%19s", members[i].contact);
            
            rewriteAllMembersFile();
            printf("\nSuccess: Member information updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nError: Member profile with ID %d was not found in cache.\n", targetID);
    }
}


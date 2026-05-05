#include <stdio.h>
#include <string.h>
#include "members.h"

void registerMember() {
    Member newMember;
    printf("Enter ID: "); scanf("%d", &newMember.memberID);
    printf("Enter Name: "); scanf(" %[^\n]s", newMember.name);
    printf("Enter Contact: "); scanf("%s", newMember.contact);

    // Call a function from filehandling.c to save this to members.txt
    saveMemberToFile(newMember); 
    printf("Member Registered Successfully!\n");
}

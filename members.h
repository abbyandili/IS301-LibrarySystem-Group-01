#ifndef MEMBERS_H
#define MEMBERS_H

typedef struct {
    int memberID;
    char name[50];
    char contact[20];
} Member;

// Function Prototypes
void registerMember();
void viewMemberDetails(int memberID);

#endif

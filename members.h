
#ifndef MEMBERS_H
#define MEMBERS_H

#define MAX_MEMBERS 100

typedef struct {
    int memberID;
    char name[50];
    char contact[20];
} Member;

extern Member members[MAX_MEMBERS];
extern int memberCount;

void printDoubleSep(void);
void printMember(Member *m);
void saveMemberToFile(Member m);
void viewMembers(void);
void registerMember(void);
void updateMemberInfo(void); // Added missing feature prototype

#endif
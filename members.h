#ifndef MEMBERS_H
#define MEMBERS_H

#define MAX_MEMBERS 100

// The blueprint for every member in the system
typedef struct {
    char memberID[10];  // Changed to string for consistency with Book IDs (e.g., "M001")
    char name[100];
    char contact[50];
} Member;

/* 
   Function Prototypes 
   These match the functional requirements in Section 3 
*/

// Register a new member
void registerMember();

// List all registered members
void viewMembers();

// Search and display details for a specific member
void viewMemberDetails();

// Update existing member information
void updateMemberInfo();

#endif /* MEMBERS_H */
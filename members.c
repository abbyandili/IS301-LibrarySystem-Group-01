#include <stdio.h>
#include "members.h"

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
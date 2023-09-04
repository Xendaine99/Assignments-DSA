#include <stdio.h>

int main() {
    char *names[] = {
        "Alice",
        "Bob",
        "Charlie",
        "David"
    };
    int numNames = sizeof(names) / sizeof(names[0]);
    printf("List of names:\n");
    for (int i = 0; i < numNames; i++) {
        printf("Name %d: %s\n", i + 1, names[i]);
    }
    return 0;
}

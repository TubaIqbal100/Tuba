#include <stdio.h>
#include <stdlib.h> /* Required for malloc and free */

struct Student {
    char name[50];
    int age;
};

int main() {
    struct Student *ptr; /* Pointer declaration */
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    /* Dynamic Memory Allocation */
    ptr = (struct Student*) malloc(n * sizeof(struct Student));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter name and age for student %d: ", i + 1);
        /* Using pointer arithmetic or arrow operator */
        scanf("%s %d", (ptr + i)->name, &(ptr + i)->age);
    }

    printf("\nDisplaying Information:\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s\tAge: %d\n", (ptr + i)->name, (ptr + i)->age);
    }

    /* Important: Always free dynamically allocated memory */
    free(ptr);

    return 0;
}


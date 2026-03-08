/*cprogram to remove all vowels from the string*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], result[100];
    int i, j = 0;
    printf("Enter a string: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    printf("String after removing vowels: %s\n", result);
    return 0;
}


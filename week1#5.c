#include <stdio.h>
#include <string.h>

void test_addition() {
    char str1[50] = "Hello";
    char str2[50] = "World";
    char result[100];

    strcpy(result, str1);
    strcat(result, str2);
    printf("Addition (\"Hello\" + \"World\"): %s\n", result);

    strcpy(str1, "");
    strcpy(result, str1);
    strcat(result, str2);
    printf("Addition (Empty + \"World\"): %s\n", result);

    strcpy(str2, "");
    strcpy(str1, "Hello");
    strcpy(result, str1);
    strcat(result, str2);
    printf("Addition (\"Hello\" + Empty): %s\n", result);
}

void test_copying() {
    char source[50] = "Copied!";
    char destination[50];

    strcpy(destination, source);
    printf("Copy non-empty to empty: %s\n", destination);

    strcpy(source, "");
    strcpy(destination, source);
    printf("Copy empty string: \"%s\"\n", destination);
}

void test_reverse() {
    char str[50] = "abcd";
    char reversed[50];
    int i, len;

    len = strlen(str);
    for (i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
    printf("Reverse of \"abcd\": %s\n", reversed);

    strcpy(str, "a");
    len = strlen(str);
    for (i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
    printf("Reverse of \"a\": %s\n", reversed);
}

void test_length() {
    char str1[50] = "";
    char str2[50] = "Hello";

    printf("Length of \"\": %d\n", strlen(str1));
    printf("Length of \"Hello\": %d\n", strlen(str2));
}

int main() {
    printf("=== String Function Tests ===\n\n");

    test_addition();
    printf("\n");

    test_copying();
    printf("\n");

    test_reverse();
    printf("\n");

    test_length();
    printf("\n");

    return 0;
}


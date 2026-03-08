#include <stdio.h>
#include <string.h>

int main() {
    char input[256];
    char word[50];
    char result[256];
    int i, j, k, len, start;

    result[0] = '\0';  /* initialize result string */

    printf("Enter string: ");
    fgets(input, sizeof(input), stdin);

    /* remove newline manually */
    len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    printf("Enter word to remove: ");
    scanf("%s", word);

    i = 0;
    while (input[i] != '\0') {
        /* skip leading spaces */
        while (input[i] == ' ') {
            i++;
        }

        if (input[i] == '\0') break;

        /* mark start of word */
        start = i;

        /* find end of word */
        while (input[i] != ' ' && input[i] != '\0') {
            i++;
        }

        /* copy word into temp */
        char temp[50];
        j = 0;
        for (k = start; k < i; k++) {
            temp[j++] = input[k];
        }
        temp[j] = '\0';

        /* compare with word to remove */
        if (strcmp(temp, word) != 0) {
            strcat(result, temp);
            
        }
    }

    /* remove trailing space */
    len = strlen(result);
    if (len > 0 && result[len - 1] == ' ') {
        result[len - 1] = '\0';
    }

    printf("Result: %s\n", result);
    return 0;
}


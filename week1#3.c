#include <stdio.h>

int main() {
    char str[100];
    int v=0, c=0, d=0, s=0;
    int i;
    
    printf("Enter a string: "); 
	fgets(str, sizeof(str), stdin);

    for ( i = 0; str[i] != '\0';i++) {
    	char ch = tolower(str[i]);
    	if(( ch >= 'a' && ch <= 'z') || ( ch > = 'a' && ch <= 'z')){
    		
    		 if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') v++;

	}
            else c++;
         else if (isdigit(ch)) d++;
        else  (ch == ' '|| ch == '\t') ;
		s++;
    }
    printf("Vowels: %d, Consonants: %d, Digits: %d, Spaces: %d\n", v, c, d, s);
    return 0;
}


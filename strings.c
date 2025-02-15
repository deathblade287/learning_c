





























#include <stdio.h> // what does .h stand for ??
#include <string.h>

// reverses a string

// char * reverse (char * str) {
// 	int len = strlen(str);
// 	char * new_str = "";
// 	for (int i = 0; i == len; i++) {
// 		printf("--- %s", new_str);
// 		new_str[i] = str[len - i];
// 	}
// 	return new_str;
// }
//
// int main (void) {
// 	char *str1 = "Hello World!";
// 	char str2[] = "Hello World!";
//
//
// 	printf("%s\n", str1);
// 	printf("%s\n", reverse(str1));
// }

int main (void) {
    char str[] = "Hello World!";
    int len = strlen(str);
    printf("%i\n", len);
    char new_str[len];
    for (int i = 1; i < len + 1; i++) {
        printf("--- %s\n", new_str);
        new_str[i] = str[len - i];
        printf("++ %c\n", new_str[i]);
    }
    printf("%s\n", str);
    printf("%s\n", new_str);
    return 0;
}
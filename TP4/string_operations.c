#include <stdio.h>

int main()
{
    char str1[200], str2[200];
    int i, j, count = 0;
    
    printf("Enter first string(max of 200 characters): ");
    fgets(str1, sizeof(str1), stdin);

    for (i = 0; str1[i] != '\0'; i++);
    printf("%c", str1[i]); // to check the last character before null terminator
    return 0;
}
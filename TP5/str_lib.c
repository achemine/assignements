#include <stdio.h>

// function's prototypes
int my_strlen(char *str);
void my_strcpy(char *dest, char *src);
void my_strcat(char *dest, char *src);
int my_strcmp(char *str1, char *str2);
void my_strrev(char *str);

// main code
int main()
{
    char s1[200], s2[200], dest[400];
    // getting s1 and s2 from user input
    printf(" Enter string 1: ");
    fgets(s1, 200, stdin);
    s1[my_strlen(s1) - 1] = '\0';

    printf(" Enter string 2: ");
    fgets(s2, 200, stdin);
    s2[my_strlen(s2) - 1] = '\0';

    // first functions testing
    printf("\n=== my_strlen ===\n");
    printf(" Length of \"% s \": %d\n", s1, my_strlen(s1));
    printf(" Length of \"% s \": %d\n", s2, my_strlen(s2));

    // second functions testing
    printf("\n=== my_strcpy ===\n");
    my_strcpy(dest, s1);
    printf(" Copied : \"% s\"\n", dest);

    // third functions testing
    printf("\n=== my_strcat ===\n");
    my_strcpy(dest, s1);  // start fresh with a copy of s1
    my_strcat(dest, " "); // append a space
    my_strcat(dest, s2);  // append s2
    printf(" Concatenated : \"% s \"\n", dest);

    // fourth functions testing
    printf("\n=== my_strcmp ===\n");
    int cmp = my_strcmp(s1, s2);
    if (cmp == 0)
        printf(" \"% s\" == \"% s \"\n", s1, s2);
    else if (cmp > 0)
        printf(" \"% s\" > \"% s \"\n", s1, s2);
    else
        printf(" \"% s\" < \"% s \"\n", s1, s2);

    // fifth functions testing
    printf("\n=== my_strrev ===\n");
    my_strcpy(dest, s1); // work on a copy to keep s1 unchanged
    my_strrev(dest);
    printf(" Reversed \"% s \": \"% s \"\n", s1, dest);
    return 0;
}

// function's definitions:
// phase 1:
int my_strlen(char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

// phase 2
void my_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// phase 3
void my_strcat(char *dest, char *src)
{
    int dest_len = my_strlen(dest);
    int i = 0;
    while (src[i] != '\0')
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
}

// phase 4
int my_strcmp(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
        i++;
    }
    return 0;
}

// phase 5
void my_strrev(char *str)
{
    int j = my_strlen(str);
    for (int i = 0; i < j / 2; i++)
    {
        char temp = str[i];
        str[i] = str[j - i - 1];
        str[j - i - 1] = temp;
    }
}
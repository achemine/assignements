#include <stdio.h>

#define MAX 200

int main() {
    // declaring variablies and getting user's input
    char str[MAX], copy[MAX], cleaned[MAX], temp[MAX];
    int choice, len = 0;

    printf("Enter a string (max 200 characters): ");
    fgets(str, MAX, stdin);


    // Menu loop
    do {
        printf("\n=== MENU ===\n");
        printf("1. Calculate string length\n");
        printf("2. Copy string\n");
        printf("3. Count vowels\n");
        printf("4. Clean string from symbols\n");
        printf("5. Check if palindrome\n");
        printf("0. Exit\n");
        printf("Choose operation: ");
        scanf("%d", &choice);
        getchar(); /* clear newline */

        // Perform operation based on user's choice
        switch (choice) {

            /* 1. String length */
            case 1: {
                
                while (str[len] != '\0')
                    len++;
                printf("String length: %d characters\n", len);
                break;
            }

            /* 2. String copy */
            case 2: {
                int i = 0;
                while (str[i] != '\0') {
                    copy[i] = str[i];
                    i++;
                }
                copy[i] = '\0';

                printf("Original string: %s", str);
                printf("Copied string: %s", copy);
                break;
            }

            /* 3. Count vowels */
            case 3: {
                int vowels = 0,
                char c;

                for (int i = 0; str[i] != '\0'; i++) 
                {
                    if ( c == 'a' || c == 'e' || c == 'i' ||
                        c == 'o' || c == 'u')
                        vowels++;
                }

                printf("Vowel count: %d\n", vowels);
                printf("Percentage of vowels: %.2f%%\n",(vowels * 100.0) / len);
                break;
            }

            /* 4. Clean string */
            case 4: {
                int j = 0;
                for (int i = 0; str[i] != '\0'; i++) {
                    if ((str[i] >= 'A' && str[i] <= 'Z') ||
                        (str[i] >= 'a' && str[i] <= 'z') ||
                        (str[i] >= '0' && str[i] <= '9') ||
                        str[i] == ' ') {
                        cleaned[j++] = str[i];
                    }
                }
                cleaned[j] = '\0';

                printf("Original string: %s", str);
                printf("Cleaned string: %s\n", cleaned);
                break;
            }

            /* 5. Palindrome check */
            case 5: {
                int j = 0;

                for (int i = 0; str[i] != '\0'; i++) {
                    if ((str[i] >= 'A' && str[i] <= 'Z') ||
                        (str[i] >= 'a' && str[i] <= 'z') ||
                        (str[i] >= '0' && str[i] <= '9')) {

                        char c = str[i];
                        if (c >= 'A' && c <= 'Z')
                            c = c + 32;

                        temp[j++] = c;
                    }
                }
                temp[j] = '\0';

                int left = 0, right = j - 1, palindrome = 1;
                while (left < right) {
                    if (temp[left] != temp[right]) {
                        palindrome = 0;
                        break;
                    }
                    left++;
                    right--;
                }

                printf("Original string: %s", str);
                if (palindrome)
                    printf("This IS a palindrome!\n");
                else
                    printf("This is NOT a palindrome.\n");
                break;
            }

            case 0:
                printf("Thank you for using the program!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}

#include <stdio.h>

int main()
{
    /*we declare a variable to store the number of photocopies*/
    int photocopys;
    printf("Enter the number of photocopys you want to make: ");
    scanf("%d", &photocopys);

    /*we use an if statment to find which of the 3 cases is ideal for the customer then calculate and display the prize*/
    if (photocopys <= 10)
    {
        printf("The total cost is: %i", (photocopys * 2));
    }
    else if (photocopys > 10 && photocopys <= 30)
    {
        printf("The total cost is: %.2f", ((photocopys - 10) * 1.5 + 20));
    }
    else
    {
        printf("The total cost is: %d", ((photocopys - 30) + 20 + 30));
    }
}
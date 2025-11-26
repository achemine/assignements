#include <stdio.h>

int main()
{
    /*we declare 3 boolean variables to store the status of ambulance, traffic, and daytime*/
    int ambulance, traffic, daytime;
    printf("Is there an ambulance?(1 for yes, 0 for no) : ");
    scanf("%d", &ambulance);
    printf("Is there traffic?(1 for yes, 0 for no) : ");
    scanf("%d", &traffic);
    printf("Is it daytime?(1 for yes, 0 for no) : ");
    scanf("%d", &daytime);

    /*we verify that the user entered the correct values for ambulance, traffic, and daytime*/
    if ((ambulance != 0 && ambulance != 1) || (traffic != 0 && traffic != 1) || (daytime != 0 && daytime != 1))
    {
        printf("Invalid input detected. Please enter 1 for yes or 0 for no.");
        return 1;
    }

    /*we use if statements to determine the color of the city light based on the status of ambulance, traffic, and daytime*/
    if (ambulance == 1)
    {
        printf("Ambulance detected ! Turning light GREEN immediately");
    }
    else if (traffic == 1)
    {
        if (daytime == 1)
        {
            printf("due to heavy traffic GREEN light will be extended.");
        }
        else
        {
            printf("switching to blink mode due to traffic at night.");
        }
    }
    else if (daytime == 1)
    {
        printf("no intureptions, the city light will continue operating normaly.");
    }
    else
    {
        printf("turning The city light yellow for caution at night.");
    }
    return 0;
}
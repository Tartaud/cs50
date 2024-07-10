#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    //Asks the height until it is between 1 and 8 (inclusive) 
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //Constructs the pyramid
    for (int i = 0; i < height; i++)
    {

        for (int j = height - i - 1; j > 0; j--)
        {
            printf(" ");
        }

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
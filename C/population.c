#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startSize;
    int endSize;
    int lamaNumber;
    int years = 0;

    // TODO: Prompt for start size
    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    do
    {
        endSize = get_int("End size: ");
    }
    while (startSize > endSize);

    // TODO: Calculate number of years until we reach threshold
    lamaNumber = startSize;
    while (lamaNumber < endSize)
    {
        lamaNumber = lamaNumber + lamaNumber / 3 - lamaNumber / 4;
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
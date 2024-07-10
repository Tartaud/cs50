#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

int main(int argc, char *argv[])
{

    int numberFile = 0;

    if (argc > 2)
    {
        printf("Usage : ./recover image");
        return 1;
    }

    FILE *image = fopen(argv[1], "r");
    if (image == NULL)
    {
        printf("Could not open %s.\n",  argv[1]);
        return 1;
    }

    uint8_t byte[512];
    FILE *output;

    while (fread(&byte, sizeof(uint8_t), 512, image) == 512)
    {
        if (byte[0] == 0xff && byte[1] == 0xd8 && byte[2] == 0xff && (byte[3] & 0xf0) == 0xe0)
        {
            if (numberFile == 0)
            {
                string filename = "000.jpg";
                output = fopen(filename, "w");
                numberFile++;
            }
            else
            {
                char filename[7];
                fclose(output);
                sprintf(filename, "%03i.jpg", numberFile);
                output = fopen(filename, "w");
                numberFile++;
            }
        }

        if (output != NULL)
        {
            fwrite(&byte, sizeof(uint8_t), 512, output);
        }
    }

    fclose(image);
}
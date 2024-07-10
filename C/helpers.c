#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE widthPixels[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            widthPixels[i][j] = image[i][width - j - 1];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = widthPixels[i][j];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int n = 0;
            int averageBlue = 0;
            int averageGreen = 0;
            int averageRed = 0;

            for (int a = (i - 1); a <= (i + 1); a++)
            {
                for (int b = (j - 1); b <= (j + 1); b++)
                {
                    if (a < height && a >= 0 && b >= 0 && b < width)
                    {
                        n++;
                        averageBlue += image[a][b].rgbtBlue;
                        averageGreen += image[a][b].rgbtGreen;
                        averageRed += image[a][b].rgbtRed;
                    }
                }
            }

            averageBlue = round(averageBlue / (float)n);
            averageGreen = round(averageGreen / (float)n);
            averageRed = round(averageRed / (float)n);

            newImage[i][j].rgbtBlue = averageBlue;
            newImage[i][j].rgbtGreen = averageGreen;
            newImage[i][j].rgbtRed = averageRed;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = newImage[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int averageBlue = 0;
            int averageGreen = 0;
            int averageRed = 0;

            int averageBlueX = 0;
            int averageGreenX = 0;
            int averageRedX = 0;
            int multiplierX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

            int averageBlueY = 0;
            int averageGreenY = 0;
            int averageRedY = 0;
            int multiplierY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

            for (int a = i - 1; a <= i + 1; a++)
            {
                for (int b = j - 1; b <= j + 1; b++)
                {
                    if (a < height && a >= 0 && b >= 0 && b < width)
                    {
                        averageBlueX += image[a][b].rgbtBlue * multiplierX[(a - i) + 1][(b - j) + 1];
                        averageGreenX += image[a][b].rgbtGreen * multiplierX[(a - i) + 1][(b - j) + 1];
                        averageRedX += image[a][b].rgbtRed * multiplierX[(a - i) + 1][(b - j) + 1];

                        averageBlueY += image[a][b].rgbtBlue * multiplierY[(a - i) + 1][(b - j) + 1];
                        averageGreenY += image[a][b].rgbtGreen * multiplierY[(a - i) + 1][(b - j) + 1];
                        averageRedY += image[a][b].rgbtRed * multiplierY[(a - i) + 1][(b - j) + 1];
                    }
                }
            }

            averageBlue = round(sqrt(pow(averageBlueX, 2) + pow(averageBlueY, 2)));
            averageGreen = round(sqrt(pow(averageGreenX, 2) + pow(averageGreenY, 2)));
            averageRed = round(sqrt(pow(averageRedX, 2) + pow(averageRedY, 2)));

            if (averageBlue > 255)
            {
                averageBlue = 255;
            }
            if (averageRed > 255)
            {
                averageRed = 255;
            }
            if (averageGreen > 255)
            {
                averageGreen = 255;
            }
            if (averageBlue < 0)
            {
                averageBlue = 0;
            }
            if (averageRed < 0)
            {
                averageRed = 0;
            }
            if (averageGreen < 0)
            {
                averageGreen = 0;
            }

            newImage[i][j].rgbtBlue = averageBlue;
            newImage[i][j].rgbtGreen = averageGreen;
            newImage[i][j].rgbtRed = averageRed;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = newImage[i][j];
        }
    }
    return;
}

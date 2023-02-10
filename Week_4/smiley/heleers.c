#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for(int imageHeight = 0; imageHeight < height; imageHeight++)
    {
        for(int imageWidth = 0; imageWidth < width; imageWidth++)
        {
            if (image[imageHeight][imageWidth].rgbtBlue == 0 && image[imageHeight][imageWidth].rgbtGreen == 0 && image[imageHeight][imageWidth].rgbtRed == 0 )
            {
                image[imageHeight][imageWidth].rgbtBlue = 157;
                image[imageHeight][imageWidth].rgbtGreen = 1;
                image[imageHeight][imageWidth].rgbtRed = 1;
            }
        }
    }
}

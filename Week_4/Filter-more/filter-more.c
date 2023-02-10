#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int imageHeight = 0; imageHeight < height; imageHeight++)
    {
        for(int imageWidth = 0; imageWidth < width; imageWidth++)
        {
            float blue = image[imageHeight][imageWidth].rgbtBlue;
            float green = image[imageHeight][imageWidth].rgbtGreen;
            float red = image[imageHeight][imageWidth].rgbtRed;
            int grayScale =  round((blue + green + red)/3);
            image[imageHeight][imageWidth].rgbtBlue = grayScale;
            image[imageHeight][imageWidth].rgbtGreen = grayScale;
            image[imageHeight][imageWidth].rgbtRed = grayScale;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for(int imageHeight = 0; imageHeight < height; imageHeight++)
    {
        for(int imageWidth = 0; imageWidth < width / 2; imageWidth++)
        {
            RGBTRIPLE temp = image[imageHeight][imageWidth];
            image[imageHeight][imageWidth] = image[imageHeight][width-(imageWidth+1)];
            image[imageHeight][width-(imageWidth+1)] = temp;


        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }


    for(int imageHeight = 0; imageHeight < height; imageHeight++)
    {
        for(int imageWidth = 0; imageWidth < width; imageWidth++)
        {
            float sum_red = 0;
            float sum_blue = 0;
            float sum_green = 0;
            int counter = 0;

            for (int blurHeight = -1; blurHeight < 2; blurHeight++)
            {
                for (int blurWidth = -1; blurWidth < 2; blurWidth++)
                {
                    if(imageHeight + blurHeight < 0 || imageHeight + blurHeight >= height)
                    {
                        continue;
                    }

                    if(imageWidth + blurWidth < 0 || imageWidth + blurWidth >= width)
                    {
                        continue;
                    }

                    sum_red += temp[imageHeight + blurHeight][imageWidth + blurWidth].rgbtRed;
                    sum_blue += temp[imageHeight + blurHeight][imageWidth + blurWidth].rgbtBlue;
                    sum_green += temp[imageHeight + blurHeight][imageWidth + blurWidth].rgbtGreen;
                    counter++;

                }
            }
            image[imageHeight][imageWidth].rgbtBlue = round(sum_blue / counter);
            image[imageHeight][imageWidth].rgbtGreen = round(sum_green / counter);
            image[imageHeight][imageWidth].rgbtRed = round(sum_red / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int gX[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
    int gY[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};


    for(int imageHeight = 0; imageHeight < height; imageHeight++)
    {
        for(int imageWidth = 0; imageWidth < width; imageWidth++)
        {
            int gXsumRed = 0;
            int gYsumRed = 0;
            int gXsumGreen = 0;
            int gYsumGreen = 0;
            int gXsumBlue = 0;
            int gYsumBlue = 0;

            for (int blurHeight = -1; blurHeight < 2; blurHeight++)
            {
                for (int blurWidth = -1; blurWidth < 2; blurWidth++)
                {
                    if(imageHeight + blurHeight < 0 || imageHeight + blurHeight >= height)
                    {
                        continue;
                    }

                    if(imageWidth + blurWidth < 0 || imageWidth + blurWidth >= width)
                    {
                        continue;
                    }

                    gXsumRed += temp[imageHeight + blurHeight][imageWidth + blurWidth].rgbtRed * gX[blurHeight+1][blurWidth+1];
                    gYsumRed += temp[imageHeight + blurHeight][imageWidth + blurWidth].rgbtRed * gY[blurHeight+1][blurWidth+1];

                    gXsumGreen += temp[imageHeight + blurHeight][imageWidth + blurWidth].rgbtGreen * gX[blurHeight+1][blurWidth+1];
                    gYsumGreen += temp[imageHeight + blurHeight][imageWidth + blurWidth].rgbtGreen * gY[blurHeight+1][blurWidth+1];

                    gXsumBlue += temp[imageHeight + blurHeight][imageWidth + blurWidth].rgbtBlue * gX[blurHeight+1][blurWidth+1];
                    gYsumBlue += temp[imageHeight + blurHeight][imageWidth + blurWidth].rgbtBlue * gY[blurHeight+1][blurWidth+1];


                }
            }
            int red = round(sqrt(gXsumRed*gXsumRed+gYsumRed*gYsumRed));
            int green = round(sqrt(gXsumGreen*gXsumGreen+gYsumGreen*gYsumGreen));
            int blue = round(sqrt(gXsumBlue*gXsumBlue+gYsumBlue*gYsumBlue));

            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            image[imageHeight][imageWidth].rgbtRed = red;
            image[imageHeight][imageWidth].rgbtGreen = green;
            image[imageHeight][imageWidth].rgbtBlue = blue;
        }
    }



    return;
}

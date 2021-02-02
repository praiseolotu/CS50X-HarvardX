#include "helpers.h"
#include <math.h>
// I included this since we are going to work with rounding numbers
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int row, col;
    for (row = 0; row < height; row++) //Iterate through the height
    {
        for (col = 0; col < width; col++) // Iterate through the width
        {
            int red = image[row][col].rgbtRed;
            int blue = image[row][col].rgbtBlue;
            int green = image[row][col].rgbtGreen;
            
            int grayShade = round((red + blue + green) / 3.00); // Getting the average for the grayShade
            
            image[row][col].rgbtRed = grayShade; //the red now takes the grayShade value
            image[row][col].rgbtBlue = grayShade; //the blue now takes the grayShade value
            image[row][col].rgbtGreen = grayShade; // the green now takes the graySade value
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int row, col;

    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            int red = image[row][col].rgbtRed;
            int blue = image[row][col].rgbtBlue;
            int green = image[row][col].rgbtGreen;
            int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);
            int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            image[row][col].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[row][col].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[row][col].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int row, col;

    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width / 2; col++) // We used width/2 to make sure we dont swap twice
        {
            // Swap each pixel to opposite sides
            RGBTRIPLE temp = image[row][col];
            image[row][col] = image[row][width - col - 1]; //pin**
            image[row][width - col - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Temporary image to apply blur on
    RGBTRIPLE temp[height][width];
    int row, col;

    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            // Initializing some variables
            int count = 0;
            float red = 0, green = 0, blue = 0;

            // Creating a box around each pixel
            int boxRows[] = {row - 1, row, row + 1};
            int boxCols[] = {col - 1, col, col + 1};

            // iterating each pixel in the box
            for (int pixelRow = 0; pixelRow < 3; pixelRow++)
            {
                for (int pixelCol = 0; pixelCol < 3; pixelCol++)
                {
                    int tempRow = boxRows[pixelRow];
                    int tempCol = boxCols[pixelCol];

                    if (tempRow >= 0 && tempRow < height && tempCol >= 0 && tempCol < width)
                    {
                        RGBTRIPLE boxColors = image[tempRow][tempCol];

                        red += boxColors.rgbtRed;
                        green += boxColors.rgbtGreen;
                        blue += boxColors.rgbtBlue;

                        count++;
                    }
                }
            }

            temp[row][col].rgbtRed = round(red / count);
            temp[row][col].rgbtGreen = round(green / count);
            temp[row][col].rgbtBlue = round(blue / count);
        }
    }

    for (int iterRow = 0; iterRow < height; iterRow++)
    {
        for (int iterCol = 0; iterCol < width; iterCol++)
        {
            image[iterRow][iterCol] = temp[iterRow][iterCol];
        }
    }
    return;
}

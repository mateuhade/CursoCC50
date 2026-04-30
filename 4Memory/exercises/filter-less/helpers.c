#include "helpers.h"
#include <stdio.h>

typedef int8_t COLOR;
const int red = 1;
const int green = 2;
const int blue = 3;
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
    int lowestColorValue;
    COLOR *buffer;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (image[i][j].rgbtBlue < image[i][j].rgbtGreen && image[i][j].rgbtBlue < image[i][j].rgbtRed) {
                image[i][j].rgbtGreen = image[i][j].rgbtBlue;
                image[i][j].rgbtRed = image[i][j].rgbtBlue;
            }
            else if (image[i][j].rgbtRed < image[i][j].rgbtGreen && image[i][j].rgbtRed < image[i][j].rgbtBlue) {
                image[i][j].rgbtGreen = image[i][j].rgbtRed;
                image[i][j].rgbtBlue = image[i][j].rgbtRed;
            }
            else if (image[i][j].rgbtGreen < image[i][j].rgbtRed && image[i][j].rgbtGreen < image[i][j].rgbtBlue) {
                image[i][j].rgbtRed = image[i][j].rgbtGreen;
                image[i][j].rgbtBlue = image[i][j].rgbtGreen;
            }
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

#include "helpers.h"

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int averageColor = ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
            image[i][j].rgbtRed = averageColor;
            image[i][j].rgbtGreen = averageColor;
            image[i][j].rgbtBlue = averageColor;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    const int MAX_RGB_VALUE = 255;
    RGBTRIPLE originalColors;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            originalColors = image[i][j];

            int sepiaRed = 0.393 * originalColors.rgbtRed + 0.769 * originalColors.rgbtGreen + 0.189 * originalColors.rgbtBlue;
            if (sepiaRed < MAX_RGB_VALUE) {
                image[i][j].rgbtRed = sepiaRed;
            }
            else {
                image[i][j].rgbtRed = MAX_RGB_VALUE;
            }

            int sepiaGreen = 0.349 * originalColors.rgbtRed + 0.686 * originalColors.rgbtGreen + 0.168 * originalColors.rgbtBlue;
            if (sepiaGreen < MAX_RGB_VALUE) {
              image[i][j].rgbtGreen = sepiaGreen;
            }
            else {
                image[i][j].rgbtGreen = MAX_RGB_VALUE;
            }

            int sepiaBlue = 0.272 * originalColors.rgbtRed + 0.534 * originalColors.rgbtGreen + 0.131 * originalColors.rgbtBlue;
            if (sepiaBlue < MAX_RGB_VALUE) {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            else {
                image[i][j].rgbtBlue = MAX_RGB_VALUE;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE swap;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < (width / 2); j++) {
            swap = image[i][width-j-1];
            image[i][width-j-1] = image[i][j];
            image[i][j] = swap;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copiedImage[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            copiedImage[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixelAmount = 0;
            int red = 0, green = 0, blue = 0;

            //iterates through a 3x3 grid around a pixel in the image
            for (int k = i-1; k <= i+1; k++) {
                for (int l = j-1; l <= j+1; l++) {
                    //increments to l and jumps back to the start of the loop if the pixel position is invalid
                    if (k > height || k < 0 || l > width || l < 0) {
                        continue;
                    }
                    red += copiedImage[k][l].rgbtRed;
                    green += copiedImage[k][l].rgbtGreen;
                    blue += copiedImage[k][l].rgbtBlue;
                    pixelAmount++;
                }
            }

            image[i][j].rgbtRed = red / pixelAmount;
            image[i][j].rgbtGreen = green / pixelAmount;
            image[i][j].rgbtBlue = blue / pixelAmount;
        }
    }
    return;
}

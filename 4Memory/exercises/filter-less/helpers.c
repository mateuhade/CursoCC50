#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if ((image[i][j].rgbtBlue < image[i][j].rgbtGreen && image[i][j].rgbtBlue > image[i][j].rgbtRed) ||
            (image[i][j].rgbtBlue > image[i][j].rgbtGreen && image[i][j].rgbtBlue < image[i][j].rgbtRed)) {
                image[i][j].rgbtGreen = image[i][j].rgbtBlue;
                image[i][j].rgbtRed = image[i][j].rgbtBlue;
            }
            else if ((image[i][j].rgbtRed < image[i][j].rgbtGreen && image[i][j].rgbtRed > image[i][j].rgbtBlue) ||
            (image[i][j].rgbtRed > image[i][j].rgbtGreen && image[i][j].rgbtRed < image[i][j].rgbtBlue)) {
                image[i][j].rgbtGreen = image[i][j].rgbtRed;
                image[i][j].rgbtBlue = image[i][j].rgbtRed;
            }
            else if ((image[i][j].rgbtGreen < image[i][j].rgbtRed && image[i][j].rgbtGreen > image[i][j].rgbtBlue) ||
            (image[i][j].rgbtGreen > image[i][j].rgbtRed && image[i][j].rgbtGreen < image[i][j].rgbtBlue)) {
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
    RGBTRIPLE swap;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < (width / 2); j++) {
            swap = image[i][width-j];
            image[i][width-j] = image[i][j];
            image[i][j] = swap;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumRed, sumGreen, sumBlue, averageRed, averageGreen, averageBlue, pixelAmount;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixelAmount = 9;
            sumRed = 0;
            sumGreen = 0;
            sumBlue = 0;
            for (int k = i-1; k < i+1; k++) {
                for (int l = j-1; l < j+1; l++) {
                    if (k > height || k < 0 || l > width || l < 0) {
                        pixelAmount -= 1;
                        break;
                    }
                    sumBlue += image[k][l].rgbtBlue;
                    sumGreen += image[k][l].rgbtGreen;
                    sumRed += image[k][l].rgbtRed;
                }
            }

            averageRed = sumBlue / pixelAmount;
            averageGreen = sumGreen / pixelAmount;
            averageBlue = sumRed / pixelAmount;
            for (int k = i-1; k < i+1; k++) {
                for (int l = j-1; l < j+1; l++) {
                    if (k > height || k < 0 || l > width || l < 0) {
                        break;
                    }
                    image[k][l].rgbtRed = averageRed;
                    image[k][l].rgbtGreen = averageGreen;
                    image[k][l].rgbtBlue = averageBlue;
                }
            }
        }
    }
    return;
}
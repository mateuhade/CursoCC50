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
    RGBTRIPLE originalColors;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            originalColors = image[i][j];
            

            if (0.393 * originalColors.rgbtRed + 0.769 * originalColors.rgbtGreen +
            0.189 * originalColors.rgbtBlue < 255) {
                image[i][j].rgbtRed = 0.393 * originalColors.rgbtRed + 0.769 * originalColors.rgbtGreen +
                0.189 * originalColors.rgbtBlue;
            }
            else {
                image[i][j].rgbtRed = 255;
            }

            if (0.349 * originalColors.rgbtRed + 0.686 * originalColors.rgbtGreen +
            0.168 * originalColors.rgbtBlue < 255) {
              image[i][j].rgbtGreen = 0.349 * originalColors.rgbtRed + 0.686 * originalColors.rgbtGreen +
              0.168 * originalColors.rgbtBlue;
            }
            else {
                image[i][j].rgbtGreen = 255;
            }

            if (0.272 * originalColors.rgbtRed + 0.534 * originalColors.rgbtGreen +
            0.131 * originalColors.rgbtBlue < 255) {
                image[i][j].rgbtBlue = 0.272 * originalColors.rgbtRed + 0.534 * originalColors.rgbtGreen +
                0.131 * originalColors.rgbtBlue;
            }
            else {
                image[i][j].rgbtBlue = 255;
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


            for (int k = i-1; k <= i+1; k++) {
                for (int l = j-1; l <= j+1; l++) {
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

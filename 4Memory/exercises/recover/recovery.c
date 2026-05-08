#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int BLOCK_SIZE = 512;

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./recover file.raw\n");
        return 1;
    }

    FILE *memoryCard = fopen(argv[1], "rb");

    if (memoryCard == NULL) {
        printf("Could not find file.\n");
        return 2;
    }

    BYTE blockBuffer[BLOCK_SIZE];
    int fileCounter = 0, numberRead;
    char filename[10];
    while ((numberRead = fread(blockBuffer, sizeof(BYTE), 512, memoryCard)) > 0) {

        // checks for the file header
        if (blockBuffer[0] == 0xff && blockBuffer[1] == 0xd8 && blockBuffer[2] == 0xff &&
        (blockBuffer[3] & 0xf0) == 0xe0) {
            // makes a name for a file based on how many files there already are (001.jpg, 002.jpg, etc.)
            sprintf(filename, "%03i.jpg", fileCounter);
            // writes 512 bytes into a new file
            FILE *image = fopen(filename, "wb");
            fwrite(&blockBuffer, sizeof(BYTE), numberRead, image);
            fclose(image);
            fileCounter++;
        }
        else {
            if (fileCounter > 0) {
                FILE *image = fopen(filename, "ab");
                fwrite(&blockBuffer, sizeof(BYTE), numberRead, image);
                fclose(image);
            }
        }

        if (numberRead < 512) {
            return 0;
        }
    }
    return 0;
}

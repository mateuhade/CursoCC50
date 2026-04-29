// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

typedef int8_t BYTE;
typedef int16_t TWOBYTES;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // reads the file header from the input file
    BYTE header[HEADER_SIZE];
    fread(header, sizeof(BYTE), HEADER_SIZE, input);
    fwrite(header, sizeof(BYTE), HEADER_SIZE, output);


    // multiplies the volume of each two bytes in the file  after the header by the factor
    TWOBYTES buffer;
    while (fread(&buffer, sizeof(TWOBYTES), 1, input)) {
        buffer = buffer * factor;
        fwrite(&buffer, sizeof(TWOBYTES), 1, output);
    }


    // Close files
    fclose(input);
    fclose(output);
}

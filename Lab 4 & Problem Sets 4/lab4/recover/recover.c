#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// FAT 32 file system has a block size of 512Bytes
#define BlockSize 512
// Stores int from 0 to 255
typedef uint8_t BYTE;

// count number of jpegs image recovered
int jpegCount = 0;

// Names of files to be generated
char nameOfFile[10];

int main(int argc, char *argv[])
{
    // Check command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
    }

    //Open file(memory card) for reading
    FILE *input = fopen(argv[1], "r");
    //Initially my output does not write to anything
    FILE *output = NULL;

    // An array storing 512 bytes
    BYTE byte[BlockSize];

    while (fread(byte, sizeof(BYTE), BlockSize, input) || feof(input) == 0)
    {
        // If start of JPEG
        if (byte[0] == 0xff && byte[1] == 0xd8 && byte[2] == 0xff &&  (byte[3] & 0xf0) == 0xe0)
        {
            //if output does not contain any file, then populate output with files.
            if (output == NULL)
            {

                sprintf(nameOfFile, "%03d.jpg", jpegCount);
                //write to the name of file
                output = fopen(nameOfFile, "w");
                jpegCount++;

            }
            // Now that output has some file, close and then start populating with other files
            else if (output != NULL)
            {

                fclose(output);
                sprintf(nameOfFile, "%03d.jpg", jpegCount);
                output = fopen(nameOfFile, "w");
                jpegCount++;

            }
        }
        // If not start of JPEG, then continue writing. This is the next 512 byte block.
        if (output != NULL)
        {

            fwrite(byte, sizeof(BYTE), BlockSize, output);

        }
    }
    fclose(output);
    fclose(input);
}
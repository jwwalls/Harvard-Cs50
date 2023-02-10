#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
       return 1;
    }

    else
    {
        int BLOCK_SIZE = 512;
        char *fileName = argv[1];
        FILE *picture = fopen(fileName, "r");

        if(picture == NULL)
        {
            return 2;
        }

        BYTE buffer[BLOCK_SIZE];
        int counter = 0;
        FILE *picPointer = NULL;
        char fileNames[8];

        while (fread(buffer,1,BLOCK_SIZE,picture) == BLOCK_SIZE)
        {
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                    if (!(counter == 0))
                    {
                        fclose(picPointer);
                    }

                    sprintf(fileNames, "%03i.jpg", counter);
                    picPointer = fopen(fileNames, "w");
                    counter++;
            }
            if (!(counter == 0))
            {
                fwrite(&buffer, BLOCK_SIZE, 1, picPointer);
            }

        }

        fclose(picture);
        fclose(picPointer);
        return 0;
    }
}

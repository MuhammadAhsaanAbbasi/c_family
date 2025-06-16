#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inputFile, *outputFile;
    char ch;

    // Open input file in read mode
    inputFile = fopen("abbasi.txt", "r");
    if (inputFile == NULL)
    {
        printf("Cannot open input.txt for reading.\n");
        return 1;
    }

    // Open output file in write mode
    outputFile = fopen("abbasi2.txt", "w");
    if (outputFile == NULL)
    {
        printf("Cannot open output.txt for writing.\n");
        fclose(inputFile);
        return 1;
    }

    // First write: Copy from input to output character by character
    while ((ch = fgetc(inputFile)) != EOF)
    {
        fputc(ch, outputFile);
    }

    // Second write: Rewind and copy again
    rewind(inputFile);
    while ((ch = fgetc(inputFile)) != EOF)
    {
        fputc(ch, outputFile);
    }
    printf("Content copied twice successfully to output.txt\n");

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

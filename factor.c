#include "factor.h"

/**
 * main - The main function for factorizing numbers from a file.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments.
 *
 * Return: 0 on success, a non-zero value on failure.
 */
int main(int argc, char *argv[])
{
    FILE *filePtr;
    size_t bufferSize = 0;
    ssize_t bytesRead;
    char *lineBuffer = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: factor <filename>\n");
        return EXIT_FAILURE;
    }

    filePtr = fopen(argv[1], "r");
    if (filePtr == NULL)
    {
        fprintf(stderr, "Error: can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    while ((bytesRead = getline(&lineBuffer, &bufferSize, filePtr)) != -1)
    {
        factorize(lineBuffer);
    }

    // Clean up allocated resources
    if (lineBuffer != NULL)
        free(lineBuffer);

    fclose(filePtr);
    return EXIT_SUCCESS;
}

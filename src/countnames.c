// filepath: /countnames/src/countnames.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 20
#define Line_BUFFER_SIZE 256


int main(int argc, char *argv[])
{
    /*This will be able to open names.txt and read the 
    names in it, but it doesn't do anything with them yet.*/
    FILE *fp = fopen("namesB.txt", "r");
    //This is setup if the file name can not be opened
    if (fp == NULL)
    {
        fprintf(stderr, "Could not open file namesB.txt\n");
        return 1;
    }
    NameCount table[MAX_NAMES];
    int lengthCOunt = 0;

    for (int i = 0; i < MAX_NAMES; i++)
    {
        table[i].count = 0;
        table[i].name[0] = '\0';
    }

    char buffer[Line_BUFFER_SIZE];
    int lineNumber = 0;

    while (fgets(buffer, Line_BUFFER_SIZE, fp) != NULL)
    {
        lineNumber++;
        // Remove newline character if present
        buffer[strcspn(buffer, "\n")] = '\0';

        // Check if the name is already in the table
        int found = 0;
        for (int i = 0; i < lengthCOunt; i++)
        {
            if (strcmp(table[i].name, buffer) == 0)
            {
                table[i].count++;
                found = 1;
                break;
            }
        }

        // If not found, add it to the table
        if (!found && lengthCOunt < MAX_NAMES)
        {
            strncpy(table[lengthCOunt].name, buffer, MAX_NAME_LENGTH - 1);
            table[lengthCOunt].name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
            table[lengthCOunt].count = 1;
            lengthCOunt++;
        }
    }
    // Close the file after reading
    fclose(fp);

    //print the name counts
    for (int i = 0; i < lengthCOunt; i++)
    {
        printf("%s: %d\n", table[i].name, table[i].count);
    }

    return 0;
}
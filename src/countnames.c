// filepath: /countnames/src/countnames.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 100 // 100 distinct names
#define MAX_NAME_LENGTH 31
#define Line_BUFFER_SIZE 256


int main(int argc, char *argv[])
{
    /*This will be able to open names.txt and read the 
    names in it, but it doesn't do anything with them yet.*/
    FILE *fp = NULL;
    //This is setup if the file name can not be opened
    if (argc == 2)
    {
        fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            return 1;
        }
    }
    else if (argc == 1)
    {
        fp = stdin;
    }
    else
    {
        return 0;
    }
    
    char names[MAX_NAMES][MAX_NAME_LENGTH];
    int counts[MAX_NAMES];
    int lengthCOunt = 0;

    for (int i = 0; i < MAX_NAMES; i++)
    {
        counts[i] = 0;
        names[i][0] = '\0';
    }

    char buffer[Line_BUFFER_SIZE];
    int lineNum = 0;

    while (fgets(buffer, Line_BUFFER_SIZE, fp) != NULL)
    {
        lineNum++;
        // Remove newline character if present
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strlen(buffer) == 0)
        {
            fprintf(stderr, "Warning: Line %d is empty.\n", lineNum);
            continue;
        }

        // Check if the name is already in the table
        int found = 0;
        for (int i = 0; i < lengthCOunt; i++)
        {
            if (strcmp(names[i], buffer) == 0)
            {
                counts[i]++;
                found = 1;
                break;
            }
        }

        // If not found, add it to the table
        if (!found && lengthCOunt < MAX_NAMES)
        {
            strncpy(names[lengthCOunt], buffer, MAX_NAME_LENGTH - 1);
            names[lengthCOunt][MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
            counts[lengthCOunt] = 1;
            lengthCOunt++;
        }
    }
    // Close the file after reading
    if (fp != stdin)
    {
        fclose(fp);
    }

    //print the name counts
    for (int i = 0; i < lengthCOunt; i++)
    {
        printf("%s: %d\n", names[i], counts[i]);
    }

    return 0;
}
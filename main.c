#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Future thoughts: Add separate commands for writing windows variables
 *
 * Definitions:
 * file - key value pair where the key is what the user wants to swap and the value is an array of all the paths to the executable
 *
 * Functions:
 * add_var - open the file, find the key corresponding to what the user wants to add to, if none exist, make a new one and write
 * remove_var - display a selection of the stored directories based on the user's input and remove the selected one
 * find_var - open the file, find what the user wants to see and display a list of all the stored directories in said file
 * read_var - read from path windows variable, find what the user wants to see based on the executable name and print out the directory
 * swap_var - display a selection of the stored directories based on the user's input. Swap the corresponding directory in the path variable with the one the user chose
 * list_vars - output the file's contents in a nice, readable way
 * help - output help for the commands and their arguments
 */

// Helper Functions
// TODO: make a header file containing these functions and the directory
FILE *open_file()
{
    FILE *fp;
    fp = fopen("data/directories.txt", "rw");

    return fp;
}
//

int add_var(char path[], char variable[])
{
    // TODO: open the file, find the key corresponding to what the user wants to add to, if none exist, make a new one and write
    printf("ADD TODO: Path: %s, Variable: %s\n", path, variable);

    return EXIT_SUCCESS;
}

int remove_var(char variable[])
{
    // TODO: display a selection of the stored directories based on the user's input and remove the selected one
    printf("REMOVE TODO: Variable: %s\n", variable);

    return EXIT_SUCCESS;
}

int read_var(char *variable)
{
    char path[1024];
    FILE *fp = _popen("echo %PATH%", "r");
    fgets(path, sizeof(path), fp);

    char *pathEnvironmentVariables = strtok(path, ";");

    while (pathEnvironmentVariables != NULL)
    {
        if ((strstr(pathEnvironmentVariables, variable)))
        {
            printf("%s", pathEnvironmentVariables);
            fclose(fp);
            return EXIT_SUCCESS;
        }

        pathEnvironmentVariables = strtok(NULL, ";");
    }

    fclose(fp);
    return EXIT_FAILURE;
}

int swap_var(char variable[])
{
    // TODO: display a selection of the stored directories based on the user's input. Swap the corresponding directory in the path variable with the one the user chose
    printf("SWAP TODO: Variable: %s\n", variable);

    return EXIT_SUCCESS;
}

int find_vars(char variable[])
{
    // TODO: open the file, find what the user wants to see and display a list of all the stored directories in said file
    FILE *fp = open_file();
    char contents;

    contents = fgetc(fp);

    while (contents != EOF)
    {
        printf("%c", contents);
        contents = fgetc(fp);
    }
}

int help()
{
    // TODO: output help for the commands and their arguments
    printf("HELP TODO");

    return EXIT_SUCCESS;
}

int list_vars()
{
    FILE *fp = open_file();
    char contents;
    // TODO: research why i cant create the file if it doesnt exist
    if (fp == NULL)
    {
        perror("fopen");
    }

    contents = fgetc(fp);

    while (contents != EOF)
    {
        printf("%c", contents);
        contents = fgetc(fp);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    // TODO: validate everything
    if (strcmp(argv[1], "add") == 0)
    {
        add_var(argv[2], argv[3]);
    }
    else if (strcmp(argv[1], "remove") == 0)
    {
        remove_var(argv[2]);
    }
    else if (strcmp(argv[1], "read") == 0)
    {
        read_var(argv[2]);
    }
    else if (strcmp(argv[1], "swap") == 0)
    {
        swap_var(argv[2]);
    }
    else if (strcmp(argv[1], "list") == 0)
    {
        list_vars();
    }
    else if (strcmp(argv[1], "find") == 0)
    {
        find_vars(argv[2]);
    }
    else if (strcmp(argv[1], "help") == 0)
    {
        help();
    }

    return EXIT_SUCCESS;
}
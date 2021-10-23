#include <stdio.h>
#include <stdlib.h>
#include "cs50.h"

int checkArray26(char *array);
int checkKey26(char *array);
void strToUpper(char *argv[], char compare[]);

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    int x = 0;
    char alphabetUpper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alphabetLower[] = "abcdefghijklmnopqrstuvwxyz";
    char output[1000];

    if (argc != 2)
    {
        printf("Invalid command line arguments. Please enter only 26 alphabetical characters as argument.\n");
        return 1;
    }

    checkArray26(argv[1]);
    checkKey26(argv[1]);
    strToUpper(argv, alphabetLower);
	
    string input_plaintext = get_string("plaintext: ");

    if ((input_plaintext[j] >= 'A' && input_plaintext[j] <= 'Z') || (input_plaintext[j] >= 'a' && input_plaintext[j] <= 'z'))
    {

        while (input_plaintext[j] && i <= 25)
        {

            if (input_plaintext[j] == alphabetLower[i])
            {

                output[j] = argv[1][i] + 32;

                j++;
                i = 0;
            }
            else if (input_plaintext[j] == alphabetUpper[i])
            {

                output[j] = argv[1][i];

                j++;

                i = 0;
            }
            else
            {
                i++;
            }
        }
        output[j] = '\0';
    }
    else
    {
        printf("Error.");
    }

    printf("ciphertext: %s", output);

    return 0;
}

int checkKey26(char *array)
{

    int i = 0;

    while (array[i] != '\0')
    {
        if ((array[i] >= 'A' && array[i] <= 'Z') || (array[i] >= 'a' && array[i] <= 'z'))
        {
           	//
        }
        else
        {
            printf("Bad character detected at index %d. Character: %c.\nPlease enter only alphabetical characters.", i, array[i]);
            exit(1);
        }
        i++;
    }
}

int checkArray26(char *array)
{
    int i = 0;
    while (array[i] != '\0')
    {
        i++;
    }
    if (i == 26)
    {
        return 0;
    }
    else
    {
        printf("Invalid key. Please enter only 26 alphabetical characters as argument.\n");
        exit(1);
    }
}

void strToUpper(char **argv, char compare[])
{
    int i1 = 0;
    int y = 0;
    while (argv[1][i1] != 0)
    {
        y = 0;
        while (y <= 26 && i1 < 26)
        {
            if (argv[1][i1] == compare[y])
            {
                argv[1][i1] -= 32;
                y = 0;
                i1++;
            }
            else
            {
                y++;
            }
        }
        i1++;
    }
}

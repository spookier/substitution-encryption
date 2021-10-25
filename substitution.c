#include <ctype.h>

#include <stdio.h>

#include <stdlib.h>

#include "cs50.h"

int checkArray26(char * array);
int checkKey26(char * array);
int occurence(char * arr);
void strToUpper(char * argv[], char compare[]);

int main(int argc, char * argv[]) {
    int i = 0;
    int j = 0;
    int x = 0;
    //                      YTNSHKVEFXRBAUQZCLWDMIPGJO
    char alphabetUpper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alphabetLower[] = "abcdefghijklmnopqrstuvwxyz";
    char allowedChars[] = "$`<@\"^[(\\{_},)]/+-~%%'?&|:!*.=>;#0123456789 ";

    if (argc != 2) {
        printf("Invalid command line arguments. Please enter only 26 alphabetical characters as argument.\n");
        return 1;
    }

    if (checkArray26(argv[1]) == 1 || checkKey26(argv[1]) == 1 || occurence(argv[1]) == 1) {
        return 1;
    }

    strToUpper(argv, alphabetLower); 

    string input_plaintext = get_string("plaintext:");
    int kk = 0;
    while (input_plaintext[kk] != '\0') {
        kk++;
    }

    char output[kk];

    if ((input_plaintext[j] >= 'A' && input_plaintext[j] <= 'Z') || (input_plaintext[j] >= 'a' && input_plaintext[j] <= 'z') ||
        (input_plaintext[j] >= 32 && input_plaintext[j] <= 64) || (input_plaintext[j] >= 91 && input_plaintext[j] <= 96) ||
        (input_plaintext[j] >= 123 && input_plaintext[j] <= 126)) {
        while (input_plaintext[j]) // && i <= 25
        {
            if (input_plaintext[j] == alphabetLower[i]) {
                output[j] = argv[1][i] + 32;
                j++;
                i = 0;
            } else if (input_plaintext[j] == alphabetUpper[i]) {
                output[j] = argv[1][i];
                j++;
                i = 0;
            } else if (input_plaintext[j] == allowedChars[i]) {
                output[j] = allowedChars[i];

                j++;
                i = 0;
            } else {
                i++;
            }
        }
        output[j] = '\0';
    } else {
        printf("Error.\n");
        return 1;
    }
    printf("ciphertext:%s\n", output);
    printf("\n");
    return 0;
}

int checkKey26(char * array) //checks key1
{

    int i = 0;

    while (array[i] != '\0') {
        if ((array[i] >= 'A' && array[i] <= 'Z') || (array[i] >= 'a' && array[i] <= 'z')) {
            //
        } else {
            printf("Bad character detected at index %d. Character: %c.\nPlease enter only alphabetical characters.", i,
                array[i]); //exit if invalid
            return 1;
        }
        i++;
    }
    return 0; // <-- added this
}

int checkArray26(char * array) //checks key2
{
    int i = 0;
    while (array[i] != '\0') {
        i++;
    }
    if (i == 26) {
        return 0;
    } else {
        printf("Invalid key. Please enter only 26 alphabetical characters as argument.\n"); //prints and returns if key invalid
        //exit(1);
        return 1;
    }
}

void strToUpper(char ** argv, char compare[]) //puts str to uppercase
{
    int i1 = 0;
    int y = 0;
    while (argv[1][i1] != 0) {
        y = 0;
        while (y <= 26 && i1 < 26) //looping
        {
            if (argv[1][i1] == compare[y]) {
                argv[1][i1] -= 32;
                y = 0;
                i1++;
            } else {
                y++;
            }
        }
        i1++;
    }
}

int occurence(char * arr) //testing for duplicates
{
    int strlength = 0;
    int i = 0;
    int passes = 0;
    int y = 0;
    char Seen[27] = {
        0
    };

    while (arr[strlength] != '\0') {
        arr[strlength] = toupper(arr[strlength]);
        strlength++;
    }
    if (strlength != 26) {
        printf("Invalid array size.");
        return 1;
    }

    while (arr[i] != '\0') 
    {
        if (Seen[0] == 0) //one time check 
        {
            Seen[0] = arr[0];
            i++;
            y++;

        }
        while (Seen[passes] != '\0') 
        {
            if (Seen[passes - 1] == arr[i]) //check
            {
                printf("Duplicate char found at %c:%d - %c:%d\n", Seen[passes - 1], passes, arr[i], i + 1);
                return 1;

            }
            Seen[y] = arr[i]; 
            passes++;

        }
        passes = 0;
        i++;
        y++;

    }
    return 0;
}

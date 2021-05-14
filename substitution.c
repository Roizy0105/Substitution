#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    //check to see if the user entered a string or more than one string
    if (argc == 2)
    {
        //agign key to the length of the string the user enters
        int key = strlen(argv[1]);
        //check to see if the string contains 26 caracters
        if (key == 26)
        {
            int success = 0;
            int notalpha = 0;
            int alphamatch = 0;

            //iterate through the string
            for (int i = 0; i < 26; i++)
            {
                //check if the char is an alpha
                if (isalpha(argv[1][i]))
                {
                    //iterate through the string starting with the next index of the array to compare
                    for (int j = i + 1; j < 26; j++)
                    {
                        //compare to see if they are different
                        if (argv[1][i] != argv[1][j])
                        {
                            //add to success if it was successfull
                            success++;
                        }

                        else
                        {
                            //add to alphamatch if this char apears more then once
                            alphamatch++;
                        }

                    }
                }
                else
                {
                    //add if the char is not an alpha
                    notalpha++;
                }

            }
            if (notalpha > 0)
            {
                printf("enter only alpha\n");
                return 1;
            }
            else if (alphamatch > 0)
            {
                printf("enter each alpha only once\n");
                return 1;
            }
            else
            {

                //get test from user
                string plainText = get_string("Enter Text: ");

                printf("ciphertext: ");
                for (int i = 0, length = strlen(plainText); i < length; i++)
                {
                    
                    if (isalpha(plainText[i]))
                    {
                        if (isupper(plainText[i]))
                        {
                            int text = plainText[i] - 'A';
                            char cipher = argv[1][text];
                            printf("%c", toupper(cipher));
                        }
                        else if (islower(plainText[i]))
                        {
                            int text = plainText[i] - 'a';
                            char cipher = argv[1][text];
                            printf("%c", tolower(cipher));
                        }
                    }
                    else
                    {
                        printf("%c", plainText[i]);
                    }
                }
                printf("\n");
                return 0;
            }

        }
        else
        {
            printf("Must contain 26 alphabets\n");
            return 1;
        }
    }
    else
    {
        printf("usage: %s key\n", argv[0]);
        return 1;
    }
}
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void rotate(string input);
char change(char letter, string alphabet);

const string alphaU = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string alphaL = "abcdefghijklmnopqrstuvwxyz";
string subst, text;
char cipher, final;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < 26; i++)
    {
        for (int l = (i + 1); l < 26; l++)
        {
            if (argv[1][i] == argv[1][l])
            {
                printf("Usage: ./substitution key\n");
                // printf("%c %c %i %i\n",argv[1][i], argv[1][l], i, l);
                return 1;
            }
        }
    }
    subst = argv[1];
    text = get_string("plaintext:  ");
    rotate(text);
}

void rotate(string input)
{
    printf("ciphertext: ");
    for (int k = 0; k < strlen(text); k++)
    {
        if (((text[k] >= 'A') && (text[k] <= 'Z')) || ((text[k] >= 'a') && (text[k] <= 'z')))
        {
            final = text[k];
            cipher = change(final, subst);
        }
        if (isalpha(text[k]) == 0)
        {
            printf("%c", text[k]);
        }
    }
    printf("\n");
}

char change(char letter, string alphabet)
{
    for (int j = 0; j < 26; j++)
    {
        if (((final == alphaU[j]) && (isupper(subst[j]) != 0)) || ((final == alphaL[j]) && (islower(subst[j]) != 0)))
        {
            final = subst[j];
            printf("%c", final);
            return 1;
        }
        else if ((final == alphaL[j]) && (islower(subst[j]) == 0))
        {
            final = tolower((subst[j]));
            printf("%c", final);
            return 1;
        }
        else if ((final == alphaU[j]) && (isupper(subst[j]) == 0))
        {
            final = toupper((subst[j]));
            printf("%c", final);
            return 1;
        }
    }
    return 0;
}
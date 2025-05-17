#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Use: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]) % 26;

    string plain_text = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plain_text); i++)
    {
        char c = plain_text[i];

        if (isupper(c))
        {
            printf("%c", ((c - 'A' + key) % 26) + 'A');
        }
        else if (islower(c))
        {
            printf("%c", ((c - 'a' + key) % 26) + 'a');
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}

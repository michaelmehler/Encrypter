#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char encryption_letter(char* key, char letter);
int is_valid(char* key);

int main(int argc, char* argv[])
{
    char key[27];  
    char plaintext[100];
    char cyphertext[100];

    printf("Enter key: ");
    scanf("%s", key);

    if (!is_valid(key))
    {
        printf("Invalid Key\n");
        return 0;
    }

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    for (int i = 0; i < strlen(plaintext); i++)
    {
        cyphertext[i] = encryption_letter(key, plaintext[i]);
    }

    printf("cyphertext: %s\n", cyphertext);

    return 0;
}

char encryption_letter(char* key, char letter)
{
    if (letter >= 'A' && letter <= 'Z')
    {
        return key[letter - 'A'];  
    }
    else if (letter >= 'a' && letter <= 'z')
    {
        return key[letter - 'a'] + ('a' - 'A');  
    }
    return letter;  
}

int is_valid(char* key) // False == 0 and True == 1
{
    if (strlen(key) != 26)
    {
        return 0;  
    }

    int letter_count[26] = {0};  

    for (int i = 0; i < 26; i++)
    {
        if (key[i] < 'A' || key[i] > 'Z')
        {
            return 0;  
        }
        int index = key[i] - 'A';
        letter_count[index]++;
        if (letter_count[index] > 1)
        {
            return 0;  
        }
    }

    return 1;  
}
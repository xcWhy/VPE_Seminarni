#include <stdio.h>
#include <string.h>

void isFoundLetter(char letter, char *secret, char *placeholder)
{
    for (int i = 0; i < strlen(secret); i++)
    {
        if (letter == secret[i])
        {
            placeholder[i] = letter;
        }
    }
}

int main()
{
    char secret_duma[] = "concatenation";
    char placeholder_secret_duma[20];

    strcpy(placeholder_secret_duma, secret_duma);

    for (int i = 0; i < strlen(placeholder_secret_duma); i++)
    {
        placeholder_secret_duma[i] = '_';
    }

    int win = 0, counter = 0;

    while (!win)
    {
        printf("\n\n~~~ guess the word ~~~ \n\n");
        for (int i = 0; i < strlen(placeholder_secret_duma); i++)
        {
            printf("%c", placeholder_secret_duma[i]);
        }

        printf("\n\n");

        char letter;

        printf("Poznaite bukva: ");
        scanf(" %c", &letter);

        counter++;
        isFoundLetter(letter, secret_duma, placeholder_secret_duma);

        if (!strcmp(secret_duma, placeholder_secret_duma)) 
        {
            win = 1;
            break;
        }

        else if(counter == strlen(secret_duma) + 2)
        {
            break;
        }
        
                
    }

    if (win) 
    {
        printf("YEY U GUESSED !!");

        printf("\nThe word was... %s !!", secret_duma);
    }

    else printf("SLABO - too many tries :P");

    return 0;


}
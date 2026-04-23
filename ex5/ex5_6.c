#include <stdio.h>
#include <string.h>

int isFoundLetter(char l1, char *duma)
{
    for (int i = 0; i < strlen(duma); i++)
    {
        if (l1 == duma[i]) 
        {
            duma[i] = '*';
            return 1;
        }

    }

    return 0;
}

int main()
{
    char duma[20];
    char duma2[20];


    printf("Vyvedete pyrvata duma: ");
    scanf("%s", duma);

    printf("Vyvedte vtorata duma: ");
    scanf("%s", duma2);

    int anagrama = 0, counter = 0;

    if (strlen(duma) == strlen(duma2))
    {
        for (int i = 0; i < strlen(duma); i++)
        {
            if (isFoundLetter(duma[i], duma2)) counter++;
        }

        if (counter == strlen(duma)) anagrama = 1;
    }

    if (anagrama) printf("1 !!");
    else printf("0 !!");

    return 0;

}

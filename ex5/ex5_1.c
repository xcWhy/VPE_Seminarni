#include <stdio.h>
#include <string.h>

int main()
{
    // float chair = 13.99;
    // float table = 42.00; // 8 choveka
    // float cups = 5.98; // komplekt 6 chashi
    // float dishes = 21.02; // komplekt 6 chinii

    const char *items[] = {"Chair", "Table", "Cups", "Dishes"};
    float prices[] = {13.99, 42.00, 5.98, 21.02};

    int counts[4] = {0};

    int broi_gosti;

    printf("Vyvedete broi gosti: ");
    scanf("%d", &broi_gosti);

    int required[4];

    required[0] = broi_gosti;
    required[1] = (broi_gosti + 7) / 8;
    required[2] = (broi_gosti + 5) / 6;
    required[3] = (broi_gosti + 5) / 6;

    float sum = 0;
    char vyvedena_duma[20] = "";

    while (1)
    {
        printf("Pokupka na: ");
        scanf("%s", &vyvedena_duma);
        
        if (!strcmp(vyvedena_duma, "PARTY!")) break;

        int found_product = 0;

        for (int i = 0; i < 4; i++)
        {
            if (!strcmp(vyvedena_duma, items[i]))
            {
                sum += prices[i];
                counts[i]++;
                found_product = 1;
                break;
            }
        }

        if (!found_product) printf("Nqma takova neshto v magazina !\n");
    }

    printf("\n~~~ KRAI ~~~\n\n");
    printf("Kraina cena na pazara: %.2f\n", sum);
    printf("Dopylnitelni nujni pokupki: \n");
    
    for (int i = 0; i < 4; i++)
    {
        if (counts[i] < required[i])
        {
            printf("%s: %d\n", items[i], required[i] - counts[i]);
        }
    }
}
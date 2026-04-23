#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 200
#define MAX_LEN 51

int main()
{
    FILE *in, *bin;
    char words[MAX_WORDS][MAX_LEN];
    char selected[MAX_WORDS][MAX_LEN];

    int count = 0, selected_count = 0;

    in = fopen("input.txt", "r");
    if (!in)
    {
        printf("Error opening input.txt!\n");
        return 1;
    }

    printf("Reading words from input.txt...\n");

    while (fscanf(in, "%50s", words[count]) == 1)
    {
        count++;
    }

    fclose(in);

    if (count == 0)
    {
        printf("No words found!\n");
        return 1;
    }

    printf("Total words read: %d\n", count);

    // first word always included
    strcpy(selected[selected_count++], words[0]);

    char last_char = words[0][strlen(words[0]) - 1];

    for (int i = 1; i < count; i++)
    {
        if (words[i][0] == last_char)
        {
            strcpy(selected[selected_count++], words[i]);
            last_char = words[i][strlen(words[i]) - 1];
        }
    }

    bin = fopen("output.bin", "wb");
    if (!bin)
    {
        printf("Error creating output.bin!\n");
        return 1;
    }

    printf("Writing selected words to binary file...\n");

    for (int i = 0; i < selected_count; i++)
    {
        fwrite(selected[i], sizeof(char), strlen(selected[i]), bin);
        if (i != selected_count - 1)
        {
            char space = ' ';
            fwrite(&space, sizeof(char), 1, bin);
        }
    }

    fclose(bin);

    printf("Binary file created: output.bin\n");

    // display binary file content
    bin = fopen("output.bin", "rb");
    if (!bin)
    {
        printf("Error opening output.bin!\n");
        return 1;
    }

    printf("\n--- Binary file content ---\n");

    char ch;
    while (fread(&ch, sizeof(char), 1, bin))
    {
        printf("%c", ch);
    }

    printf("\n");

    fclose(bin);

    return 0;
}
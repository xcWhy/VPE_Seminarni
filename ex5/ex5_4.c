#include <stdio.h>
#include <stdlib.h>

int main()
{
    char inputFile[100] = "input.txt";
    char outputFile[100] = "output.txt";
    FILE *in, *out;

    char text[1000];
    int key;

    // 1. Input text from user
    printf("Enter text to save in file: ");
    getchar(); // clear buffer
    fgets(text, sizeof(text), stdin);

    // 2. Create / write to input file
    in = fopen(inputFile, "w");
    if (!in)
    {
        printf("Error creating input file!\n");
        return 1;
    }

    fprintf(in, "%s", text);
    fclose(in);

    printf("Text saved in %s\n", inputFile);

    // 3. Read key from user
    printf("Enter key (2 - 10): ");
    scanf("%d", &key);

    if (key < 2 || key > 10)
    {
        printf("Invalid key!\n");
        return 1;
    }

    // 4. Open input for reading + output for writing
    in = fopen(inputFile, "r");
    if (!in)
    {
        printf("Error opening input file!\n");
        return 1;
    }

    out = fopen(outputFile, "w");
    if (!out)
    {
        printf("Error creating output file!\n");
        fclose(in);
        return 1;
    }

    // 5. Encode file
    char ch;
    while ((ch = fgetc(in)) != EOF)
    {
        fputc(ch + key, out);
    }

    fclose(in);
    fclose(out);

    printf("Encoded file saved in %s\n", outputFile);

    return 0;
}
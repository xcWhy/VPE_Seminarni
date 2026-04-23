#include <stdio.h>
#include <stdlib.h>

#define MAX 30

typedef struct {
    int id;
    float hourly_pay;
    int hours;
    float weekly_salary;
} Worker;

void calculate_salary(Worker *w)
{
    int overtime_hours = (w->hours > 40) ? (w->hours - 40) : 0;
    int normal_hours = (w->hours > 40) ? 40 : w->hours;

    float gross = normal_hours * w->hourly_pay +
                  overtime_hours * w->hourly_pay * 1.5;

    float tax = gross * 0.0365;

    w->weekly_salary = gross - tax;
}

void add_worker(FILE *file)
{
    Worker w;

    printf("\nEnter worker ID: ");
    scanf("%d", &w.id);

    printf("Enter hourly pay: ");
    scanf("%f", &w.hourly_pay);

    printf("Enter hours worked: ");
    scanf("%d", &w.hours);

    calculate_salary(&w);

    fwrite(&w, sizeof(Worker), 1, file);

    printf("Worker added successfully!\n");
}

void show_workers(FILE *file)
{
    Worker w;

    rewind(file);

    printf("\n--- Weekly Salaries ---\n");

    while (fread(&w, sizeof(Worker), 1, file))
    {
        printf("ID: %d | Hours: %d | Salary: %.2f\n",
               w.id, w.hours, w.weekly_salary);
    }
}

int main()
{
    FILE *file;
    int choice;

    file = fopen("workers.dat", "ab+");
    if (!file)
    {
        printf("Error opening file!\n");
        return 1;
    }

    while (1)
    {
        printf("\n===== MENU =====\n");
        printf("1. Add worker\n");
        printf("2. Show salaries\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int count = 0;
            Worker temp;

            rewind(file);
            while (fread(&temp, sizeof(Worker), 1, file))
                count++;

            if (count >= MAX)
            {
                printf("Max workers reached!\n");
                continue;
            }

            add_worker(file);
        }
        else if (choice == 2)
        {
            show_workers(file);
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }

    fclose(file);

    printf("Program ended.\n");

    return 0;
}
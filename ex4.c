#include <stdio.h>
#include <stdlib.h>

void ex1()
{
    int n, m;

    printf("Vyvedete n: ");
    scanf("%d", &n);

    printf("Vyvedete m: ");
    scanf("%d", &m);

    int arr[n][m];

    // въвеждане
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Element %d-%d: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int rows_ok = 1;
    int cols_ok = 1;

    // проверка на редове (нарастващ)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (arr[i][j] > arr[i][j + 1])
            {
                rows_ok = 0;
            }
        }
    }

    // проверка на колони (намаляващ)
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i][j] < arr[i + 1][j])
            {
                cols_ok = 0;
            }
        }
    }

    printf("\n");

    if (rows_ok)
        printf("Redovete sa narastvashti\n");
    else
        printf("Redovete NE sa narastvashti\n");

    if (cols_ok)
        printf("Klonite sa namalqvashti\n");
    else
        printf("Klonite NE sa namalqvashti\n");
    
    printf("\n");
}

void ex2()
{
    int n, m;

    printf("Vyvedete n: ");
    scanf("%d", &n);

    printf("Vyvedete m: ");
    scanf("%d", &m);

    int arr[n][m];

    // въвеждане
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Element %d-%d: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int max_sum;
    int best_i = 0, best_j = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = 0;

            // обхождаме съседите
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    // пропускаме себе си
                    if (di == 0 && dj == 0)
                        continue;

                    // проверка за граници
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                    {
                        sum += arr[ni][nj];
                    }
                }
            }

            // първа стойност
            if (i == 0 && j == 0)
            {
                max_sum = sum;
                best_i = i;
                best_j = j;
            }
            else if (sum > max_sum)
            {
                max_sum = sum;
                best_i = i;
                best_j = j;
            }
        }
    }

    printf("\nElementat s nai-golqm sbor na sasetite e: %d\n", arr[best_i][best_j]);
    printf("Poziciq: (%d, %d)\n", best_i, best_j);
    printf("Sbor na sasetite: %d\n", max_sum);
}

void ex3()
{

    int n, m;

    printf("Vyvedete n: ");
    scanf("%d", &n);

    printf("Vyvedete m: ");
    scanf("%d", &m);

    int arr[n][m], tmp_arr[n][m];

    int max_i, min_i;

    int max_num, min_num;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Vyvedete element %d-%d : ", i, j);
            scanf("%d", &arr[i][j]);
            tmp_arr[i][j] = arr[i][j];

            if (i == 0 && j == 0) 
            {
                max_num = arr[i][j];
                min_num = arr[i][j];
                max_i = i;
                min_i = i;
            }

            else if (max_num < arr[i][j])
            {
                max_num = arr[i][j];
                max_i = i;
            }

            else if (min_num > arr[i][j])
            {
                min_num = arr[i][j];
                min_i = i;
            }
        }
    }

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf(" %d ", arr[i][j]);
        }

        printf("\n");
    }

    // print_arr(arr[n][m]);

    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == max_i)
            {
                arr[i][j] = tmp_arr[min_i][j];
            }

            else if (i == min_i)
            {
                arr[i][j] = tmp_arr[max_i][j];
            }
        }
    }

    // print_arr(arr[n][m]);

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf(" %d ", arr[i][j]);
        }

        printf("\n");
    }

    
}

void ex4()
{
    int n, m;

    printf("Vyvedi broi hora: ");
    scanf("%d",&n);

    printf("Vyvedi broi priyatelstva: ");
    scanf("%d",&m);

    int count[100001]={0};

    printf("Vuvedi prijatelstvata (x : y): \n");

    for(int i = 0;i < m; i++)
    {
        int a,b;

        scanf("%d %d",&a,&b);

        // dobavqme prijatelstvo 
        count[a]++;
        count[b]++;
    }

    int person;

    printf("Za koi chovek iskash informaciq: ");
    scanf("%d",&person);

    printf("Chovek nomer %d ima %d na broi priqteli!\n",
    person,count[person]);

}

void ex5()
{
    int *arr = NULL;
    int size = 0;

    int n;
    printf("Vyvedi broi elementi: ");
    scanf("%d", &n);

    // заделяне на памет
    arr = malloc(n * sizeof(int));
    size = n;

    // въвеждане на елементите
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int command;

    while (1)
    {
        printf("\n(1)add (2)delete (3)smallest (0)exit: ");
        scanf("%d", &command);

        if (command == 0) break;

        int x;

        if (command == 1) // add
        {
            printf("Dobavete element: ");
            scanf("%d", &x);

            size++;
            arr = realloc(arr, size * sizeof(int));

            arr[size - 1] = x;
        }

        else if (command == 2) // delete
        {
            scanf("%d", &x);

            int new_size = 0;

            for (int i = 0; i < size; i++)
            {
                if (arr[i] != x)
                {
                    arr[new_size++] = arr[i];
                }
            }

            size = new_size;
            arr = realloc(arr, size * sizeof(int));
        }

        else if (command == 3) // smallest(x)
        {
            scanf("%d", &x);

            if (x > size || x <= 0)
            {
                printf("Nqma takyv element\n");
                continue;
            }

            // сортиране
            for (int i = 0; i < size - 1; i++)
            {
                for (int j = 0; j < size - i - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        int tmp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = tmp;
                    }
                }
            }

            printf("%d-toto nai-malko: %d\n", x, arr[x - 1]);
        }

        // показване на масива след всяка команда
        printf("Update na elementite: ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    free(arr);
}

int isPrime(int x)
{
    if (x < 2) return 0;

    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return 0;
    }

    return 1;
}

void ex6()
{
    int n;

    printf("Vyvedete broi chisla: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Chislo %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int *primes = NULL;
    int primes_size = 0;

    int new_size = 0;

    for (int i = 0; i < n; i++)
    {
        if (isPrime(arr[i]))
        {
            primes_size++;
            primes = realloc(primes, primes_size * sizeof(int));
            primes[primes_size - 1] = arr[i];
        }
        else
        {
            arr[new_size++] = arr[i];
        }
    }

    arr = realloc(arr, new_size * sizeof(int));

    // печат
    printf("\nNe-prosti chisla:\n");
    for (int i = 0; i < new_size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nProsti chisla:\n");
    for (int i = 0; i < primes_size; i++)
    {
        printf("%d ", primes[i]);
    }

    printf("\n");

    free(arr);
    free(primes);
}

void ex7()
{
    int n, m;

    printf("Vyvedete n: ");
    scanf("%d", &n);

    printf("Vyvedete m: ");
    scanf("%d", &m);

    int arr[n][m];

    // въвеждане
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Element %d-%d: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int max_sum;
    int best_i = 0, best_j = 0;

    // обхождаме всички 3x3 подматрици
    for (int i = 0; i <= n - 3; i++)
    {
        for (int j = 0; j <= m - 3; j++)
        {
            int sum = 0;

            // сума на текущата 3x3
            for (int di = 0; di < 3; di++)
            {
                for (int dj = 0; dj < 3; dj++)
                {
                    sum += arr[i + di][j + dj];
                }
            }

            // първа стойност
            if (i == 0 && j == 0)
            {
                max_sum = sum;
                best_i = i;
                best_j = j;
            }
            else if (sum > max_sum)
            {
                max_sum = sum;
                best_i = i;
                best_j = j;
            }
        }
    }


    printf("Cqlata matrica: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");


    // принтиране на резултата
    printf("\nPodmatricata 3x3 s nai-golqma suma:\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", arr[best_i + i][best_j + j]);
        }
        printf("\n");
    }

    printf("Suma: %d\n", max_sum);
}

void ex8()
{
    int n = 10;
    int final_size = n;
    printf("Vyvedete 10 elementa: \n");
    // scanf("%d", &n);

    int * arr;

    arr = (int*) malloc (n * sizeof(int));

    int is_break = 0;

    if (arr != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            printf("Vyvedete element %d: ", i+1);
            scanf("%d", &arr[i]);
        }

    }


    int num = 1, pos;

    while (1)
    {
        printf("Chislo: ");
        scanf("%d", &num);

        if (num == 0) break;

        printf("Poziciq: ");
        scanf("%d", &pos);

        final_size++;

        int *temp = realloc(arr, final_size * sizeof(int));
        arr = temp;

        for (int i = final_size - 1; i > pos; i--) 
        {
            arr[i] = arr[i - 1];
        }

        arr[pos] = num;

        
        printf("\nArray: ");
        for (int i = 0; i < final_size; i++) 
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < final_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);


}

int main()
{

    int otg;
    printf("Izberete zadacha: ");
    scanf("%d", &otg);

    switch (otg)
    {
    case 1: ex1(); break;

    case 2: ex2(); break;

    case 3: ex3(); break;

    case 4: ex4(); break;

    case 5: ex5(); break;

    case 6: ex6(); break;

    case 7: ex7(); break;

    case 8: ex8(); break;
    
    default:
        printf("Nqma takava zadacha");
        break;
    }

    return 0;

}
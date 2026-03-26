#include <stdio.h>


void ex1()
{
    int n; 

    printf("Vyvedete N: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Vyvedete element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n - i- 1;j++){
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        printf(" %d",arr[i]);
    }

   int counter = 1 , index_start = 0, longest = 1, curr_start = 0;

    for(int i = 1; i < n; i++)
        {
        if(arr[i]== arr[i-1])
            {
             counter++;
            }
            else
            {
                counter = 1;
                curr_start = i;
            }
            if(counter > longest)
            {
                longest = counter;
                index_start = curr_start;
            }
        }

    printf("Nachalo na ploshtadkata: %d\nDyljina na ploshtadkata: %d\n", index_start, longest);

}
void ex2()
{
    int n;

    printf("Vyvedete N: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Vyvedete element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int isRelational = 1;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1 && arr[i] > arr[i-1])
        {
            continue;
        }

        else if (i % 2 == 0 && arr[i] < arr[i-1])
        {
            continue;
        }

        else
        {
            isRelational = 0;
            break;
        }
    }

    if (isRelational) printf("Redicata e relacionna!");
    else printf("Redicata NE e relacionna!");
}

void ex3()
{
    int n;

    printf("Vyvedete N: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Vyvedete element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int rev_arr[n];

    for (int i = 0; i < n; i++)
    {
        rev_arr[i] = arr[n-i-1];
    }

    printf("Obyrnatiqt masiv: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", rev_arr[i]);
    }

}


// 4.
#include <stdio.h>

void ex4() {
    int n;

    printf("Vyvedete N: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Vyvedete element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int k;

    printf("Vyvedete K: ");
    scanf("%d", &k);

    k = k % n;

    int temp[n];

    for(int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }

    printf("Izmesteniqt masiv izglejda taka: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
}

void ex5() /// otricatelni chisla??
{
    int n;

    printf("Vyvedete N: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Vyvedete element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int k;

    printf("\nVyvedete K: ");
    scanf("%d", &k);

    int k_num = arr[0], max = arr[0], max_index = 0;

    for(int i = 0; i < k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (max < arr[i])
            {
                max = arr[i];
                max_index = i;
            }
        }

        k_num = max;

        if (i != k - 1) arr[max_index] = 0;
    }

    printf("%d-iqt element po golemina v masiva e raven na: %d", k, k_num);

}


void ex6() 
{

    int n;

    printf("Vyvedete N: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Vyvedete element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int bestStart = 0, bestLen = 1;
    int currStart = 0, currLen = 1;

    for(int i = 1; i < n; i++) {
        if(arr[i] > arr[i - 1]) {
            currLen++;
        } else {
            if(currLen > bestLen) {
                bestLen = currLen;
                bestStart = currStart;
            }
            currStart = i;
            currLen = 1;
        }
    }

    if(currLen > bestLen) 
    {
        bestLen = currLen;
        bestStart = currStart;
    }

    printf("Nai-dylgata monotonno narastvashta / namalqvashta redica: ");
    for(int i = bestStart; i < bestStart + bestLen; i++) 
    {
        printf("%d ", arr[i]);
    }
}



void ex7()
{
    int n;

    printf("Vyvedete N: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Vyvedete element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int tyrsena_suma;

    printf("\nVyvedete tyrsena suma: ");
    scanf("%d", &tyrsena_suma);

    int sum = 0, sum_elem[n], found = 0;

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            // printf("waht suma: %d\n", sum);

            sum_elem[j] = arr[j];

            if (sum == tyrsena_suma) 
            {
                found = 1;
                printf("NAMERIH SUMA!\n");
                break;
            }
        }

        // printf("Suma %d: %d\n", i+1, sum);
        // printf("Elementi: ");

        // for (int i = 0; i < n; i++)
        // {
        //     printf("%d ", sum_elem[i]);
        // }
        // printf("\n");

        if (found) break;
        else if (!found)
        {
            // printf("vlizam li?");
            // sum = 0;
            // printf("nov sum: %d\n", sum);
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                sum_elem[j] = 0;
            }
        }
    }

    printf("Posledovatelni elementi v masiva praveshti sumata %d sa: ", tyrsena_suma);
    for (int i = 0; i < n; i++)
    {
        if (sum_elem[i] != 0) printf("%d ", sum_elem[i]);
    }

}


void ex8()
{
    int arr[20];
    int size = 10;

    printf("Vyvedete pyrvite 10 chisla v masiva!\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Vyvedete element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    while (size < 20)
    {
        int element;
        printf("Vyvedete chislo (0 za krai): ");
        scanf("%d", &element);

        if (element == 0)
            break;

        int index;
        printf("Vyvedete index: ");
        scanf("%d", &index);

        for (int i = size; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[index] = element;
        size++;
    }

    printf("Celiqt masiv izglejda taka: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void ex9() 
{
    int n;

    printf("Vyvedete N: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Vyvedete element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int bestStart = 0, bestLen = 1;
    int currStart = 0, currLen = 1;

    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i - 1]) {
            currLen++;
        } else {
            if(currLen > bestLen) {
                bestLen = currLen;
                bestStart = currStart;
            }
            currStart = i;
            currLen = 1;
        }
    }

    if(currLen > bestLen) {
        bestLen = currLen;
        bestStart = currStart;
    }

    printf("Tova e maksimalnata redica ot posledovatelni ednakvi elementi v masiva: ");
    for(int i = bestStart; i < bestStart + bestLen; i++) 
    {
        printf("%d ", arr[i]);
    }
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

    case 9: ex9(); break;
    
    default:
        printf("Nqma takava zadacha");
        break;
    }

    return 0;

}
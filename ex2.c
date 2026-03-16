#include <stdio.h>

int ex1_bigger(int a, int b)
{

    if (a == b)
    {
        printf("Chislata sa ravni! returning a..\n");
        return a;
    }
    else if (a > b) 
    {
        printf("a e po-golqmo!\n"); 
        return a;
    }
    else
    {
        printf("b e po-golqmo!\n");
        return b;
    } 
}

int ex1_smaller(int a, int b)
{
    if (a == b)
    {
        printf("Chislata sa ravni! returning a..\n");
        return a;
    }
    else if (a < b) 
    {
        printf("a e po-malko!\n"); 
        return a;
    }

    else
    {
        printf("b e po-malko!\n");
        return b;
    } 
}

void ex1()
{
    int a, b, bigger_num, smaller_num, i = 0;
    int max = 0, min = 0;

    while (1)
    {
        printf("Vyvedete a: ");
        scanf("%d", &a);

        if (a == 0) break;

        printf("Vyvedete b: ");
        scanf("%d", &b);

        if (b == 0) break;

        bigger_num = ex1_bigger(a, b);
        smaller_num = ex1_smaller(a, b);

        if (max < bigger_num) max = bigger_num;
        if (!i) min = smaller_num;
        else if (min > smaller_num && smaller_num != 0) min = smaller_num;

        i++;

    }

    printf("Nai-golqmoto vyvedeno chislo do sega e bilo: %d\n", max);
    printf("Nai-malkoto vyvedeno chislo do sega e bilo: %d\n", min);
    
}



void ex2() 
{
    int chas, min;

    printf("vyvedete chas(0-23): ");
    scanf("%d", &chas);
    while (chas > 23 || chas < 0)
    {
        printf("vyvedete chas(0-23)!: ");
        scanf("%d", &chas);
    }

    printf("vyvedete minuti(0-59): ");
    scanf("%d", &min);
    while (min > 59 || min < 0)
    {
        printf("vyvedete minuti(0-59)!: ");
        scanf("%d", &min);
    }

    if (min + 15 > 60) 
    {
        chas++;
        
        int ostatyk = (min + 15) - 60;

        if (ostatyk < 10) printf("Chasyt sled 15 min e: %d:0%d", chas, ostatyk);
        else printf("Chasyt sled 15 min e: %d:%d", chas, ostatyk);
    }

    else
    {
        if (min < 10) printf("Chasyt sled 15 min e: %d:0%d", chas, min);
        else printf("Chasyt sled 15 min e: %d:%d", chas, min);
    } 
}

void ex3()
{
    float a, b, c;

    printf("Vyvedete 3 chisla: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == b && b == c) printf("yes");
    else printf("no");
}


void ex4()
{
    int tochki;

    printf("Vyvedete broi tochki: ");
    scanf("%d", &tochki);

    int bonus = 0;

    if (tochki < 100) bonus += 5;
    else if (tochki > 100) bonus += tochki * 2 / 10;
    else if (tochki > 1000) bonus += tochki / 10;

    if (tochki % 2 == 0) bonus++;
    if (tochki % 10 == 5) bonus += 2;

    printf("Bonusi: %d\n", bonus);
    printf("Tochki sled bonusite: %d\n", tochki + bonus);
}

void ex5()
{
    int a, b, c;

    printf("Vyvedete vremenata na 3mata systezateli: ");
    scanf("%d %d %d", &a, &b, &c);

    int sum = a + b + c;
    int min = sum / 60;
    int sec = sum - min*60;

    if (sec < 10)
    {
        printf("Sumarno vreme: %d:0%d", min, sec);
    }

    else printf("Sumarno vreme: %d:%d", min, sec);
}

void ex6() //////
{
    int x, y, x1, y1, x2, y2;

    printf("x: ");
    scanf("%d", &x);

    printf("y: ");
    scanf("%d", &y);

    printf("x1: ");
    scanf("%d", &x1);

    printf("y1: ");
    scanf("%d", &y1);

    printf("x2: ");
    scanf("%d", &x2);

    printf("y2: ");
    scanf("%d", &y2);

    // while (x1 < x2 || y1 > y2)
    // {
    //     printf("x1 < x2 !! y1 < y2");

    //     printf("x1: ");
    //     scanf("%d", &x1);

    //     printf("y1: ");
    //     scanf("%d", &y1);

    //     printf("x2: ");
    //     scanf("%d", &x2);

    //     printf("y2: ");
    //     scanf("%d", &y2);
    // }

    if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
    {
        printf("Inside\n");
    }
    else
    {
        printf("Outside\n");
    }


}


void ex7()
{
    int kilo;
    char ch;

    printf("Broi kilometri: ");
    scanf("%d", &kilo);

    printf("Chast ot denq(D/N): ");
    scanf(" %c", &ch);

    float taksi, avtobus, vlak;

    if (kilo < 20)
    {
        if (ch == 'D')
        {
            taksi = 1.7 + 0.79 * (kilo - 1);
        }
        else if (ch == 'N')
        {
            taksi = 1.7 - 0.9 * (kilo - 1);
        }

        printf("Edinstveno taksito vyrshi rabota za cena: %d", taksi);
    }



    if (kilo >= 20)
    {
        avtobus = kilo * 0.09;

        if (taksi < avtobus)
        {
            printf("Taksito vyrshi rabota za cena: %d", taksi);
        }

        else printf("Avtobusyt vyrshi rabota za cena: %d", avtobus);
    }

    if (kilo >= 100)
    {
        if (taksi < avtobus && taksi < vlak)
        {
            printf("Taksito vyrshi rabota za cena: %d", taksi);
        }

        else if (avtobus < taksi && avtobus < vlak)
        {
            printf("Avtobusyt vyrshi rabota za cena: %d", avtobus);
        }
        
        else printf("Vlakyt vyrshi rabota za cena: %d", vlak);
    }


}

void ex8() ////
{
    int V;
    int pipe1;
    int pipe2;
    int N;

    printf("V: ");
    scanf("%d", &V);

    printf("Pipe 1: ");
    scanf("%d", &pipe1);

    printf("Pipe 2: ");
    scanf("%d", &pipe2);

    printf("N: ");
    scanf("%d", &N);

    int pool_liters = V * 1000;
    int water = (pipe1 + pipe2) * N;

    if (water <= pool_liters) {
        double percent_full = (water * 100.0) / pool_liters;
        double pipe1_percent = (pipe1 * N * 100.0) / water;
        double pipe2_percent = (pipe2 * N * 100.0) / water;

        printf("The pool is %.2f%% full. Pipe1: %.2f%%. Pipe2: %.2f%%\n",
               percent_full, pipe1_percent, pipe2_percent);
    } else {
        int overflow = water - pool_liters;
        printf("For %d hours the pool overflows with %d liters\n", N, overflow);
    }
}

void ex9() /////
{
    int X;       
    double Y;    
    int Z;       
    int workers;

    printf("X: ");
    scanf("%d", &X);

    printf("Y: ");
    scanf("%lf", &Y);

    printf("Z: ");
    scanf("%d", &Z);

    printf("Broi workers: ");
    scanf("%d", &workers);

    double total_grapes = X * Y;
    double wine_grapes = total_grapes * 0.40;
    double wine = wine_grapes / 2.5;

    if (wine < Z) {
        printf("It will be a tough winter! More %.2f liters wine needed.\n", Z - wine);
    } 
    else {
        double leftover = wine - Z;
        double per_worker = leftover / workers;

        printf("Good harvest this year! Total wine: %.2f liters.\n", wine);
        printf("%.2f liters left -> %.2f liters per person.\n", leftover, per_worker);
    }
}

void ex10() //////
{
    int n;
    printf("Broi chisla: ");
    scanf("%d", &n);

    int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (num < 200) {
            p1++;
        }
        else if (num <= 399) {
            p2++;
        }
        else if (num <= 599) {
            p3++;
        }
        else if (num <= 799) {
            p4++;
        }
        else {
            p5++;
        }
    }

    printf("%.2f%%\n", p1 * 100.0 / n);
    printf("%.2f%%\n", p2 * 100.0 / n);
    printf("%.2f%%\n", p3 * 100.0 / n);
    printf("%.2f%%\n", p4 * 100.0 / n);
    printf("%.2f%%\n", p5 * 100.0 / n);

}

void ex11()
{
    int n, ostatyk_;

    printf("n: ");
    scanf("%d", &n);

    ostatyk_ = (n * 2) - 4 - (n/2)*2;

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            printf("/");
            for(int j = 0; j < n / 2; j++)
            {
                printf("^");
            }
            printf("\\");

            for (int k = 0; k < ostatyk_; k++)
            {
                printf("_");
            }

            printf("/");
            for(int j = 0; j < n / 2; j++)
            {
                printf("^");
            }
            printf("\\\n");

        }

        else if (i != n) 
        {
            printf("|");
            // for (int j = 0; j < (n * 2) - 2; j++)
            // {

                if (ostatyk_ > 0)
                {
                    for (int k = 0; k < (n*2 - 2 - ostatyk_)/2; k++)
                    {
                        printf(" ");
                    }

                    if (i == n-1)
                    {
                        for (int k = 0; k < ostatyk_; k++)
                        {
                            printf("_");
                        }
                    }

                    else
                    {
                        for (int k = 0; k < ostatyk_; k++)
                        {
                            printf(" ");
                        }
                    }

                    for (int k = 0; k < (n*2 - 2 - ostatyk_)/2; k++)
                    {
                        printf(" ");
                    }
                }

                else 
                {
                    for (int k = 0; k < n*2 - 2; k++)
                    {
                        printf(" ");
                    }
                }
            // }
            printf("|\n");
        }

        
        else if (i == n)
        {
            printf("\\");
            for(int j = 0; j < n / 2; j++)
            {
                printf("_");
            }
            printf("/");

            for (int k = 0; k < ostatyk_; k++)
            {
                printf(" ");
            }

            printf("\\");
            for(int j = 0; j < n / 2; j++)
            {
                printf("_");
            }
            printf("/\n");
        }
    }
}


void ex12()
{
    int n;

    printf("n: ");
    scanf("%d", &n);

    int shirina = 2 * n - 1;
    int visochina = 2 * (n - 2) + 1;

    int sreda = visochina / 2 + 1;

    // kolko pyti se namira 2 v n za ***

    for (int i = 1; i <= visochina; i++)
    {
        if (i == sreda)
        {
            for (int k = 0; k < shirina / 2; k++)
            {
                printf(" ");
            }

            printf("@");

            for (int k = 0; k < shirina / 2; k++)
            {
                printf(" ");
            }

            printf("\n");

        }

        else if (i == 0 || i % 2 == 1)
        {
            for (int j = 0; j < (shirina - 3)/2; j++)
            {
                printf("*");
            }

            if (i < sreda) printf("\\ /");
            else printf("/ \\");

            for (int j = 0; j < (shirina - 3)/2; j++)
            {
                printf("*");
            }
            printf("\n");
        }

        else if (i == 0 || i % 2 == 0)
        {
            for (int j = 0; j < (shirina - 3)/2; j++)
            {
                printf("-");
            }

            if (i < sreda) printf("\\ /");
            else printf("/ \\");

            for (int j = 0; j < (shirina - 3)/2; j++)
            {
                printf("-");
            }
            printf("\n");
        }
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

    case 10: ex10(); break;

    case 11: ex11(); break;

    case 12: ex12(); break;
    
    default:
        printf("Nqma takava zadacha");
        break;
    }

    return 0;

}
#include <stdio.h>
#include <math.h>


void ex1()
{
    for(int i=1; i<11; i++)
    {
        printf("%d\n", i);
    }
}

void ex2()
{
    for(int i=1; i<11; i++)
    {
        for (int j=0; j<i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void ex3()
{
    char ch;
    printf("Vyvedete znak: ");
    scanf("%c", &ch);

    for (int i=0; i<5; i++)
    {
        if (i==0 || i==4)
        {
            for(int j=0; j<10; j++)
            {
                printf("%c", ch);
            }
            printf("\n");
        }

        else
        {
            printf("%c", ch);
            for (int j=0; j<8; j++)
            {
                printf(" ");
            }
            printf("%c", ch);
            printf("\n");
        }
    }
}


void ex4() ////
{
    char ch;
    int n = 5;

    printf("Vyvedete simvol: ");
    scanf(" %c", &ch);

    // pyrvi triygylnik

    for (int i = 1; i <= n; i++)
    {

        for (int j = i; j < n; j++)
            {
                printf(" ");
            }
            printf("%c", ch);
            // printf("\n");

            if (i > 1 && i != n)
            {
                for (int k = 1; k < i*2 - 2; k++)
                {
                    printf(" ");
                }

                printf("%c\n", ch);
                
            }

            else if (i == n)
            {
                for (int k = 1; k < 2*i - 2; k++)
                {
                    printf("%c", ch);
                }

                printf("%c", ch);
            }

            else printf("\n");
    }

    printf("\n");

    // vtori triygylnik

    for (int i = n; i > 0; i--)
    {

        for (int j = i; j < n; j++)
            {
                printf(" ");
            }
            printf("%c", ch);
            // printf("\n");

            if (i > 1 && i != n)
            {
                for (int k = 1; k < i*2 - 2; k++)
                {
                    printf(" ");
                }

                printf("%c\n", ch);
                
            }

            else if (i == n)
            {
                for (int k = 1; k < 2*i - 2; k++)
                {
                    printf("%c", ch);
                }

                printf("%c\n", ch);
            }

            else printf("\n");
    }
}


void ex5()
{
    float inches;
    int otg;

    printf("Vyvedete inchove: ");
    scanf("%f", &inches);

    printf("Izberete da preobrazite inchovete v:\n");
    printf("(1) mm\n (2) cm\n (3) m\n otg: ");
    scanf("%d", &otg);

    switch (otg)
    {
    case 1:
        printf("Inches to mm: %.2f mm", inches*25.4);
        break;

    case 2:
        printf("Inches to cm: %.2f cm", inches*2.54);
        break;

    case 3:
        printf("Inches to m: %.2f m", inches*0.0254);
        break;
    
    default:
        printf("vyvedete (1), (2) ili (3)!!");
        break;
    }
}

void ex6()
{
    float celsii;

    printf("Vyvedete gradusi v celsii: ");
    scanf("%f", &celsii);

    printf("Tezi gradusi v celsii sa ravni na: %.2f v Farenhait", celsii*9/5 + 32);

}


void ex7()
{
    float gradusi;
    float pi = 3.14;

    printf("Vyvedete gradusi: ");
    scanf("%f", &gradusi);

    printf("Tezi gradusi sa ravni na %.4f v radiani", gradusi*pi/180);
}

void ex8()
{
    float leva;
    int otg;

    printf("Vyvedete kolko leva imate: ");
    scanf("%f", &leva);

    printf("Izberete da konvertirate levovete v:\n");
    printf("(1) dolari\n (2) evro\n (3) paundove\n otg: ");
    scanf("%d", &otg);

    switch (otg)
    {
    case 1:
        printf("Leva v dolari: %.2f $", leva*0.6);
        break;

    case 2:
        printf("Leva v evro: %.2f €", leva*0.51);
        break;

    case 3:
        printf("Leva v paundove: %.2f £", leva*0.44);
        break;
    
    default:
        printf("vyvedete (1), (2) ili (3)!!");
        break;
    }
}

void ex9()
{
    float a, b, h;

    printf("Vyvedete strana (a) na trapeca: ");
    scanf("%f", &a);

    printf("Vyvedete strana (b) na trapeca: ");
    scanf("%f", &b);

    printf("Vyvedete visochinata (h) na trapeca: ");
    scanf("%f", &h);

    float lice = (a+b)*h/2;

    printf("Liceto na tozi trapec e: %.2f", lice);
}


void ex10()
{
    float gradusi, radiani;
    float pi=3.14;

    printf("Vyvedete gradusi: ");
    scanf("%f", &gradusi);

    radiani = gradusi * pi / 180;

    printf("Sin(%f) e raven na %.2f\n", gradusi, sin(radiani));
    printf("Cos(%f) e raven na %.2f\n", gradusi, cos(radiani));
    printf("Tg(%f) e raven na %.2f\n", gradusi, tan(radiani));
    printf("Cotg(%f) e raven na %.2f\n", gradusi, 1/tan(radiani));

}


void ex11()
{
    int x1, y1, x2, y2;

    printf("Vyvedete koordinati na tochka A(x, y): ");
    scanf("%d %d", &x1, &y1);

    // printf("%d %d", x1, y1);

    printf("Vyvedete koordinati na tochka B(x, y): ");
    scanf("%d %d", &x2, &y2);

    // printf("%d %d", x2, y2);


    int strana_a = abs(x2 - x1), strana_b = abs(y2 - y1), lice;

    lice = strana_a * strana_b;
    printf("Liceto na pravoygylnika e ravno na: %d", lice);

}


void ex12()
{
    int x1, y1, x2, y2, x3, y3;

    printf("Vyvedete koordinati na tochka A(x, y): ");
    scanf("%d %d", &x1, &y1);

    printf("Vyvedete koordinati na tochka B(x, y): ");
    scanf("%d %d", &x2, &y2);

    printf("Vyvedete koordinati na tochka C(x, y): ");
    scanf("%d %d", &x3, &y3);

    int lice = abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2;

    // printf("umm %d", abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)));

    printf("Liceto na triygulnika syzdaden ot tezi tochki e ravno na: %d", lice);

}


void ex13()
{
    float w, h;

    printf("Vyvedete shirina (w) i dyljina (h) na uchebnata zala: ");
    scanf("%f %f", &w, &h);

    float mqsto_w = 1.2;
    float mqsto_h = 0.7;

    float w_bez_koridor = w - 1;

    int mesta_w = (int)(w_bez_koridor / mqsto_w);
    int mesta_h = (int)(h / mqsto_h);

    int broi_mesta = mesta_w * mesta_h - 3;

    printf("Broi rabotni mesta v zalata: %d", broi_mesta);
}

void ex14()
{
    float cena_plod, kg_plod, cena_zelen, kg_zelen;

    printf("Cena za kg zelenchuci: ");
    scanf("%f", &cena_zelen);

    printf("Cena za kg plodove: ");
    scanf("%f", &cena_plod);

    printf("Obshto kg zelenchuci: ");
    scanf("%f", &kg_zelen);

    printf("Obshto kg plodove: ");
    scanf("%f", &kg_plod);

    float pechalba_zelenchuci = cena_zelen * kg_zelen;
    float pechalba_plodove = cena_plod * kg_plod;

    float pechalba = (pechalba_plodove + pechalba_zelenchuci)/1.95;

    printf("Pechalba ot rekoltata: %.2f evro", pechalba);

}

void ex15()
{
    float N; 
    float W, L; 
    float M, O; 

    printf("Vyvedete strana na ploshtadka N: ");
    scanf("%f", &N);

    printf("Vyvedete shirina i dyljina na plochkata W L: ");
    scanf("%f %f", &W, &L);

    printf("Vyvedete shirina i dyljina na peikata M O: ");
    scanf("%f %f", &M, &O);

    float ploshtadka = N * N;
    float peika = M * O;
    float plosht_za_pokrivane = ploshtadka - peika;
    float plochka = W * L;

    float broi_plochki = plosht_za_pokrivane / plochka;

    float vreme = broi_plochki * 0.2;

    // printf("Plosht na ploshtadka: %.2f\n", ploshtadka);
    // printf("Plosht za pokrivane: %.2f\n", plosht_za_pokrivane);
    printf("Neobhodimi broi plochki: %.2f\n", broi_plochki);
    printf("Neobhodimo vreme (minuti): %.2f\n", vreme);
    
}


void ex16()
{
    float N, M, kurs;

    printf("Vyvedete sreden broi rabotni dni N: ");
    scanf("%f", &N);

    printf("Vyvedete dredno izkarani dolara za den M: ");
    scanf("%f", &M);

    printf("Vyvedete kurs na dolara: ");
    scanf("%f", &kurs);

    float mesechna_zaplata = N * M;
    float godishna_zaplata = mesechna_zaplata * 12;
    float bonus = 2.5 * mesechna_zaplata;
    float netno = godishna_zaplata * 0.75;

    float sredno_dolari = netno / 365.0;

    float sredno_leva = sredno_dolari * kurs;

    printf("Chista sredna pechalba na den v leva: %.2f\n", sredno_leva);
}

int main()
{

    int otg;
    printf("Izberete zadacha: ");
    scanf("%d", &otg);

    switch (otg)
    {
    case 1:
        ex1();
        break;
    
    case 2:
        ex2();
        break;

    case 3:
        ex3();
        break;

    case 4:
        ex4();
        break;
    
    case 5:
        ex5();
        break;

    case 6:
        ex6();
        break;

    case 7:
        ex7();
        break;

    case 8:
        ex8();
        break;

    case 9:
        ex9();
        break;

    case 10:
        ex10();
        break;

    case 11:
        ex11();
        break;

    case 12:
        ex12();
        break;

    case 13:
        ex13();
        break;
    
    case 14:
        ex14();
        break;

    case 15:
        ex15();
        break;

    case 16:
        ex16();
        break;
    
    default:
        printf("Nqma takava zadacha");
        break;
    }

    return 0;
}


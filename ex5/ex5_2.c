#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    float price;
    int id;
} Product;

typedef struct {
    char address[100];
    int product_id;
} Order;

int main() {
    Product products[MAX];
    Order waiting[MAX];

    int product_count = 0;
    int waiting_count = 0;

    char command[20];

    while (1) {
        printf("Vyvedete komanda (END, Product, Order): ");
        scanf("%s", command);

        if (strcmp(command, "END") == 0)
            break;

        if (strcmp(command, "Product") == 0) {
            Product p;
            Printf("Ime na producta, Cenata mu, ID-to: ");
            scanf("%s", p.name);
            scanf("%f", &p.price);
            scanf("%d", &p.id);

            products[product_count++] = p;

            for (int i = 0; i < waiting_count; i++) {
                if (waiting[i].product_id == p.id) {
                    printf("Client %s ordered %s\n", waiting[i].address, p.name);

                    for (int j = i; j < waiting_count - 1; j++) {
                        waiting[j] = waiting[j + 1];
                    }
                    waiting_count--;
                    i--;
                }
            }
        }

        else if (strcmp(command, "Order") == 0) {
            Order o;
            printf("Address na Klient, ID na zakupen product: ");
            scanf("%s", o.address);
            scanf("%d", &o.product_id);

            int found = 0;

            for (int i = 0; i < product_count; i++) {
                if (products[i].id == o.product_id) {
                    printf("Client with address %s ordered %s\n", o.address, products[i].name);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                waiting[waiting_count++] = o;
            }
        }
    }

    return 0;
}
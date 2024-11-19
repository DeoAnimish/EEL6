#include <stdio.h>
//#include <string.h>

int calculateTotal(int n, int *costs) {
    if (n == 0) {
        return 0;
    } else {
        return costs[n - 1] + calculateTotal(n - 1, costs);
    }
}

int main() {
    int n = 10, costs[10];
    char itemNames[10][20];
    start : 
    printf("Enter item names and costs:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d name: ", i+1 );
        scanf("%s", itemNames[i]);
        printf("Item %d cost: ", i+1 );
        scanf("%d", &costs[i]);
        if (costs[i]<0)
        {
            printf("Cost may nont be negative\n");
            goto start;
        }
    }

    int total = calculateTotal(n, costs);

    printf("________________________________|\n");
    printf("|           SHOPPING BILL       |\n");
    printf("|_______________________________|\n");
    printf("| ITEM NAME  |    COST(RUPIES)  |\n");
    printf("|_______________________________|\n");
    for (int i = 0; i < n; i++) {
        printf("| %-10s |      %-5u       |\n", itemNames[i], costs[i]);
    }
    printf("|       TOTAL BILL=%-5u        |\n", total);
    printf("|______________________________|\n");

    return 0;
}
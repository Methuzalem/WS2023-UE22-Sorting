#include <stdio.h>

void selection_sort(int a[], int nummern, int *vergleich, int *getauscht) {
    int min = 0;
    int t = 0;

    *vergleich = 0;
    *getauscht = 0;

    for(int i = 0; i < nummern-1; i++) {
        min = i;
        for (int j = i+1; j < nummern; j++) {
            (*vergleich)++;
            if (a[j] < a[min]) {
                min = j;
            }
        }

        (*getauscht)++;
    printf("Step %d: ", *getauscht);
    for (int k = 0; k < nummern; k++) {
        if (k == min && k == i){
            printf("[(%d)] ", a[k]);
        }else if (k == i){
            printf("(%d) ", a[k]);
        }else if (k == min){
            printf("[%d] ", a[k]);
        }else{
            printf("%d ", a[k]);
        }
        }
        printf("\n");

        if (min != i) {
            t = a[min];
            a[min] = a[i];
            a[i] = t;
        }
    }
}

int main() {
    int nummern[1024];
    int count = 0;
    int num = 0;
    int vergleiche = 0;
    int tausch = 0;

    printf(": \n");
        while (1) {
            scanf("%d", &num);
            if (num == 0)
                break;
            nummern[count++] = num;
        }

    selection_sort(nummern, count, &vergleiche, &tausch);

    printf("Result: ");
        for (int i = 0; i < count; i++){
            printf("%d ", nummern[i]);
        }
    printf("\n\n");

    printf("Number of comparisons: %d\n", vergleiche);
    printf("Number of swaps: %d\n", tausch);

    return 0;
}

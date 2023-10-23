#include <stdio.h>
#include <omp.h>

int main() {
    int n = 1000;
    int array[n];
    int sum = 0;

    // Inisialisasi array
    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
    }

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }

    printf("Jumlah: %d\n", sum);

    return 0;
}

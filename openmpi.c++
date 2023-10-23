#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size;
    
    MPI_Init(&argc, &argv); // Inisialisasi MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Mendapatkan rank proses
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Mendapatkan jumlah total proses
    
    printf("Proses %d dari total %d proses\n", rank, size);
    
    if (rank == 0) {
        // Proses dengan rank 0 mengirim pesan ke proses dengan rank 1
        int data = 42;
        MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Proses 0 mengirim data: %d\n", data);
    } else if (rank == 1) {
        // Proses dengan rank 1 menerima pesan dari proses dengan rank 0
        int received_data;
        MPI_Recv(&received_data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Proses 1 menerima data: %d\n", received_data);
    }
    
    MPI_Finalize(); // Finalisasi MPI
    
    return 0;
}

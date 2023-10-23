#include <iostream>
#include <chrono>
#include <vector>

const int N = 5; // Ubah sesuai ukuran matriks Anda

int A[N][N], B[N][N], C[N][N], D[N][N], E[N][N];

// Fungsi untuk menjumlahkan matriks
void addMatrices() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Fungsi untuk mengurangkan matriks
void subtractMatrices() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            D[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Fungsi untuk mengalikan matriks
void multiplyMatrices() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            E[i][j] = 0;
            for (int k = 0; k < N; k++) {
                E[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // Inisialisasi matriks A dan B
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i * N + j;
            B[i][j] = j * N + i;
        }
    }
    // Tampilkan hasil inisialisasi matriks A
    std::cout << "Matriks A (inisialisasi):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Tampilkan hasil inisialisasi matriks B
    std::cout << "Matriks B (inisialisasi):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << B[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Operasi Penjumlahan Matriks
    auto start_time = std::chrono::high_resolution_clock::now();
    addMatrices();
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;

    // Tampilkan hasil operasi penjumlahan matriks
    std::cout << "Hasil Penjumlahan Matriks:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << C[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "Waktu penjumlahan matriks: " << duration.count() << " detik\n";

    // Operasi Pengurangan Matriks
    start_time = std::chrono::high_resolution_clock::now();
    subtractMatrices();
    end_time = std::chrono::high_resolution_clock::now();
    duration = end_time - start_time;

    // Tampilkan hasil operasi pengurangan matriks
    std::cout << "Hasil Pengurangan Matriks:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << D[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "Waktu pengurangan matriks: " << duration.count() << " detik\n";

    // Operasi Perkalian Matriks
    start_time = std::chrono::high_resolution_clock::now();
    multiplyMatrices();
    end_time = std::chrono::high_resolution_clock::now();
    duration = end_time - start_time;

    // Tampilkan hasil operasi perkalian matriks
    std::cout << "Hasil Perkalian Matriks:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << E[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "Waktu perkalian matriks: " << duration.count() << " detik\n";

    return 0;
}

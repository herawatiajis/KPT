#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

const int N = 5; // Ubah sesuai ukuran matriks Anda

int A[N][N], B[N][N], C[N][N], D[N][N], E[N][N];

// Fungsi untuk menjumlahkan matriks
void addMatrices(int start, int end) {
    for (int i = start; i < end; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Fungsi untuk mengurangkan matriks
void subtractMatrices(int start, int end) {
    for (int i = start; i < end; i++) {
        for (int j = 0; j < N; j++) {
            D[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Fungsi untuk mengalikan matriks
void multiplyMatrices(int start, int end) {
    for (int i = start; i < end; i++) {
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

        // Menentukan jumlah thread yang akan digunakan
        int numThreads = std::thread::hardware_concurrency();
        std::vector<std::thread> threads;

    // Menentukan jumlah baris yang akan diproses oleh setiap thread
    int rowsPerThread = N / numThreads;

    // Membuat dan menjalankan thread-thread untuk penjumlahan matriks
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numThreads; i++) {
        int start = i * rowsPerThread;
        int end = (i == numThreads - 1) ? N : (i + 1) * rowsPerThread;
        threads.emplace_back(addMatrices, start, end);
    }

    // Menunggu thread-thread selesai
    for (std::thread &t : threads) {
        t.join();
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;

    // Tampilkan hasil operasi matriks
    std::cout << "Hasil Penjumlahan Matriks:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << C[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "Waktu penjumlahan matriks: " << duration.count() << " detik\n";

    // Reset hasil
    threads.clear();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
        }
    }

    // Membuat dan menjalankan thread-thread untuk pengurangan matriks
    start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numThreads; i++) {
        int start = i * rowsPerThread;
        int end = (i == numThreads - 1) ? N : (i + 1) * rowsPerThread;
        threads.emplace_back(subtractMatrices, start, end);
    }

    // Menunggu thread-thread selesai
    for (std::thread &t : threads) {
        t.join();
    }

    end_time = std::chrono::high_resolution_clock::now();
    duration = end_time - start_time;

    // Tampilkan hasil operasi matriks
    std::cout << "Hasil Pengurangan Matriks:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << D[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "Waktu pengurangan matriks: " << duration.count() << " detik\n";

    // Reset hasil
    threads.clear();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            D[i][j] = 0;
        }
    }

    // Membuat dan menjalankan thread-thread untuk perkalian matriks
    start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numThreads; i++) {
        int start = i * rowsPerThread;
        int end = (i == numThreads - 1) ? N : (i + 1) * rowsPerThread;
        threads.emplace_back(multiplyMatrices, start, end);
    }

    // Menunggu thread-thread selesai
    for (std::thread &t : threads) {
        t.join();
    }

    end_time = std::chrono::high_resolution_clock::now();
    duration = end_time - start_time;

    // Tampilkan hasil operasi matriks
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

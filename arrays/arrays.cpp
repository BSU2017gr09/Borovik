#include <iostream>
#include <cstring>
#include <iomanip>
#include <unistd.h>

/*
 * Симметричные матрицы А(N,N) и В(N,N), заданные нижними
треугольниками в виде одномерных массивов относительно побочной
диагонали, умножить друг на друга. В памяти матрицы не получать.
 *
 */

unsigned long long int getTotalSystemMemory() {
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    return pages * page_size;
}

void input_example(int **arr, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j > i) { arr[i][j] = 0; }
            else { arr[i][j] = N - i + j; }
        }
    }
}

void get_symmetrical_matrix(int **arr, int N, int **newarr) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            newarr[i][j] = 0;
            for (int k = 0; k < N; k++)
                newarr[i][j] += arr[i][k] * arr[k][j];
        }
    }
}

void print_matrix(int **arr, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            std::cout << std::setw(10) << arr[i][j];
        }
        std::cout << std::endl;
    }
}

void Allocate_memory(int **&str, int N) {
    try {
        str = new int *[N];
        for (int i = 0; i < N; i++) {
            str[i] = new int[N];
        }
    }
    catch (...) {
        exit(0);
    }
}

void free(int **str, int N) {
    for (int i = 0; i < N; ++i) {
        delete[] str[i];
    }
    delete[] str;
}

void multiply_arr(int **arr, int **secondarr, int N, int **newarr) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            newarr[i][j] = 0;
            for (int k = 0; k < N; k++)
                newarr[i][j] += arr[i][k] * secondarr[k][j];
        }
    }
}

int main() {
    std::cout << "Available memory: ";
    std::cout << getTotalSystemMemory() << std::endl;
    int N = 0;
    std::cin >> N;
    int **arrexample = nullptr;
    int **arr = nullptr;
    int **secondarr = nullptr;
    int **multipl = nullptr;
    Allocate_memory(arrexample, N);
    Allocate_memory(arr, N);
    Allocate_memory(secondarr, N);
    Allocate_memory(multipl, N);
    input_example(arrexample, N);
    get_symmetrical_matrix(arrexample, N, arr);
    get_symmetrical_matrix(arrexample, N, secondarr);
    std::cout << "For instruction input 5" << std::endl;
    while (true) {
        int operation = 0;
        std::cout << "Enter the number of the operation: ";
        std::cin >> operation;
        switch (operation) {
            case 1: {
                print_matrix(arr, N);
                break;
            }
            case 2: {
                print_matrix(secondarr, N);
                break;
            }
            case 3: {
                multiply_arr(arr, secondarr, N, multipl);
                print_matrix(multipl, N);
                break;
            }

            case 4: {
                free(arr, N);
                free(secondarr, N);
                free(arrexample, N);
                free(multipl, N);
                exit(3);
            }
            case 5: {
                std::cout << "1 - Display the first array" << std::endl;
                std::cout << "2 - Display the second array" << std::endl;
                std::cout << "3 - Multiply arrays and get result" << std::endl;
                std::cout << "4 - Exit" << std::endl;
            }
            default:
                std::cout << "Operation doesn't exists, try again " << std::endl;
                std::cout << std::endl;
                break;
        }
    }

}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <cmath>
#include <ctime>
//Элементы целочисленного массива А(N), значения которых оказались простыми числами, расположить в порядке возрастания, не нарушая порядка следования других элементов.
unsigned long long int getTotalSystemMemory() {
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    return pages * page_size;
}

void inputArray(int *arr, int N) {
    for (int i = 0; i < N; ++i) { *(arr + i) = rand() % (10 * N); }
}

void printArray(int *arr, int N) {
    for (int i = 0; i < N; ++i) { std::cout << *(arr + i) << " "; }
    std::cout << std::endl;
}

bool isPrime(int number) {
    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) { return false; }
    }
    return true;
}

void sort(int *arr, int N) {
    int save = true;
    while (save) {
        save = false;
        for (int i = 0; i < N; ++i) {
            if (isPrime(*(arr + i))) {
                for (int j = i; j < N; ++j) {
                    if (isPrime(*(arr + j)) && (*(arr + j) < *(arr + i))) {
                        std::swap(*(arr + j), *(arr + i));
                        save = true;
                    }
                }
            }
        }
    }
}

void allocate(int *&arr, int N) {
    /*решил использовать упомянутый на лекции alloc и free
     покопавшись на stackoverflow нашел несколько способов ипользования
     malloc в самой функции и free в main()*/
    arr = (int *) malloc(N * sizeof(int));
    std::cout << "Allocated memory: " << N * sizeof(int) << std::endl;
    if (arr != nullptr) {
        for (int i = 0; i < N; i++)
            *(arr + i) = i;
    } else {
        std::cout << "Couldn't allocate memory";
        exit(3);
    }
}

int main() {
    std::cout << "Available memory: ";
    std::cout << getTotalSystemMemory() << std::endl;
    int N = 0;
    std::cout << "N = ";
    std::cin >> N;
    int *arr;
    allocate(arr, N);
    inputArray(arr, N);
    std::cout << "Source array:" << std::endl;
    printArray(arr, N);
    sort(arr, N);
    std::cout << "Sorted array:" << std::endl;
    printArray(arr, N);
    free(arr);
    return 0;
}

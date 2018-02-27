#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <cmath>
//Даны точки плоскости своими координатами в виде двух одномерных массивов. Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.
unsigned long long int getTotalSystemMemory() {
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    return pages * page_size;
}

void inputArray(int *x, int *y, int N) {
    for (int i = 0; i < N; i++) {
        std::cin >> *(x + i);
        std::cin >> *(y + i);
    }
}

void allocatedouble(double *&arr, int N) {
    /*решил использовать упомянутый на лекции alloc и free
     покопавшись на stackoverflow нашел несколько способов ипользования
     malloc в самой функции и free в main()*/
    arr = (double *) malloc(N * sizeof(double));
    std::cout << "Allocated memory: " << N * sizeof(double) << std::endl;
    if (arr != nullptr) {
        for (int i = 0; i < N; i++)
            *(arr + i) = i;
    } else {
        std::cout << "Couldn't allocate memory";
        exit(3);
    }
}

void printArray(int *x, int *y, int N) {
    for (int i = 0; i < N; i++) { std::cout << "(" << *(x + i) << ";" << *(y + i) << ") "; }
    std::cout << std::endl;
}

void printArrayd(double *dist, int N) {
    for (int i = 0; i < N; i++) { std::cout << *(dist + i) << " "; }
    std::cout << std::endl;
}

void countDistance(int *x, int *y, double *dist, int a, int b, int c, int N) {
    for (int i = 0; i < N; i++) *(dist + i) = abs(a * x[i] + b * y[i] + c) / sqrt(a * a + b * b);
}

void sort(double *dist, int *x, int *y, int N) {
    int save = true;
    while (save) {
        save = false;
        for (int j = 0; j < N - 1; ++j) {
            if (*(dist + j) > *(dist + j + 1)) {
                std::swap(*(dist + j), *(dist + j + 1));
                std::swap(*(x + j), *(x + j + 1));
                std::swap(*(y + j), *(y + j + 1));
                save = true;
            }
        }
    }
}

void allocateint(int *&arr, int N) {
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
    int *x;
    int *y;
    double *dist;
    int a = 0, b = 0, c = 0;
    std::cout << "N = ";
    std::cin >> N;
    allocateint(x, N);
    allocateint(y, N);
    allocatedouble(dist, N);
    std::cout << "Enter the coefficients:" << std::endl;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "c = ";
    std::cin >> c;
    inputArray(x, y, N);
    std::cout << "Set of points:" << std::endl;
    printArray(x, y, N);
    countDistance(x, y, dist, a, b, c, N);
    sort(dist, x, y, N);
    std::cout << "Sorted points are in ascending order:" << std::endl;
    printArray(x, y, N);
    free(x);;
    free(y);
    return 0;
}

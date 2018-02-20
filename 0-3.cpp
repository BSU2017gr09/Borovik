#include <iostream>

//Массив чисел размера N проинициализировать случайными числами из промежутка от -N до N. Написать функцию циклического сдвига элементов массива вправо на k элементов.

void inputArray(int *arr, int N) {
    for (int i = 0; i < N; ++i) { *(arr + i) = (-N) + rand() % (2 * N); }
}

void printArray(int *arr, int N) {
    for (int i = 0; i < N; ++i) { std::cout << *(arr + i) << " "; }
    std::cout << std::endl;
}

void rightTransposition(int *arr, int N, int k) {
    int arrb[N];
    int save = 0;
    for (int l = N - 1; l >= 0; --l) {
        if ((l + k) >= N) {
            *(arrb + save) = *(arr + l);
            save++;
        }
    }
    for (int i = N - 1; i >= 0; --i) {
        if ((i + k) < N) {
            *(arr + i + k) = *(arr + i);
        }

    }
    for (int j = 0; j < save; ++j) {
        *(arr + j) = *(arrb + save - 1 - j);
    }
}


int main() {
    int N;
    int k;
    std::cin >> N;
    std::cout << "На сколько элементов сдвигать массив?" << std::endl;
    std::cin >> k;
    int *arr;
    try {
        arr = new int[N];
    }
    catch (...) {
        std::cout << "Нехватка памяти";
    }
    inputArray(arr, N);
    std::cout << "Сгенерированный массив" << std::endl;
    printArray(arr, N);
    rightTransposition(arr, N, k);
    std::cout << "Массив после сдвига:" << std::endl;
    printArray(arr, N);
    delete[] arr;
    return 0;
}





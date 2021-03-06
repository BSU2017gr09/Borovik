#include <iostream>

//В массиве размера N, заполненного случ.числами от 0 до 10, определить максимальную длину последовательности равных элементов.

void inputArray(int *arr, int N) {
    for (int i = 0; i < N; ++i) { *(arr + i) = rand() % 11; }
}


void printArray(int *arr, int N) {
    for (int i = 0; i < N; ++i) { std::cout << *(arr + i) << " "; }
    std::cout << std::endl;
}

int Countline(int *arr, int N) {
    int length = 1;
    int maxlen = 1;
    for (int i = 0; i < N; ++i) {
        if (*(arr + i) == *(arr + i + 1)) {
            length++;
        } else {
            if (length > maxlen) {
                maxlen = length;
            }
            length = 1;
        }

    }
    return maxlen;
}


int main() {
    int N;
    std::cin >> N;
    int *arr;

    try {
        arr = new int[N];
    }
    catch (...) {
        std::cout << "Нехватка памяти";// и что????? Продолжаем работать!!!!
    }

    inputArray(arr, N);

    std::cout << "Cгенерированный массив:" << std::endl;
    printArray(arr, N);
    std::cout << std::endl;

    std::cout << "Максимальная длинна последовательности" << std::endl;
    std::cout << Countline(arr, N) << std::endl;

    delete[] arr;
    return 0;
}





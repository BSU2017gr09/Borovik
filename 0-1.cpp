#include <iostream>

//В массиве размера N, заполненного случ.числами от 0 до 10, подсчитать количество элементов, встречающихся более одного раза.

void inputArray(int *arr, int N) {
    for (int i = 0; i < N; ++i) { *(arr + i) = rand() % 11; }
}

void printArray(int *arr, int N) {
    for (int i = 0; i < N; ++i) { std::cout << *(arr + i) << " "; }
    std::cout << std::endl;
}

int Countsamenumb(int *arr, int N) {
    int count = 0;
    int answer = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (*(arr + i) == *(arr + j)) {
                count++;
            }
        }
        if (count >= 1) { answer++; }
        if (count >= 2) { answer--; }
        count = 0;
    }
    return answer;
}

int main() {
    int N;
    std::cin >> N;
    int *arr;


    try {
        arr = new int[N];
    }
    catch (...) {
        std::cout << "Нехватка памяти";//// и что????? Продолжаем работать!!!!
    }

    inputArray(arr, N);

    std::cout << "Сгенерированный масcив:" << std::endl;
    printArray(arr, N);
    std::cout << std::endl;


    std::cout << "Количество элементов встречающихся более одного раза:" << std::endl;
    std::cout << Countsamenumb(arr, N) << std::endl;

    delete[] arr;
    return 0;
}





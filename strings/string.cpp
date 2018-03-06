#include <iostream>
#include <cstring>
#include <unistd.h>

//в строке найти и вывести на экран все слова в которых буквы упорядочены в порядке, обратном алфавтному
unsigned long long int getTotalSystemMemory() {
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    return pages * page_size;
}

void allocatememory(char *&str, int N) {
    try {
        str = new char[N];

        // std::cout << "Allocated memory: " << 255 * sizeof(char) << std::endl;
    }
    catch (...) {
        std::cout << "Couldn't allocate memory";
        exit(3);
    }
}

void checkstring(char *str, int N) {//the essence of the algorithm is to check each word in the second string
    int i = 0;
    int r = 0;
    char *newstr = nullptr;
    allocatememory(newstr, N);
    while (*(str + i)) {
        if (isalpha(*(str + i))) {//checking for a letter
            while (isalpha(*(str + i))) {//writing a word to the second string
                *(newstr + r) = *(str + i);
                i += 1;
                r++;
            }
            int k = 0;
            for (int j = 0; j < strlen(newstr); ++j) {//checking for an order of symbols
                if (tolower(*(newstr + j)) >= tolower(*(newstr + j + 1))) {
                    k += 1;
                }
            }
            if (k == strlen(newstr)) {//if the order is correct, prints the word
                std::cout << newstr << ' ';
            }
            for (int j = strlen(newstr); j > 0; --j) {//clear the second line from the word
                *(newstr + j) = '\0';
            }
            r = 0;
            k = 0;
        }
        i += 1;
    }
    delete[] newstr;
}

int main() {
    std::cout << "Available memory: ";
    std::cout << getTotalSystemMemory() << std::endl;
    const int N = 1000;
    char *str = nullptr;
    allocatememory(str, N);
    std::cout << "For instruction input 4" << std::endl;
    while (true) {
        int operation = 0;
        std::cout << "Enter the number of the operation: ";
        std::cin >> operation;
        switch (operation) {
            case 1: {
                std::cout << "Enter the string: ";
                std::cin.ignore();
                std::cin.getline(str, N);
                std::cout << std::endl;
                break;
            }
            case 2: {
                std::cout << "The right words: " << std::endl;
                checkstring(str, N);
                std::cout << std::endl;
                break;
            }
            case 3: {
                delete[] str;
                exit(3);
            }
            case 4: {
                std::cout << "1 - Enter the string" << std::endl;
                std::cout << "2 - Get words" << std::endl;
                std::cout << "3 - Exit" << std::endl;
            }
            default:
                std::cout << "Operation doesn't exists, try again " << std::endl;
                std::cout << std::endl;
                break;
        }
    }
}

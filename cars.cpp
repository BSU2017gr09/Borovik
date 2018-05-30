#include <iostream>
#include <cstring>

using namespace std;

class Auto {
private:
    char *mark;
    char *color;
    unsigned int price;
    unsigned  int year;


public:
    Auto() : year(0), price(0), mark(nullptr), color(nullptr) {};

    Auto(char *mark, char *color, int p = 0, int s = 0, int d = 0) : mark(nullptr), price(s), year(d), color(nullptr) {
        try {
            mark = new char[strlen(mark) + 1];
            color = new char[strlen(color) + 1];
        }
        catch (...) {
            exit(1);
        }
        strcpy(color, color);
        strcpy(mark, mark);
        
    }

    ~Auto() {
        delete[] mark;
        delete[] color;
    };

    
    
    Auto(Auto &other) : mark(nullptr), color(nullptr), year(other.year), price(other.price) {
        try {
            mark = new char[strlen(other.mark) + 1];
            color = new char[strlen(other.color) + 1];
        }
        catch (...) {
            exit(1);
        }
        strcpy(mark, other.mark);
        strcpy(color, other.color);
    };

    
    
    
    
    Auto &operator=(const Auto &other) {
        if (this == &other) {
            return *this;

        } else {
            delete[] mark;
            delete[] color;
        }
    };



    int getPrice() {
        return price;
    }

    int getYear() {
        return year;
    }
    
    char *getName() {
        return mark;
    }

    char *getColor() {
        return color;
    }
    

    void setName(char *str) {
        try {
            this->mark = new char[strlen(str) + 1];
        }
        catch (...) {
            exit(1);
        }
        strcpy(mark, str);
    }

    void setColor(char *str) {
        try {
            this->color = new char[strlen(str) + 1];
        }
        catch (...) {
            exit(1);
        }
        strcpy(color, str);
    }

    void setPrice(int price) {
        (*this).price = price;
    }

    void setYear(int year) {
        (*this).year = year;
    }

    friend ostream &operator<<(ostream &output, Auto &tmp) {
        cout << "Car mark: " << tmp.mark << endl << "Color: " << tmp.color << endl << "Price:" << tmp.price << " $ "<< endl;
        cout << "Year: " << tmp.year << endl;
        return output;
    }


};

void init(Auto *A, int N) {
    char *mark[] = {"Audi"};
    char *color[] = {"Purple", "Black"};
    int price[] = {3, 4, 5, 6, 7,};
    int year[] = {1001, 2004, 3004};
    for (int i = 0; i < N; i++) {
        A[i].setName(mark[0]);
        A[i].setColor(color[rand() % 2]);
        A[i].setPrice(price[rand() % 5]);
        A[i].setYear(year[rand() % 3]);

    }
}

int main() {
    int N = 10;
    Auto A[N];
    init(A, N);
    return 0;
}

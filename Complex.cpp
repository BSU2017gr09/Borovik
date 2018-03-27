#include <iostream>
#include <cmath>


class Complex {
private:
    float Re;
    float Im;
public:

    Complex(int r = 0, int i = 0) : Re(r), Im(i) {}

    Complex(const Complex &other) {
        this->Re = other.Re;
        this->Im = other.Im;
    }

    void operator=(const Complex &other) {
        Re = other.Re;
        Im = other.Im;
    }

    Complex operator+(const Complex &other) {
        Complex tmp;
        tmp.Re = this->Re + other.Re;
        tmp.Im = this->Im + other.Im;
        return tmp;
    }

    Complex operator-(const Complex &other) {
        Complex tmp;
        tmp.Re = this->Re - other.Re;
        tmp.Im = this->Im - other.Im;
        return tmp;
    }

    Complex operator*(const Complex &other) {
        Complex tmp;
        tmp.Re = (Re * other.Re) - (Im * other.Im);
        tmp.Im = (Re * other.Im) + (Im * other.Re);
        return tmp;
    }

    Complex operator/(const Complex &other) {
        float division = (other.Re * other.Re) + (other.Im * other.Im);
        Complex tmp;
        tmp.Re = (Re * other.Re) + (Im * other.Im);
        tmp.Re = tmp.Re / division;
        tmp.Im = (Im * other.Re) - (Re * other.Im);
        tmp.Im = tmp.Im / division;
        return tmp;
    }

    friend std::ostream &operator<<(std::ostream &output, Complex &tmp) {
        output << tmp.Re << '+' << tmp.Im << 'i';
        return output;
    }

    friend std::istream &operator>>(std::istream &input, Complex &tmp) {
        input >> tmp.Re;
        input.ignore();
        input >> tmp.Im;
        input.ignore();
        return input;
    }

    bool operator==(const Complex &tmp) const {
        return (Re == tmp.Re) && (Im == tmp.Im);
    }

    bool operator!=(const Complex &tmp) {
        return !((Re == tmp.Re) && (Im == tmp.Im));
    }

    Complex &operator+=(const Complex &other) {
        Re += other.Re;
        Im += other.Im;
        return *this;
    };

    Complex &operator-=(const Complex &other) {
        Re -= other.Re;
        Im -= other.Im;
        return *this;
    };

    Complex &operator*=(const Complex &other) {
        Complex tmp;
        tmp.Re = (Re * other.Re) - (Im * other.Im);
        tmp.Im = (Re * other.Im) + (Im * other.Re);
        Re = tmp.Re;
        Im = tmp.Im;
        return *this;
    };

    Complex &operator/=(const Complex &other) {
        float division = (other.Re * other.Re) + (other.Im * other.Im);
        Complex tmp;
        tmp.Re = (Re * other.Re) + (Im * other.Im);
        tmp.Re = tmp.Re / division;
        tmp.Im = (Im * other.Re) - (Re * other.Im);
        tmp.Im = tmp.Im / division;
        Re = tmp.Re;
        Im = tmp.Im;
        return *this;
    };
};

int main() {
    Complex c3(4, 5);
    Complex c2(12, 3);
    c3 /= c2;
    std::cout << c3 << std::endl;
    std::cin >> c3;
    std::cout << c3 << std::endl;
}


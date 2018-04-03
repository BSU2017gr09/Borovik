#include <iostream>
#include <cmath>

/* Что бы привести дробь к стандартному виду используйте simplify();
 * при объявлении дроби integer_part и (numerator/denominator) рассматриваются как отдельные части,
 * а не как единое целое, то есть -3,(-4/-5) перейдет не в -3,(4/5), а в -2,(4/5)
 * *
 */
using namespace std;

class Mixed_fraction {
private:
    int numerator;
    int denominator;
    int integer_part;
public:
    Mixed_fraction(int i = 0, int n = 0, int d = 0);

    Mixed_fraction(const Mixed_fraction &other);

    void operator=(const Mixed_fraction &other);

    Mixed_fraction operator+(const Mixed_fraction &other);

    Mixed_fraction operator-(const Mixed_fraction &other);

    Mixed_fraction operator*(const Mixed_fraction &other);

    Mixed_fraction operator/(const Mixed_fraction &other);

    Mixed_fraction &operator/=(const Mixed_fraction &other);

    Mixed_fraction &operator*=(const Mixed_fraction &other);

    Mixed_fraction &operator-=(const Mixed_fraction &other);

    Mixed_fraction &operator+=(const Mixed_fraction &other);

    friend ostream &operator<<(ostream &output, Mixed_fraction &tmp);

    friend istream &operator>>(istream &input, Mixed_fraction &tmp);

    bool operator==(const Mixed_fraction &tmp);

    bool operator!=(const Mixed_fraction &tmp);

    void simplify();

    void reduce();

    ~Mixed_fraction() = default;
};

Mixed_fraction::Mixed_fraction(int i, int n, int d) : integer_part(i), numerator(n), denominator(d) {}

Mixed_fraction::Mixed_fraction(const Mixed_fraction &other) {
    this->integer_part = other.integer_part;
    this->numerator = other.numerator;
    this->denominator = other.denominator;
}

void Mixed_fraction::operator=(const Mixed_fraction &other) {
    this->integer_part = other.integer_part;
    this->numerator = other.numerator;
    this->denominator = other.denominator;
}

ostream &operator<<(ostream &output, Mixed_fraction &tmp) {
    output << tmp.integer_part << ',' << '(' << tmp.numerator << '/' << tmp.denominator << ')';
}

istream &operator>>(istream &input, Mixed_fraction &tmp) {
    input >> tmp.integer_part;
    input.ignore();
    input >> tmp.numerator;
    input.ignore();
    input >> tmp.denominator;
    input.ignore();

}

bool Mixed_fraction::operator==(const Mixed_fraction &tmp) {
    return (this->integer_part == tmp.integer_part &&
            this->denominator == tmp.denominator &&
            this->numerator == tmp.numerator
    );
}

bool Mixed_fraction::operator!=(const Mixed_fraction &tmp) {
    return !(this->integer_part == tmp.integer_part &&
             this->denominator == tmp.denominator &&
             this->numerator == tmp.numerator
    );
}

void Mixed_fraction::simplify() {
    Mixed_fraction other;
    other.numerator = numerator;
    other.denominator = denominator;
    other.integer_part = integer_part;
    if (numerator < 0 && denominator < 0) {
        this->denominator = abs(other.denominator);
        this->numerator = abs(other.numerator);
    }
    other.numerator = numerator;
    other.denominator = denominator;
    other.integer_part = integer_part;
    if (numerator < 0 && denominator > 0 && abs(numerator) > denominator) {
        numerator = abs(other.numerator);
        denominator = (-1) * other.denominator;
    }
    if (integer_part < 0 && (numerator > 0 && denominator > 0)) {
        other.numerator = numerator;
        other.denominator = denominator;
        other.integer_part = integer_part;
        numerator = other.numerator + other.integer_part * other.denominator;
        integer_part = 0;
    }
    if (abs(numerator) > abs(denominator) && numerator < 0) {
        other.numerator = numerator;
        other.denominator = denominator;
        other.integer_part = integer_part;
        numerator = abs(other.numerator % other.denominator);
        integer_part = other.numerator / other.denominator + other.integer_part;
        //integer_part -= 1;
        numerator = other.numerator + other.denominator;
    }
    if (abs(numerator) > abs(denominator)) {
        other.numerator = numerator;
        other.denominator = denominator;
        other.integer_part = integer_part;
        numerator = abs(other.numerator % other.denominator);
        integer_part = other.numerator / other.denominator + other.integer_part;

    }
    if (integer_part < 0 && numerator < 0) {
        other.numerator = numerator;
        other.denominator = denominator;
        other.integer_part = integer_part;
        numerator = abs(other.numerator);
    }
    if (integer_part < 0 && denominator < 0) {
        other.numerator = numerator;
        other.denominator = denominator;
        other.integer_part = integer_part;
        denominator = abs(other.denominator);
    }
    if (integer_part > 0 && (denominator < 0 || numerator < 0)) {
        other.numerator = numerator;
        other.denominator = denominator;
        other.integer_part = integer_part;
        integer_part -= 1;
        numerator = other.numerator + other.denominator;
    }
    if (numerator < 0 && denominator < 0) {
        other.numerator = numerator;
        other.denominator = denominator;
        other.integer_part = integer_part;
        denominator = abs(other.denominator);
        numerator = abs(other.numerator);
    }
    if (denominator != 0 && !(numerator % denominator)) {
        integer_part += numerator / denominator;
        //numerator = 0;
        //denominator = 0;
    }
    /*if (numerator == 0) {
        denominator = 0;
        integer_part = 0;
    }*/

}

Mixed_fraction Mixed_fraction::operator+(const Mixed_fraction &other) {
    Mixed_fraction tmp;
    tmp.denominator = other.denominator * denominator;
    if (integer_part < 0) { tmp.numerator = (-1) * other.denominator; }
    tmp.numerator =
            (integer_part * denominator + numerator) * other.denominator + (other.integer_part * other.denominator +
                                                                            tmp.numerator) * denominator;
    tmp.simplify();
    tmp.reduce();
    if (integer_part < 0) { numerator *= -1; }
    if (denominator == 0 && numerator == 0 && integer_part == 0) { return other; }
    return tmp;
}

Mixed_fraction Mixed_fraction::operator-(const Mixed_fraction &other) {
    Mixed_fraction tmp;
    tmp.denominator = other.denominator * denominator;
    tmp.numerator =
            (integer_part * denominator + numerator) * other.denominator - (other.integer_part * other.denominator +
                                                                            other.numerator) * denominator;
    tmp.simplify();
    tmp.reduce();
    if (denominator == 0 && numerator == 0 && integer_part == 0) {
        tmp.denominator = other.denominator;
        tmp.numerator = other.numerator;
        tmp.integer_part = (-1) * other.integer_part;
        return tmp;
    }
    return tmp;
}

Mixed_fraction Mixed_fraction::operator*(const Mixed_fraction &other) {
    Mixed_fraction tmp;
    tmp.denominator = denominator * other.denominator;
    tmp.numerator =
            (integer_part * denominator + numerator) * (other.integer_part * other.denominator + other.numerator);
    tmp.simplify();
    tmp.reduce();
    return tmp;
}

Mixed_fraction Mixed_fraction::operator/(const Mixed_fraction &other) {
    Mixed_fraction tmp;
    tmp.denominator = denominator * (other.integer_part * other.denominator + other.numerator);
    tmp.numerator =
            (integer_part * denominator + numerator) * other.denominator;
    tmp.simplify();
    tmp.reduce();
    return tmp;
}

Mixed_fraction &Mixed_fraction::operator/=(const Mixed_fraction &other) {
    Mixed_fraction tmp;
    tmp.denominator = denominator * (other.integer_part * other.denominator + other.numerator);
    tmp.numerator =
            (integer_part * denominator + numerator) * other.denominator;
    tmp.simplify();
    tmp.reduce();
    denominator = tmp.denominator;
    numerator = tmp.numerator;
    integer_part = tmp.integer_part;
    return *this;
}

Mixed_fraction &Mixed_fraction::operator+=(const Mixed_fraction &other) {
    Mixed_fraction tmp;
    tmp.denominator = other.denominator * denominator;
    if (integer_part < 0) { numerator *= -1; }
    tmp.numerator =
            (integer_part * denominator + numerator) * other.denominator + (other.integer_part * other.denominator +
                                                                            other.numerator) * denominator;
    tmp.simplify();
    tmp.reduce();
    if (integer_part < 0) { numerator *= -1; }
    denominator = tmp.denominator;
    numerator = tmp.numerator;
    integer_part = tmp.integer_part;
    return *this;
}

Mixed_fraction &Mixed_fraction::operator-=(const Mixed_fraction &other) {
    Mixed_fraction tmp;
    tmp.denominator = other.denominator * denominator;
    tmp.numerator =
            (integer_part * denominator + numerator) * other.denominator - (other.integer_part * other.denominator +
                                                                            other.numerator) * denominator;
    tmp.simplify();
    tmp.reduce();
    if (denominator == 0 && numerator == 0 && integer_part == 0) {
        tmp.denominator = other.denominator;
        tmp.numerator = other.numerator;
        tmp.integer_part = (-1) * other.integer_part;
    }
    denominator = tmp.denominator;
    numerator = tmp.numerator;
    integer_part = tmp.integer_part;
    return *this;
}


Mixed_fraction &Mixed_fraction::operator*=(const Mixed_fraction &other) {
    Mixed_fraction tmp;
    tmp.denominator = denominator * other.denominator;
    tmp.numerator =
            (integer_part * denominator + numerator) * (other.integer_part * other.denominator + other.numerator);
    tmp.simplify();
    tmp.reduce();
    denominator = tmp.denominator;
    numerator = tmp.numerator;
    integer_part = tmp.integer_part;
    return *this;
}

void Mixed_fraction::reduce() {
    Mixed_fraction other;
    other.numerator = numerator;
    other.denominator = denominator;
    other.integer_part = integer_part;
    for (int i = 2; i <= numerator; ++i) {
        if (numerator % i == 0 && denominator % i == 0) {
            numerator /= i;
            denominator /= i;
        }
    }
}


int main() {
    Mixed_fraction a(13, 3, 5);
    Mixed_fraction b(12, 2, 3);
    Mixed_fraction c(-3, 6, 5);
    //cout << a << endl;
    cout << b << endl;
    //a.simplify();
    //b.simplify();
    //cout << a << endl;
    cout << b << endl;
    c = a + b;
    cout << c << endl;
    c = a - b;
    cout << c << endl;
    c = a / b;
    cout << c << endl;
    c = a * b;
    cout << c << endl;
}


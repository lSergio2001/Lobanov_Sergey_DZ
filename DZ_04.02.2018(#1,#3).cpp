#include <iostream>
#include <math.h>

using namespace std;

class Complex{
    double re;
    double im;
    double size = 0;

public:
    Complex* prev;

    Complex(double newRe = 0, double newIm = 0) {
        re = newRe;
        im = newIm;
        prev = NULL;

        if (re == 0 && im == 0) size = 0;

        updateSize();
    };

    Complex(Complex* ref) {
        re = ref->getRe();
        im = ref->getIm();
        size = ref->size;
        prev = NULL;

        if (re == 0 && im == 0) size = 0;

        updateSize();
    };

    void updateSize() {
        size = sqrt(re * re + im * im);
    };

    double getRe() {
        return re;
    }

    double getIm() {
        return im;
    };

    void setRe(double newRe) {
        re = newRe;
    }

    void setIm(double newIm) {
        im = newIm;
    };

    Complex operator+(Complex value) {
        this->re += value.re;
        this->im += value.im;
        updateSize();
        return *this;
    };

    Complex operator-(Complex value) {
        this->re -= value.re;
        this->im -= value.im;
        updateSize();
        return *this;
    };

    Complex operator+(double value) {
        this->re += value;
        updateSize();
        return *this;
    };

    Complex operator-(double value) {
        this->re -= value;
        updateSize();
        return *this;
    };

    bool operator== (Complex value) {
        if (this->size == value.size) return true;
        return false;
    };

    bool operator!= (Complex value) {
        if ( !(*this == value) ) return true;
        return false;
    };

    bool operator> (Complex value) {
        if (this->size > value.size) return true;
        return false;
    };

    bool operator< (Complex value) {
        if (*this != value && !(*this > value)) return true;
        return false;
    };

    bool operator>= (Complex value) {
        if (*this > value || *this == value) return true;
        return false;
    };

    bool operator<= (Complex value) {
        if (*this < value || *this == value) return true;
        return false;
    };

    double getMod() {
        return size;
    };

    Complex interfacing() {
        im = -im;
        return *this;
    };

};

class ComplexVector {
    Complex* tail;
    int size = 0;

public:

    ComplexVector(ComplexVector ref) {
        *this = ref;
    };

    ~ComplexVector() {
        for (int i = 0; i < size; ++i) {
            pop();
        }
        delete *this;
    };

    ComplexVector operator= (ComplexVector ref) {
        for (int i = 0; i < size; ++i) {
            pop();
        }

        size = ref.size;
        tail = NULL;
        Complex* copy;
        Complex* el = ref.tail;
        Complex* temp = new Complex(el);
        tail = temp;
        el = el->prev;
        for (int i = 0; i < ref.size; ++i) {
            if (el != NULL) {
                copy = new Complex(el);
                temp->prev = copy;
                temp = copy;
                el = el->prev;
            }
        }
    };

    Complex operator[] (int i) {
        Complex* temp = tail;
        for (int j = 0; j < i; ++j) {
            temp = temp->prev;
        }

        return *temp;
    };

    void writeVector() {
        double tRe, tIm;
        cout << "( ";
        for (int i = 0; i < size; ++i) {
            tRe = (*this)[i].getRe();
            tIm = (*this)[i].getIm();
            cout << tRe << " + ( " << tIm << " * i ), "
        }
    };

    void push(Complex value) {
        value.prev = tail;
        tail = & value;
        size++;
    };

    void pop() {
        Complex* temp = tail;
        tail = tail->prev;
        delete *temp;
    };


};

int main(string* args) {

    return 0;

}
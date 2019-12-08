/*
	testRational.cpp
	CS2124
	Implement the class Rational, so that the following program works.
 */

#include <iostream>

// If usingtime allows use  separate compilation, otherwise just define the class below
//#include "Rational.h"

using namespace std;

// If usingtime allows after using separate compilation, then wrap the class in a namespace.
//using namespace CS2124;

class Rational{
    friend ostream& operator<<(ostream& os, const Rational& rhs){
        os << rhs.numerator << "/" << rhs.denominator << endl;;
        return os;
    }
    
    friend istream& operator>>(istream& is, Rational& rhs){
        is >> rhs.numerator;
        char oneOperator;
        is >> oneOperator;
        is >> rhs.denominator;
        rhs.normalize();
        return is;
        
    }
    
    friend bool operator==(const Rational& lhs, const Rational& rhs){
        return rhs.numerator == lhs.numerator && rhs.denominator == lhs.denominator;
    }
    
    friend bool operator<(const Rational& lhs, const Rational& rhs){
        int lhsN = lhs.numerator* rhs.denominator;
        int rhsN = rhs.numerator* lhs.denominator;
        return lhsN < rhsN;
    }
    
public:
    
    Rational(int firstNumber = 0, int secondNumber = 1):numerator(firstNumber),denominator(secondNumber){normalize();}
//    Rational(){};
//    Rational(int number):numerator(number),denominator(number){normalize();};
    
    void normalize(){
        int test = greatestCommonDivisor(numerator, denominator);
        if(test != 0 ){
            numerator = numerator/test;
            denominator = denominator/test;
            if(denominator < 0){
                numerator = -numerator;
                denominator = -denominator;
            }
        }
        
    }
    
    int greatestCommonDivisor(int x, int y) {
        while (y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }
    
    Rational& operator+=(const Rational& rhs){
        int num1 = rhs.numerator;
        int num2 = numerator;
        int den1 = rhs.denominator;
        int den2 = denominator;
        
        numerator = num1*den2 + num2*den1;
        denominator = den1 * den2;
        normalize();
        return *this;
    }
    
    
    
    // different i++ and ++i.
    Rational& operator++(){
        numerator += denominator;
        return *this;
    }
    
    
    
    Rational operator++(int dummy){
        Rational out(*this);
        numerator += denominator;
        return out;
    }
    
    explicit operator bool() const{
        return numerator != 0;
    }
private:
    int numerator;
    int denominator;
};

Rational& operator--(Rational& rhs){
//    Rational add(-1,1);
    rhs += -1;
    return rhs;
}

//why we need the dummy here
Rational operator--(Rational& rhs, int dummy){
    //Rational add(-1,1);
    Rational outd(rhs);
    rhs += -1;
    return outd;
}

bool operator!=(const Rational& lhs, const Rational& rhs){
    return !(lhs == rhs);
}

const Rational operator+(const Rational& lhs, const Rational& rhs){
    Rational out = lhs;
    out += rhs;
    return out;
}

bool operator<=(const Rational& lhs, const Rational& rhs){
    return lhs < rhs || lhs == rhs;
}

bool operator>(const Rational& lhs, const Rational& rhs){
    return rhs < lhs;
}

bool operator>=(const Rational& lhs, const Rational& rhs){
    return rhs < lhs || lhs == rhs;
}



int main() {
    Rational twoThirds(2,3);
    cout << twoThirds << endl;
    
    Rational a, b;
    cout << "Input two rational numbers.\n";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    Rational one(1);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;    // Implement as member
    cout << "a = " << a << endl;

    // Implement as non-member, but not a friend
    cout << "a + one: " << (a + one) << endl;
    cout << "a == one: " << boolalpha << (a == one) << endl;
//
//    // How does this manage to work?
//    // It does NOT require writing another == operator.
    cout << "1 == one: " << boolalpha << (1 == one) << endl;
//
//    // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;
//
    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;
    cout << "a = " << a << endl;
    cout << "--a = " << (--a) << endl;
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;
    cout << "a = " << a << endl;

    cout << "++ ++a = " << (++ ++a) << endl;
    cout << "a = " << a << endl;
    cout << "-- --a = " << (-- --a) << endl;
    cout << "a = " << a << endl;

    cout << "a++ ++ = " << (a++ ++) << endl;
    cout << "a = " << a << endl;

//     Even though the above example, (a++ ++), compiled, the
//     following shouldn't.
//     But some compiler vendors might let it...  Is your compiler
//     doing the right thing?
//     cout << "a-- -- = " << (a-- --) << endl;
//     cout << "a = " << a << endl;


    if (Rational(1)) {
        cout << "1 is true" << endl;
    } else {
        cout << "1 is false" << endl;
    }
    if (Rational(0)) {
        cout << "0 is true" << endl;
    } else {
        cout << "0 is false" << endl;
    }
}

//
//  test.cpp
//  rec08_2
//
//  Created by Zhengyi Li on 10/28/18.
//  Copyright © 2018 Zhengyi Li. All rights reserved.
//

#include <stdio.h>
#include "Rational.h"

using namespace std;
using namespace CS2124;

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


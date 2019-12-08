//
//  Rational.h
//  rec08_2
//
//  Created by Zhengyi Li on 10/28/18.
//  Copyright © 2018 Zhengyi Li. All rights reserved.
//

#ifndef Rational_h
#define Rational_h
#include <iostream>

#endif /* Rational_h */

namespace CS2124{
    class Rational{
        friend std::ostream& operator<<(std::ostream& os, const Rational& rhs);
        
        friend std::istream& operator>>(std::istream& is, Rational& rhs);
        
        friend bool operator==(const Rational& lhs, const Rational& rhs);
        
        friend bool operator<(const Rational& lhs, const Rational& rhs);
        
    public:
        
        Rational(int firstNumber =0, int secondNumber=1);
        
        void normalize();
        
        int greatestCommonDivisor(int x, int y);
        
        Rational& operator+=(const Rational& rhs);
        
        
        
        // different i++ and ++i.
        Rational& operator++();
        
        
        
        Rational operator++(int dummy);
        
        explicit operator bool() const;
        
    private:
        int numerator;
        int denominator;
    };
}


//
//  Rational.cpp
//  rec08_2
//
//  Created by Zhengyi Li on 10/28/18.
//  Copyright © 2018 Zhengyi Li. All rights reserved.
//

#include <stdio.h>
#include "Rational.h"
#include <iostream>
using namespace std;

namespace CS2124 {
    ostream& operator<<(ostream& os, const Rational& rhs){
        os << rhs.numerator << "/" << rhs.denominator << endl;;
        return os;
    }
    
    istream& operator>>(istream& is, Rational& rhs){
        is >> rhs.numerator;
        char oneOperator;
        is >> oneOperator;
        is >> rhs.denominator;
        rhs.normalize();
        return is;
        
    }
    
    bool operator==(const Rational& lhs, const Rational& rhs){
        return rhs.numerator == lhs.numerator && rhs.denominator == lhs.denominator;
    }
    
    bool operator<(const Rational& lhs, const Rational& rhs){
        int lhsN = lhs.numerator* rhs.denominator;
        int rhsN = rhs.numerator* lhs.denominator;
        return lhsN < rhsN;
    }
    
    Rational::Rational(int firstNumber, int secondNumber):numerator(firstNumber),denominator(secondNumber){normalize();}
    
    
    void Rational::normalize(){
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
    
    int Rational::greatestCommonDivisor(int x, int y) {
        while (y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }
    
    Rational& Rational::operator+=(const Rational& rhs){
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
    Rational& Rational::operator++(){
        numerator += denominator;
        return *this;
    }
    
    
    
    Rational Rational::operator++(int dummy){
        Rational out(*this);
        numerator += denominator;
        return out;
    }
    
    Rational::operator bool() const{
        return numerator != 0;
    }

}




//
//  Utilities.cpp
//  GeneratePrimeNumbers
//
//  Created by Marc Munar Covas on 26/10/2019.
//  Copyright © 2019 MarcMunar. All rights reserved.
//

#include "Utilities.hpp"

unsigned long long int modulo(unsigned long long int a, unsigned long long int b) {
    unsigned long long int result= a % b;
    if (result < 0)
        result += b;
    return result;
}

bool perfect_square(long double number) {
    if (pow(int(sqrt(number)), 2) == number) {
        return true;
    }
    else {
        return false;
    }
}

unsigned long long int fast_exponentiation(unsigned long long int x, unsigned long long int y, unsigned long long int p) {
    
    unsigned long long int res = 1;
    x = x % p;
    
    while (y > 0) {
        if (y%2 == 1){
            res = (res*x) % p;
        }

        y = y/2;
        x = (x*x)%p;
    }
    return res;
}

unsigned long long int greatest_common_divisor(unsigned long long int a, unsigned long long int b) {
    while (b!=0) {
        long r = a%b;
        a=b;
        b=r;
    }
    return a;
}

unsigned long long int jacobi_symbol(unsigned long long int a, unsigned long long int n){
    
    unsigned long long int b = (unsigned long long int)(a%n);
    unsigned long long int c = n;
    unsigned long long int s=1;
    
    while (b >= 2) {
        while (b%4==0){
            b = b/4;
        }
        if (b%2==0){
            if (c%8 == 3 or c%8==5){
                s = -s;
            }
            b = b/2;
        }
        if (b==1){
            break;
        }
        if (b%4==c%4 and c%4==3){
            s = -s;
        }
        long k = b;
        b = c%b;
        c = k;
    }
    return int(s*b);
}

//
//  Fermat.cpp
//  GeneratePrimeNumbers
//
//  Created by Marc Munar Covas on 26/10/2019.
//  Copyright © 2019 MarcMunar. All rights reserved.
//

#include "Fermat.hpp"

bool fermat_test(unsigned long long int number, unsigned long long int k) {
    
    if (number % 2 == 0) {
        return false;
    }
    
    if (number <= 1 || number == 4) {
        return false;
    }
    if (number <= 3) {
        return true;
    }
    
    while (k>0) {
        unsigned long long int a = 2 + rand()%(number-4);
        if (greatest_common_divisor(number, a) != 1) {
            return false;
        }
            
        if (power(a, number-1, number) != 1) {
            return false;
        }
        k--;
      }
      return true;
}

unsigned long long int power(unsigned long long int a, unsigned long long int n, unsigned long long int p) {
    unsigned long long int res = 1;
    a = a % p;
    
    while (n > 0) {
        if (n & 1) {
            res = (res*a) % p;
        }
              
        n = n>>1;
        a = (a*a) % p;
    }
    return res;
}

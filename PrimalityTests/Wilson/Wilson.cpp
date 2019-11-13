//
//  Lucas.cpp
//  GeneratePrimeNumbers
//
//  Created by Marc Munar Covas on 26/10/2019.
//  Copyright © 2019 MarcMunar. All rights reserved.
//

#include "Wilson.hpp"

bool wilson_test(unsigned long long int number) {
    
    if (number % 2 == 0) {
        return false;
    }
    
    if (fast_factorial_modulo(number-1, number) == -1 || fast_factorial_modulo(number-1, number) == number-1) {
        return true;
    }
    else {
        return false;
    }
}

unsigned long long int fast_factorial_modulo(unsigned long long int n_1, unsigned long long int n_2) {
    if (n_1 >= n_2)
        return 0;
  
    unsigned long long int result = 1;
    for (unsigned long long int i = 1; i <= n_1; i++)
        result = (result * i) % n_2;
  
    return result;
}

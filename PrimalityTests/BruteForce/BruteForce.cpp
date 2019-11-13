//
//  BruteForce.cpp
//  GeneratePrimeNumbers
//
//  Created by Marc Munar Covas on 27/10/2019.
//  Copyright © 2019 MarcMunar. All rights reserved.
//

#include "BruteForce.hpp"

bool detect_prime_number(unsigned long long int number) {
    
    if (number % 2 == 0) {
        return false;
    }
    
    for (unsigned long long int i = 2; i < number/2; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

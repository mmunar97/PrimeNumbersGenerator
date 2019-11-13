//
//  MillerRabin.cpp
//  GeneratePrimeNumbers
//
//  Created by Marc Munar Covas on 26/10/2019.
//  Copyright © 2019 MarcMunar. All rights reserved.
//

#include "MillerRabin.hpp"

bool miller_rabin_test(unsigned long long int number, long double probability) {
    
    if (number % 2 == 0) {
        return false;
    }
    
    //Decomposing the number according to the Miller-Rabin test notation
    unsigned long long int j=0;
    unsigned long long int d=number-1;
    unsigned long long int secondNumber = number-1;
    
    while (secondNumber%2 == 0) {
        j = j+1;
        secondNumber = secondNumber/2;
    }
    d = (number-1)/pow(2, j);
    
    //Calculating the minimum necessary steps to reach the probability
    long total_steps = 0;
    while (probability < pow(0.25, total_steps) and total_steps<(number-3)) {
        total_steps = total_steps+1;
    }
    
    //Setting the seed
    srand(static_cast<unsigned int>(time(NULL)));
    
    //Declarating and cleaning the memory
    unsigned long long int* number_array = new unsigned long long int[total_steps+1];
    memset(number_array, 0, (total_steps+1)*sizeof(long));
    
    //Filling the array with the necessary numbers
    for (long i = 0; i < total_steps+1; i++) {
        number_array[i] = rand() % (number-3)+2;
    }
    
    bool is_prime = false;
    
    //Miller-Rabin Test
    for (int k=0; k<total_steps; k++) {
        long b = number_array[k];
        long x = fast_exponentiation(b, d, number);
        
        if (x==1 or x==number-1) {
            is_prime = true;
            continue;
        }
        for (int i = 1; i<= j-1; i++) {
            x = (x*x)%number;
            if (x == 1) {
                delete[] number_array;
                return false;
            }
            if (x == number-1 or x==-1) {
                is_prime = true;
                break;
            }
        }
    }
    delete[] number_array;
    return is_prime;
}

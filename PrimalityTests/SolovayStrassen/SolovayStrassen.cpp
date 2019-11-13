//
//  SolovayStrassen.cpp
//  GeneratePrimeNumbers
//
//  Created by Marc Munar Covas on 26/10/2019.
//  Copyright © 2019 MarcMunar. All rights reserved.
//

#include "SolovayStrassen.hpp"

bool solovay_strassen_test(unsigned long long int number, long double probability) {
    
    if (number % 2 == 0) {
        return false;
    }
    
    //Calculating the minimum necessary steps to reach the probability
    unsigned long long total_steps = 0;
    while (probability < pow(0.25, total_steps) and total_steps<(number-3)) {
        total_steps = total_steps+1;
    }
    
    //Setting the seed
    srand(static_cast<unsigned int>(time(NULL)));
    
    //Declarating and cleaning the memory
    unsigned long long int* numberArray = new unsigned long long int[total_steps+1];;
    memset(numberArray, 0, (total_steps+1)*sizeof(long));
    
    //Filling the array with the necessary numbers
    for (long i = 0; i < total_steps; i++) {
        numberArray[i] = rand() % (number-3);
    }
    
    int step = 0;
    bool is_prime = true;
    
    //Solovay-Strassen Test
    while (step<total_steps and is_prime == true) {
        if (modulo(fast_exponentiation(numberArray[step], (number-1)/2, number)*jacobi_symbol(numberArray[step], number), number) != 1){
            is_prime = false;
        }
        step = step+1;
    }
    
    delete[] numberArray;
    
    return is_prime;
}

//
//  PrimalityTestManager.cpp
//  GeneratePrimeNumbers
//
//  Created by Marc Munar Covas on 26/10/2019.
//  Copyright © 2019 MarcMunar. All rights reserved.
//

#include "PrimalityTestManager.hpp"
#include <unistd.h>
#include <time.h>

using namespace std;
using namespace std::chrono;

PrimeTuple apply_primality_test(PrimalityTest test,
                                unsigned long long int number,
                                unsigned long long int fermat_parameter,
                                long double probability) {
    
    switch (test) {
        case fermat: {
            clock_t t = clock();
            bool res = fermat_test(number, fermat_parameter);
            t = clock() - t;
            double time_taken = ((double)t)/CLOCKS_PER_SEC;
            
            return std::make_pair(res, time_taken);
            break;
        }
        case wilson: {
            clock_t t = clock();
            bool res = wilson_test(number);
            t = clock() - t;
            double time_taken = ((double)t)/CLOCKS_PER_SEC;
            
            return std::make_pair(res, time_taken);
            break;
        }
        case solovay_strassen: {
            clock_t t = clock();
            bool res = solovay_strassen_test(number, probability);
            t = clock() - t;
            double time_taken = ((double)t)/CLOCKS_PER_SEC;
            
            return std::make_pair(res, time_taken);
            break;
        }
        case miller_rabin: {
            clock_t t = clock();
            bool res = miller_rabin_test(number, probability);
            t = clock() - t;
            double time_taken = ((double)t)/CLOCKS_PER_SEC;
            
            return std::make_pair(res, time_taken);
            break;
        }
        case brute_force: {
            clock_t t = clock();
            bool res = detect_prime_number(number);
            t = clock() - t;
            double time_taken = ((double)t)/CLOCKS_PER_SEC;
            
            return std::make_pair(res, time_taken);
            break;
        }
        default: {
            return std::make_pair(false, 0.0);
            break;
        }
    }
    
}

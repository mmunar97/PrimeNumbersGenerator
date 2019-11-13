//
//  Utilities.hpp
//  GeneratePrimeNumbers
//
//  Created by Marc Munar Covas on 26/10/2019.
//  Copyright © 2019 MarcMunar. All rights reserved.
//

#ifndef Utilities_hpp
#define Utilities_hpp

#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

unsigned long long int modulo(unsigned long long int a, unsigned long long int b);
unsigned long long int fast_exponentiation(unsigned long long int x, unsigned long long int y, unsigned long long int p);
unsigned long long int greatest_common_divisor(unsigned long long int a, unsigned long long int b);
unsigned long long int jacobi_symbol(unsigned long long int a, unsigned long long int n);

#endif /* Utilities_hpp */

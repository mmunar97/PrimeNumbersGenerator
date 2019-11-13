//
//  Fermat.hpp
//  GeneratePrimeNumbers
//
//  Created by Marc Munar Covas on 26/10/2019.
//  Copyright © 2019 MarcMunar. All rights reserved.
//

#ifndef Fermat_hpp
#define Fermat_hpp

#include <stdio.h>
#include "Utilities.hpp"

bool fermat_test(unsigned long long int number, unsigned long long int k);
unsigned long long int power(unsigned long long int a, unsigned long long int n, unsigned long long int p);

#endif /* Fermat_hpp */

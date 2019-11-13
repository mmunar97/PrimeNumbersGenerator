//
//  PrimalityTestManager.hpp
//  GeneratePrimeNumbers
//
//  Created by Marc Munar Covas on 26/10/2019.
//  Copyright © 2019 MarcMunar. All rights reserved.
//

#ifndef PrimalityTestManager_hpp
#define PrimalityTestManager_hpp

#include <stdio.h>
#include <chrono>

#include "MillerRabin/MillerRabin.hpp"
#include "SolovayStrassen/SolovayStrassen.hpp"
#include "Fermat/Fermat.hpp"
#include "Wilson/Wilson.hpp"
#include "BruteForce/BruteForce.hpp"

#include "PrimalityTest.cpp"

using PrimeTuple = std::pair<bool, double>;

PrimeTuple apply_primality_test(PrimalityTest test, unsigned long long int number, unsigned long long int fermat_parameter, long double probability);

#endif /* PrimalityTestManager_hpp */

//
//  PrimalityTest.cpp
//  GeneratePrimeNumbers
//
//  Created by Marc Munar Covas on 26/10/2019.
//  Copyright © 2019 MarcMunar. All rights reserved.
//

#include <stdio.h>
#include <iostream>

enum PrimalityTest {
    fermat = 0,
    wilson = 1,
    solovay_strassen = 2,
    miller_rabin = 3,
    brute_force = 4
};

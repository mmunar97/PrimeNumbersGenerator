//
//  main.cpp
//  GeneratePrimeNumbers
//
//  Created by Marc Munar Covas on 26/10/2019.
//  Copyright © 2019 MarcMunar. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

#include "PrimalityTests/PrimalityTestManager.hpp"

using namespace std;
using namespace std::chrono;

void generate_prime_numbers(unsigned long long int, unsigned long long int, char*);
bool detect_prime_number(unsigned long long int);

int main(int argc, const char * argv[]) {
    
    unsigned long long int start_number = 0;
    unsigned long long int final_number = 0;
    
    int finite_execution = 0;
    
    char saving_path[1000];
    
    printf("ENTER INITIAL NUMBER: ");
    scanf("%lld",&start_number);
    
    printf("\nENTER FINAL CRITERIA (0: Finite execution, 1: Infinite execution): ");
    scanf("%d",&finite_execution);
    
    if (finite_execution == 0) {
        printf("\nENTER FINAL NUMBER: ");
        scanf("%lld",&final_number);
    }
    else {
        final_number = ULLONG_MAX;
    }
    
    printf("\nENTER SAVING RESULTS PATH: ");
    scanf("%s",&saving_path);
    
    printf("\nGENERATING PRIME NUMBERS \n");
    generate_prime_numbers(start_number, final_number, saving_path);
    
    return 0;
}

void generate_prime_numbers(unsigned long long int start_number, unsigned long long int final_number, char* saving_path) {
    
    ofstream results_file(saving_path);
    
    if (results_file.is_open()) {
        
        string header_row= "NUMBER,RESULT_BF,TIME_BF,RESULT_FERMAT,TIME_FERMAT,RESULT_WILSON,TIME_WILSON,RESULT_SS,TIME_SS,RESULT_MR,TIME_MR";
        results_file<<header_row<<endl;
        
        for (unsigned long long int i = start_number; i <= final_number; i++) {

            PrimeTuple result_bf = apply_primality_test(PrimalityTest::brute_force, i, NULL, NULL);
            PrimeTuple result_fermat = apply_primality_test(PrimalityTest::fermat, i, 50, NULL);
            PrimeTuple result_wilson = apply_primality_test(PrimalityTest::wilson, i, NULL, NULL);
            PrimeTuple result_ss = apply_primality_test(PrimalityTest::solovay_strassen, i, NULL, 0.975);
            PrimeTuple result_mr = apply_primality_test(PrimalityTest::miller_rabin, i, NULL, 0.975);
            
            string row = std::to_string(i)+","+std::to_string(result_bf.first)+","+std::to_string(result_bf.second);
            row = row+","+std::to_string(result_fermat.first)+","+std::to_string(result_fermat.second);
            row = row+","+std::to_string(result_wilson.first)+","+std::to_string(result_wilson.second);
            row = row+","+std::to_string(result_ss.first)+","+std::to_string(result_ss.second);
            row = row+","+std::to_string(result_mr.first)+","+std::to_string(result_mr.second);
            results_file<<row<<endl;
        }
    }
    results_file.close();
    
}

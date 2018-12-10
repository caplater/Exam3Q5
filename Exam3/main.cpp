//
//  main.cpp
//  Exam3
//
//  Created by Charles Plater on 12/9/18.
//  Copyright © 2018 Charles Plater. All rights reserved.
//

#include <iostream>
#include <tgmath.h>
#include <math.h>

int E (int x, int x2, int x3) {
    
    int retval1 = (pow(x,3) + pow(x2,4) + pow(x3,6) - 263467);
    int retval2 = (pow(x2,4) + (x*x3*pow(x2,2)) + pow(x,5) - 2403);
    int retval3 = (pow(x,6) + (pow(x2,2) * pow(x3,3) * pow(x,4)) + (pow(x2,3) * pow(x3,5)) - 8571609);
    
    int returnValue = ( pow(retval1,2) + pow(retval2,2) + pow(retval3,2));
    return returnValue;
}

int main(int argc, const char * argv[]) {

    int x1 = arc4random_uniform(9);
    int x2 = arc4random_uniform(9);
    int x3 = arc4random_uniform(9);

    int accepted1, accepted2, accepted3;

    for (int temp = 100; temp > 9; temp -= 10){

        int result1 = E(x1, x2, x3);

        for (int x = 0; x < 5 ; x++) {
            int x4 = arc4random_uniform(9);
            int x5 = arc4random_uniform(9);
            int x6 = arc4random_uniform(9);

            int result2 = E(x4,x5,x6);

            float p = exp(-(result1 - result2)/temp);

            if (p>=1) {
                accepted1 = x4;
                accepted2 = x5;
                accepted3 = x6;
            } else {
                x4 = arc4random_uniform(9);
                x5 = arc4random_uniform(9);
                x6 = arc4random_uniform(9);
            }
        }
        std::cout << accepted1;
        std::cout << " ";
        std::cout << accepted2;
        std::cout << " ";
        std::cout << accepted3;
        std::cout << " accepted at temp ";
        std::cout << temp;
        std::cout << "\n";
    }
    return 0;
}
